//
// Created by uber-driver on 11/8/21.
//
#include "DynamicArray.h"
#include "Stack.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
    Stack<int> stack;
    for (int i = 0; i < 100; i++) {
        stack.push(i);
    }
    for (int i = 0; i < 5; i++) {
        cout << "Pop: " << stack.pop() << '\n';
    }
}
