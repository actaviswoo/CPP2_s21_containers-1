#ifndef CPP2_S21_CONTAINERS_SRC_HEADERS_S21_MAP_H
#define CPP2_S21_CONTAINERS_SRC_HEADERS_S21_MAP_H

#include "s21_set.h"

namespace s21 {
template <typename Key, typename T>
class map final : public s21::set<std::pair<Key, T>> {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<Key, T>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = typename set<value_type>::iterator;
  using const_iterator = typename set<value_type>::const_iterator;
  using size_type = size_t;

  map() {}
  map(std::initializer_list<value_type> const& items);
  map(const map& m);
  map(map&& m) noexcept;
  ~map();
  map& operator=(map&& m) noexcept;

  T& at(const Key& key);
  T& operator[](const Key& key);

  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(const Key& key, const T& obj);
  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
  void merge(map& other);

  bool contains(const Key& key) const;

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> emplace(Args&&... args);

 private:
  iterator find(const Key& key) const;
};

template <typename Key, typename T>
map<Key, T>::map(std::initializer_list<value_type> const& items) {
  for (auto& item : items) insert(item);
}

template <typename Key, typename T>
map<Key, T>::map(const map& m) : set<std::pair<Key, T>>::set() {
  iterator last = m.end();
  for (iterator it = m.begin(); it != last; ++it) insert(*it);
}

template <typename Key, typename T>
map<Key, T>::map(map&& m) noexcept {
  set<value_type>::swap(m);
}

template <typename Key, typename T>
map<Key, T>::~map() {
  set<value_type>::clear();
}

template <typename Key, typename T>
typename map<Key, T>::map& map<Key, T>::operator=(map&& m) noexcept {
  if (this == &m) return *this;

  set<value_type>::clear();
  set<value_type>::swap(m);

  return *this;
}

template <typename Key, typename T>
T& map<Key, T>::at(const Key& key) {
  iterator it = find(key);
  if (it == set<value_type>::end()) throw std::invalid_argument("Wrong key");

  return (*set<value_type>::get_address_val(it)).second;
}

template <typename Key, typename T>
T& map<Key, T>::operator[](const Key& key) {
  std::pair<iterator, bool> p = insert(key, {});

  return (*set<value_type>::get_address_val(p.first)).second;
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const value_type& value) {
  iterator it = find(value.first);
  if (it == set<value_type>::end()) return set<value_type>::insert(value);

  return std::pair<iterator, bool>(it, false);
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const Key& key, const T& obj) {
  return insert({key, obj});
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const Key& key, const T& obj) {
  iterator it = find(key);
  if (it == set<value_type>::end()) return insert(key, obj);

  (*set<value_type>::get_address_val(it)).second = obj;
  return std::pair<iterator, bool>(it, false);
}

template <typename Key, typename T>
void map<Key, T>::merge(map& other) {
  if (this != &other) {
    iterator it = other.set<value_type>::begin();
    iterator temp;
    while (it != other.set<value_type>::end()) {
      if (!contains(it->first)) {
        insert(*it);
        temp = it;
        ++it;
        other.set<value_type>::erase(temp);
      } else {
        ++it;
      }
    }
  }
}

template <typename Key, typename T>
bool map<Key, T>::contains(const Key& key) const {
  if (find(key) != set<value_type>::end()) return true;

  return false;
}

template <typename Key, typename T>
template <typename... Args>
std::vector<std::pair<typename map<Key, T>::iterator, bool>>
map<Key, T>::emplace(Args&&... args) {
  std::vector<std::pair<iterator, bool>> v;
  v.push_back(insert(std::forward<Args>(args)...));
  return v;
}

template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::find(const Key& key) const {
  iterator it = set<value_type>::begin();
  while (it != set<value_type>::end()) {
    if (it->first == key) return it;
    ++it;
  }

  return it;
}
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_HEADERS_S21_MAP_H
