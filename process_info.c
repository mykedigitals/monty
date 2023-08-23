#include "monty.h"

/**
 * info_process - processes and execute the opcode instructions
 * @list_head: head of linked list stack
 * @lineNumber: track of the current position of input being read
 * @instructionString: pointer to a character array or string
 * representing content to be processed
 * @input_file: a pointer to FILE structure representing file stream
 *
 * Return: nil
 */
int info_process(stack_t **list_head, unsigned int lineNumber,
		char *instructionString, FILE *input_file)
{
	instruction_t instructions[] = {
	{"pop", pop_self},		{"swap", swap_self},	{"add", plus_self},
	{"nop", noppe_self},		{"sub", counter_self},		{"div", demar_self},
	{"mul", mul_self},		{"mod", mod_self},		{"pchar", pucha_self},
	{"pstr", pstring_self},	{"rotl", rotl_self},	{"rotr", rotr_self},
	{"queue", selfmade_queue},	{"stack", selfmade_stack},	{"push", self_push},
	{"pall", pall_self},	{"pint", pint_self},	{NULL, NULL}
	};

	char *opcode;
	unsigned int idx = 0;

	opcode = strtok(instructionString, " \n\t");

	if (opcode && opcode[0] == '#')
	{
		return (0);
	}

	executionContext.value = strtok(NULL, " \n\t");

	while (instructions[idx].opcode && opcode)
	{
		if (strcmp(opcode, instructions[idx].opcode) == 0)
		{
			instructions[idx].f(list_head, lineNumber);
			return (0);
		}
		idx++;
	}

	if (opcode && instructions[idx].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, opcode);
		fclose(input_file);
		free(instructionString);
		stack_empty(*list_head);
		exit(EXIT_FAILURE);
	}
	return (1);
}


/**
 * stack_empty - function that frees a doubly linked list
 * @list_head: head of linked list stack
 *
 * Return: nil
 */
void stack_empty(stack_t *list_head)
{
	stack_t *tem_val;

	tem_val = list_head;

	/* Traverse the linked list and free each node*/
	while (list_head)
	{
		/* Store the next node in the temporary value*/
		tem_val = list_head->next;

		/* Free the current node*/
		free(list_head);

		/* Move to the next node*/
		list_head = tem_val;
	}
}


/**
 * p_stak - adds a new element to the top of a stack
 * @list_head: head of linked list stack
 * @new: new value
 *
 * Return: nil
 */
void p_stak(stack_t **list_head, int new)
{
	stack_t *tem_val;
	stack_t *new_node;

	tem_val = *list_head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	/* Update the previous pointer of the current list head if it exists*/
	if (tem_val != NULL)
	{
		tem_val->prev = new_node;
	}

	/* Set the value of the new node to the given value*/
	new_node->n = new;

	/* Update the next and previous pointers of the new node*/
	new_node->next = *list_head;
	new_node->prev = NULL;
	/* Set the new node as the new list head*/
	*list_head = new_node;
}


/**
 * pushQueue -  adds a new node to the end of queue
 * @list_head: head of the queue
 * @new: new value
 *
 * Return: nil
 */
void pushQueue(stack_t **list_head, int new)
{
	stack_t *tmp_val;
	stack_t *new_node;

	tmp_val = *list_head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		printf("Error\n");

	new_node->n = new;
	new_node->next = NULL;
	if (tmp_val)
		/* Traverse to the last node of the list*/
		while (tmp_val->next)
		{
			tmp_val = tmp_val->next;
		}

	if (!tmp_val)
	{
		*list_head = new_node;
		new_node->prev = NULL;
	}

	else
	{
		tmp_val->next = new_node;
		new_node->prev = tmp_val;
	}
}
