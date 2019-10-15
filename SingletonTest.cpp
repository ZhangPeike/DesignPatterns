#include "Singleton.hpp"
#include <iostream>
int main() {
  peking::Config::Ptr instance = peking::Config::GetConfig();
  auto instance_cp = peking::Config::GetConfig();
  return 0;
}