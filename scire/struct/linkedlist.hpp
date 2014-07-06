// scire/struct/linkedlist

// Copyright (c) 2014, Khan 'Sadh' Mostafa (http://nafSadh.com/Khan)
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying text at http://www.boost.org/LICENSE_1_0.txt)

/**
 scire/struct/linkedlist.hpp

 scire Linked List implementations:
 - SinglyList         : Singly Linked List
 - DoublyList	        : Doubly Linked List
 - CircularList	      : Circular List

 other required scire files:
  scire/struct/container.hpp

 author:
  ~nafSadh
 */
#ifndef SCIRE_struct_linkedlist_HPP
#define SCIRE_struct_linkedlist_HPP

#include "container.hpp"

namespace scire
{

#ifndef SCIRE_SinglyList_CLASS
#define SCIRE_SinglyList_CLASS
  /**
  * A Singly Linked List class.
  *
  * Singly linked list contains a linear list of items. Each item points to it's
  * next; the last item of the list points to nullptr. A head pointer points to
  * the first item of the list.
  */
  template<typename Type, typename SzType = int>
  class SinglyList
    : public AContainer<Type, SzType>
  {
   public:
    /** initialize a SinglyList object, with head pointing to nullptr */
    SinglyList();

    /** finalize a SinglyList object by deleting all items from the list */
    virtual ~SinglyList();

    /**
    * Traverse each element of the list
    * @param travfunc     function to traverse each element of list with
    */
    void Traverse(void(*travfunc)(const Type&)) const;

    /**
    * insert a new item in the list with passed element after location nodes
    * @param element        element to insert as new item in the list
    * @param location       location in the list where the new element to insert
    * @return SzType        location where item inserted
    */
    SzType Insert(Type element, SzType location = 0);

    //@implement Container
    virtual SzType Size() const;

    //@implement Container
    virtual bool Add(const Type& element)
    {
      return (this->Insert(element, 0) == 0);
    }

    //@implement Container
    virtual bool Deduce();

    //@implement Container
    virtual Type Peek() const;

   protected:
    /** represent an item node in Singly Linked List */
    struct Node {
     public:
      Type element; /** element at this node */
      Node* next; /** pointer to next item */

      Node(const Type& newElement, Node *nextNode)
        : element(newElement), next(nextNode) {}
    };

    /** points to first item of the list */
    Node *head;

    /** track count of items in the list */
    SzType size;
  };

  template<typename Type, typename SzType>
  SinglyList<Type,SzType>::SinglyList()
    : head(0), size()
  {
    //empty ctor body, all init on initlist
  }

  template<typename Type, typename SzType>
  SinglyList<Type, SzType>::~SinglyList()
  {
    Node *node = this->head;

    // remove all nodes to avoid leak
    while (node != nullptr) {
      Node *next = node->next;
      delete node;
      node = next;
    }
  }

  template<typename Type, typename SzType>
  void SinglyList<Type, SzType>::Traverse(void(*travfunc)(const Type&)) const
  {
    Node *node = this->head;

    while (node != nullptr) {
      travfunc(node->element);
      node = node->next;
    }
  }

  template<typename Type, typename SzType>
  SzType SinglyList<Type, SzType>::Insert(Type element, SzType location)
  {
    Node *node = new Node(element, nullptr);
    // exception when new fails
    if (nullptr == node) {
      return -1;
    }

    this->size++;

    // if list is empty or if insert to 0th location (at begining)
    // point node->next to head and make head point to this new node
    if (location <= 0 || this->head == nullptr) {
      node->next = this->head;
      this->head = node;
      return 0;
    }

    //if list is not empty and location is not at beginning
    SzType i = 0;
    Node *prev = this->head;
    Node *curr = this->head;
    while (i++ < location && curr != nullptr) {
      prev = curr;
      curr = curr->next;
    }
    node->next = prev->next;
    prev->next = node;

    return i;
  }

  template<typename Type, typename SzType>
  SzType SinglyList<Type, SzType>::Size() const
  {
    return this->size;
  }

  template<typename Type, typename SzType>
  bool SinglyList<Type, SzType>::Deduce()
  {
    if (this->IsEmpty()) return false;

    Node *node = this->head;
    this->head = head->next;
    this->size--;
    delete node;

    return true;
  }

  template<typename Type, typename SzType>
  Type SinglyList<Type, SzType>::Peek() const
  {
    return this->head->element;
  }
#endif//SCIRE_SinglyList_CLASS
}//scire namespace
#endif//SCIRE_struct_linkedlist_HPP
