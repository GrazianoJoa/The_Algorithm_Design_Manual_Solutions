#include "ds/codes.h"
#include "string.h"

#include "ds/stack.h"

Stack* stack_create(size_t elem_size, size_t capacity, const TypeOps* ops) {
  if (elem_size == 0 || capacity == 0 || !ops)  return NULL;

  Stack* s = malloc(sizeof(Stack));
  if (!s) return NULL;

  s->data = malloc(elem_size * capacity);
  if (!s->data) {
    free(s);
    return NULL;
  }

  s->elem_size = elem_size;
  s->ops = ops;
  s->size = 0;
  s->capacity = capacity;
  return s;
}

void stack_destroy(Stack **stack) {
  if (!stack || !(*stack)) return;

  if ((*stack)->ops && (*stack)->ops->destroy) {
    char* base_ptr = (char*)(*stack)->data;
    for (size_t i = 0; i < (*stack)->size; i++) {
      (*stack)->ops->destroy(base_ptr + (i * (*stack)->elem_size));
    }
  }

  free((*stack)->data);
  free(*stack);

  *stack = NULL;
}


STATUS_CODE stack_resize(Stack *stack, size_t new_capacity) {
  if (stack->capacity >= new_capacity) return ERROR_BAD_ARGUMENTS;

  void* res = realloc(stack->data, new_capacity * stack->elem_size);
  if (!res) return ERROR_WHILE_ALLOCATING_MEMORY;

  stack->data = res;
  stack->capacity = new_capacity;
  return STATUS_OK;
}

STATUS_CODE stack_push(Stack *stack, void *elem) {
  if (!elem || !stack) return ERROR_BAD_ARGUMENTS;
  if (stack->capacity == stack->size) {
    int code = stack_resize(stack, stack->capacity * 2);
    if (code != STATUS_OK) return code;
  }

  void* target = (char *)stack->data + (stack->size * stack->elem_size);
  
  if (stack->ops && stack->ops->copy) 
    stack->ops->copy(target, elem);
  else 
    memcpy(target, elem, stack->elem_size);

  stack->size++;
  return STATUS_OK;
}

STATUS_CODE stack_pop(Stack *stack, void *elem) {
  if (!elem || !stack) return ERROR_BAD_ARGUMENTS;



  stack->size--;
  return STATUS_OK;
}


