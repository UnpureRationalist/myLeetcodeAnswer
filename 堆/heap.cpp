#include <bits/stdc++.h>
using namespace std;

class Heap {
 public:
  Heap() : heap(1, -1) {}

  explicit Heap(const vector<int> &arr) {
    // 从下标 1 开始存储元素
    int n = arr.size();
    heap.resize(n + 1);
    std::copy(arr.begin(), arr.end(), heap.begin() + 1);
    // 建堆 时间复杂度 O(n)
    for (int i = n / 2; i >= 1; --i) {
      downAdjust(i, n);
    }
  }

  int Top() { return heap[1]; }

  // 删除堆顶元素 时间复杂度 O(logn)
  void Pop() {
    heap[1] = heap.back();
    heap.pop_back();
    downAdjust(1, Size());
  }

  // 添加元素并调整堆结构 时间复杂度 O(logn)
  void Push(int elem) {
    heap.push_back(elem);
    upAdjust(1, Size());
  }

  int Size() { return heap.size() - 1; }

  bool Empty() { return Size() == 0; }

 private:
  // 对 heap 数组的 [low, high] 范围进行向下调整
  void downAdjust(int low, int high) {
    int cur = low, child = 2 * cur;
    while (child <= high) {
      if (child + 1 <= high && heap[child + 1] > heap[child]) {
        child = child + 1;  // 右孩子存在且值更大
      }
      if (heap[child] > heap[cur]) {
        swap(heap[child], heap[cur]);
        cur = child;      // 向下走
        child = 2 * cur;  // 更新孩子节点
      } else {
        break;
      }
    }
  }

  // 向上调整元素
  void upAdjust(int low, int high) {
    int cur = high;
    int parent = cur / 2;
    while (parent >= low) {
      if (heap[cur] > heap[parent]) {
        swap(heap[cur], heap[parent]);
        cur = parent;
        parent = cur / 2;
      } else {
        break;
      }
    }
  }

  vector<int> heap;
};

void Test1() {
  vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 5, 4, 2, 1};
  Heap heap(arr);

  priority_queue<int> q;
  for (const auto &elem : arr) {
    q.emplace(elem);
  }
  bool pass = true;
  while (!q.empty()) {
    int target = q.top();
    q.pop();
    int real = heap.Top();
    heap.Pop();
    if (real != target) {
      pass = false;
      cout << "real = " << real << " expected = " << target << endl;
    }
  }
  if (pass) {
    cout << "Heap pop test passed!" << endl;
  } else {
    cout << "Heap pop test failed!" << endl;
  }
}

void Test2() {
  vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 5, 4, 2, 1, 0, 2, 3, 3, 12, 23, 43, 2};
  Heap heap;

  bool pass = true;
  priority_queue<int> q;

  for (const auto &elem : arr) {
    q.push(elem);
    heap.Push(elem);
    if (q.top() != heap.Top()) {
      pass = false;
      cout << "Error: real = " << heap.Top() << " expected = " << q.top() << endl;
    }
  }

  if (pass) {
    cout << "Heap push test passed!" << endl;
  } else {
    cout << "Heap push test failed!" << endl;
  }

  pass = true;
  while (!q.empty()) {
    int target = q.top();
    q.pop();
    int real = heap.Top();
    heap.Pop();
    if (real != target) {
      pass = false;
      cout << "Error: real = " << real << " expected = " << target << endl;
    }
  }

  if (pass) {
    cout << "Heap pop test passed!" << endl;
  } else {
    cout << "Heap pop test failed!" << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  Test1();
  Test2();
  return 0;
}
