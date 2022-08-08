#include <stdlib.h>

#define STACK_DECLARE(x)                                              \
  typedef struct stack {                                              \
    x value;                                                          \
    struct stack *next;                                               \
  } stack;                                                            \
                                                                      \
  struct stack *init(x a) {                                           \
    struct stack *p;                                                  \
    p = (struct stack *)malloc(sizeof(struct stack));                 \
    p->value = a;                                                     \
    p->next = NULL;                                                   \
    return p;                                                         \
  }                                                                   \
                                                                      \
  struct stack *push(struct stack *head, x a) {                       \
    struct stack *tmp = (struct stack *)malloc(sizeof(struct stack)); \
    tmp->next = head;                                                 \
    tmp->value = a;                                                   \
    return tmp;                                                       \
  }                                                                   \
                                                                      \
  x pop(struct stack **head) {                                        \
    x out;                                                            \
    struct stack *tmp;                                                \
    tmp = *head;                                                      \
    *(head) = (*head)->next;                                          \
    out = tmp->value;                                                 \
    free(tmp);                                                        \
    return out;                                                       \
  }                                                                   \
                                                                      \
  void destroy(struct stack *head) {                                  \
    while (head) {                                                    \
      struct stack *tmp;                                              \
      tmp = head;                                                     \
      head = head->next;                                              \
      free(tmp);                                                      \
    }                                                                 \
  }
