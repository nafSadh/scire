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
  * A Singly Linked List class.
  * Singly linked list contains a linear list of items. Each item points to it's
  * next; the last item of the list points to nullptr. A head pointer points to
  * the first element of the list.
  */
  template<typename Type, typename SzType = int>
  class SinglyList
  {
   public:
    /** initialize a SinglyList object, with head pointing to nullptr */
    SinglyList();

    /** finalize a SinglyList object by deleting all items from the list */
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
    SzType Insert(Type data, SzType location = 0);


    /**
    * get count of items in the list
    *
    * @return SzType        count
    */
    SzType Count();

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
      /** pointer to next node in list */
      SinglyNode* next;
    };

    /** points to first item of the list */
    SinglyNode *head;

    /** track count of items in the list */
    SzType count;

   private:

  };

  template<typename Type, typename SzType>
  SinglyList<Type,SzType>::SinglyList()
  {
    this->head = nullptr;
    this->count = 0;
  }

  template<typename Type, typename SzType>
  SinglyList<Type, SzType>::~SinglyList()
  {
    SinglyNode *node = this->head;

    // remove all node pointers, or else memory will leak
    while (node != nullptr) {
      SinglyNode *next = node->next;
      delete node;
      node = next;
    }
  }

  template<typename Type, typename SzType>
  void SinglyList<Type, SzType>::Traverse(void(*travfunc)(Type))
  {
    SinglyNode *node = this->head;

    while (node != NULL) {
      travfunc(node->data);
      node = node->next;
    }
  }

  template<typename Type, typename SzType>
  SzType SinglyList<Type, SzType>::Insert(Type data, SzType location = 0)
  {
    SinglyNode *node = new SinglyNode();
    //TODO: exception when new fails

    this->count++;
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

  template<typename Type, typename SzType>
  SzType SinglyList<Type, SzType>::Count()
  {
    return this->count;
  }

  template<typename Type, typename SzType>
  void SinglyList<Type, SzType>::Push(Type data)
  {
    SinglyNode *node = new SinglyNode();

    this->count++;

    node->data = data;
    node->next = head;
    this->head = node;
  }

  template<typename Type, typename SzType>
  Type SinglyList<Type, SzType>::Pop()
  {
    Type data = this->head->data;

    SinglyNode *node = this->head;

    this->head = head->next;

    this->count--;

    delete node;

    return data;
  }
}
#endif SCIRE_struct_SinglyList_CLASS

#endif SCIRE_linkedlist_HPP__
