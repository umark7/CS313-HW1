//
// Created by Hema Muni on 3/6/21.
//

#ifndef HEMA_MUNI_HOMEWORK1_QUESTION1_H
#define HEMA_MUNI_HOMEWORK1_QUESTION1_H

#include <vector>
#include <list>
#include <iostream>
#include <string>

using namespace std;

template<class T>
class Vec{
public:
    //these are our three constructors
    Vec();
    Vec(int n);
    Vec(int n, T a);

    //copy constructors
    Vec(const Vec &orig);
    //operator=
    Vec& operator= (const Vec &rhs);
    //deallocate
    ~Vec();

    //our size function which checks the size of vector
    int size() const     { return _size; }      //inline

    //this function checks the first index of the vector
    T front() const;
    //this functions checks the last index of the vector
    T back() const;

    //this functions clears the whole vector
    void clear();
    //this function deletes the last index of the vector
    void pop_back();
    //this functions adds to the vector
    void push_back(T a);

    T& at(int n);
    T& operator[] (int n);

private:
    void allocate();
    void release();

    int _capacity;
    int _size;
    T * _vec;

};

//this is our default constructor where everything is set to 0
template<typename T>
Vec<T> :: Vec() : _capacity(0), _size(0), _vec(0) {}


template<typename T>
Vec<T> :: Vec(int n) {
    if (n <= 0) {
        //everything stays at 0 if n is a negative number
        _capacity = 0;
        _size = 0;
        _vec = NULL;
    } else if (n > 0) {
        //the size and capacity will be n
        _capacity = n;
        _size = n;
        allocate();
    }
}

template<typename T>
Vec<T> :: Vec(int n, T a) {
    if (n <= 0) {
        //everything stays at 0 if n is a negative number
        _capacity = 0;
        _size = 0;
        _vec = NULL;
    } else if (n > 0) {
        //the size and capacity will be n and vec[i] has a value
        _capacity = n;
        _size = n;
        allocate();
        for(int i = 0; i < _capacity; i++){
            _vec[i] = a;
        }
    }
}

template<typename T>
Vec<T> :: Vec(const Vec &orig) {
    //we equal the values to what is in the parameters
    _capacity = orig._size;
    _size = orig._size;
    allocate();

    for(int i = 0; i < _size; i++) {
        _vec[i] = orig._vec[i];
    }
}

template<typename T>
Vec<T>& Vec<T>:: operator= (const Vec &rhs) {
    //this is our base case
    if (this == &rhs) {
        return *this;
    }
    //we copy over values from the parameters
    _capacity = rhs._size;
    _size = rhs._size;
    release();
    allocate();
    for(int i = 0; i < _size; i++) {
        _vec[i] = rhs._vec[i];
    }
    return *this;
}

//this deallocates memeory
template<typename T>
Vec<T> :: ~Vec() {
    release();
}

//this calls the first element of the vector
template<typename T>
T Vec<T> :: front() const {
    if(_size <= 0) {
        T default_obj;
        return default_obj;
    } else
        return _vec[0];

}

//this calls the back element of the vector
template<typename T>
T Vec<T> :: back() const {
    if(_size <= 0) {
        T default_obj;
        return default_obj;
    } else
        return _vec[_size-1];

}

//this sets the vector to 0 and clears it.
template<typename T>
void Vec<T> :: clear() {
    _size = 0;
}

//this deletes the last element of the vector
template<typename T>
void Vec<T> :: pop_back() {
    if (_size > 0) {
        _size--;
    }
}

template<typename T>
void Vec<T> :: push_back(T a) {
    //we check to see if the size is less than the capacity
    if(_size < _capacity) {
        //if so we add a value to the vector
        _vec[_size] = a;
        _size = _size + 1;
        return;
    } else if (_size == _capacity) {
        //we add one to our capacity so it isn't empty
        if (_capacity == 0) {
            _capacity = 1;
        } else if (_capacity > 0) {
            _capacity *= 2;
        }
    }

    //we allocate memory here and delete so there isn't a memory leak
    T *oldvec = _vec;
    allocate();
    if (oldvec != NULL) {
        for (int i = 0; i < _size; ++i) {
            _vec[i] = oldvec[i];
        }
    }
    delete [] oldvec;

    _vec[_size] = a;
    _size++;
}

//this will allocate memory
template<typename T>
void Vec<T> :: allocate() {
    if(_capacity <= 0) {
        _vec = NULL;
    } else if (_capacity > 0) {
        _vec = new T[_capacity];
    }
}

