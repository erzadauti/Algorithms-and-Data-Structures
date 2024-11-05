#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstdlib> 
#include <cstddef> 

template <class T>
class Node { 
    public:
        T data;
        Node *previous = NULL;
        Node *next = NULL;
        Node(T Data);
};

template <class T>
class List {
    private:
        int size;
        Node<T> *Front;
        Node<T> *Back;
    public:
        List();
        ~List();

        void push_back(T element);
        void push_front(T element);
        T pop_back();
        T pop_front();
        T front();
        T back();
        int elementNumber();
};

template <class T>
List<T>::List() {
    this->Front = NULL;
    this->Back = NULL;
    this->size = 0;
}

template <class T>
List<T>::~List() {
    if (this->Front != NULL) {
        Node<T> *cursor = this->Front;
        Node<T> *temp;
        while (cursor != NULL) {
            temp = cursor;
            cursor = cursor->next;
            delete temp;
        }
    }
}

template <class T>
void List<T>::push_back(T element) {
    Node<T> *newElement = new Node<T>(element);
    newElement->previous = this->Back;
    newElement->next = NULL;

    if (this->size == 0)
        this->Front = newElement;
    else
        this->Back->next = newElement;

    this->Back = newElement;
    this->size++;
}

template <class T>
void List<T>::push_front(T element) {
    Node<T> *newElement = new Node<T>(element);
    newElement->previous = NULL;
    newElement->next = this->Front;

    if (this->size == 0)
        this->Back = newElement;
    else
        this->Front->previous = newElement;

    this->Front = newElement;
    this->size++;
}

template <class T>
T List<T>::pop_back() {
    Node<T> *temp = NULL;

    if (this->size > 0) {
        T data;
        data = this->Back->data;
        temp = this->Back;
        this->Back = this->Back->previous;
        this->size--;
        delete temp;
        return data;
    } else {
        std::cout << "Unable to pop when List is empty!" 
                  << std::endl;
        exit(1);
    }
}

template <class T>
T List<T>::pop_front() {
    Node<T> *temp = NULL;

    if (this->size > 0) {
        T data;
        data = this->Front->data;
        temp = this->Front;
        this->Front = this->Front->next;
        this->size--;
        delete temp;
        return data;
    } else {
        std::cout << "Unable to pop when List is empty!"
                  << std::endl;
        exit(1);
    }
}

template <class T>
int List<T>::elementNumber() {
    return this->size;
}

template <class T>
T List<T>::front() {
    return this->Front->data;
}

template <class T>
T List<T>::back(){
    return this->Back->data;
}

template <class T>
Node<T>::Node(T Data) {
    this->data = Data;
}

#endif