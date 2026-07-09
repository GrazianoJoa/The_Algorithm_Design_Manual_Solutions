#include "tests.h"
#include "ds/test_stack.h"

#include "stdio.h"

int main() {
  TestCase tests[] = {
    { "stack_create", test_stack_create },
  };

  run_tests(tests, sizeof(tests) / sizeof(TestCase));
  return 0;
}
