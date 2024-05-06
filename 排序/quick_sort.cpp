#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int partition(int *arr, int left, int right) {
  int temp = arr[left];
  while (left < right) {
    while (left < right && arr[right] > temp) {
      --right;
    }
    arr[left] = arr[right];
    while (left < right && arr[left] <= temp) {
      ++left;
    }
    arr[right] = arr[left];
  }
  arr[left] = temp;
  return left;
}

void quick_sort(int *arr, int left, int right) {
  if (left >= right) {
    return;
  }
  int idx = partition(arr, left, right);
  quick_sort(arr, left, idx - 1);
  quick_sort(arr, idx + 1, right);
}

void quick_sort(int *arr, int n) { quick_sort(arr, 0, n - 1); }

void Test1() {
  int arr[] = {-1, 2, 32, 43, 123, 340, -12, -34, 0, 12, 12, 12, 0, -1, -1, 12};
  int n = sizeof(arr) / sizeof(int);
  quick_sort(arr, n);
  for (auto &elem : arr) {
    cout << elem << " ";
  }
  cout << endl;
  cout << "is_sorted: " << is_sorted(arr, arr + n) << endl;
}

int main() {
  Test1();
  return 0;
}
