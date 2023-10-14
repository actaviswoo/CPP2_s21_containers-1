#ifndef CPP2_S21_CONTAINERS_SRC_HEADERS_S21_VECTOR_H
#define CPP2_S21_CONTAINERS_SRC_HEADERS_S21_VECTOR_H

#include <algorithm>
#include <iterator>
#include <limits>

namespace s21 {
template <typename T>
class vector {
 public:
  //-----------------------------------------------------------------
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;
  //-----------------------------------------------------------------
  vector() = default;
  explicit vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  ~vector();
  //-----------------------------------------------------------------
  vector<T> &operator=(const vector &v);
  vector<T> &operator=(vector &&v);
  //-----------------------------------------------------------------
  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference operator[](size_type pos) noexcept;
  const_reference operator[](size_type pos) const noexcept;
  reference front() noexcept;
  const_reference front() const noexcept;
  reference back() noexcept;
  const_reference back() const noexcept;
  iterator data() noexcept;
  const_iterator data() const noexcept;
  //-----------------------------------------------------------------
  iterator begin() noexcept;
  const_iterator cbegin() const noexcept;
  iterator end() noexcept;
  const_iterator cend() const noexcept;
  //-----------------------------------------------------------------
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;
  void reserve(size_type size);
  size_type capacity() const noexcept;
  void shrink_to_fit() noexcept;
  //-----------------------------------------------------------------
  void clear() noexcept;
  iterator insert(const_iterator pos, const_reference value);
  iterator insert(const_iterator pos, value_type &&value);
  iterator erase(const_iterator pos);
  void push_back(const_reference value);
  void push_back(value_type &&value);
  void pop_back();
  void swap(vector &other) noexcept;
  //-----------------------------------------------------------------
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);
  //-----------------------------------------------------------------
 private:
  value_type *vector_ = nullptr;
  size_type size_ = 0;
  size_type capacity_ = 0;
  //-----------------------------------------------------------------
};

//-----------------------------------------------------------------

template <typename T>
vector<T>::vector(size_type n)
    : vector_(new value_type[n]), size_(n), capacity_(n) {
  for (size_type i = 0; i < n; ++i) {
    vector_[i] = T();
  }
}

template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items)
    : vector(items.size()) {
  std::copy(items.begin(), items.end(), begin());
}

template <typename T>
vector<T>::vector(const vector &v) : vector(v.size()) {
  std::copy(v.cbegin(), v.cend(), begin());
}

template <typename T>
vector<T>::vector(vector &&v) {
  size_ = std::exchange(v.size_, 0);
  capacity_ = std::exchange(v.capacity_, 0);
  vector_ = std::exchange(v.vector_, nullptr);
}

template <typename T>
vector<T>::~vector() {
  delete[] vector_;
  vector_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}

//-----------------------------------------------------------------

template <typename T>
vector<T> &vector<T>::operator=(const vector &v) {
  if (this != &v) {
    if (v.size_ > capacity_) {
      reserve(v.size_);
    }
    size_ = v.size_;
    std::copy(v.cbegin(), v.cend(), begin());
  }
  return *this;
}

template <typename T>
vector<T> &vector<T>::operator=(vector &&v) {
  if (this != &v) {
    size_ = std::exchange(v.size_, 0);
    capacity_ = std::exchange(v.capacity_, 0);
    vector_ = std::exchange(v.vector_, nullptr);
  }
  return *this;
}

//-----------------------------------------------------------------

template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range(
        "typename vector<T>::reference vector<T>::at(size_type pos) "
        ":: index out of range");
  }
  return vector_[pos];
}

template <typename T>
typename vector<T>::const_reference vector<T>::at(size_type pos) const {
  if (pos >= size_) {
    throw std::out_of_range(
        "typename vector<T>::const_reference vector<T>::at(size_type "
        "pos) const :: index out of range");
  }
  return vector_[pos];
}

template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos) noexcept {
  return vector_[pos];
}

template <typename T>
typename vector<T>::const_reference vector<T>::operator[](
    size_type pos) const noexcept {
  return vector_[pos];
}

template <typename T>
typename vector<T>::reference vector<T>::front() noexcept {
  return vector_[0];
}

template <typename T>
typename vector<T>::const_reference vector<T>::front() const noexcept {
  return vector_[0];
}

template <typename T>
typename vector<T>::reference vector<T>::back() noexcept {
  return vector_[size_ - 1];
}

template <typename T>
typename vector<T>::const_reference vector<T>::back() const noexcept {
  return vector_[size_ - 1];
}

