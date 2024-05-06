#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void merge(int *arr, int left, int mid, int right, int *temp) {
  int left1 = left;
  int right1 = mid;
  int left2 = mid + 1;
  int right2 = right;
  int idx = 0;
  while (left1 <= right1 && left2 <= right2) {
    if (arr[left1] <= arr[left2]) {
      temp[left + idx++] = arr[left1++];
    } else {
      temp[left + idx++] = arr[left2++];
    }
  }
  while (left1 <= right1) {
    temp[left + idx++] = arr[left1++];
  }
  while (left2 <= right2) {
    temp[left + idx++] = arr[left2++];
  }
  // copy to arr
  while (left <= right) {
    arr[left] = temp[left];
    ++left;
  }
}

void merge_sort(int *arr, int left, int right, int *temp) {
  if (left >= right) {
    return;
  }
  int mid = left + (right - left) / 2;
  merge_sort(arr, left, mid, temp);
  merge_sort(arr, mid + 1, right, temp);
  merge(arr, left, mid, right, temp);
}

void merge_sort(int *arr, int n) {
  int *temp = new int(n);
  merge_sort(arr, 0, n - 1, temp);
  delete[] temp;
}

void Test1() {
  int arr[] = {-1, 2, 32, 43, 123, 340, -12, -34, 0, 12, 12, 12, 0, -1, -1, 12};
  int n = sizeof(arr) / sizeof(int);
  merge_sort(arr, n);
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
