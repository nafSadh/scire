#include <map>
#include <set>

using namespace std;

namespace L33tC0d3
{
  class LRUCache
  {
    std::set<int> tsheap;
    map<int, int> cache;
    map<int, int> ts2key;
    map<int, int> key2ts;
    int cap;
    int ts;
    int count;
   public:
    LRUCache(int capacity)
    {
      cap = capacity;
      ts = 0;
      count = 0;
    }

    int get(int key)
    {
      if (cache.find(key) == cache.end()) return -1;
      ts++;
      //replace last ts of the key with new one
      int lastTs = key2ts[key];
      ts2key.erase(lastTs);
      tsheap.erase(lastTs);
      ts2key[ts] = key;
      tsheap.insert(ts);
      key2ts[key] = ts;
      return cache[key];
    }

    void set(int key, int value)
    {
      ts++;
      bool prexist = (cache.find(key) != cache.end());
      if (count<cap || prexist) {
        if (!prexist)count++;
        int lastTs = key2ts[key];
        ts2key.erase(lastTs);
        tsheap.erase(lastTs);
        ts2key[ts] = key;
        tsheap.insert(ts);
        key2ts[key] = ts;
        cache[key] = value;
      } else {
        int lruts = *(tsheap.begin());
        int evictkey = ts2key[lruts];
        key2ts.erase(evictkey);
        key2ts[key] = ts;
        ts2key.erase(lruts);
        ts2key[ts] = key;
        tsheap.erase(lruts);
        tsheap.insert(ts);
        cache[evictkey] = -1;
        cache.erase(evictkey);
        cache[key] = value;
      }
      return;
    }
  };

}