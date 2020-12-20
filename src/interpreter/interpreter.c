#include "../monty.h"



/**
 * get_op_func -  selects the correct function to
 * perform the operation asked by the commad
 * @command: input string
 * Return: pointer to a function
 */
void (*get_op_func(char *command))(stack_t **, unsigned int, code_args_t)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_m},
		{"mult", mult},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"queue", queue},
		{"stack", stack},
	};
	int i = 0;
	const int num_of_cmds = 17; /*number of commands in ops*/

	/*Handle incase the line is comment*/
	if (command[0] == '#')
		return (nop);
	/*Handle the case incase the line is empty*/
	if (!strcmp(command, "\n"))
		return (nop);

	while (i < num_of_cmds)
	{
		if (!strcmp(ops[i].opcode, command))
			return (ops[i].func);
		i++;
	}

	return (NULL);
}

/**
 * interpret - iterprets a singe line code
 * according the rules  specified by the monty
 * language
 * @line: a string holding a command
 * @line_number: the line number where the string is found
 * @head: a double pointer to the stack holding all the
 * information about the program
 */
void interpret(char *line, int line_number, stack_t **head)
{
	char *cmd = NULL, *tmp = NULL, *opcode = NULL;
	void (*func)(stack_t **, unsigned int, code_args_t) = NULL;
	code_args_t token;

	/*Remove uncessary white spaces  and tab from line and store it in cmd*/
	trims(&cmd, line);
	token.argc = 0;
	/* remove the new line character at the end of cmd*/
	if (strlen(cmd) > 1)
		cmd[strlen(cmd) - 1] = '\0';
	/*Parse the command name and the arguments into the token*/
	tmp = strtok(cmd, " ");
	opcode = _strdup(tmp);
	tmp = strtok(NULL, " ");
	if (tmp)
	{
		if (!isint(tmp))
		{
			dprintf(2, "L%u: argument must be an integer\n", line_number);
			free(opcode), free(cmd);
			exit(EXIT_FAILURE);
		}
		token.args = atoi(tmp);
		token.argc += 1;
		tmp = strtok(NULL, " ");
		if (tmp)
			token.argc += 1;
	}
	free(cmd);
	/*Get the corrspondng fuction to the opcode and callit*/
	func = get_op_func(opcode);
	if (func)
		func(head, line_number, token),	free(opcode);
	else
	{
		/*print an error message if no command is found*/
		dprintf(2, "L%u: unknown instruction %s\n", line_number, opcode);
		free(opcode);
		exit(EXIT_FAILURE);
	}
}
