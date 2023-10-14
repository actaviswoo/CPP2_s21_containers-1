#ifndef CPP2_S21_CONTAINERS_SRC_HEADERS_S21_LIST_H
#define CPP2_S21_CONTAINERS_SRC_HEADERS_S21_LIST_H

namespace s21 {
#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <stdexcept>
#include <utility>

template <class T>
class list {
 private:
  // Internal Data Container representing single value
  struct Node {
    T data;
    Node *next;

    Node(T value) : data(value), next(nullptr){};
    Node(T value, Node *next) : data(value), next(next){};
  };

  class ListIterator {
   public:
    // Member types
    using iter_category = std::forward_iterator_tag;
    using diff_type = std::ptrdiff_t;
    using ref = T &;

    ListIterator(Node *ptr) : m_ptr(ptr){};

    ref operator*() const { return m_ptr->data; };
    ref operator->() { return m_ptr->data; };

    // Prefix increment
    ListIterator &operator++() {
      m_ptr = m_ptr->next;
      return *this;
    };

    // Postfix increment
    ListIterator operator++(int) {
      ListIterator tmp = *this;
      m_ptr = m_ptr->next;
      return tmp;
    };

    friend bool operator==(const ListIterator &a, const ListIterator &b) {
      return a.m_ptr == b.m_ptr;
    };
    friend bool operator!=(const ListIterator &a, const ListIterator &b) {
      return a.m_ptr != b.m_ptr;
    };

    Node *ptr() { return m_ptr; };

   private:
    Node *m_ptr;
  };

  class ListConstIterator {
   public:
    // Member types
    using iter_category = std::forward_iterator_tag;
    using diff_type = std::ptrdiff_t;
    using ref = T &;
    using const_ref = const T &;

    ListConstIterator(Node *ptr) : m_ptr(ptr){};

    const_ref operator*() const { return m_ptr->data; };
    const_ref operator->() { return m_ptr->data; };

    // Prefix increment
    ListConstIterator &operator++() {
      m_ptr = m_ptr->next;
      return *this;
    };

    // Postfix increment
    ListConstIterator operator++(int) {
      ListConstIterator tmp = *this;
      m_ptr = m_ptr->next;
      return tmp;
    };

    friend bool operator==(const ListConstIterator &a,
                           const ListConstIterator &b) {
      return a.m_ptr == b.m_ptr;
    };
    friend bool operator!=(const ListConstIterator &a,
                           const ListConstIterator &b) {
      return a.m_ptr != b.m_ptr;
    };

    Node *ptr() { return m_ptr; };

   private:
    Node *m_ptr;
  };

 public:
  // Member types
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;
  using size_type = size_t;

  // Constructors and Destructors
  list();
  list(std::initializer_list<value_type> const &items);
  list(size_type n);
  list(const list &l);
  list(list &&l) noexcept;

  ~list();

  list &operator=(const list &l) noexcept;
  list &operator=(list &&l) noexcept;

  // Element access
  const_reference front();
  const_reference back();

  // Iterators
  iterator begin();
  iterator end();

  const_iterator cbegin();
  const_iterator cend();

  // Capacity
  bool empty();
  size_t size();
  size_t max_size();

  // Modifiers
  void clear();
  iterator insert(iterator pos, const_reference val);
  void erase(iterator pos);
  void push_back(const_reference val);
  void pop_back();
  void push_front(const_reference val);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

  template <class... Args>
  iterator insert_many(const_iterator pos, Args &&...args);

  template <class... Args>
  void insert_many_back(Args &&...args);

  template <class... Args>
  void insert_many_front(Args &&...args);

 private:
  // Private functions
  Node *_tail();
  Node *_second_to_last();
  size_t _count_elements();
  void _copy(const list &other);
  Node *_get_at_node(size_t index);
  std::pair<Node *, Node *> _get_at_node_with_predicate(size_t index);
  void _swap_nodes(size_t idx1, size_t idx2);

