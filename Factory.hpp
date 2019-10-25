#ifndef __ABSTRACTFACTORY__
#define __ABSTRACTFACTORY__
#include <memory>
#include <string>
namespace peking {
enum class ProductID { Laptop, Cellphone, Camera };
class Product {
public:
  Product() {}
  Product(const std::string &name) : name_(name) {}
  std::string Name() { return name_; }

private:
  std::string name_;
};
class ConcreteProduct : public Product {
public:
  ConcreteProduct(const std::string &name) : Product(name) {}
};
class Creator {
public:
  virtual Product *Create(ProductID id);

protected:
};
Product *Creator::Create(ProductID id) {
  switch (id) {
  case ProductID::Laptop:
    return new ConcreteProduct("Laptop");
    break;
  case ProductID::Cellphone:
    return new ConcreteProduct("Cellphone");
    break;
  case ProductID::Camera:
    return new ConcreteProduct("Camera");
    break;
  default:
    return new Product("Meta");
    break;
  }
}
template <typename OneProduct> class StandardCreator : public Creator {
public:
  Product *Create() {
    return new OneProduct("one");
  }
};
} // namespace peking
#endif