#ifndef __ABSTRACTFACTORY__
#define __ABSTRACTFACTORY__
#include <memory>
#include <string>
namespace peking {
class AbstractProduct {
public:
  using ProductPtr = std::shared_ptr<AbstractProduct>;
  AbstractProduct(const std::string &name) : name_(name) {}
  std::string Name() { return name_; }

private:
  std::string name_;
};
class ProductA : public AbstractProduct {
public:
  ProductA() : AbstractProduct("A") {}
};
class AbstractFactory {
public:
  virtual AbstractProduct::ProductPtr Make() { return AbstractProduct::ProductPtr(); }
};
class FactoryA : public AbstractFactory {
public:
  virtual AbstractProduct::ProductPtr Make() {
    return AbstractProduct::ProductPtr(new ProductA());
  }
};
class Application {
public:
  AbstractProduct::ProductPtr Create(AbstractFactory& factory) {
    return factory.Make();
  }
};
} // namespace peking
#endif