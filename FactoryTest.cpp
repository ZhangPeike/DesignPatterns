#include "Factory.hpp"
#include <iostream>
int main() {
  peking::Creator factory;
  auto pro = factory.Create(peking::ProductID::Cellphone);
  std::cout << "Product name: " << pro->Name() << std::endl;
  peking::StandardCreator<peking::ConcreteProduct> std_creator;
  std::cout << "StandardCreator makes " << std_creator.Create()->Name() << std::endl;
  return 0;
}