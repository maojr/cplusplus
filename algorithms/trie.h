// Simple trie data structure using STL.Based on code by Vivek Narayanan.
// - rlyeh, 2013-2015 zlib/libpng licensed ~~ listening to Baroness / March to
// the Sea.

#pragma once
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

template <typename K, typename V = int>
class trie {
 public:
  trie() : end(false) {}

  bool has(const K &collection) const {
    for (const auto &it : children) {
      if (it.second.has(collection)) {
        return true;
      }
    }
    return end && collection == branch ? true : false;
  }

  void insert(const K &collection) {
    trie *node = this;
    for (auto &c : collection) {
      auto found = node->children.find(c);
      if (found == node->children.end()) {
        auto copy = node->branch;
        std::back_inserter(copy) = c;
        node->children[c] = trie(copy);
      }
      node = &(node->children[c]);
    }
    node->end = true;
  }

  V &operator[](const K &collection) { return insert(collection); }

  std::vector<const K *> list() const {
    std::vector<const K *> results;
    if (end) {
      results.push_back(&branch);
    }
    for (const auto &it : children) {
      auto keys = it.second.list();
      for (const auto &key : keys) {
        results.push_back(key);
      }
    }
    return results;
  }

  std::vector<const K *> complete(const K &prefix) const {
    const trie *node = this;
    for (auto &elem : prefix) {
      const auto found = node->children.find(elem);
      if (found == node->children.end()) {
        return std::vector<const K *>();
      }
      node = &found->second;
    }
    return node->list();
  }

  unsigned size() const { return list().size(); }

  void print() const {
    std::cout << "end: " << end << " branch: " << branch << std::endl;
    for (const auto &it : children) {
      std::cout << it.first << std::endl;
      it.second.print();
    }
  }

 protected:
  trie(const K &branch) : branch(branch), end(false) {}

  K branch;
  bool end;
  std::map<typename K::value_type, trie> children;
};
