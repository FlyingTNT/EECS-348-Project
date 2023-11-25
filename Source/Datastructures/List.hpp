/**
 * List.hpp
 * Purpose: An implementation of a list.
 * Author: C. Cooper
 * Date Created: 2023-11-22
*/

#ifndef LIST_H
#define LIST_H
#include <iostream>

/**
 * An implementation of a list. Internally uses a linked list structure.
*/
template <typename T>
class List
{
    public:
    List();
    ~List();
    void append(T* item);
    T* pop();
    T* get(int index);
    void set(int index, T* value);
    void remove(int index);
    void insert(int index, T* value);
    int length();

    template <typename K>
    friend std::ostream& operator << (std::ostream& stream, const List<K>& list);

    private:
    class Node
    {
        public:
        Node(T*);
        Node* getNext();
        void setNext(Node* next);
        T* getValue();
        void setValue(T* value);
        bool hasNext();

        private:
        T* value;//The value stored in this node
        Node* next;//The node that proceeds this one.
    };
    Node* root;//The first item in thisl list.
};

#include "List.tpp"

#endif