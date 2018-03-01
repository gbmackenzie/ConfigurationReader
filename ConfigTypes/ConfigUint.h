#ifndef CONFIGREADER_CONFIGTYPES_CONFIGUINT_H_
#define CONFIGREADER_CONFIGTYPES_CONFIGUINT_H_

#include "ConfigInterface.h"

class ConfigUint : public ConfigInterface {
 public:
  ConfigUint(string key_name);
  ConfigUint(string key_name, unsigned int upper_bound,
             unsigned int lower_bound);
  const unsigned int& getVal();
  bool setVal(LuaScript* script);

 protected:
  unsigned int u_bound;
  unsigned int l_bound;
  unsigned int val;
};

#endif
