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

/*global variables*/
char data_mod[6];


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct code_args_s -  argument information
 * @args: a list of the aguments
 * @argc: number of arguments to passed
 * 0 - means none,
 * 1 - means 1,
 * 2 - more than one
 */
typedef struct code_args_s
{
	int args;
	int argc;
} code_args_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @func: function to handle the opcode
 *
 * Description: opcode and its respctive function
 */
typedef struct instruction_s
{
	char *opcode;
	void (*func)(stack_t **, unsigned int, code_args_t);
} instruction_t;


/*loader*/
FILE *sopen(char *);

/*memory_utils*/
void freedp(char **);
void trims(char **, char *);
void *smalloc(unsigned int);
void *srealloc(void *, unsigned int);
char *_strdup(char *);
void freedll(stack_t *);

/*utils.c*/
int isint(char *);

/*Interpreter funnction*/
void (*get_op_func(char *))(stack_t **, unsigned int, code_args_t);
void interpret(char *, int, stack_t **);

/*Interpreter helpers*/
void push(stack_t **, unsigned int, code_args_t);
void pall(stack_t **, unsigned int, code_args_t);
void pint(stack_t **, unsigned int, code_args_t);
void pop(stack_t **, unsigned int, code_args_t);
void swap(stack_t **, unsigned int, code_args_t);

void add(stack_t **, unsigned int, code_args_t);
void nop(stack_t **, unsigned int, code_args_t);
void sub(stack_t **, unsigned int, code_args_t);
void div_m(stack_t **, unsigned int, code_args_t);
void mult(stack_t **, unsigned int, code_args_t);

void mod(stack_t **, unsigned int, code_args_t);
void pchar(stack_t **, unsigned int, code_args_t);
void pstr(stack_t **, unsigned int, code_args_t);
void rotl(stack_t **, unsigned int, code_args_t);
void rotr(stack_t **, unsigned int, code_args_t);

void queue(stack_t **, unsigned int, code_args_t);
void stack(stack_t **, unsigned int, code_args_t);


#endif /*MONTY*/
