#ifndef STACK_H 
#define STACK_H

#include <stdlib.h>

#include "ds/type_ops.h"
#include "ds/codes.h"

typedef struct {
  void* data;
  size_t elem_size;
  const TypeOps *ops;

  size_t size;
  size_t capacity;
} Stack;

// BASIC
Stack* stack_create(size_t elem_size, size_t capacity, const TypeOps* ops);
void stack_destroy(Stack** stack);
STATUS_CODE stack_push(Stack* stack, void* elem);
STATUS_CODE stack_pop(Stack* s, void* elem);

STATUS_CODE stack_resize(Stack* s, size_t new_capacity);

#endif
