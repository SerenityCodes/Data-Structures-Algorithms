#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <type_traits>

template <typename T>
class DynamicArray {
	private:
        int _size;
		int _capacity;
        T* _arr;
	public:
		DynamicArray();
		DynamicArray(T* arr, int size_, int capacity_);
		DynamicArray(const DynamicArray& copy);
        ~DynamicArray();

		[[nodiscard]] int size() const;
		[[nodiscard]] int capacity() const;
		
		void add(const T& elem);
		void remove(const T& elem);
		void removeAt(int index);

		T get(int index) const;
        T operator[](int index) const;
        T front() const;
        T back() const;

        [[nodiscard]] bool empty() const;
};

template <typename T>
DynamicArray<T>::DynamicArray() : _size(0), _capacity(2), _arr(new T[_capacity]) { }

template <typename T>
DynamicArray<T>::DynamicArray(T *arr, int size_, int capacity_) {
	_arr = arr;
	_size = size_;
	_capacity = capacity_;
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& copy) : _size(copy.size()), _capacity(copy.capacity()), _arr(new T[copy.capacity()]) {
    for (int i = 0; i < _size; i++) {
        _arr[i] = copy[i];
    }
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] _arr;
}

template <typename T>
int DynamicArray<T>::size() const {
	return _size;
}

template <typename T>
int DynamicArray<T>::capacity() const {
	return _capacity;
}

template <typename T>
T DynamicArray<T>::get(int index) const {
    if (index < 0 || index > _size) {
        throw std::logic_error("Index out of bounds. Please try again");
    }
    return _arr[index];
}

template<typename T>
T DynamicArray<T>::operator[](int index) const {
    return _arr[index];
}

template<typename T>
void DynamicArray<T>::add(const T& elem) {
    if (_size >= _capacity) {
        _capacity *= 2;
        T* copyArr = new T[_capacity];
        for (int i = 0; i < _size; i++) {
            copyArr[i] = _arr[i];
        }
        delete[] _arr;
        _arr = copyArr;
    }
    _arr[_size] = elem;
    ++_size;
}

template <typename T>
void DynamicArray<T>::remove(const T& elem) {
    T* copyArr = new T[_capacity];
    for (int i = 0, j = 0; i < _size; i++) {
        if (_arr[i] == elem) {
            copyArr[j] = _arr[i];
        } else {
            copyArr[j] = _arr[i];
            j++;
        }
    }
    --_size;
    delete[] _arr;
    _arr = copyArr;
}

template <typename T>
T DynamicArray<T>::front() const {
    return operator[](0);
}

template <typename T>
T DynamicArray<T>::back() const {
    return operator[](_size - 1);
}

template <typename T>
bool DynamicArray<T>::empty() const {
    return _size == 0;
}

template <typename T>
void DynamicArray<T>::removeAt(int index) {
    if (index < 0 || index > _size) {
        throw std::logic_error("Index out of bounds. Please try again");
    }

    for (int i = 0; i < _size; i++) {
        if (i == index) remove(_arr[i]);
    }
}


#endif
