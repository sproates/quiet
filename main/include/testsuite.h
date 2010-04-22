#ifndef _QUIET_TESTSUITE_H
#define _QUIET_TESTSUITE_H

/**
 * Tests whether an expression throws a particular type of exception.
 */

#define ASSERT_THROWS(expression, exceptionType, message) {                    \
  bool wasThrown = false;                                                      \
  try {                                                                        \
    (expression);                                                              \
  } catch(exceptionType&) {                                                    \
    wasThrown = true;                                                          \
  } catch(...) {}                                                              \
  __quiet_throws(wasThrown, message, __FILE__, __LINE__);                      \
}

/**
 * Tests whether an expression evaluates as true.
 */

#define ASSERT_TRUE(expression, message) {                                     \
  __quiet_assert(expression, message, __FILE__, __LINE__);                     \
}

/**
 * Tests whether an expression evaluates as false.
 */

#define ASSERT_FALSE(expression, message) {                                    \
  ASSERT_TRUE(!(expression), message);                                         \
}

/**
 * Tests whether two expressions evaluate as equal.
 */

#define ASSERT_EQUALS(a, b, message) {                                         \
  ASSERT_TRUE((a == b), message);                                              \
}

namespace quiet {

  class TestSuite {

    public:

      TestSuite();
      virtual ~TestSuite();

      virtual void run() = 0;

      int getTestCount();
      int getFailCount();
      int getPassCount();

    protected:

      virtual void startup() = 0;
      virtual void teardown() = 0;

      void __quiet_throws(bool thrown, const char * message,
        const char * file, int line);

      void __quiet_assert(bool condition, const char * message,
                          const char * file, int line);

    private:

      int testCount;
      int failCount;
      int passCount;

      TestSuite(const TestSuite & s);
      TestSuite & operator = (const TestSuite & s);
  };
}

#endif
