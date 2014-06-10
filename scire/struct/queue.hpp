// scire/struct/queue

// Copyright (c) 2014, Khan 'Sadh' Mostafa (http://nafSadh.com/Khan)
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying text at http://www.boost.org/LICENSE_1_0.txt)

/**
 scire/struct/queue.hpp

 scire Queue abstraction:
 - AQueue               : queue abstraction (Enque, Deque, Front)

 scire Queue implementations:
 - Queue                : standard linked list implementation of queue
 - QueueCrate           : array implementation of queue

 other required scire files:
  scire/struct/container.hpp

 author:
  ~nafSadh
 */
#ifndef SCIRE_struct_queue_HPP
#define SCIRE_struct_queue_HPP

#include "container.hpp"

namespace scire
{

#ifndef SCIRE_Queue_ABSTR
#define SCIRE_Queue_ABSTR

  /**
  * A Queue should support Enque(), Deque() and Front() operations
  */
  template<typename Type, typename SzType>
  class AQueue : public AContainer < Type, SzType >
  {
   public:
    // -- please implement -- //
    /**
    * Enqueue a new element at the end of queue
    * @parama element element to enqueue
    * @return true on success
    */
    virtual bool Enqueue(const Type& element) = 0;

    /**
    * Dequeue the an element from the front of queue
    * @return true on success
    */
    virtual bool Dequeue() = 0;

    /**
    * Access the front (next in line) element of queue
    * @return front element of the queue
    */
    virtual Type Front() = 0;

    //@implement AContainer
    virtual SzType Size() = 0;

    // -- functions aliases : do not override -- //
    /** @copydoc AQueue::Enqueue */
    bool Enque(const Type& element)
    {
      return Enqueue(element);
    }

    /** @copydoc AQueue::Enqueue */
    bool Deque()
    {
      return Dequeue();
    }

    /** @copydoc AQueue::Enqueue */
    Type Fore()
    {
      return Front();
    }

    // -- AQueue wrapped as AContainer -- //
    //@implement AContainer
    bool Add(const Type& element)
    {
      return Enqueue(element);
    }

    //@implement AContainer
    bool Deduce()
    {
      return Dequeue();
    }

    //@implement AContainer
    Type Peek()
    {
      return Front();
    }
  };

#endif//SCIRE_Queue_ABSTR

#ifndef SCIRE_Queue_CLASS
#define SCIRE_Queue_CLASS

  /**
  * Linked List implementation of Queue.
  *
  * Queue implemented as linked items. A pointer points to head and another to
  * tail of the queue. A new element is always added to the tail of the queue
  * and removed from the head. This is a FIFO structure.
  */
  template<typename Type, typename SzType = int>
  class Queue
    : public AQueue < Type, SzType >
  {
   public:
    /** initialize a Queue object, with head and tail pointing to nullptr */
    Queue();

    /** finalize a Queue object by deleting all items from it */
    ~Queue();

    //@implement AQueue
    bool Enqueue(const Type& element);

    //@implement AQueue
    bool Dequeue();

    //@implement AQueue
    Type Front();

    //@implement AContainer
    SzType Size();

   protected:

   private:
    /** represent an item in the queue */
    struct Node {
     public:
      Type element; /** element at this node */
      Node* next; /** pointer to next item */

      Node(const Type& newElement, Node *nextNode)
        : element(newElement), next(nextNode) {}
    };

    /** entry point of the queue */
    Node *head;

    /** exit point of the queue */
    Node *tail;

    /** track count of items in the queue */
    SzType size;
  };

  template<typename Type, typename SzType>
  Queue<Type, SzType>::Queue()
    : head(0), tail(0), size(0)
  {
    //empty ctor body, all init on initlist
  }

  template<typename Type, typename SzType>
  Queue<Type, SzType>::~Queue()
  {
    Node *node = head;

    //remove all nodes to avoid leak
    while (node != nullptr) {
      Node *next = node->next;
      delete node;
      node = next;
    }
  }

  template<typename Type, typename SzType>
  bool Queue<Type, SzType>::Enqueue(const Type& element)
  {
    Node *node = new Node(element, nullptr);
    size++;

    if (head == nullptr) {
      head = node;
    }

    if (tail != nullptr) {
      tail->next = node;
    }
    tail = node;

    return true;
  }

  template<typename Type, typename SzType>
  bool Queue<Type, SzType>::Dequeue()
  {
    if (head == nullptr) return false;

    Node* temp =  head;
    head = head->next;
    size--;
    delete temp;

    if (head == nullptr) {
      tail = nullptr;
    }

    return true;
  }

  template<typename Type, typename SzType>
  Type Queue<Type, SzType>::Front()
  {
    return this->head->element;
  }

  template<typename Type, typename SzType>
  SzType Queue<Type, SzType>::Size()
  {
    return this->size;
  }
#endif//SCIRE_Queue_CLASS
}
#endif//SCIRE_struct_queue_HPP