//this will release memory
template<typename T>
void Vec<T> :: release() {
    if(_vec == NULL) {
        return;
    } else if (_vec != NULL) {
        delete [] _vec;
        _vec = NULL;
    }
}

template<typename T>
T& Vec<T> :: at(int n) {
    if (n >= 0 && n < _size) {
        //we use this so we can pinpoint certain places in the code
        return _vec[n];
    } else {
        T *pnull = NULL;
        return *pnull;
    }
}

template<typename T>
T& Vec<T> :: operator[] (int n) {
    return at(n);
}

template<class T>
class Node {
public:
    T Value;
    Node<T>* Next;

    Node(T data) {
        Value = data;
    }
};

template<class T>
class LinkedList{
private:
    int m_count;
public:
    // The first node in the list
    // or null if empty
    Node<T>* Head;

    // The last node in the list
    // or null if empty
    Node<T>* Tail;

    // Constructor
//    LinkedList();

    // Get() operation
    Node<T>* Get(int index);

    // Insert() operation
    void InsertHead(T val);
    void InsertTail(T val);
    void Insert(int index, T val);

    // Search() operation
    int Search(T val);

    // Remove() operation
    void RemoveHead();
    void RemoveTail();
    void Remove(int index);

    // Additional operation
    int Count();
    void print();
    void PrintList();

//    T& at(int n);
//    T& operator[] (int n);
};

template <typename T>
void LinkedList<T>::InsertHead(T val)
{
    // Create a new Node
    Node<T> * node = new Node<T>(val);

    // The current Head will no longer become a Head
    // so the Next pointer of the new Node will
    // point to the current Head
    node->Next = Head;

    // The new Node now become the Head
    Head = node;

    // If the linked list is empty
    // The Tail is also the Head
    if(m_count == 0)
        Tail = Head;

    // One element is added
    m_count++;
}

template <typename T>
void LinkedList<T>::InsertTail(T val)
{
    // If the linked list is empty,
    // just simply invoke InsertHead()
    if(m_count == 0)
    {
        InsertHead(val);
        return;
    }

    // Create a new Node
    Node<T> * node = new Node<T>(val);

    // The current Tail will no longer become a Tail
    // so the Next pointer of the current Tail will
    // point to the new node
    Tail->Next = node;

    // The new Node now become the Tail
    Tail = node;

    // One element is added
    m_count++;
}

//template <typename T>
//LinkedList<T>::LinkedList(){}

template <typename T>
void LinkedList<T>::Insert(int index, T val)
{
    // Check if the index is out of bound
    if(index < 0 || index > m_count)
        return;

    // If inserting a new Head
    if(index == 0)
    {
        InsertHead(val);
        return;
    }
        // If inserting a new Tail
    else if(index == m_count)
    {
        InsertTail(val);
        return;
    }

    // Start to find previous node
    // from the Head
    Node<T> * prevNode = Head;

    // Traverse the elements until
    // the selected index is found
    for(int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->Next;
    }

    // Create the next node which is
    // the element after previous node
    Node<T> * nextNode = prevNode->Next;

    // Create a new node
    Node<T> * node = new Node<T>(val);

    // Insert this new node between
    // the previous node and the next node
    node->Next = nextNode;
    prevNode->Next = node;

    // One element is added
    m_count++;
}

template <typename T>
Node<T> * LinkedList<T>::Get(int index)
{
    // Check if the index is out of bound
    if(index < 0 || index > m_count)
        return NULL;

    // Start from the Head
    Node<T> * node = Head;

    // Iterate through the linked list elements
    // until it finds the selected index
    for(int i = 0; i < index; ++i)
    {
        node = node->Next;
    }

    // Simply return the node result
    return node;
}

template <typename T>
int LinkedList<T>:: Search(T val)
{
    // If LinkedList is empty,
    // just return NOT_FOUND
    if(m_count == 0)
        return -1;

    // Need to count the index
    int index = 0;

    // Traverse from the Head node
    Node<T> * node = Head;

    // Traverse until the selected value
    // is matched with the value
    // of the current position,
    while(node->Value != val)
    {
        index++;
        node = node->Next;

        // This will happen
        // if the selected value
        // is not found
        if(node == NULL)
        {
            return -1;
        }
    }

    return index;
}

