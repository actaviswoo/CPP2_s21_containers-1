#ifndef CPP2_S21_CONTAINERS_SRC_HEADERS_S21_ARRAY_H
#define CPP2_S21_CONTAINERS_SRC_HEADERS_S21_ARRAY_H

#include <algorithm>
#include <iterator>

namespace s21 {
template <typename T, size_t N>
class array {
 public:
  //-----------------------------------------------------------------
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;
  //-----------------------------------------------------------------
  array() = default;
  array(std::initializer_list<value_type> const &elements);
  array(const array &elements);
  array(array &&elements);
  ~array();
  //-----------------------------------------------------------------
  array<T, N> &operator=(const array &elements);
  array<T, N> &operator=(array &&elements);
  //-----------------------------------------------------------------
  constexpr reference at(size_type pos);
  constexpr const_reference at(size_type pos) const;
  constexpr reference operator[](size_type pos) noexcept;
  constexpr const_reference operator[](size_type pos) const noexcept;
  constexpr reference front() noexcept;
  constexpr const_reference front() const noexcept;
  constexpr reference back() noexcept;
  constexpr const_reference back() const noexcept;
  constexpr iterator data() noexcept;
  constexpr const_iterator data() const noexcept;
  //-----------------------------------------------------------------
  constexpr iterator begin() noexcept;
  constexpr const_iterator cbegin() const noexcept;
  constexpr iterator end() noexcept;
  constexpr const_iterator cend() const noexcept;
  //-----------------------------------------------------------------
  constexpr bool empty() const noexcept;
  constexpr size_type size() const noexcept;
  constexpr size_type max_size() const noexcept;
  //-----------------------------------------------------------------
  void swap(array &elements);
  void fill(const_reference value);

 private:
  value_type *array_ = new value_type[N];
};
//-----------------------------------------------------------------

template <typename T, size_t N>
array<T, N>::array(std::initializer_list<value_type> const &elements) {
  if (elements.size() > N) {
    throw std::runtime_error(
        "array<T, N>::array(std::initializer_list<value_type> const &elements) "
        ":: size is not the same");
  }
  std::copy(elements.begin(), elements.end(), begin());
}

template <typename T, size_t N>
array<T, N>::array(const array &elements) {
  std::copy(elements.cbegin(), elements.cend(), begin());
}

template <typename T, size_t N>
array<T, N>::array(array &&elements) {
  std::move(elements.begin(), elements.end(), begin());
}

template <typename T, size_t N>
array<T, N>::~array() {
  delete[] array_;
}

//-----------------------------------------------------------------

template <typename T, size_t N>
array<T, N> &array<T, N>::operator=(const array &elements) {
  if (this != &elements) {
    std::copy(elements.begin(), elements.end(), begin());
  }
  return *this;
}

template <typename T, size_t N>
array<T, N> &array<T, N>::operator=(array &&elements) {
  if (this != &elements) {
    std::move(elements.begin(), elements.end(), begin());
  }
  return *this;
}

//-----------------------------------------------------------------

template <typename T, size_t N>
constexpr typename array<T, N>::reference array<T, N>::at(size_type pos) {
  if (pos >= N) {
    throw std::out_of_range(
        "constexpr typename array<T, N>::reference array<T, N>::at(size_type "
        "pos) :: index out of range");
  }
  return array_[pos];
}

template <typename T, size_t N>
constexpr typename array<T, N>::const_reference array<T, N>::at(
    size_type pos) const {
  if (pos >= N) {
    throw std::out_of_range(
        "constexpr typename array<T, N>::reference array<T, N>::at(size_type "
        "pos) :: index out of range");
  }
  return array_[pos];
}

template <typename T, size_t N>
constexpr typename array<T, N>::reference array<T, N>::operator[](
    size_type pos) noexcept {
  return array_[pos];
}

template <typename T, size_t N>
constexpr typename array<T, N>::const_reference array<T, N>::operator[](
    size_type pos) const noexcept {
  return array_[pos];
}

template <typename T, size_t N>
constexpr typename array<T, N>::reference array<T, N>::front() noexcept {
  return array_[0];
}

template <typename T, size_t N>
constexpr typename array<T, N>::const_reference array<T, N>::front()
    const noexcept {
  return array_[0];
}

template <typename T, size_t N>
constexpr typename array<T, N>::reference array<T, N>::back() noexcept {
  return array_[N - 1];
}

template <typename T, size_t N>
constexpr typename array<T, N>::const_reference array<T, N>::back()
    const noexcept {
  return array_[N - 1];
}

template <typename T, size_t N>
constexpr typename array<T, N>::iterator array<T, N>::data() noexcept {
  return array_;
}

template <typename T, size_t N>
constexpr typename array<T, N>::const_iterator array<T, N>::data()
    const noexcept {
  return array_;
}

//-----------------------------------------------------------------

template <typename T, size_t N>
constexpr typename array<T, N>::iterator array<T, N>::begin() noexcept {
  return array_;
}

template <typename T, size_t N>
constexpr typename array<T, N>::const_iterator array<T, N>::cbegin()
    const noexcept {
  return array_;
}

template <typename T, size_t N>
constexpr typename array<T, N>::iterator array<T, N>::end() noexcept {
  return array_ + size();
}

template <typename T, size_t N>
constexpr typename array<T, N>::const_iterator array<T, N>::cend()
    const noexcept {
  return array_ + size();
}

//-----------------------------------------------------------------

template <typename T, size_t N>
constexpr bool array<T, N>::empty() const noexcept {
  return size() == 0;
}

template <typename T, size_t N>
constexpr typename array<T, N>::size_type array<T, N>::size() const noexcept {
  return N;
}

template <typename T, size_t N>
constexpr typename array<T, N>::size_type array<T, N>::max_size()
    const noexcept {
  return size();
}

//-----------------------------------------------------------------

template <typename T, size_t N>
void array<T, N>::swap(array &elements) {
  std::swap_ranges(elements.begin(), elements.end(), begin());
}

template <typename T, size_t N>
void array<T, N>::fill(const_reference value) {
  std::fill(begin(), end(), value);
}

//-----------------------------------------------------------------

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_HEADERS_S21_ARRAY_H