template <typename T>
typename vector<T>::iterator vector<T>::data() noexcept {
  return vector_;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::data() const noexcept {
  return vector_;
}

//-----------------------------------------------------------------

template <typename T>
typename vector<T>::iterator vector<T>::begin() noexcept {
  return vector_;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::cbegin() const noexcept {
  return vector_;
}

template <typename T>
typename vector<T>::iterator vector<T>::end() noexcept {
  return vector_ + size_;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::cend() const noexcept {
  return vector_ + size_;
}

//-----------------------------------------------------------------

template <typename T>
bool vector<T>::empty() const noexcept {
  return size() == 0;
}

template <typename T>
typename vector<T>::size_type vector<T>::size() const noexcept {
  return size_;
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() const noexcept {
  return std::numeric_limits<size_type>::max() / sizeof(value_type) / 2;
}

template <typename T>
void vector<T>::reserve(size_type size) {
  if (size > max_size()) {
    throw std::length_error(
        "void vector<T>::reserve(size_type size) :: can't allocate "
        "memory of this size");
  }
  if (size >= size_) {
    vector<value_type> temp(size);
    std::copy(vector_, vector_ + size_, temp.vector_);
    temp.size_ = size_;
    std::swap(*this, temp);
  }
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() const noexcept {
  return capacity_;
}

template <typename T>
void vector<T>::shrink_to_fit() noexcept {
  if (size_ < capacity_) {
    vector<value_type> temp(size_);
    std::copy(vector_, vector_ + size_, temp.vector_);
    this->~vector();
    new (this) vector(std::move(temp));
  }
}

//-----------------------------------------------------------------

template <typename T>
void vector<T>::clear() noexcept {
  size_ = 0;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(const_iterator pos,
                                               const_reference value) {
  const size_type index = pos - cbegin();
  if (index > size_) {
    throw std::out_of_range(
        "typename vector<T>::iterator "
        "vector<T>::insert(const_iterator pos, const_reference value) :: out "
        "of range");
  }
  if (size_ == capacity_) {
    reserve(capacity_ == 0 ? 1 : 2 * capacity_);
  }
  std::copy_backward(cbegin() + index, cend(), end() + 1);
  vector_[index] = value;
  ++size_;
  return begin() + index;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(const_iterator pos,
                                               value_type &&value) {
  const size_type index = pos - cbegin();
  if (index > size_) {
    throw std::out_of_range(
        "typename vector<T>::iterator "
        "vector<T>::insert(const_iterator pos, value_type &&value) :: out of "
        "range");
  }
  if (size_ == capacity_) {
    reserve(capacity_ == 0 ? 1 : 2 * capacity_);
  }
  std::move_backward(cbegin() + index, cend(), end() + 1);
  vector_[index] = std::move(value);
  ++size_;
  return begin() + index;
}

template <typename T>
typename vector<T>::iterator vector<T>::erase(const_iterator pos) {
  const size_type index = pos - cbegin();
  if (index >= size_) {
    throw std::out_of_range(
        "typename vector<T>::iterator "
        "vector<T>::erase(const_iterator pos) :: out of range");
  }
  std::move(cbegin() + index + 1, cend(), vector_ + index);
  --size_;
  return begin() + index;
}

template <typename T>
void vector<T>::push_back(const_reference value) {
  if (capacity_ == max_size()) {
    throw std::length_error(
        "void vector<T>::push_back(const_reference value) :: reached "
        "maximum size");
  }
  if (size_ == capacity_) {
    reserve(capacity_ == 0 ? 1 : 2 * capacity_);
  }
  vector_[size_] = value;
  ++size_;
}

template <typename T>
void vector<T>::push_back(value_type &&value) {
  if (capacity_ == max_size()) {
    throw std::length_error(
        "void vector<T>::push_back(const_reference value) :: reached "
        "maximum size");
  }
  if (size_ == capacity_) {
    reserve(capacity_ == 0 ? 1 : 2 * capacity_);
  }
  vector_[size_] = std::move(value);
  ++size_;
}

template <typename T>
void vector<T>::pop_back() {
  if (empty()) {
    throw std::logic_error("void vector<T>::pop_back() :: vector is empty");
  }
  size_ -= 1;
}

template <typename T>
void vector<T>::swap(vector &other) noexcept {
  std::swap(vector_, other.vector_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

//-----------------------------------------------------------------

template <typename value_type>
template <typename... Args>
typename vector<value_type>::iterator vector<value_type>::insert_many(
    const_iterator pos, Args &&...args) {
  vector<value_type> temp{args...};
  iterator it = begin() + (pos - cbegin());
  for (size_t i = 0; i < temp.size(); ++i) {
    it = insert(it, temp[i]);
    ++it;
  }
  return it;
}

template <typename value_type>
template <typename... Args>
void vector<value_type>::insert_many_back(Args &&...args) {
  insert_many(end(), args...);
}

//-----------------------------------------------------------------

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_HEADERS_S21_VECTOR_H
