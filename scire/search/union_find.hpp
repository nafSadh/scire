// scire/search/union_find

// Copyright (c) 2014, Khan 'Sadh' Mostafa (http://nafSadh.com/Khan)
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying text at http://www.boost.org/LICENSE_1_0.txt)

/**
 scire/search/union_find.hpp

 scire <thing> implementation:
 - UnionFind	            : very brief description

 other required scire files:
  none

 author:
  ~nafSadh
 */
#ifndef SCIRE_search_union_find_HPP
#define SCIRE_search_union_find_HPP

namespace scire
{

#ifndef SCIRE_UnionFind_CLASS
#define SCIRE_UnionFind_CLASS

  /**
  */
  template<typename type=int>
  class UnionFind
  {
   protected:
    type n;/**<number of sites */
    type count;/**<number of connected components (i.e. trees)*/
    type *id;/**<parent link, site indexed */
    type *sz;/**<sites size for root */

   public:
    /** Construct UnionFind algorithm object for n sites. Also initializes the
    id (parent link) array and sz (size of root) array. */
    UnionFind(
      type number/**<number of sites */
    ) : n(number), count(n)
    {
      id = new type[n];
      sz = new type[n];

      for (type i = 0; i < n; i++) {
        id[i] = i;
        sz[i] = 1;
      }
    }

    /** follow links to find a root.
    @return index of root */
    type Find(
      type x/**<index of site to find root of*/
    )
    {
      if (x < 0 || x >= n) return -1;
      type p = x;
      while (p != id[p]) {
        id[p] = id[id[p]];
        p = id[p];
      }
      return p;
    }


    /** Union operation. Connect site a with site b and update the tree */
    void Unite(
      type a, type b
    )
    {
      type i = Find(a);
      type j = Find(b);
      if (i == j) return;
      // Make smaller root point to larger one.
      if (sz[i] < sz[j]) {
        id[i] = j;
        sz[j] += sz[i];
      } else {
        id[j] = i;
        sz[i] += sz[j];
      }
      count--;

    }
    bool IsConnected(type a, type b)
    {
      return (Find(a) == Find(b));
    }

    type SiteCount()
    {
      return n;
    }

    type ComponentsCount()
    {
      return count;
    }
  };

#endif//SCIRE_UnionFind_CLASS
}
#endif//SCIRE_search_union_find_HPP
