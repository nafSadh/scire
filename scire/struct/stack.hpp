// scire/struct/stack

// Copyright (c) 2014, Khan 'Sadh' Mostafa (http://nafSadh.com/Khan)
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying text at http://www.boost.org/LICENSE_1_0.txt)

/**
 scire/struct/stack.hpp

 scire Stack implementation:
 - Stack	            : standard simple stack

 other required scire files:
  scire/struct/container.hpp

 author:
 ~nafSadh
 */
#ifndef SCIRE_struct_stack_HPP
#define SCIRE_struct_stack_HPP

namespace scire
{

#ifndef SCIRE_Stack_CLASS
#define SCIRE_Stack_CLASS


  /**
  * Stack class.
  *
  * Linked list implementation of stack. A top pointer points to first item in
  * the stack. Each item points to next item of it and the last item points to
  * nullptr. Items can be added (push) and removed (pop) at top of the stack.
  */
  template<typename Type, typename SzType = int>
  class Stack : public IContainer<Type, SzType>
  {
   public:
    /** initialize a Stack object, with top pointing to nullptr */
    Stack();

    /** finalize a Stack object by deleting all items from the it */
    ~Stack();

    /**
    * get count of items in the stack
    * @implement Container
    * @return SzType    count
    */
    SzType Size();

    /**
    * Push a new item at the top of stack with passed <data>
    *
    * @param data       data to push
    * @return bool			true on success
    */
    bool Push(Type data);

    /**
    * Pop (remove) an item from the top.
    *
    * @return true on success
    */
    bool Pop();

    /**
    * Access the top element of stack
    * @return element at the top  of the stack
    */
    Type Top();


    //@implement Container
    virtual bool Add(Type val)
    {
      return Push(val);
    }

    //@implement Container
    virtual bool Deduce()
    {
      return Pop();
    }

    //@implement Container
    virtual Type Peek()
    {
      return Top();
    }
   protected:
    /**
    * represent an item in the stack
    */
    struct Node {
     public:
      /** data */
      Type data;
      /** pointer to next item */
      Node* next;
    };

   private:
    /** points to the top of the stack */
    Node *top;

    /** track count of items stack  */
    SzType size;

  };

  template<typename Type, typename SzType>
  Stack<Type,SzType>::Stack()
  {
    this->top = nullptr;
    this->size = 0;
  }

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
  bool Stack<Type, SzType>::Push(Type data)
  {
    Node *node = new Node();

    node->data = data;
    node->next = this->top;
    this->top = node;
    this->size++;

    return true;
  }

  template<typename Type, typename SzType>
  bool Stack<Type, SzType>::Pop()
  {
    if(top==nullptr)
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
    if(this->top == nullptr) return NULL;

    return this->top->data;
  }

#endif SCIRE_Stack_CLASS
}
#endif SCIRE_struct_stack_HPP
