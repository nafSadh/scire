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
    void Traverse(void(*travfunc)(Type));

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
    class SinglyNode
    {
     public:
      /** element */
      Type element;
      /** pointer to next node in list */
      SinglyNode* next;
    };

    /** points to first item of the list */
    SinglyNode *head;

    /** track count of items in the list */
    SzType count;
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
      travfunc(node->element);
      node = node->next;
    }
  }

  template<typename Type, typename SzType>
  SzType SinglyList<Type, SzType>::Insert(Type element, SzType location)
  {
    SinglyNode *node = new SinglyNode();
    //TODO: exception when new fails

    this->count++;
    node->element = element;

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
  SzType SinglyList<Type, SzType>::Size() const
  {
    return this->count;
  }

  template<typename Type, typename SzType>
  bool SinglyList<Type, SzType>::Deduce()
  {
    if (this->IsEmpty()) return false;

    SinglyNode *node = this->head;
    this->head = head->next;
    this->count--;
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
