#ifndef CPP2_S21_CONTAINERS_SRC_HEADERS_S21_SET_H
#define CPP2_S21_CONTAINERS_SRC_HEADERS_S21_SET_H

#include <initializer_list>
#include <stdexcept>

#include "s21_vector.h"

namespace s21 {
template <typename T>
class set {
 public:
  using key_type = T;
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;

 private:
  struct Node {
    value_type data_{};
    Node* parent_{nullptr};
    Node* left_{nullptr};
    Node* right_{nullptr};
  };

 public:
  class SetIterator {
   public:
    SetIterator() {}
    const_reference operator*() const;
    const value_type* operator->() const;
    SetIterator& operator++();
    SetIterator& operator--();
    bool operator==(const SetIterator& other) const;
    bool operator!=(const SetIterator& other) const;

    friend class set;

   private:
    Node* ptr_{nullptr};

    SetIterator(Node* ptr) : ptr_(ptr) {}
    void check_null_error() const;
    void check_last_error() const;
  };

  using iterator = SetIterator;
  using const_iterator = SetIterator;

  set() {}
  set(std::initializer_list<value_type> const& items);
  set(const set& s);
  set(set&& s) noexcept;
  virtual ~set();
  set& operator=(set&& s) noexcept;

  iterator begin() const;
  iterator end() const;

  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  void erase(iterator pos);
  void swap(set& other);
  void merge(set& other);

  iterator find(const key_type& key) const;
  bool contains(const key_type& key) const;

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> emplace(Args&&... args);

 protected:
  std::pair<iterator, bool> insert_node(const value_type& value);
  value_type* get_address_val(const iterator& it);

 private:
  Node* top_{nullptr};
  size_type size_{0};

  set& operator=(const set& s) {}

