#include "stdlib.h"
#include "ds/type_ops.h"

TypeOps* set_ops(void *(*copy)(void *,const void *), 
    int (*compare)(const void *, const void *), void (*destroy)(void *)) {
  
  TypeOps* ops = malloc(sizeof(TypeOps));
  ops->copy = copy;
  ops->compare = compare;
  ops->destroy = destroy;
  return ops;
}
