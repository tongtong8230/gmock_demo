#include <iostream>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "sonar.h"

// class LogSink {
//  public:
//   virtual void send(int severity, const char* full_filename,
//                     const char* base_filename, int line,
//                     const struct tm* tm_time, const char* message,
//                     size_t message_len) {
//     return;
//   }
// };
// class ScopedMockLog : public LogSink {
//  public:
//   void send(int severity, const char* full_filename, const char*
//   base_filename,
//             int line, const tm* tm_time, const char* message,
//             size_t message_len) {
//     // We are only interested in the log severity, full file name, and
//     // log message.
//     Log(severity, full_filename, message);
//   }

//   // Implements the mock method:
//   //
//   //   void Log(int severity,
//   //            const string& file_path,
//   //            const string& message);
//   MOCK_METHOD3(Log, void(int severity, const std::string& file_path,
//                          const std::string& message));
// };

// class MockSonar{
//  public:
//   MOCK_METHOD1(ReadSerial, bool(std::string *serial));
// };

class MockMath : public Math {
 public:
  MOCK_METHOD2(Add, int(int, int));
};

TEST(Sonar, ReadSerial) {
  // MockSonar *mock_sonar = new MockSonar;
  // EXPECT_CALL(*mock_sonar, ReadSerial)
  //     .WillRepeatedly(::testing::Return(false));  // expect always return 11.
  std::string content;
  // EXPECT_EQ(mock_sonar->ReadSerial(&content), false);
  // delete mock_sonar;
  MockMath mock_math;
  EXPECT_CALL(mock_math, Add)
      .Times(1)
      .WillRepeatedly(::testing::Return(1000));

  SonarServer sonar_server(&mock_math);
  auto ret = sonar_server.ReadSerial(&content);
  std::cout << "ret = " << content << std::endl;

}