  iterator add(Node*& ptr, Node* parent, const value_type& data);
  Node* remove_node(Node* ptr, key_type key);
  Node* min(Node* ptr) const;
  Node* max(Node* ptr) const;
  bool is_end(Node* ptr) const;
  bool is_begin(Node* ptr) const;
  void free(Node* top);
};

template <typename T>
typename set<T>::const_reference set<T>::SetIterator::operator*() const {
  check_null_error();
  check_last_error();

  return ptr_->data_;
}

template <typename T>
const typename set<T>::value_type* set<T>::SetIterator::operator->() const {
  check_null_error();
  check_last_error();

  return &(ptr_->data_);
}

template <typename T>
typename set<T>::SetIterator& set<T>::SetIterator::operator++() {
  check_null_error();
  if (set().is_end(ptr_))
    throw std::invalid_argument("Cannot increment end set/map iterator");

  if (ptr_->right_) {
    ptr_ = ptr_->right_;
    while (ptr_->left_) ptr_ = ptr_->left_;
  } else {
    while (ptr_->parent_ && ptr_->data_ >= ptr_->parent_->data_)
      ptr_ = ptr_->parent_;
    ptr_ = ptr_->parent_;
  }
  return *this;
}

template <typename T>
typename set<T>::SetIterator& set<T>::SetIterator::operator--() {
  check_null_error();
  if (set().is_begin(ptr_))
    throw std::invalid_argument("Cannot decrement begin set/map iterator");

  if (set().is_end(ptr_)) {
    ptr_ = ptr_->parent_;
  } else if (ptr_->left_) {
    ptr_ = ptr_->left_;
    while (ptr_->right_) ptr_ = ptr_->right_;
  } else {
    while (ptr_->parent_ && ptr_->data_ < ptr_->parent_->data_)
      ptr_ = ptr_->parent_;
    ptr_ = ptr_->parent_;
  }
  return *this;
}

template <typename T>
bool set<T>::SetIterator::operator==(const SetIterator& other) const {
  return ptr_ == other.ptr_;
}

template <typename T>
bool set<T>::SetIterator::operator!=(const SetIterator& other) const {
  return ptr_ != other.ptr_;
}

template <typename T>
void set<T>::SetIterator::check_null_error() const {
  if (!ptr_ || (!ptr_->parent_ && !ptr_->right_))
    throw std::invalid_argument("Incorrect access to the iterator");
}

template <typename T>
void set<T>::SetIterator::check_last_error() const {
  if (set().is_end(ptr_))
    throw std::invalid_argument("Incorrect access to the iterator");
}

template <typename T>
set<T>::set(std::initializer_list<set<T>::value_type> const& items) {
  for (auto& item : items) insert(item);
}

template <typename T>
set<T>::set(const set& s) {
  const_iterator it(s.begin());
  const_iterator last(s.end());
  for (; it != last; ++it) insert(*it);
}

template <typename T>
set<T>::set(set&& s) noexcept : top_(s.top_), size_(s.size_) {
  s.top_ = nullptr;
  s.size_ = 0;
}

template <typename T>
set<T>::~set() {
  free(top_);
}

template <typename T>
typename set<T>::set& set<T>::operator=(set&& s) noexcept {
  if (this == &s) return *this;

  free(top_);
  top_ = s.top_;
  size_ = s.size_;
  s.top_ = nullptr;
  s.size_ = 0;

  return *this;
}

template <typename T>
typename set<T>::iterator set<T>::begin() const {
  return iterator(min(top_));
}

template <typename T>
typename set<T>::iterator set<T>::end() const {
  return iterator(max(top_));
}

template <typename T>
bool set<T>::empty() const {
  return size_ == 0;
}

template <typename T>
typename set<T>::size_type set<T>::size() const {
  return size_;
}

template <typename T>
typename set<T>::size_type set<T>::max_size() const {
  return std::numeric_limits<size_t>::max() / (sizeof(Node) / 2) / 5;
}

template <typename T>
void set<T>::clear() {
  free(top_);
  top_ = nullptr;
  size_ = 0;
}

template <typename T>
std::pair<typename set<T>::iterator, bool> set<T>::insert(
    const value_type& value) {
  if (!contains(value)) return insert_node(value);

  iterator it = find(value);
  return std::pair<iterator, bool>(it, false);
}

template <typename T>
void set<T>::erase(iterator pos) {
  if (size_ == 0) throw std::invalid_argument("Set is empty");
  if (pos == end()) throw std::invalid_argument("Incorrect iterator");

  top_ = remove_node(top_, *pos);
  --size_;
}

template <typename T>
void set<T>::swap(set& other) {
  if (top_ != other.top_) {
    Node* temp = top_;
    top_ = other.top_;
    other.top_ = temp;

    size_ += other.size_;
    other.size_ = size_ - other.size_;
    size_ = size_ - other.size_;
  }
}

template <typename T>
void set<T>::merge(set& other) {
  if (this != &other) {
    iterator it = other.begin();
    iterator temp;
    while (it != other.end()) {
      if (!contains(*it)) {
        insert(*it);
        temp = it;
        ++it;
        other.erase(temp);
      } else {
        ++it;
      }
    }
  }
}

template <typename T>
typename set<T>::iterator set<T>::find(const key_type& key) const {
  iterator it = begin();
  while (it != end()) {
    if (*it == key) return it;
    ++it;
  }

  return it;
}

template <typename T>
bool set<T>::contains(const key_type& key) const {
  if (find(key) != end()) return true;

  return false;
}

template <typename T>
template <typename... Args>
std::vector<std::pair<typename set<T>::iterator, bool>> set<T>::emplace(
    Args&&... args) {
  std::vector<std::pair<iterator, bool>> v;
  v.push_back(insert(key_type(std::forward<Args>(args)...)));
  return v;
}

template <typename T>
std::pair<typename set<T>::iterator, bool> set<T>::insert_node(
    const value_type& value) {
  iterator it;
  Node* ptr = max(top_);
  if (size_ == 0) {
    top_ = new Node;
    top_->data_ = value;
    top_->right_ = new Node;
    top_->right_->parent_ = top_;
    it = iterator(top_);
  } else if (value >= ptr->parent_->data_) {
    ptr->data_ = value;
    ptr->right_ = new Node;
    ptr->right_->parent_ = ptr;
    it = iterator(ptr);
  } else {
    it = add(top_, nullptr, value);
  }
  ++size_;
  return std::pair<iterator, bool>(it, true);
}

template <typename T>
typename set<T>::value_type* set<T>::get_address_val(const iterator& it) {
  it.check_null_error();
  it.check_last_error();

  return &(it.ptr_->data_);
}

template <typename T>
typename set<T>::iterator set<T>::add(Node*& ptr, Node* parent,
                                      const value_type& data) {
  if (!ptr) {
    ptr = new Node;
    ptr->data_ = data;
    ptr->parent_ = parent;
    return iterator(ptr);
  } else if (data < ptr->data_) {
    return add(ptr->left_, ptr, data);
  } else if (data >= ptr->data_) {
    return add(ptr->right_, ptr, data);
  }
  return iterator();
}

template <typename T>
typename set<T>::Node* set<T>::remove_node(Node* ptr, key_type key) {
  Node* temp = nullptr;
  if (!ptr) return ptr;

  if (key < ptr->data_) {
    ptr->left_ = remove_node(ptr->left_, key);
  } else if (key > ptr->data_) {
    ptr->right_ = remove_node(ptr->right_, key);
  } else if (ptr->left_ && ptr->right_) {
    temp = ptr;
    ptr = min(ptr->right_);
    ptr->left_ = temp->left_;
    temp->left_->parent_ = ptr;
    if (ptr != temp->right_) {
      if (ptr->right_) {
        ptr->parent_->left_ = ptr->right_;
        ptr->right_->parent_ = ptr->parent_;
      } else {
        ptr->parent_->left_ = nullptr;
      }
      ptr->right_ = temp->right_;
      temp->right_->parent_ = ptr;
    }
    ptr->parent_ = nullptr;
  } else if (ptr->left_) {
    temp = ptr;
    ptr = ptr->left_;
    ptr->parent_ = temp->parent_;
  } else if (ptr->right_) {
    temp = ptr;
    ptr = ptr->right_;
    ptr->parent_ = temp->parent_;
  } else {
    temp = ptr;
    ptr = nullptr;
  }

  if (temp) {
    delete temp;
    temp->left_ = nullptr;
    temp->right_ = nullptr;
    temp->parent_ = nullptr;
  }

  return ptr;
}

template <typename T>
typename set<T>::Node* set<T>::min(Node* ptr) const {
  if (!ptr) return ptr;
  while (ptr->left_) ptr = ptr->left_;
  return ptr;
}

template <typename T>
typename set<T>::Node* set<T>::max(Node* ptr) const {
  if (!ptr) return ptr;
  while (ptr->right_) ptr = ptr->right_;
  return ptr;
}

template <typename T>
bool set<T>::is_end(Node* ptr) const {
  Node* temp = ptr;
  while (temp->parent_) temp = temp->parent_;

  return max(temp) == ptr;
}

template <typename T>
bool set<T>::is_begin(Node* ptr) const {
  Node* temp = ptr;
  while (temp->parent_) temp = temp->parent_;

  return min(temp) == ptr;
}

template <typename T>
void set<T>::free(Node* top) {
  if (top) {
    free(top->left_);
    free(top->right_);
    delete top;
  }
}
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_HEADERS_S21_SET_H
