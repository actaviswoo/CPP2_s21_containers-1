#ifndef CPP2_S21_CONTAINERS_SRC_HEADERS_S21_STACK_H
#define CPP2_S21_CONTAINERS_SRC_HEADERS_S21_STACK_H
#include <iostream>

#include "s21_list.h"

namespace s21 {

template <typename T>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;
  /*---------------------------------------------*/
  stack() noexcept;
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);
  stack(stack &&s);
  ~stack() noexcept;
  stack<T> &operator=(stack &&s);
  stack<T> &operator=(const stack &s);
  /*---------------------------------------------*/
  const_reference top();
  /*---------------------------------------------*/
  bool empty() noexcept;
  size_type size() noexcept;
  /*---------------------------------------------*/
  void push(const_reference value);
  void pop();
  void swap(stack &other);
  template <class... Args>
  void insert_many_front(Args &&...args);

 private:
  list<value_type> list_;
};

template <typename T>
stack<T>::stack() noexcept {}

template <typename T>
stack<T>::stack(std::initializer_list<value_type> const &items) {
  list_.clear();
  for (const auto value : items) {
    list_.push_front(value);
  }
}

template <typename T>
stack<T>::stack(const stack &s) {
  operator=(s);
}

template <typename T>
stack<T>::stack(stack &&s) {
  operator=(std::move(s));
}

template <typename T>
stack<T>::~stack() noexcept {
  list_.clear();
}

template <typename T>
stack<T> &stack<T>::operator=(stack &&s) {
  list_.clear();
  list_ = std::move(s.list_);
  return *this;
}

template <typename T>
stack<T> &stack<T>::operator=(const stack &s) {
  list_.clear();
  list_ = s.list_;
  return *this;
}

template <typename T>
bool stack<T>::empty() noexcept {
  return list_.empty();
}

template <typename T>
size_t stack<T>::size() noexcept {
  return list_.size();
}

template <typename T>
void stack<T>::push(const_reference value) {
  list_.push_front(value);
}

template <typename T>
void stack<T>::pop() {
  list_.pop_front();
}

template <typename T>
void stack<T>::swap(stack &other) {
  return list_.swap(other.list_);
}

template <typename T>
const T &stack<T>::top() {
  return list_.front();
}

template <typename T>
template <class... Args>
void stack<T>::insert_many_front(Args &&...args) {
  list_.insert_many_front(args...);
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_HEADERS_S21_STACK_H