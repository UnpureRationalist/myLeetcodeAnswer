#include <algorithm>
#include <climits>
#include <cmath>
#include <ctime>
#include <iostream>
#include <list>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *nex) : val(x), next(nex) {}
};

// Definition for a Node.
// class Node {
//  public:
//   int val;
//   Node *next;
//   Node *random;

//   Node(int _val) {
//     val = _val;
//     next = NULL;
//     random = NULL;
//   }
// };

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
