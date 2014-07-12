// scire/graph/stable_matching

// Copyright (c) 2014, Khan 'Sadh' Mostafa (http://nafSadh.com/Khan)
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying text at http://www.boost.org/LICENSE_1_0.txt)

/**
 scire/graph/stable_matching.hpp

 scire <thing> implementation:
 - ClassName	            : very brief description

 other required scire files:
  none

 author:
  ~nafSadh
 */
#ifndef SCIRE_graph_stable_matching_HPP
#define SCIRE_graph_stable_matching_HPP

#include <vector>

namespace scire
{

#ifndef SCIRE_ClassName_CLASS
#define SCIRE_ClassName_CLASS

  /**
  */
  template <typename type>
  class Actor
  {
   protected:
    type id;
    vector<type> rank;
    size_t n;

   public:
    Actor(type id, size_t size)
      :id(id), n(size)
    {}

    Actor(type id, const vevtor<type>& ranklist)
      : id(id), rank(ranklist), n(ranklist.size())
    {}

    type Id() const
    {
      return id;
    }

    type Preference(size_t index) const
    {
      return rank[index];
    }

    bool SetRanklist(const vevtor<type>& ranklist)
    {
      if (ranklist.size() != n) return false;
      rank = ranklist;
      return true;
    }

    void AddToRanklist(const type& val)
    {
      rank.p
    }
  };



#endif//SCIRE_ClassName_CLASS
}
#endif//SCIRE_graph_stable_matching_HPP
