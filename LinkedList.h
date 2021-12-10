#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>

template <typename T>
class LinkedList {
private:
    struct Node {
        Node* prev;
        Node* next;
        T data;
        Node(Node* prev_node, Node* next_node, T data_to_store) : prev(prev_node), next(next_node), data(data_to_store) { }
        explicit Node(T data_to_store) : Node(nullptr, nullptr, data_to_store) { }
    };
    int _size;
    Node* head;
    Node* tail;
public:
    LinkedList();
    ~LinkedList();

    void clear();
    void add(T elem);
    void addLast(T elem);
    void addFirst(T elem);
    void addAt(T elem, int index);

    T removeFirst();
    T removeLast();
    T remove(Node* node);
    T remove(T elem);

    const T& peekFirst() const;
    const T& peekLast() const;
    int indexOf(T elem) const;

    [[nodiscard]] int size() const;
    [[nodiscard]] bool isEmpty() const;

    friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
        for (Node* trav = list.head; trav != nullptr; trav = trav->next) {
            os << trav->data << ' ';
        }
        return os;
    }
};

template <typename T>
LinkedList<T>::LinkedList() : _size(0), head(nullptr), tail(nullptr) { }

template <typename T>
LinkedList<T>::~LinkedList<T>() {
    clear();
}

template <typename T>
void LinkedList<T>::clear() {
    for (Node* trav = head; trav != nullptr; ) {
        Node* next = trav->next;
        delete trav;
        trav = next;
    }
    _size = 0;
}

template <typename T>
void LinkedList<T>::add(T elem) {
    addLast(elem);
}

template <typename T>
void LinkedList<T>::addFirst(T elem) {
    if (head == nullptr) {
        head = new Node(nullptr, nullptr, elem);
    } else {
        Node* temp = new Node(nullptr, head, elem);
        head->prev = temp;
        head = temp;
    }
    ++_size;
}

template <typename T>
void LinkedList<T>::addLast(T elem) {
    Node* to_add = new Node(elem);
    if (tail == nullptr) {
        if (_size == 0) {
            delete to_add;
            addFirst(elem);
        }
        else {
            tail = to_add;
            head->next = tail;
            tail->prev = head;
            ++_size;
        }
    } else {
        tail->next = to_add;
        to_add->prev = tail;
        tail = to_add;
        ++_size;
    }
}

template <typename T>
void LinkedList<T>::addAt(T elem, int index) {
    if (index < 0 || index > _size) {
        throw std::runtime_error("Index out of range. Largest index is " + std::to_string(_size) + '\n');
    }

    if (index == 0) {
        addFirst(elem);
        return;
    }

    if (index == _size) {
        addLast(elem);
        return;
    }

    Node* trav = head;
    for (int i = 0; i < index; i++) {
        trav = trav->next;
    }
    Node* temp = new Node(elem);
    temp->prev = trav->prev;
    trav->prev->next = temp;
    temp->next = trav;
    trav->prev = temp;
}

template <typename T>
T LinkedList<T>::removeFirst() {
    if (isEmpty()) {
        throw std::runtime_error("Cannot remove the first element from an empty list.");
    }
    Node* temp = head;
    T data = temp->data;
    head = head->next;
    --_size;
    delete temp;
    if (isEmpty()) {
        delete tail;
        tail = nullptr;
    }
    return data;
}

template <typename T>
T LinkedList<T>::removeLast() {
    if (isEmpty()) {
        throw std::runtime_error("Cannot remove the last element from an empty list");
    }
    Node* temp = tail;
    T data = temp->data;
    if (_size == 1) {
        return removeFirst();
    }

    tail->next = nullptr;
    --_size;

    delete temp;
    return data;
}

template <typename T>
T LinkedList<T>::remove(Node* node) {
    T data = node->data;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    --_size;
    return data;
}

template <typename T>
T LinkedList<T>::remove(T elem) {
    if (head->data == elem) return removeFirst();
    if (tail->data == elem) return removeLast();
    for (Node* trav = head; trav != nullptr; trav = trav->next) {
        if (trav->data == elem) return remove(trav);
    }
    return T();
}

template <typename T>
const T &LinkedList<T>::peekFirst() const {
    return head->data;
}

template <typename T>
const T &LinkedList<T>::peekLast() const {
    return tail->data;
}

template <typename T>
int LinkedList<T>::indexOf(T elem) const {
    bool foundElement = false;
    int index = 0;
    for (Node* trav = head; trav != nullptr; trav = trav->next, ++index) {
        if (trav->data == elem) {
            foundElement = true;
            break;
        }
    }
    return foundElement ? index : -1;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return _size == 0;
}

template <typename T>
int LinkedList<T>::size() const {
    return _size;
}

#endif