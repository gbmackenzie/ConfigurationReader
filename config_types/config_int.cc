#include "config_int.h"

ConfigInt::ConfigInt(string key_name) {
  key_ = key_name;
  val_ = 0;
  upper_bound_ = 0;
  lower_bound_ = 0;
  type_ = ConfigInterface::cint;
}

ConfigInt::ConfigInt(string key_name, int upper_bound, int lower_bound) {
  key_ = key_name;
  val_ = 0;
  upper_bound_ = upper_bound;
  lower_bound_ = lower_bound;
  type_ = ConfigInterface::cint;
}

int& ConfigInt::GetVal() {
  int& i = val_;
  return i;
}

bool ConfigInt::SetVal(LuaScript* script) {
  int value = script->get<int>(key_);
  if (upper_bound_ != 0 && lower_bound_ != 0) {  // If the bounds exist
    if (value <= lower_bound_ &&
        value >= upper_bound_) {  // Check the value against them
      val_ = value;
      return true;
    } else {
      std::cout << "Value was not between (or equal to) the bounds. Blowing up."
                << std::endl;
      return false;
    }
  } else {  // There are no bounds, set the value
    val_ = value;
    return true;
  }
}
