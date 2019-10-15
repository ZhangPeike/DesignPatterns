#include <iostream>
#include <memory>
namespace peking {
class Config {

public:
  using Ptr = std::shared_ptr<Config>;

private:
  Config() {}

private:
  static Ptr ptr_config_b_;

public:
  // lazy or hungry
  // volatile
  static Ptr GetConfig() {
    if (ptr_config_b_.get() == nullptr) {
      ptr_config_b_ = Ptr(new Config());
      std::cout << "Created ";
    }
    std::cout<<ptr_config_b_.use_count()<<std::endl;
    return ptr_config_b_;
  }
};
Config::Ptr Config::ptr_config_b_ = nullptr;
} // namespace peking
