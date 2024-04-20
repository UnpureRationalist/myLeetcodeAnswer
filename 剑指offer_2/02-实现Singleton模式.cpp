#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

// 单线程
class Singleton1 {
 private:
  Singleton1() = default;

  static Singleton1 *instance;

 public:
  static Singleton1 *Instance();
};

Singleton1 *Singleton1::instance = nullptr;

Singleton1 *Singleton1::Instance() {
  if (instance == nullptr) {
    std::cout << "Init Singleton1\n";
    instance = new Singleton1();
  }
  return instance;
}

// 多线程安全+锁
class Singleton2 {
 private:
  Singleton2() = default;

  static Singleton2 *instance;
  static std::mutex mtx;

 public:
  static Singleton2 *Instance();
};

Singleton2 *Singleton2::instance = nullptr;
std::mutex Singleton2::mtx{};

Singleton2 *Singleton2::Instance() {
  std::lock_guard lock(mtx);
  if (instance == nullptr) {
    std::cout << "Init Singleton2\n";
    instance = new Singleton2();
  }
  return instance;
}

// 多线程安全+call_once
class Singleton3 {
 private:
  Singleton3() = default;

  static Singleton3 *instance;
  static std::once_flag init_flag;

  static void Init();

 public:
  static Singleton3 *Instance();
};

Singleton3 *Singleton3::instance = nullptr;
std::once_flag Singleton3::init_flag{};

void Singleton3::Init() {
  std::cout << "Init Singleton3\n";
  instance = new Singleton3();
}

Singleton3 *Singleton3::Instance() {
  std::call_once(Singleton3::init_flag, Singleton3::Init);
  return instance;
}

int main() {
  std::vector<std::thread> threads;
  int num_threads = 20;
  for (int i = 0; i < num_threads; ++i) {
    threads.emplace_back(std::thread([thread_id = i]() {
      int mod = thread_id % 3;
      switch (mod) {
        case 0:
          Singleton1::Instance();
          break;
        case 1:
          Singleton2::Instance();
          break;
        case 2:
          Singleton3::Instance();
          break;
        default:
          break;
      }
    }));
  }
  for (auto &t : threads) {
    t.join();
  }
  return 0;
}
