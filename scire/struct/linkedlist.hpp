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
#ifndef _SCIRE_linkedlist_HPP__
#define _SCIRE_linkedlist_HPP__

#include <iostream>
using namespace std;

#ifndef _SCIRE_struct_SinglyList_CLASS
#define _SCIRE_struct_SinglyList_CLASS

namespace scire
{
  template<typename Type>
  class SinglyList
  {
   public:
    SinglyList();
    ~SinglyList();
    void Traverse(void(*travfunc)(Type));
    template<typename SzType = int>
    SzType Insert(Type data, SzType location = 0);
    void Push(Type data);
    Type Pop();

   protected:
    struct SinglyNode {
     public:
      Type data;
      SinglyNode* next;
    };

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
  template<typename SzType=int>
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

  template<typename Type>
  void SinglyList<Type>::Traverse(void(*travfunc)(Type))
  {
    SinglyNode *node = this->head;

    while (node != NULL) {
      travfunc(node->data);
      node = node->next;
    }
  }
}
#endif _SCIRE_struct_SinglyList_CLASS

#endif _SCIRE_linkedlist_HPP__
