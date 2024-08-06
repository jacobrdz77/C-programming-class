/*
 * Creates and manipulates a stack of characters
 */
#include <stdio.h>
#include <stdlib.h>

typedef char stack_element_t;

typedef struct stack_node {
  stack_element_t element;
  struct stack_node *restp;
} stack_node_t;

typedef struct {
  stack_node_t *topp;
} stack_t;

void push(stack_t *sp, stack_element_t c);
stack_element_t pop(stack_t *sp);

int main(void) {
  stack_t s = {NULL}; /* stack of characters - initially empty */
  printf("Enter a string: ");
  char c;

  do {
    c = getchar();
    if (c == '\n') {
      break;
    }
    push(&s, c);
  } while (c != '\n');

  printf("Reversed: ");

  while (s.topp != NULL) {
    printf("%c", pop(&s));
  }
  printf("\n");

  return 0;
}

/*
 * The value in c is placed on top of the stack accessed through sp
 * Pre: the stack is defined
 */
void push(stack_t *sp, stack_element_t c) {
  stack_node_t *newp; /* pointer to new stack node */

  /* Creates and defines new node */
  newp = (stack_node_t *)malloc(sizeof(stack_node_t));
  newp->element = c;
  newp->restp = sp->topp;
  /* Sets stack pointer to point to new node */
  sp->topp = newp;
}

/*
 * Removes and frees top node of stack, returning character value
 * stored there.
 * Pre: the stack is not empty
 */
stack_element_t pop(stack_t *sp) {
  stack_node_t *to_freep; /* pointer to node removed */
  stack_element_t ans;    /* value at top of stack */

  to_freep = sp->topp;        /* saves pointer to node being deleted */
  ans = to_freep->element;    /* retrieves value to return */
  sp->topp = to_freep->restp; /* deletes top node */
  free(to_freep);             /* deallocates space */

  return (ans);
}

/*
Program #2
Stack Extensions
Implement a stack based on code found in Section 13.5 of the book, include the
push and pop functions.  Use a loop to read characters from stdin using the
getchar() function.  Push each character entered into a stack.  Have the loop
exit when the user enters a newline ('\n') character.

Using the pop() function, output the stack of characters in reverse order:

Enter a string: Hello world!

Reversed: !dlrow olleH
Your code for the stack must include a data node that uses a pointer as a link
to another data node.

Hint: You may want to implement an isEmpty function for the stack; alternately,
we know that a stack is empty when the top of it is NULL.
*/