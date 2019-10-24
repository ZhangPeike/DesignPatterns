#include "Factory.hpp"
#include <iostream>
int main() {
  peking::Creator factory;
  factory.Create(peking::ProductID::Cellphone);
  return 0;
}