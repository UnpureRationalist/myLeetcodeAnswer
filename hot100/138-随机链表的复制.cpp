#include <unordered_map>
using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    Node node{0};
    int count = 0;
    // unordered_map<Node*, int> ptr2idx;  // 原链表的 <node*, index> 映射
    // unordered_map<int, Node*> idx2ptr;  // 新链表的 <index, node*> 映射
    // 则 idx2ptr[ptr2idx[node->random]] 可获得新链表对应 random 指针
    // 进一步合并为：
    unordered_map<Node*, Node*> mp(100);
    // 首先进行 new
    Node* p = head;
    Node* pre = &node;
    while (p) {
      Node* new_node = new Node(p->val);
      mp[p] = new_node;
      pre->next = new_node;
      pre = new_node;
      p = p->next;
      count++;
    }
    // 更新 random 指针
    p = head;
    Node* p2 = node.next;
    while (p) {
      if (p->random == nullptr) {
        p2->random = nullptr;
      } else {
        p2->random = mp[p->random];
      }
      p = p->next;
      p2 = p2->next;
    }
    return node.next;
  }
};