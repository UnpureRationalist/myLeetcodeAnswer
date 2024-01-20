#include <queue>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* nex) : val(x), next(nex) {}
};

class Solution {
  bool over(vector<ListNode*>& lists) {
    for (const auto& elem : lists) {
      if (elem != nullptr) {
        return false;
      }
    }
    return true;
  }
  int minElement(vector<ListNode*>& lists) {
    int n = lists.size();
    if (n == 0) {
      return -1;
    }
    int idx = -1;
    int min_value;
    for (int i = 0; i < n; ++i) {
      if (lists[i]) {
        if (idx == -1) {
          idx = i;
          min_value = lists[i]->val;
        } else {
          if (lists[i]->val < min_value) {
            idx = i;
            min_value = lists[i]->val;
          }
        }
      }
    }
    return idx;
  }

 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode node{0};
    ListNode* p = &node;
    while (!over(lists)) {
      int idx = minElement(lists);
      p->next = lists[idx];
      lists[idx] = lists[idx]->next;
      p = p->next;
    }
    return node.next;
  }
};

class Solution2 {
 public:
  ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    if ((!a) || (!b)) return a ? a : b;
    ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
    while (aPtr && bPtr) {
      if (aPtr->val < bPtr->val) {
        tail->next = aPtr;
        aPtr = aPtr->next;
      } else {
        tail->next = bPtr;
        bPtr = bPtr->next;
      }
      tail = tail->next;
    }
    tail->next = (aPtr ? aPtr : bPtr);
    return head.next;
  }

  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* ans = nullptr;
    for (size_t i = 0; i < lists.size(); ++i) {
      ans = mergeTwoLists(ans, lists[i]);
    }
    return ans;
  }
};

class Solution3 {
  struct Comp {
    bool operator()(ListNode* lhs, ListNode* rhs) const {
      return lhs->val > rhs->val;
    }
  };

 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Comp> q;
    for (auto node : lists) {
      if (node) {
        q.push(node);
      }
    }
    ListNode head, *tail = &head;
    while (!q.empty()) {
      ListNode* ptr = q.top();
      q.pop();
      tail->next = ptr;
      tail = tail->next;
      if (ptr->next) {
        q.push(ptr->next);
      }
    }
    return head.next;
  }
};
