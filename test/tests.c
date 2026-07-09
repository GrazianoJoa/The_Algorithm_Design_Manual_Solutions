#include "tests.h"
#include "stdio.h"

void run_tests(TestCase tests[], size_t count) {
  size_t passed = 0; 

  for (size_t i = 0; i < count; i++) {
    printf("[RUN] %s\n", tests[i].name);
    if (tests[i].fn()) {
      printf("[PASS] %s\n", tests[i].name);
      passed++;
    } else {
      printf("[FAILED] %s\n", tests[i].name);
    }

    printf("==================================\n");
    printf("PASSED: %zu\n", passed);
    printf("FAILED: %zu\n", count - passed);
    printf("TOTAL: %zu\n", count);
  }
}
