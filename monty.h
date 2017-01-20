#ifndef MONTY
#define MONTY
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int value;

/* failures.c */
void check_argc(int argc);

/* stack_funcs.c */
int add_to_stack(stack_t **head, int n);
void free_stack(stack_t *head);
int delete_stack_head(stack_t **head);
int delete_stack_end(stack_t **head);
void print_stack(stack_t **head);

/* get_opcode_func.c */
void (*get_opcode_func(char *s))(stack_t **stack, unsigned int ln);

/* helper.c */
int check_if_number(char *str);
int check_if_push(char **tok_line);
#endif
