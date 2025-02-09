#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "termcolor.hpp"
#include <time.h>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <iostream>
#include <string>
#include "zombie_clark.h"

using namespace std;

template <typename T>
class Node
{
public:
  T data;
  // Pointer to next node
  Node *next;
  // Pointer to prev node
  Node *prev;
  // Constructor
  Node();
  // Constructor (new_data)
  Node(T);
  // Constructor (new_data, next, prev)
  Node(T, Node<T> *, Node<T> *);

  // Gets node data
  T getData();

  // Sets node data
  void setData(T);

  // Gets Next
  Node<T> *getNext();

  // Sets Next
  void setNext(Node<T> *);

  // Gets Prev
  Node<T> *getPrevious();

  // Sets Prev
  void setPrevious(Node<T> *);
};
template <typename T>
Node<T>::Node() : data(), next(nullptr), prev(nullptr) {}

// Constructor (new_data)
template <typename T>
Node<T>::Node(T new_data) : data(new_data) {}
// Constructor (new_data, next, prev)
template <typename T>
Node<T>::Node(T new_data, Node<T> *new_next, Node<T> *new_prev) : data(new_data), next(new_next), prev(new_prev) {}

// Gets node data
template <typename T>
T Node<T>::getData()
{
  return data;
}
// Sets node data
template <typename T>
void Node<T>::setData(T new_data)
{
  data = new_data;
}

// Gets Next
template <typename T>
Node<T> *Node<T>::getNext()
{
  return next;
}

// Sets Next
template <typename T>
void Node<T>::setNext(Node *new_node)
{
  next = new_node;
}
// Gets Prev
template <typename T>
Node<T> *Node<T>::getPrevious()
{
  return prev;
}

// Sets Prev
template <typename T>
void Node<T>::setPrevious(Node *new_node)
{
  prev = new_node;
}

template <typename T>
class LinkedList
{
private:
  Node<T> *head;
  Node<T> *tail;
  int size = 0;

public:
  // Header Methods:
  LinkedList();
  ~LinkedList();
  void AddToFront(T);
  void AddToEnd(T);
  void AddAtIndex(T, int);
  void AddBefore(Node<T> *, T);
  void AddAfter(Node<T> *, T);
  T RemoveFromFront();
  T RemoveFromEnd();
  void RemoveTheFirst(T);
  void RemoveAllOf(T);
  T RemoveBefore(Node<T> *);
  T RemoveAfter(Node<T> *);
  bool ElementExists(T);
  Node<T> *Find(T);
  int IndexOf(T);
  T RetrieveFront();
  T RetrieveEnd();
  T Retrieve(int);
  void PrintList();
  void PrintColorList();
  void Empty();
  int Length();
  int *CountList();
};

// Constructor
template <typename T>
LinkedList<T>::LinkedList()
{
  head = nullptr;
  tail = nullptr;
  size = 0;
}

// Destructor, runs empty
template <typename T>
LinkedList<T>::~LinkedList()
{
  Empty();
}

// How many elements are in the list
template <typename T>
int LinkedList<T>::Length()
{
  return size;
}

// Loop through each node and print the contents of the Node
template <typename T>
void LinkedList<T>::PrintList()
{
  // Create traversing node*
  Node<T> *current = head;
  // Traverse the list, print [current->data]
  while (current != nullptr)
  {
    cout << "[" << current->data << "]";
    cout << " ";
    // Go to next node
    current = current->next;
  }
}
template <typename T>
int *LinkedList<T>::CountList()
{
    Node<T> *current = head;
    int teamRed = 0;
    int teamYellow = 0;
    int teamGreen = 0;
    int teamBlue = 0;
    int teamCyan = 0;
    int teamMagenta = 0;

    // Traverse the linked list
    while (current != nullptr)
    {
        T data = current->data;
        if (data.getType() == 'R')
        {
            teamRed++;
        }
        else if (data.getType() == 'Y')
        {
            teamYellow++;
        }
        else if (data.getType() == 'B')
        {
            teamBlue++;
        }
        else if (data.getType() == 'G')
        {
            teamGreen++;
        }
        else if (data.getType() == 'C')
        {
            teamCyan++;
        }
        else if (data.getType() == 'M')
        {
            teamMagenta++;
        }
        current = current->next;
    }

    // Allocate memory on the heap
    int *arr = new int[6];
    arr[0] = teamRed;
}

