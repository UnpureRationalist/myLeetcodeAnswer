class Node {
 public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

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
  void connectRandomNodes(Node *head) {
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
    connectRandomNodes(head);
    return splitNodes(head);
  }
};
