struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *nex) : val(x), next(nex) {}
};

class Solution {
 public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *p1 = list1, *p2 = list2;
    ListNode node;
    ListNode *head = &node;
    while (p1 && p2) {
      if (p1->val < p2->val) {
        head->next = p1;
        p1 = p1->next;
      } else {
        head->next = p2;
        p2 = p2->next;
      }
      head = head->next;
    }
    while (p1) {
      head->next = p1;
      p1 = p1->next;
      head = head->next;
    }
    while (p2) {
      head->next = p2;
      p2 = p2->next;
      head = head->next;
    }
    return node.next;
  }
};