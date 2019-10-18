#include "AbstractFactory.hpp"
#include <iostream>
int main() {
  peking::Application app;
  peking::FactoryA fa;
  auto app_res = app.Create(fa);
  std::cout << app_res->Name() << std::endl;
  return 0;
}