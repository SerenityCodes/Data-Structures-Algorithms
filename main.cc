//
// Created by uber-driver on 11/8/21.
//
#include "DynamicArray.h"
#include <iostream>

using namespace std;

int main() {
    DynamicArray<int> array;
    for (int i = 0; i < 1000; i++) {
        array.add((i+1) * 10);
    }
    array.remove(900);
    array.remove(300);
    cout << "Capacity: " << array.capacity() << '\n';
    cout << "Size: " << array.size() << '\n';
    cout << array;
}
