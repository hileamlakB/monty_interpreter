#include "../monty.h"

/**
 * mod - computes rest of division of second element by top element
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void mod(stack_t **head, unsigned int line_number, code_args_t token)
{
	stack_t *_head = *head, *tmp = NULL;


	(void)(token);

	/*check if there are nodes to be divided*/
	if (!_head)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(_head->next))
	{

		dprintf(2, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/*Handle division by zero*/
	if (_head->n == 0)
	{

		dprintf(2, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	/*Find the division of the top two nodes and store it in the second node*/
	_head->next->n %= _head->n;

	/*Remove the top node after storing and move the head*/
	tmp = _head->next;
	_head->next->prev = NULL;
	free(_head);
	*head = tmp;
}



/**
 * pchar - prints character at top of stack followed by new line
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void pchar(stack_t **head, unsigned int line_number, code_args_t token)
{

	stack_t *_head = *head;


	(void)(token);

	/*Incase there is no node to be printed*/
	if (!_head)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);

	}

	/*handle if isn't a non printable character*/
	if (_head->n < 0 || _head->n > 127)
	{

		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*if everything went well print to stdout*/
	printf("%c\n", _head->n);
}


/**
 * pstr - prints string starting at top of stack followed by new line
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void pstr(stack_t **head, unsigned int line_number, code_args_t token)
{
	stack_t *_head = *head;


	(void)(token);
	(void)(line_number);
	/*
	 *print everything in the linked list unless
	 * it's value is a zero,
	 * it's is empty (has reached to the end)
	 * The value of the element isn't in stack
	 */
	while (_head)
	{
		if (_head->n < 0 || _head->n > 127 || _head->n == 0)
			break;
		printf("%c", _head->n);
		_head = _head->next;
	}
	/*Print a new line in the end*/
	printf("\n");
}


/**
 * rotl - rotates the stack so that The top element of the
 * stack becomes the last one, and the second top element of the
 * stack becomes the first one
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void rotl(stack_t **head, unsigned int line_number, code_args_t token)
{
	stack_t *_head = *head, *top = *head, *second = NULL;


	(void)(token);
	(void)(line_number);
	if (!_head)
		return;
	/*Get the second top element*/
	second = _head->next;

	/*Go to the end of the list*/
	while (_head->next)
		_head = _head->next;

	/*Bring the top to the last*/
	_head->next = top;
	/*set the last's previous to the proper value*/
	top->prev = _head;
	top->next = NULL;
	/*set the previous of the second to NULL since it is now top*/
	second->prev = NULL;
	/*Make the head point to second*/
	*head = second;
}
