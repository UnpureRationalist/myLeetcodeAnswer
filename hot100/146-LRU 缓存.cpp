#include <list>
#include <unordered_map>
#include <utility>
using namespace std;

class LRUCache {
 public:
  LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    if (mp_.find(key) == mp_.end()) {
      return -1;
    }
    int value = update(key);
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
    const auto& [key, value] = container_.back();
    mp_.erase(key);
    container_.pop_back();
  }

  void update(int key, int value) {
    auto iter = mp_[key];
    container_.erase(iter);
    container_.emplace_front(key, value);
    mp_[key] = container_.begin();
  }

  int update(int key) {
    auto iter = mp_[key];
    int old_value = iter->second;
    container_.erase(iter);
    container_.emplace_front(key, old_value);
    mp_[key] = container_.begin();
    return old_value;
  }

  int capacity_;
  list<pair<int, int>> container_;  // store keys & values
  unordered_map<int, list<pair<int, int>>::iterator> mp_;  // <key, iterator>
};

class LRUCache {
  struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value)
        : key(_key), value(_value), prev(nullptr), next(nullptr) {}
  };

 private:
  unordered_map<int, DLinkedNode*> cache;
  DLinkedNode* head;
  DLinkedNode* tail;
  int size;
  int capacity;

 public:
  LRUCache(int _capacity) : capacity(_capacity), size(0) {
    // 使用伪头部和伪尾部节点
    head = new DLinkedNode();
    tail = new DLinkedNode();
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (!cache.count(key)) {
      return -1;
    }
    // 如果 key 存在，先通过哈希表定位，再移到头部
    DLinkedNode* node = cache[key];
    moveToHead(node);
    return node->value;
  }

  void put(int key, int value) {
    if (!cache.count(key)) {
      // 如果 key 不存在，创建一个新的节点
      DLinkedNode* node = new DLinkedNode(key, value);
      // 添加进哈希表
      cache[key] = node;
      // 添加至双向链表的头部
      addToHead(node);
      ++size;
      if (size > capacity) {
        // 如果超出容量，删除双向链表的尾部节点
        DLinkedNode* removed = removeTail();
        // 删除哈希表中对应的项
        cache.erase(removed->key);
        // 防止内存泄漏
        delete removed;
        --size;
      }
    } else {
      // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
      DLinkedNode* node = cache[key];
      node->value = value;
      moveToHead(node);
    }
  }

  void addToHead(DLinkedNode* node) {
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
  }

  void removeNode(DLinkedNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void moveToHead(DLinkedNode* node) {
    removeNode(node);
    addToHead(node);
  }

  DLinkedNode* removeTail() {
    DLinkedNode* node = tail->prev;
    removeNode(node);
    return node;
  }
};
