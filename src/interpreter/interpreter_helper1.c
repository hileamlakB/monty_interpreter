#include "../monty.h"


/**
 * push - Adds a new element to the stack or que
 * depending on the choice (the choice is made
 * by using the queue or the stack command) of the
 * data structure as described in the command page.
 * If the data structure is the stack, value is
 * added in the front and in the back if the choice
 * is queue.
 * @head: a pointer to the head pointer of the stack_t
 * @line_number: current line the current instruction
 * has been read from
 * @token: the number of arguments and the arguments themself
 */
void push(stack_t **head, unsigned int line_number, code_args_t token)
{
	stack_t *new_node, *_head = *head;

	if (token.argc < 1)
	{
		dprintf(2, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/*Create a node and give it the required values*/
	new_node = smalloc(sizeof(stack_t));
	new_node->n = token.args;

	/*if the data mode is stack store the data in front*/
	if (!strcmp(data_mod, "stack"))
	{
		new_node->prev = NULL;
		new_node->next = _head;
		if (_head)
			_head->prev = new_node;
		*head = new_node;
	}
	else if (!strcmp(data_mod, "queue"))
	{
		/*go to the end of the file*/
		if (!_head)
		{
			*head = new_node;
			return;
		}
		while (_head->next)
			_head = _head->next;
		new_node->prev = _head;
		new_node->next = NULL;
		_head->next = new_node;
	}
}

/**
 * pall - prints values stored in the linked list
 * starting from the front to the back
 * @head: a pointer to the head pointer of the main stack
 * @line_number: current line the current instruction
 * has been read from
 * @token: the number of arguments and the arguments themselves
 */
void pall(stack_t **head, unsigned int line_number, code_args_t token)
{
	stack_t *_head = *head;

	(void)(token);
	(void)(line_number);
	/*
	 *print everything in the linked list unless
	 * it's is empty (has reached to the end)
	 */
	while (_head)
	{
		printf("%i\n", _head->n);
		_head = _head->next;
	}
}


/**
 * pint - prints top element of the main
 * stack followed by new line
 * @head: a pointer to the head pointer of the main stack
 * @line_number: current line the current instruction
 * has been read from
 * @token: the number of arguments and the arguments themselves
 */
void pint(stack_t **head, unsigned int line_number, code_args_t token)
{
	stack_t *_head = *head;

	(void)(token);

	/*Incase there is no node to be printed*/
	if (!_head)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);

	}
	/*if everything went well print to stdout*/
	printf("%i\n", _head->n);
}


/**
 * pop - removes top element of the main stack
 * @head: a pointer to the head pointer of the main stack
 * @line_number: current line the current instruction
 * has been read from
 * @token: the number of arguments and the arguments themselves
 */
void pop(stack_t **head, unsigned int line_number, code_args_t token)
{
	stack_t *_head = *head, *new_top = NULL;


	(void)(token);
	(void)(line_number);

	if (!_head)
	{
		dprintf(2, "L%u: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	new_top = _head->next;
	if (new_top)
		new_top->prev = NULL;
	free(_head);
	*head = new_top;

}

/**
 * swap - swaps the top two elements of the stack
 * @head: a pointer to the head pointer of the main stack
 * @line_number: current line the current instruction
 * has been read from
 * @token: the number of arguments and the arguments themselves
 */
void swap(stack_t **head, unsigned int line_number, code_args_t token)
{
	stack_t *_head = *head, *old_top = NULL, *old_second = NULL;


	(void)(token);

	/*check if there are nodes to be multiplied*/
	if (!_head)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(_head->next))
	{

		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	old_top = _head;
	old_second = _head->next;

	old_top->prev = old_second;
	old_top->next = old_second->next;

	old_second->prev = NULL;
	old_second->next = old_top;

	*head = old_second;
}

