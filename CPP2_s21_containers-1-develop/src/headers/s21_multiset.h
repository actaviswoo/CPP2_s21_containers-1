#ifndef CPP2_S21_CONTAINERS_SRC_HEADERS_S21_MULTISET_H
#define CPP2_S21_CONTAINERS_SRC_HEADERS_S21_MULTISET_H

#include "s21_set.h"

namespace s21 {
template <typename T>
class multiset final : public s21::set<T> {
 public:
  using key_type = T;
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = typename set<value_type>::iterator;
  using const_iterator = typename set<value_type>::const_iterator;
  using size_type = size_t;

  multiset() {}
  multiset(std::initializer_list<value_type> const& items);
  multiset(const multiset& ms);
  multiset(multiset&& ms) noexcept;
  ~multiset();
  multiset& operator=(multiset&& ms) noexcept;

  iterator insert(const value_type& value);
  void merge(multiset& other);

  size_type count(const key_type& key) const;
  std::pair<iterator, iterator> equal_range(const key_type& key) const;
  iterator lower_bound(const key_type& key) const;
  iterator upper_bound(const key_type& key) const;

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> emplace(Args&&... args);

 private:
  multiset& operator=(multiset& ms) {}
};

template <typename T>
multiset<T>::multiset(std::initializer_list<value_type> const& items) {
  for (auto& item : items) insert(item);
}

template <typename T>
multiset<T>::multiset(const multiset& ms) : set<T>::set() {
  iterator last = ms.end();
  for (iterator it = ms.begin(); it != last; ++it) insert(*it);
}

template <typename T>
multiset<T>::multiset(multiset&& ms) noexcept {
  set<T>::swap(ms);
}

template <typename T>
multiset<T>::~multiset() {
  set<T>::clear();
}

template <typename T>
typename multiset<T>::multiset& multiset<T>::operator=(multiset&& ms) noexcept {
  if (this == &ms) return *this;

  set<T>::clear();
  set<T>::swap(ms);

  return *this;
}

template <typename T>
typename multiset<T>::iterator multiset<T>::insert(const value_type& value) {
  return set<T>::insert_node(value).first;
}

template <typename T>
void multiset<T>::merge(multiset& other) {
  if (this != &other) {
    iterator it = other.set<T>::begin();
    iterator temp;
    while (it != other.set<T>::end()) {
      insert(*it);
      temp = it;
      ++it;
      other.set<T>::erase(temp);
    }
  }
}

template <typename T>
typename multiset<T>::size_type multiset<T>::count(const key_type& key) const {
  iterator it = set<T>::begin();
  size_type c = 0;
  while (it != set<T>::end()) {
    if (*it == key) ++c;
    ++it;
  }

  return c;
}

template <typename T>
std::pair<typename multiset<T>::iterator, typename multiset<T>::iterator>
multiset<T>::equal_range(const key_type& key) const {
  return std::pair<iterator, iterator>(lower_bound(key), upper_bound(key));
}

template <typename T>
typename multiset<T>::iterator multiset<T>::lower_bound(
    const key_type& key) const {
  iterator it = set<T>::begin();
  while (it != set<T>::end() && *it < key) ++it;

  return it;
}

template <typename T>
typename multiset<T>::iterator multiset<T>::upper_bound(
    const key_type& key) const {
  iterator it = set<T>::begin();
  while (it != set<T>::end() && *it <= key) ++it;

  return it;
}

template <typename T>
template <typename... Args>
std::vector<std::pair<typename multiset<T>::iterator, bool>>
multiset<T>::emplace(Args&&... args) {
  std::vector<std::pair<iterator, bool>> v;
  v.push_back(std::pair<iterator, bool>(
      insert(key_type(std::forward<Args>(args)...)), true));
  return v;
}
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_HEADERS_S21_MULTISET_H
