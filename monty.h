#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>
#include <fcntl.h>


/**
 * struct ProgramContext - program carrier
 * @value: represents a value or argument
 * @input_file: a pointer to monty file
 * @instructionString: represents the content of a line
 * @stackMode: a flag that indicates stack or queue mode
 *
 * Description: holds and pass around variables and flags used in the program
 */
typedef struct ProgramContext
{
	char *value;
	FILE *input_file;
	char *instructionString;
	int stackMode;
} ExecutionContext;


extern ExecutionContext executionContext;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* PROTOTYPE DEFINATIONS */


/* exe_info.c */
void self_push(stack_t **list_head, unsigned int number);
void pall_self(stack_t **list_head, unsigned int number);
void pint_self(stack_t **list_head, unsigned int number);
void pop_self(stack_t **list_head, unsigned int lineNumber);
void swap_self(stack_t **list_head, unsigned int lineNumber);


/* exe_info1.c */
void plus_self(stack_t **list_head, unsigned int lineNumber);
void noppe_self(stack_t **list_head, unsigned int lineNumber);
void counter_self(stack_t **list_head, unsigned int lineNumber);
void demar_self(stack_t **list_head, unsigned int lineNumber);
void mul_self(stack_t **list_head, unsigned int lineNumber);


/* exe_info2.c */
void mod_self(stack_t **list_head, unsigned int lineNumber);
void pucha_self(stack_t **list_head, unsigned int lineNumber);
void pstring_self(stack_t **list_head, unsigned int lineNumber);
void rotl_self(stack_t **list_head, unsigned int lineNumber);
void rotr_self(stack_t **list_head,
		__attribute__((unused)) unsigned int lineNumber);


/* exe_info3.c */
void selfmade_stack(stack_t **list_head, unsigned int lineNumber);
void selfmade_queue(stack_t **list_head, unsigned int lineNumber);


/* process_info.c */
int info_process(stack_t **list_head, unsigned int lineNumber,
		char *instructionString, FILE *input_file);
void stack_empty(stack_t *list_head);
void p_stak(stack_t **list_head, int new);
void p_que(stack_t **list_head, int new);


#endif /* MONTY_H_ */
