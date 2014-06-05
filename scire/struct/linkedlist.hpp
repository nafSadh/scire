// scire/struct/linkedlist

// Copyright (c) 2014, Khan 'Sadh' Mostafa (http://nafSadh.com/Khan)
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying text at http://www.boost.org/LICENSE_1_0.txt)

/*
 scire/struct/linkedlist.hpp

 SCIRE Linked List implementations
 - SinglyList	: Singly Linked List
 - DoublyList	: Doubly Linked List
 - CircularList	: Circular List

 */
#ifndef SCIRE_linkedlist_HPP__
#define SCIRE_linkedlist_HPP__

#include <iostream>
using namespace std;

#ifndef SCIRE_struct_SinglyList_CLASS
#define SCIRE_struct_SinglyList_CLASS

namespace scire
{
  /**
  * A Singly Linked List class
  */
  template<typename Type>
  class SinglyList
  {
   public:
    SinglyList();
    ~SinglyList();

    /**
    * Traverse each item of the list
    *
    * @param travfunc       function to traverse each item of list with
    * @return void
    */
    void Traverse(void(*travfunc)(Type));

    /**
    * insert a new item in the list with passed <data> after <location> nodes
    *
    * @param data           data to insert as new item in the list
    * @param [location]     location in the list where the new element to insert
    * @return SzType        location where item inserted
    */
    template<typename SzType = int>
    SzType Insert(Type data, SzType location = 0);

    /**
    * push a new item in the list with passed <data> at head
    *
    * @param data           data to push
    * @return void
    */
    void Push(Type data);

    /**
    * Pop the top element
    */
    Type Pop();

   protected:
    /**
    * represent a node in Singly Linked List
    */
    struct SinglyNode {
     public:
      /** data */
      Type data;
      /** pointer to next element in list */
      SinglyNode* next;
    };

    /** points to first element of the list */
    SinglyNode *head;

   private:

  };

  template<typename Type>
  SinglyList<Type>::SinglyList()
  {
    this->head = nullptr;
  }

  template<typename Type>
  SinglyList<Type>::~SinglyList()
  {
    SinglyNode *node = this->head;

    // remove all node pointers, or else memory will leak
    while (node != nullptr) {
      SinglyNode *next = node->next;
      delete node;
      node = next;
    }
  }

  template<typename Type>
  void SinglyList<Type>::Traverse(void(*travfunc)(Type))
  {
    SinglyNode *node = this->head;

    while (node != NULL) {
      travfunc(node->data);
      node = node->next;
    }
  }

  template<typename Type>
  template<typename SzType>
  SzType SinglyList<Type>::Insert(Type data, SzType location=0)
  {
    SinglyNode *node = new SinglyNode();

    node->data = data;

    // if list is empty or if insert to 0th location (at begining)
    // point node->next to head and make head point to this new node
    if (location <= 0 || this->head == nullptr) {
      node->next = this->head;
      this->head = node;
      return 0;
    }

    //if list is not empty and location is not at beginning
    SzType i = 0;
    SinglyNode *prev = this->head;
    SinglyNode *curr = this->head;
    while (i++ < location && curr != nullptr) {
      prev = curr;
      curr = curr->next;
    }
    node->next = prev->next;
    prev->next = node;

    return i;
  }

  template<typename Type>
  void SinglyList<Type>::Push(Type data)
  {
    SinglyNode *node = new SinglyNode();

    node->data = data;
    node->next = head;
    this->head = node;
  }

  template<typename Type>
  Type SinglyList<Type>::Pop()
  {
    Type data = this->head->data;

    SinglyNode *node = this->head;

    this->head = head->next;

    delete node;

    return data;
  }
}
#endif SCIRE_struct_SinglyList_CLASS

#endif SCIRE_linkedlist_HPP__
