#include "header.h"

// 空间复杂度 O(n) 时间复杂度 O(n)
class Solution {
 public:
  Node *copyRandomList(Node *head) {
    unordered_map<Node *, Node *> mp;
    mp[nullptr] = nullptr;
    Node dummyHead{-1};
    Node *oldHead = head;
    Node *pre = &dummyHead;
    Node *cur;
    while (head) {
      cur = new Node(head->val);
      mp[head] = cur;
      pre->next = cur;
      pre = cur;
      head = head->next;
    }
    Node *nHead = dummyHead.next;
    while (nHead) {
      nHead->random = mp[oldHead->random];
      nHead = nHead->next;
      oldHead = oldHead->next;
    }
    return dummyHead.next;
  }
};

// 空间复杂度 O(1) 时间复杂度 O(n)
class Solution {
  // 拷贝原始链表节点 N 为 N' ； N 的 next 指针指向 N'
  void cloneNodesInNext(Node *head) {
    Node *cur = head;
    while (cur) {
      Node *cloned = new Node(cur->val);  // N'
      cloned->next = cur->next;
      cur->next = cloned;  // N' 插入到原来节点 N 的后面
      cur = cloned->next;
    }
  }

  // 给 random 指针赋值
  void connextRandomNodes(Node *head) {
    Node *cur = head;
    while (cur) {
      Node *cloned = cur->next;  // N' 节点
      if (cur->random) {
        cloned->random = cur->random->next;  // 给 N' 的 random 指针赋值
      }
      cur = cloned->next;
    }
  }

  // 将合并的链表分为两个，返回拷贝链表的头指针
  Node *splitNodes(Node *head) {
    Node *cur = head;
    Node *clonedHead = nullptr;
    Node *clonedNode = nullptr;
    if (cur) {  // head 非空，给 clonedHead 和 clonedNode 赋值
      clonedHead = cur->next;
      clonedNode = cur->next;
      cur->next = clonedNode->next;
      cur = cur->next;  // cur 现在指向原链表的第 2 个节点
    }
    while (cur) {
      clonedNode->next = cur->next;
      clonedNode = clonedNode->next;
      cur->next = clonedNode->next;
      cur = cur->next;
    }
    return clonedHead;
  }

 public:
  Node *copyRandomList(Node *head) {
    cloneNodesInNext(head);
    connextRandomNodes(head);
    return splitNodes(head);
  }
};
