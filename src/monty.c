#include "monty.h"


/*
 ******Author
 * Hileamlak M. Yitayew
 * hilea.buisness@gmail.com
 * ----------------------------With love
 */

/*
 *****Program description
 * This program is an interpreter for the monty programming language.
 * It takes a file from the command line and tries to execute it.
 * It uses a simple algorithm in that,
 * It first takes a file as a command line argument, and tries to open in it.
 * If it successful, it statically checks if there is no syntax bug in the
 * language while putting the commands in a linked list.
 * If lexing and loading to a linked list was successful then the
 * interpreter is called.
 * The interpreter then takes the linked list and executes each command.
 * The list of the commands and what they do is documented in the man page.
 */



/*
 ******Flow Text
 *	The flow of the text is explained above
 */

/*
 ******Disclaimer
 * NONE
 */

/**
 * main - entry point of the intepreter
 * @argc: argument count
 * @argv: argument list
 * Return: 0 on success, and error messages as specified
 * in error.h
 */
int main(int argc, char **argv)
{
	FILE *fd = NULL;
	ssize_t read_stat = -1;
	char *line = NULL;
	size_t buffsize = 0;
	int reading = 1, line_number = 1;
	stack_t *head = NULL;

	/*check if there is correct argument number*/
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*safely open the file*/
	fd = sopen(argv[1]);

	/*Set the default data structure mode to stack*/
	strcpy(data_mod, "stack");

	/*Read one line at a time, and execute the instruction*/
	while (reading)
	{
		read_stat = getline(&line, &buffsize, fd);
		if (read_stat == -1)
		{
			reading = 0;
			break;
		}
		interpret(line, line_number, &head);
		line_number += 1;
	}
	if (line)
		free(line);
	if (head)
		freedll(head);
	/*Close the file before exiting*/
	fclose(fd);
	exit(EXIT_SUCCESS);
}

