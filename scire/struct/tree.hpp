// scire/struct/tree

// Copyright (c) 2014, Khan 'Sadh' Mostafa (http://nafSadh.com/Khan)
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying text at http://www.boost.org/LICENSE_1_0.txt)

/**
 scire/struct/tree.hpp

 scire <thing> implementation:
 - BinaryTree	            : very brief description

 other required scire files:
  none

 author:
  ~nafSadh
 */
#ifndef SCIRE_struct_tree_HPP
#define SCIRE_struct_tree_HPP

namespace scire
{

#ifndef SCIRE_BinaryTree_CLASS
#define SCIRE_BinaryTree_CLASS

  /**
  */
  template<typename Type>
  class BinaryTree
  {
    class node2t
    {
     public:
      Type item;
      node2t *left;
      node2t *right;

      node2t(Type val=0, node2t* leftc = nullptr, node2t* rightc = nullptr)
        : item(val), left(leftc), right(rightc)
      {}
      ~node2t();
    };

    node2t* root;

   public:


  };

#endif//SCIRE_BinaryTree_CLASS
}
#endif//SCIRE_struct_tree_HPP