// Loop through each node and print the contents of the Node, but in Color!
template <typename T>
void LinkedList<T>::PrintColorList()
{
  // Create traversing node*
  Node<T> *current = head;
  T data;
  // Traverse the list
  while (current != nullptr)
  {
    data = current->data;
    // Compare data, color matching data to their respective color
    if (data.getType() == 'R')
    {
      cout << termcolor::red << "[R]" << termcolor::reset;
    }
    if (data.getType() == 'Y')
    {
      cout << termcolor::yellow << "[Y]" << termcolor::reset;
    }
    if (data.getType() == 'B')
    {
      cout << termcolor::blue << "[B]" << termcolor::reset;
    }
    if (data.getType() == 'G')
    {
      cout << termcolor::green << "[G]" << termcolor::reset;
    }
    if (data.getType() == 'C')
    {
      cout << termcolor::cyan << "[C]" << termcolor::reset;
    }
    if (data.getType() == 'M')
    {
      cout << termcolor::magenta << "[M]" << termcolor::reset;
    }
    if (current->next != nullptr)
    {
      cout << "=";
    }
    current = current->next;
  }
}

// Create a node containing T data and add it to the end of the list
template <typename T>
void LinkedList<T>::AddToEnd(T data)
{
  // Create new node, add the data to it
  Node<T> *new_node = new Node<T>();
  new_node->data = data;
  // Adjust end pointer
  new_node->next = nullptr;
  // If new node is the first item, adjust head and tail
  if (size == 0)
  {
    head = new_node;
    tail = new_node;
    new_node->prev = nullptr;
  }
  // Point tail to new node, new node prev to the tail, make new node the tail
  else
  {
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
  }
  // Increment size
  size++;
}

// create a node containing T data and add it to the front of the list
template <typename T>
void LinkedList<T>::AddToFront(T data)
{
  Node<T> *new_node = new Node<T>();
  new_node->data = data;
  new_node->prev = nullptr;
  // If list is empty, make the new node the head and tail
  if (head == nullptr)
  {
    head = new_node;
    tail = new_node;
    new_node->next = nullptr;
  }
  // Point new node to head, head prev to new node, make new node the head
  else
  {
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
  }
  // Increment size
  size++;
}

// create a node containing T data and add it to the list at index. The new node containing the data will be the #index node in the list.
// Throws std::out_of_range exception if index is less than zero or greater than the size of the list
template <typename T>
void LinkedList<T>::AddAtIndex(T data, int index)
{
  // If the index is less than 0 throw exception
  if (index < 0)
  {
    throw std::out_of_range("Index is less than zero");
  }
  // If index is 0, add data to the front
  if (index == 0)
  {
    AddToFront(data);
  }
  else
  {
    // Create new node, fill with data
    Node<T> *new_node = new Node<T>(data);
    Node<T> *node = head;
    int current = 0;

    // Traversing to given index
    while (node != nullptr && current < index - 1)
    {
      node = node->next;
      current++;
    }
    // If index we get to is a nullptr, throw exception
    if (node == nullptr)
    {
      throw std::out_of_range("Index is out of range");
    }
    // place new node between traversing node, and node->next
    new_node->prev = node;
    new_node->next = node->next;
    // Update the node after traversing node to point to new node
    if (node->next != nullptr)
    {
      node->next->prev = new_node;
    }
    node->next = new_node;
    // Increment size
    size++;
  }
}

