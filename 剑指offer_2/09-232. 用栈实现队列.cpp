#include "header.h"

class MyQueue {
 public:
  MyQueue() = default;

  void push(int x) { stk1.emplace(x); }

  int pop() {
    if (stk2.empty()) {
      moveElements();
    }
    int elem = stk2.top();
    stk2.pop();
    return elem;
  }

  int peek() {
    if (stk2.empty()) {
      moveElements();
    }
    return stk2.top();
  }

  bool empty() { return 0 == (stk1.size() + stk2.size()); }

 private:
  void moveElements() {
    while (!stk1.empty()) {
      stk2.emplace(stk1.top());
      stk1.pop();
    }
  }

  stack<int> stk1;
  stack<int> stk2;
};

// 相关题：Leetcode 225. 用队列实现栈
class MyStack {
 public:
  MyStack() = default;

  void push(int x) {
    queue2.push(x);
    while (!queue1.empty()) {
      queue2.push(queue1.front());
      queue1.pop();
    }
    swap(queue1, queue2);
  }

  int pop() {
    int r = queue1.front();
    queue1.pop();
    return r;
  }

  int top() {
    int r = queue1.front();
    return r;
  }

  bool empty() { return queue1.empty(); }

 private:
  queue<int> queue1;
  queue<int> queue2;
};
