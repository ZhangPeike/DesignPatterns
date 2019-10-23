#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
namespace peking {
class Singleton {

public:
  using Ptr = std::shared_ptr<Singleton>;
  using Registry = std::unordered_map<std::string, Ptr>;
  static void Register(const std::string &name, const Ptr ptr) {
    auto iter = registry_.find(name);
    if (iter != registry_.end()) {
      std::cout << "Already registered: " << name << std::endl;
      return;
    } else {
      // magic &
      registry_.insert(std::make_pair<const std::string &, const Ptr &>(name, ptr));
      // registry_.insert({name, ptr});
    }
  }

protected:
  Singleton() { std::cout << "Base Singleton" << std::endl; }
  static Ptr LookUp(const std::string &name) {
    auto iter = registry_.find(name);
    if (iter == registry_.end()) {
      std::cout << "Type " << name << " is not registerd." << std::endl;
      return ptr_;
    } else {
      return iter->second;
    }
  }

private:
  static Ptr ptr_;
  // for looking up, hash is considered first.
  static Registry registry_;

public:
  // lazy or hungry
  // volatile
  static Ptr Instance() {
    if (ptr_.get() == nullptr) {
      auto c_name = getenv("HOME");
      const std::string name(c_name);
      std::cout << name << std::endl;
      ptr_ = LookUp(name);
      if (ptr_.get() == nullptr) {
        ptr_ = Ptr(new Singleton());
      }
      std::cout << "Created ";
    }
    std::cout << ptr_.use_count() << std::endl;
    return ptr_;
  }
};
Singleton::Ptr Singleton::ptr_ = nullptr;
Singleton::Registry Singleton::registry_ = Registry();
class MySingleton : public Singleton {
public:
  MySingleton() : Singleton() {
    std::cout << "My dream" << std::endl;
    Singleton::Register("Safer Car", Singleton::Ptr(this));
  }
};
} // namespace peking
#endif