// Returns an index of the item in the list (zero-based), returns -1 if the item is not in the list.
template <typename T>
int LinkedList<T>::IndexOf(T data)
{
  int index = 0;
  Node<T> *current = head;
  // Traversing list until data is found
  while (current != nullptr)
  {
    // If the data is found, return it
    if (current->data == data)
    {
      return index;
    }
    // Incrementing index, moving to next node
    index++;
    current = current->next;
  }
  // If it is not found, return -1
  return -1;
}

// create a node containing T data and add it before a particular node
template <typename T>
void LinkedList<T>::AddBefore(Node<T> *node, T data)
{
  // If passed node is a nullptr, throw exception
  if (node == nullptr)
  {
    throw std::out_of_range("Input not open");
  }
  // If the node->prev is nullptr, we are at the front of the list, add node to front
  if (node->prev == nullptr)
  {
    AddToFront(data);
  }
  else
  {
    // Create new node, fill with data
    Node<T> *new_node = new Node<T>();
    new_node->data = data;
    // Adjust pointers
    new_node->next = node;
    new_node->prev = node->prev;
    node->prev->next = new_node;
    node->prev = new_node;
    // Increment size
    size++;
  }
}

// create a node containing T data and add it after a particular node
template <typename T>
void LinkedList<T>::AddAfter(Node<T> *node, T data)
{
  // If passed node is a nullptr, throw exception
  if (node == nullptr)
  {
    throw std::out_of_range("Input not open");
  }
  // If the node->next is nullptr, we are at the end of the list, add node to end
  if (node->next == nullptr)
  {
    AddToEnd(data);
  }
  else
  {
    // Create new node, fill with data
    Node<T> *new_node = new Node<T>();
    new_node->data = data;
    // Adjust pointers
    new_node->prev = node;
    new_node->next = node->next;
    node->next->prev = new_node;
    node->next = new_node;
    // Increment size
    size++;
  }
}

// Delete first item and return its contents
template <typename T>
T LinkedList<T>::RemoveFromFront()
{
  // If there no head, list is empty, throw exception
  if (head == nullptr)
  {
    throw std::out_of_range("List Empty");
  }
  else
  {
    // Point temp to head, get data from head
    Node<T> *temp = head;
    T removedData = temp->data;
    // Move head to the next node over
    head = head->next;
    // Adjust new head prev
    if (head != nullptr)
    {
      head->prev = nullptr;
    }
    // Decrease size
    size--;
    // Free memory, return data
    delete temp;
    return removedData;
  }
}

// Delete last item and return its contents
template <typename T>
T LinkedList<T>::RemoveFromEnd()
{
  // If list is empty throw exception
  if (tail == nullptr)
  {
    throw std::out_of_range("List Empty");
  }
  else
  {
    // Point temp to head, get data from head
    Node<T> *temp = tail;
    T removedData = temp->data;
    // Move tail to prev node
    tail = temp->prev;
    // Adjust new tail pointer
    if (tail != nullptr)
    {
      tail->next = nullptr;
    }
    // Change head if list is empty
    else
    {
      head = nullptr;
    }
    // Decrease size
    size--;
    // Free memory, return data
    delete temp;
    return removedData;
  }
}

// find first instance of T data and remove it
template <typename T>
void LinkedList<T>::RemoveTheFirst(T data)
{
  // Create traversing node
  Node<T> *current = head;
  // Traverse the list
  while (current != nullptr)
  {
    // If data is found, adjust pointers
    if (current->data == data)
    {
      // If data was found at head, adjust head
      if (current == head)
      {
        head = current->next;
        // Adjust new head->prev
        if (head != nullptr)
        {
          head->prev = nullptr;
        }
        // Free memory, decrease size
        delete current;
        size--;
        return;
      }
      // If data was found anywhere else
      else
      {
        Node<T> *temp = current->prev;

        temp->next = current->next;
        if (current->next != nullptr)
        {
          current->next->prev = temp;
        }
        // free memory, decrease size
        delete current;
        size--;
        return;
      }
    }
    //Go to next node
    current = current->next;
  }
}

