# Format
## Description
 This file specifies the format to be used in this code base when it comes to files containing functions and programs.

* Author: in each file an author should be written in the following format and this is common to the whole file.
```c
/*
 ******Author
 * Hileamlak M. Yitayew
 * hilea.buisness@gmail.com
 * ----------------------------With love
 */
```
* Program discription: this is a descirption of all the functions in the file and generally what they do. This is also common for the whole file.
```c
/*
 *****Program description
 * This printer function could be activated wit a status of 0 which means
 * start. Once started messages strings to be printed could be sent to the
 * printer with a status code of 1. which means add to que. And finally when
 * it is time to print the funciton could be called with a status of 2, whihc
 * means print what is in the que. If the que is full before 2 is sent, it will
 * auto print and go back to the begning of the que.
 */
```
* Flow text: This is like a flow chart but with text. It descirbes the algorithm used in each function. there should be one for each function. thig might be one for each function.

```c
/*
 ******Flow Text
 * -- First call the funciton with no toprint message and a status of 0, which will
 *     Open the printer
 * -- The next time you want a message to be stored to a que call the function with
 *	a status of 1
 * -- And once you are done call the function with no message and the status of 2
 *	To flush everything to screen with the write system call
 */
```
* Disclaimer (optional): this will describe any possible pitfalls that might exist. There might be one for each function
```
/*
 ******Disclaimer
 * if you sent a status of 0 more than once before printing, you might loose data
 * as it will restart the printer
 */
```

* Function discription: a shor description of the funcion in the follwoing format. There should be one for each function right before the function.
```c
/**
 * printer - works like a printer but to stdin
 * @toprint - string to be printed
 * @status: command to the printer
 *	0 - open printer
 *	1 - add to printer que
 *	2 - print #even if 2 isn't sent if the printque is
 *	it will print
 * Return: the number of things printed or put to que, or -1 on failure
 */
int printer(char *toprint, int status)
{
	static char que[BUFFER_SIZE];
	static int current_index;
	int printed = 0, writestat = 0;

	if (status == 0)
		current_index = 0, printed = 0;
	else if (status == 1)

		while (*toprint)
		{
			if (current_index >= BUFFER_SIZE)
			{
				current_index = 0;
				writestat = write(1, que, BUFFER_SIZE);
				if (writestat == -1)
				{
					printf("Handle this unlikley error later");
					return (-1);
				}
			}
			que[current_index] = *toprint;
			toprint++, current_index++, printed++;
		}

	else if (status == 2)
	{
		writestat = write(1, que, current_index + 1);
		if (writestat == -1)
		{
			printf("Handle this unlikley error later");
			return (-1);
		}
		printed += writestat;
		current_index = 0;
	}
	return (printed);

}
```
* Example: finally ther should be a commented main function that will show a simple example of the usage of the functions in the file. another preferd way to present examples is in a different file like file_name_test.c. And its name should be listed under this example comment.
```c
/*
 *****Example
 *
 *int main (void)
 *{
 *	printer(NULL, 0); //turn the printer on
 *	printer("HELLO", 1); // put Hello in the que
 *	printer(" World\n", 1); // put world in the que
 *	printer(NULL, 2); // Do the actual printing with
 *				the write system call
 *
 *	return (0);
 *}
 */
```

## Author

Hileamlak M. Yitayew, 
