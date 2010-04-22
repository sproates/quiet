#include "testsuite.h"

#include <stdexcept>

class ExampleSuite : public quiet::TestSuite {

  public:

    ExampleSuite() : TestSuite() {
      startup();
    }

    ~ExampleSuite() {
      teardown();
    }

    void startup() {}

    void teardown() {}

    void run() {

      // should always pass

      ASSERT_TRUE(true, "Always true");
      ASSERT_FALSE(false, "Always false");
      ASSERT_EQUALS(0, 0, "Equal values");
      ASSERT_THROWS(alwaysThrow(), std::runtime_error, "Throws correct exception");

      // should always fail
 
      ASSERT_TRUE(false, "Should be true");
      ASSERT_FALSE(true, "Should be false");
      ASSERT_EQUALS(0, 1, "Should be equal");
      ASSERT_THROWS(alwaysThrow(), std::range_error, "Should be a range error");
    }

  private:

    void alwaysThrow() {
      throw std::runtime_error("runtime error");
    }
};

int main() {
  ExampleSuite * s = new ExampleSuite();
  s->run();
  delete s;
  return 0;
}