 private:
  Node *m_head;
};

template <class T>
list<T>::list() : m_head(nullptr) {}

template <class T>
list<T>::list(size_type n) : m_head(nullptr) {
  for (size_type i = 0; i != n; i++) push_back(value_type());
}

template <class T>
list<T>::list(std::initializer_list<value_type> const &items)
    : m_head(nullptr) {
  for (auto &item : items) push_back(item);
}

template <class T>
list<T>::list(const list &l) : m_head(nullptr) {
  // Nothing to do
  if (l.m_head == nullptr) return;
  _copy(l);
}

template <class T>
list<T>::list(list &&l) noexcept : m_head(l.m_head) {
  l.m_head = nullptr;
}

template <class T>
list<T>::~list() {
  // Nothing to do
  if (m_head == nullptr) return;

  while (m_head->next != nullptr) {
    Node *stl = _second_to_last();
    delete stl->next;
    stl->next = nullptr;
  }

  delete m_head;
}

template <class T>
list<T> &list<T>::operator=(const list &l) noexcept {
  if (m_head != nullptr) {
    this->~list();
    m_head = nullptr;
  }

  _copy(l);

  return *this;
}

template <class T>
list<T> &list<T>::operator=(list &&l) noexcept {
  m_head = l.m_head;
  l.m_head = nullptr;
  return *this;
}

template <class T>
typename list<T>::const_reference list<T>::front() {
  if (m_head == nullptr) throw std::logic_error("List is empty");
  return m_head->data;
}

template <class T>
typename list<T>::const_reference list<T>::back() {
  return _tail()->data;
}

template <class T>
typename list<T>::iterator list<T>::begin() {
  return iterator(m_head);
}

template <class T>
typename list<T>::iterator list<T>::end() {
  return iterator(_tail()->next);
}

template <class T>
typename list<T>::const_iterator list<T>::cbegin() {
  return const_iterator(m_head);
}

template <class T>
typename list<T>::const_iterator list<T>::cend() {
  return const_iterator(_tail()->next);
}

template <class T>
bool list<T>::empty() {
  return m_head == nullptr;
}

template <class T>
size_t list<T>::size() {
  return _count_elements();
}

template <class T>
size_t list<T>::max_size() {
  return std::numeric_limits<size_type>::max() / sizeof(Node) / 3;
}

template <class T>
void list<T>::clear() {
  this->~list();
  m_head = nullptr;
}

template <class T>
typename list<T>::iterator list<T>::insert(iterator pos, const_reference val) {
  Node *node = pos.ptr(), *newNode = new Node(val);
  newNode->next = node;

  size_t idx = 0;
  Node *prev = nullptr, *curr = _get_at_node(idx);

  while (curr != node) {
    prev = curr;
    curr = _get_at_node(++idx);
  }

  if (prev == nullptr) {
    m_head = newNode;
  } else {
    prev->next = newNode;
  }

  return iterator(newNode);
}

template <class T>
void list<T>::erase(iterator pos) {
  size_t idx = 0;
  auto it = begin();

  while ((it++) != pos) idx++;

  Node *tmp = pos.ptr();
  while (tmp != nullptr) {
    pos++;
    delete tmp;
    tmp = pos.ptr();
  }

  auto pair = _get_at_node_with_predicate(idx);

  // If prev == null then we erased all list
  if (pair.first == nullptr)
    m_head = nullptr;
  else
    pair.first->next = nullptr;
}

template <class T>
void list<T>::push_back(const_reference val) {
  if (m_head == nullptr)
    m_head = new Node(val);
  else
    _tail()->next = new Node(val);
}

template <class T>
void list<T>::pop_back() {
  // Nothing to do
  if (m_head == nullptr) return;

  if (m_head->next == nullptr) {
    delete m_head;
    m_head = nullptr;
  } else {
    auto stl = _second_to_last();
    delete stl->next;
    stl->next = nullptr;
  }
}

template <class T>
void list<T>::push_front(const_reference val) {
  Node *newHead = new Node(val), *oldHead = m_head;
  newHead->next = oldHead;
  m_head = newHead;
}

template <class T>
void list<T>::pop_front() {
  // Nothing to do
  if (m_head == nullptr) return;

  Node *head = m_head, *next = m_head->next;
  m_head = next;
  delete head;
}

template <class T>
void list<T>::swap(list &other) {
  list<T> tmp = *this;
  *this = other;
  other = tmp;
}

template <class T>
void list<T>::merge(list &other) {
  sort();
  other.sort();
  for (auto &item : other) push_back(item);
}

template <class T>
void list<T>::splice(const_iterator pos, list &other) {
  size_t idx = 0;
  Node *startPos = _get_at_node(idx);

  while (startPos != pos.ptr()) startPos = _get_at_node(++idx);

  auto it = iterator(startPos);
  for (auto &item : other) insert(it, item);
}

template <class T>
void list<T>::reverse() {
  list<T> reversed;
  size_t listSize = size();
  for (size_t i = 0; i != listSize; i++) {
    reversed.push_back(_tail()->data);
    pop_back();
  }
  std::swap(*this, reversed);
}

template <class T>
void list<T>::unique() {
  if (m_head == nullptr || m_head->next == nullptr) return;

  size_t listSize = size();
  for (size_t i = 0; i != listSize;) {
    auto [prev, curr] = _get_at_node_with_predicate(i);

    if (prev != nullptr && curr != nullptr && prev->data == curr->data) {
      Node *tmp = curr;
      prev->next = curr->next;
      delete tmp;
    } else {
      i++;
    }
  }
}

template <class T>
void list<T>::sort() {
  auto listSize = size();
  for (size_t i = 0; i != listSize; i++)
    for (size_t j = 0; j != listSize; j++)
      if (_get_at_node(i)->data < _get_at_node(j)->data) _swap_nodes(i, j);
}

template <class T>
template <class... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args &&...args) {
  list<T> values = {args...};
  auto it = cbegin();
  size_t n = 0;
  Node *tmp;

  while (it++ != pos) n++;
  values.reverse();

  for (auto val : values) {
    auto [prev, curr] = _get_at_node_with_predicate(n);

    if (prev == nullptr) {
      m_head = new Node(val, curr);
      tmp = m_head;
    } else {
      prev->next = new Node(val, curr);
      tmp = prev->next;
    }
  }

  return iterator(tmp);
}

