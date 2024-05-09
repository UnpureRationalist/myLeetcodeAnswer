#include <bits/stdc++.h>
using namespace std;

// 对 heap 数组的 [low, high] 范围进行向下调整
void downAdjust(int *heap, int low, int high) {
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

void createHeap(int *heap, int n) {
  for (int i = n / 2; i >= 1; --i) {
    downAdjust(heap, i, n);
  }
}

void heap_sort(int *arr, int n) {
  int *heap = arr - 1;
  createHeap(heap, n);
  for (int i = n; i > 1; --i) {
    swap(heap[i], heap[1]);
    downAdjust(heap, 1, i - 1);
  }
}

void Test1() {
  int arr[] = {-1, 2, 32, 43, 123, 340, -12, -34, 0, 12, 12, 12, 0, -1, -1, 12};
  int n = sizeof(arr) / sizeof(int);
  heap_sort(arr, n);
  for (auto &elem : arr) {
    cout << elem << " ";
  }
  cout << endl;
  cout << "is_sorted: " << is_sorted(arr, arr + n) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  Test1();
  return 0;
}
