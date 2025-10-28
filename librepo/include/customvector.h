#ifndef customvector
#define customvector

#include <memory>

template <typename T>
class CustomVector {

  public:
    explicit CustomVector(int size);
    T& operator[](int index);
    const T& operator[](int index) const;
    void push_back(T& value);
    int get_size();

  private:
    std::unique_ptr<T[]> data;
    int size; // Number of actual elements of data
    int capacity; // Number of elements data can hold

};

#endif
