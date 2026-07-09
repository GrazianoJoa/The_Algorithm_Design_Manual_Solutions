#ifndef TYPE_OPS_H
#define TYPE_OPS_H

typedef struct {
  void *(*copy)(void *, const void *);
  void (*destroy)(void *);
  int (*compare)(const void *, const void *);
} TypeOps;

#endif
