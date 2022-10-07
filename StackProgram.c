#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int count = 0;

// Creating a stack
struct stack {
  int items[MAX];
  int top;
};
typedef struct stack st;

void createEmptyStack(st *s) { s->top = -1; }

// Check if the stack is full
int isfull(st *s) {
  if (s->top == MAX - 1)
    return 1;
  else
    return 0;
}

// Check if the stack is empty
int isempty(st *s) {
  if (s->top == -1)
    return 1;
  else
    return 0;
}

// Add elements into stack
void push(st *s, int newitem) {
  if (isfull(s)) {
    printf("STACK FULL");
  } else {
    s->top++;
    s->items[s->top] = newitem;
  }
  count++;
}

// Print elements of stack
void printStack(st *s) {
  printf("Stack: ");
  for (int i = 0; i < count; i++) {
    printf("%d ", s->items[i]);
  }
  printf("\n");
}

// Search items in stack
void search(st *s, int searchedItem) {
  for (int i = 0; i < MAX; i++) {
    if (searchedItem == s->items[i]) {
      printf("%d is found  ", s->items[i]);
      printf("at location %d (from the bottom). \n", MAX - i);
    }
  }
    printf(" item not found.\n");
}

// Driver code
int main() {
  st *s = (st *)malloc(sizeof(st));
  int max = 100;
  int random;
  createEmptyStack(s);
  while (max--) {
    random = rand() % 1000 + 1;
    push(s, random);
  }
  search(s, 887);

  printStack(s);
}
