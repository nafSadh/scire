// scire/struct/stack

// Copyright (c) 2014, Khan 'Sadh' Mostafa (http://nafSadh.com/Khan)
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying text at http://www.boost.org/LICENSE_1_0.txt)

/**
 scire/struct/stack.hpp

 scire Stack abstraction:
 - AStack             : standard stack abstraction (Push, Pop, Top)
 scire Stack implementation:
 - Stack	            : linked list implementation of stack
 - StackCrate         : array implementation of stack

 other required scire files:
  scire/struct/container.hpp

 author:
 ~nafSadh

 acknowledgement:
  http://www.cplusplus.com/forum/general/81166/
 */
#ifndef SCIRE_struct_stack_HPP
#define SCIRE_struct_stack_HPP

#include "container.hpp"

namespace scire
{
#ifndef SCIRE_Stack_ABSTR
#define SCIRE_Stack_ABSTR
  /**
  * Standard stack abstraction (Push, Pop, Top).
  */
  template<typename Type, typename SzType = int>
  class AStack : public IContainer < Type, SzType >
  {
   public:
    //@implement IContainer
    virtual SzType Size() = 0;

    /**
    * Push a new element at the top of stack.
    * @param element    element to push
    * @return true on success
    */
    virtual bool Push(Type element) = 0;

    /**
    * Pop (remove/deduce) an element from the top.
    * @return true on success
    */
    virtual bool Pop() = 0;

    /**
    * Access the top element of stack.
    * @return element at the top  of the stack
    */
    virtual Type Top() = 0;

    //@implement IContainer
    virtual bool Add(Type element)
    {
      return Push(element);
    }

    //@implement IContainer
    virtual bool Deduce()
    {
      return Pop();
    }

    //@implement IContainer
    virtual Type Peek()
    {
      return Top();
    }
  };
#endif SCIRE_Stack_ABSTR

#ifndef SCIRE_Stack_CLASS
#define SCIRE_Stack_CLASS
  /**
  * Linked list implementation of stack.
  *
  * Stack implemented as linked items. A top pointer points to first item in
  * the stack. Each item points to next item of it and the last item points to
  * nullptr. Items can be added (push) and removed (pop) at top of the stack.
  */
  template<typename Type, typename SzType = int>
  class Stack : public AStack<Type, SzType>
  {
   public:
    /** initialize a Stack object, with top pointing to nullptr */
    Stack();

    /** finalize a Stack object by deleting all items from it */
    ~Stack();

    //@implement IContainer
    SzType Size();

    //@implement AStack
    bool Push(Type element);

    //@implement AStack
    bool Pop();

    //@implement AStack
    Type Top();

   protected:
    /** represent an item in the stack */
    struct Node {
     public:
      Type element; /** element at this node */
      Node* next; /** pointer to next item */

      Node(const Type& newElement, Node *nextNode)
        : element(newElement), next(nextNode) {}
    };

   private:
    /** points to the top of the stack */
    Node *top;

    /** track count of items stack  */
    SzType size;

  };

  template<typename Type, typename SzType>
  Stack<Type, SzType>::Stack()
    : top(0), size(0)
  {}

  template<typename Type, typename SzType>
  Stack<Type, SzType>::~Stack()
  {
    Node *node = this->top;

    // remove all node pointers, or else memory will leak
    while (node != nullptr) {
      Node *next = node->next;
      delete node;
      node = next;
    }
  }

  template<typename Type, typename SzType>
  SzType Stack<Type, SzType>::Size()
  {
    return this->size;
  }

  template<typename Type, typename SzType>
  bool Stack<Type, SzType>::Push(Type element)
  {
    this->top = new Node(element, this->top);
    this->size++;

    return true;
  }

  template<typename Type, typename SzType>
  bool Stack<Type, SzType>::Pop()
  {
    if(this->top==nullptr)
      return false; //nothing to pop

    //pop existing top item
    Node *temp = this->top;
    this->top = this->top->next;
    this->size--;
    delete temp;
    return true;
  }

  template<typename Type, typename SzType>
  Type Stack<Type, SzType>::Top()
  {
    return (this->top == nullptr) ? NULL: this->top->element;
  }

#endif SCIRE_Stack_CLASS

#ifndef SCIRE_StackCrate_CLASS
#define SCIRE_StackCrate_CLASS
  /**
  * array implementation of stack
  */
  template<typename Type, typename SzType = int>
  class StackCrate : public AStack<Type, SzType>
  {
   public:
    /** initialize a StackCrate  object and allocate array crate */
    StackCrate(SzType stackCapacity);

    /** finalize a StackCrate object by deleting array crate */
    ~StackCrate();

    //@implement Container
    SzType Size();

    //@implement AStack
    bool Push(Type element);

    //@implement AStack
    bool Pop();

    //@implement AStack
    Type Top();

   protected:

   private:
    /** capacity of the stack crate */
    SzType capacity;

    /** array to create the stack */
    Type *crate;

    /** track count of items stack  */
    SzType size;
  };

  template<typename Type, typename SzType>
  StackCrate<Type, SzType>::StackCrate(SzType stackCapacity)
    :capacity(stackCapacity),
     crate(0),
     size(0)
  {
    crate = new Type[capacity];
  }


  template<typename Type, typename SzType>
  StackCrate<Type, SzType>::~StackCrate()
  {
    delete[] crate;
  }


  template<typename Type, typename SzType>
  SzType StackCrate<Type, SzType>::Size()
  {
    return this->size;
  }

  template<typename Type, typename SzType>
  bool StackCrate<Type, SzType>::Push(Type element)
  {
    //if size reached the capacity, cannot push
    if (this->size >= this->capacity) return false;

    this->crate[size] = element;
    this->size++;

    return true;
  }


  template<typename Type, typename SzType>
  bool StackCrate<Type, SzType>::Pop()
  {
    //if nothing left in the stack, cannot pop
    if (size <= 0) return false;

    this->size--;
    return true;
  }

  template<typename Type, typename SzType>
  Type StackCrate<Type, SzType>::Top()
  {
    return this->crate[size - 1];
  }
#endif SCIRE_StackCrate_CLASS
}//scire
#endif SCIRE_struct_stack_HPP
