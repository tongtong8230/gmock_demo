#include <iostream>
#include <string>

class Math {
 public:
  virtual int Add(int x, int y) { return x + y; }
};

class SonarServer {
 public:
  SonarServer(Math* math) : math_(math) {}
  bool ReadSerial(std::string* serial);

 private:
  Math* math_;
};