template <class T>
template <class... Args>
void list<T>::insert_many_back(Args &&...args) {
  list<T> values = {args...};
  for (auto arg : values) push_back(arg);
}

template <class T>
template <class... Args>
void list<T>::insert_many_front(Args &&...args) {
  list<T> values = {args...};
  values.reverse();
  for (auto arg : values) push_front(arg);
}

template <class T>
typename list<T>::Node *list<T>::_tail() {
  if (m_head == nullptr) throw std::logic_error("List is empty");
  Node *tail = m_head;
  while (tail->next != nullptr) tail = tail->next;
  return tail;
}

template <class T>
typename list<T>::Node *list<T>::_second_to_last() {
  Node *prev = nullptr, *curr = m_head;

  while (curr != nullptr && curr->next != nullptr) {
    prev = curr;
    curr = curr->next;
  }

  return prev;
}

template <class T>
size_t list<T>::_count_elements() {
  // The List is empty
  if (m_head == nullptr) return 0;

  size_t listSize = 1;
  Node *tmp = m_head;

  while (tmp->next != nullptr) {
    tmp = tmp->next;
    listSize++;
  }

  return listSize;
}

template <class T>
void list<T>::_copy(const list &other) {
  Node *node = other.m_head;
  while (node != nullptr) {
    push_back(node->data);
    node = node->next;
  }
}

template <class T>
typename list<T>::Node *list<T>::_get_at_node(size_t index) {
  Node *curr = m_head;
  for (size_t i = 0; curr && i != index; i++) {
    curr = curr->next;
  }
  return curr;
}

template <class T>
std::pair<typename list<T>::Node *, typename list<T>::Node *>
list<T>::_get_at_node_with_predicate(size_t index) {
  Node *prev = nullptr, *curr = m_head;
  for (size_t i = 0; curr && i != index; i++) {
    prev = curr;
    curr = curr->next;
  }
  return {prev, curr};
}

template <class T>
void list<T>::_swap_nodes(size_t idx1, size_t idx2) {
  auto [prevX, currX] = _get_at_node_with_predicate(idx1);
  auto [prevY, currY] = _get_at_node_with_predicate(idx2);

  // If x is not head of linked list
  if (prevX != nullptr)
    prevX->next = currY;
  else
    m_head = currY;

  // If y is not head of linked list
  if (prevY != nullptr)
    prevY->next = currX;
  else
    m_head = currX;

  // Swap next pointers
  Node *temp = currY->next;
  currY->next = currX->next;
  currX->next = temp;
}
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_HEADERS_S21_LIST_H
