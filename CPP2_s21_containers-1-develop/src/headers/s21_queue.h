#ifndef CPP2_S21_CONTAINERS_SRC_HEADERS_S21_QUEUE_H
#define CPP2_S21_CONTAINERS_SRC_HEADERS_S21_QUEUE_H

#include "s21_list.h"

namespace s21 {

template <typename T>
class queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;
  /*---------------------------------------------*/
  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q);
  ~queue();
  queue<T> &operator=(queue &&q);
  /*---------------------------------------------*/
  const_reference front();
  const_reference back();
  /*---------------------------------------------*/
  bool empty();
  size_type size();
  /*---------------------------------------------*/
  void push(const_reference value);
  void pop();
  void swap(queue &other);

  template <class... Args>
  void insert_many_back(Args &&...args);

 private:
  list<value_type> list_;
};

template <typename T>
queue<T>::queue() {}

template <typename T>
queue<T>::queue(std::initializer_list<value_type> const &items) {
  list_.clear();
  for (auto i : items) {
    list_.push_back(i);
  }
}

template <typename T>
queue<T>::queue(const queue &q) {
  list_ = q.list_;
}

template <typename T>
queue<T>::queue(queue &&q) {
  operator=(std::move(q));
}

template <typename T>
queue<T>::~queue() {
  list_.clear();
}

template <typename T>
queue<T> &queue<T>::operator=(queue &&q) {
  list_ = std::move(q.list_);
  return *this;
}

template <typename T>
size_t queue<T>::size() {
  return list_.size();
}

template <typename T>
bool queue<T>::empty() {
  return list_.empty();
}

template <typename T>
const T &queue<T>::front() {
  return list_.front();
}

template <typename T>
const T &queue<T>::back() {
  return list_.back();
}

template <typename T>
void queue<T>::push(const T &value) {
  list_.push_back(value);
}

template <typename T>
void queue<T>::pop() {
  list_.pop_front();
}

template <typename T>
void queue<T>::swap(queue &other) {
  list_.swap(other.list_);
}

template <typename T>
template <class... Args>
void queue<T>::insert_many_back(Args &&...args) {
  list_.insert_many_back(args...);
}
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_HEADERS_S21_QUEUE_H