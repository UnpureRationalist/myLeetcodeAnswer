#include <cstdio>
#include <cstring>
#include <iostream>

#define SWAP (1)

class CMyString {
 public:
  CMyString(const char *pData = nullptr) { deepCopy(pData); }

  CMyString(const CMyString &str) { deepCopy(str.m_pData); }

// 最简单（经典）的实现，可能出现内存不够抛出异常的问题
#if !SWAP
  CMyString &operator=(const CMyString &other) {
    if (this != &other) {
      releaseMemory();
      deepCopy(other.m_pData);
    }
    return *this;
  }
#endif

  friend void swap(CMyString &lop, CMyString &rop) noexcept;

// 基于临时变量和 swap 的方法（推荐，保证了异常安全性）
#if SWAP
  CMyString &operator=(const CMyString &other) {
    if (this != &other) {
      CMyString temp(other);  // 拷贝构造临时对象
      swap(*this, temp);      // 交换
      // 作用域结束后 temp 对象自动析构并释放内存
    }
    return *this;
  }
#endif

  void Print() const { printf("%s", m_pData); }

  ~CMyString() { releaseMemory(); }

 private:
  void deepCopy(const char *src) {
    if (src == nullptr) {
      m_pData = new char[1];
      m_pData[0] = '\0';
    } else {
      m_pData = new char[strlen(src) + 1];
      strcpy(m_pData, src);
    }
  }

  void releaseMemory() {
    delete[] m_pData;
    m_pData = nullptr;
  }

  char *m_pData{nullptr};
};

void swap(CMyString &lop, CMyString &rop) noexcept {
  if (&lop != &rop) {
    char *temp = rop.m_pData;
    rop.m_pData = lop.m_pData;
    lop.m_pData = temp;
  }
}

// ====================测试代码====================
void Test1() {
  printf("Test1 begins:\n");

  const char *text = "Hello world";

  CMyString str1(text);
  CMyString str2;
  str2 = str1;

  printf("The expected result is: %s.\n", text);

  printf("The actual result is: ");
  str2.Print();
  printf(".\n");
}

// 赋值给自己
void Test2() {
  printf("Test2 begins:\n");

  const char *text = "Hello world";

  CMyString str1(text);
  str1 = str1;

  printf("The expected result is: %s.\n", text);

  printf("The actual result is: ");
  str1.Print();
  printf(".\n");
}

// 连续赋值
void Test3() {
  printf("Test3 begins:\n");

  const char *text = "Hello world";

  CMyString str1(text);
  CMyString str2, str3;
  str3 = str2 = str1;

  printf("The expected result is: %s.\n", text);

  printf("The actual result is: ");
  str2.Print();
  printf(".\n");

  printf("The expected result is: %s.\n", text);

  printf("The actual result is: ");
  str3.Print();
  printf(".\n");
}

int main(int argc, char *argv[]) {
  Test1();
  Test2();
  Test3();

  return 0;
}