template <typename T>
void LinkedList<T>::RemoveHead()
{
    // Do nothing if list is empty
    if(m_count == 0)
        return;

    // Save the current Head
    // to a new node
    Node<T> * node = Head;

    // Point the Head Pointer
    // to the element next to the current Head
    Head = Head->Next;

    // Now it's safe to remove
    // the first element
    delete node;

    // One element is removed
    m_count--;
}

template <typename T>
void LinkedList<T>::RemoveTail()
{
    // Do nothing if list is empty
    if(m_count == 0)
        return;

    // If List element is only one
    // just simply call RemoveHead()
    if(m_count == 1)
    {
        RemoveHead();
        return;
    }

    // Start to find previous node
    // from the Head
    Node<T> * prevNode = Head;

    // This is the candidate of
    // removed items which is
    // the element next to the prevNode
    Node<T> * node = Head->Next;

    // Traverse the elements until
    // the last element
    while(node->Next != NULL)
    {
        prevNode = prevNode->Next;
        node = node->Next;
    }

    // the prevNode now becomes the Tail
    // so the Next pointer of the prevNode
    // point to NULL
    prevNode->Next = NULL;
    Tail = prevNode;

    // Now it's safe to remove
    // the last element
    delete node;

    // One element is removed
    m_count--;
}

template <typename T>
void LinkedList<T>::Remove(int index)
{
    // Do nothing if list is empty
    if(m_count == 0)
        return;

    // Do nothing if index is out of bound
    if(index < 0 || index >= m_count)
        return;

    // If removing the current Head
    if(index == 0)
    {
        RemoveHead();
        return;
    }
        // If removing the current Tail
    else if(index == m_count - 1)
    {
        RemoveTail();
        return;
    }

    // Start to traverse the list
    // from the Head
    Node<T> * prevNode = Head;

    // Find the element before
    // the selected index
    for(int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->Next;
    }

    // The removed element is after
    // the prevNode
    Node<T> * node = prevNode->Next;

    // The nextNode will be the neighbor of
    // prevNode if the node is removed
    Node<T> * nextNode = node->Next;

    // Link the prevNode to nextNode
    prevNode->Next = nextNode;

    // It's now safe to remove
    // the selected index element
    delete node;

    // One element is removed
    m_count--;
}

template <typename T>
void LinkedList<T>::print()
{
    Node<T>* current;
    current = Head;
    while(current != nullptr){
        cout << current -> Value << " " << endl;
        current = current -> Next;
    }
}


template<typename T>
void PrintNode(Node<T> * node)
{
    // It will print the initial node
    // until it finds NULL for the Next pointer
    // that indicate the end of the Node Chain
    while(node != NULL)
    {
        cout << node->Value << " -> ";
        node = node->Next;
    }

    cout << "NULL" << endl;
}

template<class T>
class LL_Iterator {
private:
    Node<T>* current;

public:
    //constructors
    LL_Iterator() {	current = nullptr; }
    LL_Iterator(Node<T>* ptr) { current = ptr; }

    //operator overloads
    T operator*() {
        return current->info;
    }
    LL_Iterator<T> operator++() {
        current = current->Next;
        return *this;
    }
    bool operator==(const LL_Iterator<T>& right) const {
        return (current == right.current);
    }
    bool operator!=(const LL_Iterator<T>& right) const {
        return (current != right.current);
    }
};

int generateRand() {
    //randomizes the numbers
    int randNums = rand() % 52;
    return randNums;
}


template <typename T>
void BuildVector(const int size, Vec<T> vector) {
    //fills in with random numbers
    for(int i = 0; i < size; i++){
        int tempVar = generateRand();
        vector.push_back(tempVar);
    }
}

template <typename T>
void buildStringVector(const int size, Vec<T> vector) {
    //array of chars
    char arr[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                  'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                  'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    //fills in with random chars
    for(int i = 0; i < size; i++) {
        int tempVar = generateRand();
        vector.push_back(arr[tempVar]);
    }
}

template <typename T>
void BuildList(const int size, LinkedList<T> list){
    //fills in with random numbers
    for(int i = 0; i < size; i++){
        int tempVar = generateRand();
        list.Insert(i, tempVar);
    }
}

template <typename T>
void buildStringList(const int size, LinkedList<T> list) {
    //array of chars
    char arr[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                  'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                  'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    //fills in with random chars
    for(int i = 0; i < size; i++){
        int tempVar = generateRand();
        list.Insert(i, tempVar);
    }
}
#endif //HEMA_MUNI_HOMEWORK1_QUESTION1_H
