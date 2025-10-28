#include "customvector.h"

template <typename T>
CustomVector<T>::CustomVector(int size) : size(size), capacity(size), data(std::make_unique<T[]>(size)) {};

template <typename T>
T& CustomVector<T>::operator[](int index) {
  return data[index];
}

template <typename T>
const T& CustomVector<T>::operator[](int index) const {
  return data[index];
}

template <typename T>
void CustomVector<T>::push_back(T& value) {
  if (size >= capacity) {
    int new_capacity = 2 * capacity;
    std::unique_ptr<T[]> new_data = std::make_unique<T[]>(new_capacity);
    std::copy(data.get(), data.get() + size, new_data.get());
    capacity = new_capacity;
    data = std::move(new_data);
  }
  data[size] = value;
  size++;
}

template class CustomVector<int>;
template class CustomVector<double>;

