#include "Singleton.hpp"
#include <iostream>
int main() {
  std::string name = "hello world";
  // peking::Singleton::Ptr instance = peking::Singleton::Instance();
  auto instance_cp = peking::Singleton::Instance();
  // why core dump?
  // static peking::MySingleton my;
  return 0;
}