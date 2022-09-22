#include "sonar.h"
#include <iostream>

bool SonarServer::ReadSerial(std::string *serial) {
  int ret = math_->Add(2, 3);
  *serial = std::to_string(ret);
  return true;
}
