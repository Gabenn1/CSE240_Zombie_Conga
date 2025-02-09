#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Node {
public:
    T data;
    Node *next;
    Node *prev;

    Node();
    Node(T);
    Node(T, Node<T> *, Node<T> *);
};

template <typename T>
class LinkedList {
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    LinkedList();
    ~LinkedList();

    void AddToFront(T);
    void AddToEnd(T);
    void AddAtIndex(T, int);
    void AddBefore(Node<T> *, T);
    void AddAfter(Node<T> *, T);
    T RemoveFromFront();
    T RemoveFromEnd();
    void RemoveAllOf(T);
    void RemoveTheFirst(T);
    bool ElementExists(T);
    Node<T> *Find(T);
    T Retrieve(int index);
    int Length();
    void PrintList();
    void Empty();
};

// Constructor
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList() {
    Empty();
}

// Add to front
template <typename T>
void LinkedList<T>::AddToFront(T data) {
    Node<T> *new_node = new Node<T>(data, head, nullptr);
    if (head != nullptr) {
        head->prev = new_node;
    } else {
        tail = new_node;
    }
    head = new_node;
    size++;
}

// Add to end
template <typename T>
void LinkedList<T>::AddToEnd(T data) {
    Node<T> *new_node = new Node<T>(data, nullptr, tail);
    if (tail != nullptr) {
        tail->next = new_node;
    } else {
        head = new_node;
    }
    tail = new_node;
    size++;
}

// Add at index
template <typename T>
void LinkedList<T>::AddAtIndex(T data, int index) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        AddToFront(data);
    } else if (index == size) {
        AddToEnd(data);
    } else {
        Node<T> *current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node<T> *new_node = new Node<T>(data, current->next, current);
        current->next->prev = new_node;
        current->next = new_node;
        size++;
    }
}

// Add before
template <typename T>
void LinkedList<T>::AddBefore(Node<T> *node, T data) {
    if (node == nullptr) {
        throw std::invalid_argument("Node cannot be null");
    }
    if (node == head) {
        AddToFront(data);
    } else {
        Node<T> *new_node = new Node<T>(data, node, node->prev);
        node->prev->next = new_node;
        node->prev = new_node;
        size++;
    }
}

// Add after
template <typename T>
void LinkedList<T>::AddAfter(Node<T> *node, T data) {
    if (node == nullptr) {
        throw std::invalid_argument("Node cannot be null");
    }
    if (node == tail) {
        AddToEnd(data);
    } else {
        Node<T> *new_node = new Node<T>(data, node->next, node);
        node->next->prev = new_node;
        node->next = new_node;
        size++;
    }
}

// Remove from front
template <typename T>
T LinkedList<T>::RemoveFromFront() {
    if (size == 0) {
        throw std::out_of_range("Cannot remove from front, list is empty");
    }
    Node<T> *temp = head;
    T data = head->data;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
    size--;
    return data;
}

// Remove from end
template <typename T>
T LinkedList<T>::RemoveFromEnd() {
    if (size == 0) {
        throw std::out_of_range("Cannot remove from end, list is empty");
    }
    Node<T> *temp = tail;
    T data = tail->data;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
    size--;
    return data;
}

// Remove all matching elements
template <typename T>
void LinkedList<T>::RemoveAllOf(T data) {
    Node<T> *current = head;
    while (current != nullptr) {
        Node<T> *next = current->next;
        if (current->data == data) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current;
            size--;
        }
        current = next;
    }
}

// Remove the first matching element
template <typename T>
void LinkedList<T>::RemoveTheFirst(T data) {
    Node<T> *current = head;
    while (current != nullptr) {
        if (current->data == data) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current;
            size--;
            return;
        }
        current = current->next;
    }
}

// Check if element exists
template <typename T>
bool LinkedList<T>::ElementExists(T data) {
    Node<T> *current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Find a node with matching data
template <typename T>
Node<T> *LinkedList<T>::Find(T data) {
    Node<T> *current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Retrieve
template <typename T>
T LinkedList<T>::Retrieve(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    Node<T> *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

// Length
template <typename T>
int LinkedList<T>::Length() {
    return size;
}

// Print list
template <typename T>
void LinkedList<T>::PrintList() {
    Node<T> *current = head;
    while (current != nullptr) {
        std::cout << "[" << current->data << "] ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Empty
template <typename T>
void LinkedList<T>::Empty() {
    while (head != nullptr) {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

#endif
