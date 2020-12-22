#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


char **command;
void push(stack_t **stack, unsigned int line_c){
	stack_t *Top_Node;
	int number;
	stack_t *temp;
	temp = malloc(sizeof(stack_t));

	if (command[1] != NULL)
	{
		number = atoi(command[1]);
	}
	else
	{
		exit;
	}
	temp->n = number;
	temp->prev = NULL;
	if (*stack == NULL)
		temp->next = NULL;
	else
	{
		temp->next = *stack;
		(*stack)->prev = temp;
	}
	*stack = temp;

}

void pall(stack_t **stack, unsigned int line_c){

}

int search_function(unsigned int line_c, stack_t **stack)
{

	instruction_t funcion[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	int i = 0, comp;

	while (funcion[i].opcode != NULL)
	{
		comp = strcmp(funcion[i].opcode, command[0]);
		if (comp == 0)
			funcion[i].f(stack , line_c);
		i++;
	}

	return (0);
}

main() {

	FILE *fp;
	stack_t *stack = NULL;
	char line[50];
	int comp, comp2;
	char *str = (char *)malloc(sizeof(char));
	char *temp = (char *)malloc(sizeof(char));
	char *temp2 = (char *)malloc(sizeof(char));
	command = (char **)malloc(32 * sizeof(char *));
	const char delim[2] = " ";
	unsigned int line_c = 1;
	int i = 0, j = 0, flag = 0, length;

	fp = fopen("bytecodes/00.m", "r");

	while (fgets(line, 255, fp))
	{
		comp = strcmp(line, "\n");
		str = strtok(line, delim);

		
		while (str != NULL && !(comp == 0) && i <= 1)
		{
			temp = str;
			length = strlen(temp);
			temp2 = &temp[length - 1];
			comp2 = strcmp(temp2, "\n");
			if (comp2 == 0)
			{
				str[length - 1] = '\0';
			} 
			command[i] = str;
			
			i++;
			str = strtok(NULL, delim);
			flag = 1;
		}
		if (flag == 1)
			search_function(line_c,&stack);
		flag = 0;
		i = 0;
		line_c++;

	}
	i = 0;
	fclose(fp);
}