// scire/struct/container

// Copyright (c) 2014, Khan 'Sadh' Mostafa (http://nafSadh.com/Khan)
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying text at http://www.boost.org/LICENSE_1_0.txt)

/**
 scire/struct/container.hpp

 scire container interface :
 - Container	      : contains many elements

 other required scire files:
  none

 author:
  ~nafSadh
 */
#ifndef SCIRE_struct_container_HPP
#define SCIRE_struct_container_HPP

namespace scire
{

#ifndef SCIRE_Container_INTFC
#define SCIRE_Container_INTFC

  /**
  * Container Inferface.
  * Size() function is necessary to all containers;
  * this interface requires each container to implement Add(), Deduce() and
  * Peek() function eventually allowing programs to switch between completely
  * different conainers (e.g. List, Queue, Stack etc. even when Add/Deduce/Peek
  * bear very different concepts; e.g. Add vs. Insert vs Enque vs Push).
  */
  template<typename Type, typename SzType = int>
  class IContainer
  {
   public:
    /**
    * number of items contained in
    * @return SzType current size
    */
    virtual SzType Size() = 0;

    /**
    * add an element
    * @param val    value to be added as new element
    * @return bool  true on success
    */
    virtual bool Add(Type val) = 0;

    /**
    * deduce one element
    *return bool true on success
    */
    virtual bool Deduce() = 0;

    /**
    * a peek into next element to access
    * @return Type  element
    */
    virtual Type Peek() = 0;
  };

#endif SCIRE_Container_INTFC
}
#endif SCIRE_struct_container_HPP
