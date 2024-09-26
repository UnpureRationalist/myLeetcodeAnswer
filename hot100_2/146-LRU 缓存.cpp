#include <bits/stdc++.h>
using namespace std;

class LRUCache {
 public:
  explicit LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    auto iter = mp_.find(key);
    if (iter == mp_.end()) {
      return -1;
    }
    int value = update(iter->second);
    return value;
  }

  void put(int key, int value) {
    if (mp_.find(key) != mp_.end()) {  // the key already exists
      update(key, value);
    } else {
      if (container_.size() >= capacity_) {
        removeLastElement();
      }
      insert(key, value);
    }
  }

 private:
  void insert(int key, int value) {
    container_.emplace_front(key, value);  // 最近访问的在 list 最前面
    mp_[key] = container_.begin();
  }

  void removeLastElement() {
    const auto &[key, value] = container_.back();
    mp_.erase(key);
    container_.pop_back();
  }

  void update(int key, int value) {
    auto iter = mp_[key];
    container_.erase(iter);
    container_.emplace_front(key, value);
    mp_[key] = container_.begin();
  }

  int update(list<pair<int, int>>::iterator iter) {
    int key = iter->first;
    int value = iter->second;
    container_.erase(iter);
    container_.emplace_front(key, value);
    mp_[key] = container_.begin();
    return value;
  }

  int capacity_;
  list<pair<int, int>> container_;                         // store keys & values
  unordered_map<int, list<pair<int, int>>::iterator> mp_;  // <key, iterator>
};
