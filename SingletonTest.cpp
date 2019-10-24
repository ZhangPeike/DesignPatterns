#include "Singleton.hpp"
#include <iostream>
int main() {
  // peking::Singleton::Ptr instance = peking::Singleton::Instance();
  // auto instance_cp = peking::Singleton::Instance();
  // why core dump?
  peking::MySingleton my;
  return 0;
}