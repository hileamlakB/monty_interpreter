#ifndef MONTY
#define MONTY

/*Liberaries*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#include "utils/utils.h"
#include "interpreter/interpreter.h"
#include "lexer/lexer.h"
#include "loader/loader.h"

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
 * struct instruction_s - opcode and its function
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

/**
 *struct command_s - a linked list node to hold a command
 *@cmd: command string
 *@args: arguments for the command
 *@next: a pointer to the next command node
 */
typedef struct command_s
{
	char *cmd;
	int args[2];
	struct command_s *next;

}command_t;



#endif /*MONTY*/
