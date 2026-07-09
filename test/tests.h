#ifndef TESTS_H
#define TESTS_H

#include <stdbool.h>
#include <stdlib.h>

typedef bool (*TestFunc)(void);

typedef struct TestCase {
  const char* name;
  TestFunc fn;
} TestCase;

#define ASSERT_TRUE(cond) \
  do {                    \
    if (!(cond)) {          \
      printf("FAILED: %s:%d %s\n", \
          __FILE__, __LINE__, #cond);  \
      return false;                   \
    }                           \
  } while (0)

void run_tests(TestCase tests[], size_t count);

#endif
