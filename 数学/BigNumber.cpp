#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BigNumber {
 public:
  explicit BigNumber() = default;

  explicit BigNumber(const string &s) {
    int n = s.length();
    digits.resize(n, 0);
    for (int i = n - 1; i >= 0; --i) {
      digits[n - 1 - i] = s[i] - '0';
    }
  }

  BigNumber add(const BigNumber &rop) {
    BigNumber result;
    int n1 = this->digits.size();
    int n2 = rop.digits.size();
    int carry = 0;
    int i = 0;
    for (; i < n1 && i < n2; ++i) {
      int temp = this->digits[i] + rop.digits[i] + carry;
      result.digits.push_back(temp % 10);
      carry = temp / 10;
    }
    for (; i < n1; ++i) {
      int temp = this->digits[i] + carry;
      result.digits.push_back(temp % 10);
      carry = temp / 10;
    }
    for (; i < n2; ++i) {
      int temp = rop.digits[i] + carry;
      result.digits.push_back(temp % 10);
      carry = temp / 10;
    }
    if (carry) {
      result.digits.push_back(carry);
    }
    return result;
  }

  // 必须保证 *this 大于 rop
  BigNumber sub(const BigNumber &rop) {
    BigNumber lop = *this;
    BigNumber result;
    int n1 = lop.digits.size();
    int n2 = rop.digits.size();
    for (int i = 0; i < n1; ++i) {
      if (lop.digits[i] < rop.digits[i]) {
        lop.digits[i + 1]--;
        lop.digits[i] += 10;
      }
      int right = 0;
      if (i < n2) {
        right = rop.digits[i];
      }
      result.digits.push_back(lop.digits[i] - right);
    }
    while (result.digits.size() >= 2 && result.digits.back() == 0) {
      result.digits.pop_back();
    }
    return result;
  }

  string to_string() const {
    int n = this->digits.size();
    string result(n, '0');
    for (int i = 0; i < n; ++i) {
      result[i] = digits[n - 1 - i] + '0';
    }
    return result;
  }

  void show() const {
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i) {
      cout << digits[i];
    }
    cout << "\n";
  }

 private:
  vector<int> digits;
};

void Test1() {
  string s1 = "129813456";
  string s2 = "129813456";
  BigNumber n1(s1);
  BigNumber n2(s2);
  n1.show();
  n2.show();

  BigNumber n3 = n1.add(n2);
  BigNumber n4 = n2.add(n1);
  n3.show();
  n4.show();

  int target = stoi(s1) + stoi(s2);

  cout << (target == stoi(n3.to_string())) << endl;
  cout << (target == stoi(n4.to_string())) << endl;

  // 减法
  BigNumber n5 = n2.sub(n1);
  n5.show();
  target = stoi(s2) - stoi(s1);
  cout << (target == stoi(n5.to_string())) << endl;
}

int main() {
  Test1();
  return 0;
}
