// scire/struct/container

// Copyright (c) 2014, Khan 'Sadh' Mostafa (http://nafSadh.com/Khan)
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying text at http://www.boost.org/LICENSE_1_0.txt)

/**
 scire/struct/container.hpp

 scire container abstraction :
 - Container	      : contains many elements

 scire container interfaces :
 - Crate            : elements contained in array

 other required scire files:
  none

 author:
  ~nafSadh
 */
#ifndef SCIRE_struct_container_HPP
#define SCIRE_struct_container_HPP

namespace scire
{

#ifndef SCIRE_Container_ABSTR
#define SCIRE_Container_ABSTR
  /**
  * Container Inferface.
  * Size() function is necessary to all containers;
  * Each container shall also implement Add(), Deduce() and Peek() function
  * eventually allowing programs to switch between completely different
  * containers (e.g. List, Queue, Stack etc. even when Add/Deduce/Peek
  * bear very different concepts; e.g. Add vs. Insert vs Enque vs Push).
  */
  template<typename Type, typename SzType = int>
  class AContainer
  {
   public:
    /** virtual dtor for containers */
    virtual ~AContainer() {}

    /**
    * number of elements contained in
    * @return current size
    */
    virtual SzType Size() const = 0;

    /**
    * add an element
    * @param element   element to be added as new element
    * @return true on success
    */
    virtual bool Add(const Type& element) = 0;

    /**
    * deduce one element
    * @return true on success
    */
    virtual bool Deduce() = 0;

    /**
    * peek into next element contained in
    * @return element
    */
    virtual Type Peek() const = 0;

    /**
    * check if empty
    * @return true when empty
    */
    virtual bool IsEmpty() const
    {
      return (this->Size() <= 0);
    }
  };

#endif//SCIRE_Container_INTFC

#ifndef SCIRE_Crate_INTFC
#define SCIRE_Crate_INTFC
  /**
  * Crate contains elements in an arrays.
  */
  template<typename Type, typename SzType = int>
  class ICrate
  {
   public:
    virtual SzType Capacity() const  = 0;
  };
#endif//SCIRE_Crate_INTFC
}
#endif//SCIRE_struct_container_HPP
