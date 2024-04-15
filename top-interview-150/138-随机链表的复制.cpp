#include "header.h"

class Solution {
 public:
  Node *copyRandomList(Node *head) {
    Node temp{0};
    Node *current = &temp;
    unordered_map<Node *, Node *> hash;
    hash[nullptr] = nullptr;
    Node *old = head;
    while (old) {
      current->next = new Node(old->val);
      hash[old] = current->next;
      current = current->next;
      old = old->next;
    }
    old = head;
    current = temp.next;
    while (current) {
      current->random = hash[old->random];
      current = current->next;
      old = old->next;
    }
    return temp.next;
  }
};
