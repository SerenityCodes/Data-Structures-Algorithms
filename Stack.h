#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"
#include <iostream>

template <typename T>
class Stack {
private:
    LinkedList<T> list;
public:
    Stack() = default;
    explicit Stack(T elem);

    ~Stack() = default;

    void push(T elem);
    T pop();

    [[nodiscard]] int size() const;
    [[nodiscard]] bool isEmpty() const;

    friend std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
        return os << stack.list;
    }
};

template <typename T>
Stack<T>::Stack(T elem) {
    push(elem);
}

template <typename T>
void Stack<T>::push(T elem) {
    list.addFirst(elem);
}

template <typename T>
T Stack<T>::pop() {
    return list.removeFirst();
}

template <typename T>
int Stack<T>::size() const {
    return list.size();
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return list.isEmpty();
}

#endif //STACK_H