// find each instance of T data and remove it
template <typename T>
void LinkedList<T>::RemoveAllOf(T data)
{
  Node<T> *current = head;

  while (current != nullptr)
  {
    if (current->data == data)
    {
      if (current == head)
      {
        head = current->next;
        head->prev = nullptr;
        delete current;
        size--;
        current = head;
      }
      else
      {
        Node<T> *temp = current->prev;

        temp->next = current->next;
        if (current->next != nullptr)
        {
          current->next->prev = temp;
        }
        // free memory, decrease size
        delete current;
        size--;
        current = temp->next;
      }
    }
    else
    {
      current = current->next;
    }
  }
}

// delete the node before a particular node, return its contents
template <typename T>
T LinkedList<T>::RemoveBefore(Node<T> *node)
{
  //If there is no node before passed node, throw exception
  if (node->prev == nullptr)
  {
    throw std::out_of_range("No node before selected node");
  }
  //Store the node to be removed's data, point passed node-> prev to temp
  Node<T> *temp = node->prev;
  T removedData = node->data;
  //Point passed node to node before temp
  node->prev = temp->prev;
  if (temp->prev != nullptr)
  {
    temp->prev->next = node;
  }
  else
  {
    head = node;
  }
  // free memory, decrease size, return removed data
  delete temp;
  size--;
  return removedData;
}

// delete the node after a particular node, return its contents
template <typename T>
T LinkedList<T>::RemoveAfter(Node<T> *node)
{
  if (node->next == nullptr)
  {
    throw std::invalid_argument("No node after selected node");
  }
  Node<T> *temp = node->next;
  T removedData = node->data;

  node->next = temp->next;
  if (temp->next != nullptr)
  {
    temp->next->prev = node;
  }
  else
  {
    tail = node;
  }
  // free memory, decrease size, return removed data
  delete temp;
  size--;
  return removedData;
}

// Returns a T/F if element exists in list
template <typename T>
bool LinkedList<T>::ElementExists(T data)
{
  // Create traversing node*
  Node<T> *current = head;
  // Traverse the list until we find data
  while (current != nullptr)
  {
    // Return true if data found
    if (current->data == data)
    {
      return true;
    }
    // Move to next node
    current = current->next;
  }
  // Return false if not found
  return false;
}

// Look for data in the list, return a pointer to its node
template <typename T>
Node<T> *LinkedList<T>::Find(T data)
{
  // Create traversing node*
  Node<T> *current = head;
  // Traverse the list until we find data
  while (current != nullptr)
  {
    if (current->data == data)
    {
      return current;
    }
    // Move to next node
    current = current->next;
  }
  // Return the pointer where we found data
  return current;
}

// returns the data contained in node # index, does not delete it.
// Throws std::out_of_range exception if index is less than zero or greater than the size of the list
template <typename T>
T LinkedList<T>::Retrieve(int index)
{
  // if index is less than zero or greater than the size of the list, throws out of range
  if (index < 0 || index >= size)
  {
    throw std::out_of_range("Index is less than zero or greater that size of list");
  }
  else
  {
    Node<T> *current = head;
    int count = 0;

    while (current != nullptr)
    {
      if (count == index)
      {
        return (current->data);
      }
      count++;
      current = current->next;
    }
  }
}

// returns the data contained in the first node, does not delete it
template <typename T>
T LinkedList<T>::RetrieveFront()
{
  // If there is nothing in the list, throw exception
  if (head == nullptr)
  {
    throw std::out_of_range("List Empty");
  }
  return head->data;
}

// returns the data contained in the last node, does not delete it
template <typename T>
T LinkedList<T>::RetrieveEnd()
{
  //If there is nothing in the list, throw exception
  if (tail == nullptr)
  {
    throw std::out_of_range("List Empty");
  }
  return tail->data;
}

// Empty out the list, delete everything
template <typename T>
void LinkedList<T>::Empty()
{
  //While the list has contents, temp point to head, move head to next node, delete temp, decrease size
  while (head != nullptr)
  {
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    size--;
  }
}
#endif
