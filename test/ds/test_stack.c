#include "../tests.h"
#include "test_stack.h"
#include "ds/stack.h"

#include "stdio.h"

bool test_stack_create(void) {
  Stack* s = stack_create(sizeof(int), 10, NULL);
  ASSERT_TRUE(s != NULL); 
  stack_destroy(&s);

  return true;
}
