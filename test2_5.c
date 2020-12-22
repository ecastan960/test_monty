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

stack_t *Top_Node;

void push(stack_t **stack, unsigned int line_c){
	printf("Linea donde hay push :%d \n", line_c);
	/*int number;
	stack_t *temp;
	temp = malloc(sizeof(stack_t));

	if (node != NULL)
	{
		number = atoi(node);
	}

	temp->n = number;
	temp->prev = NULL;

	if ( *stack != NULL)
	{
		temp->next = *stack;
		(*stack)->prev = temp;
		Top_Node = *stack;
	}
	else
	{
		temp->next = NULL;
	}

	int isEmpty()
	{
		return (Top_Node == NULL);
	}*/
		
}

void pall(stack_t **stack, unsigned int line_c){
	printf("Linea donde hay pall :%d \n", line_c);
	/*int number;
	stack_t *temp;
	temp = malloc(sizeof(stack_t));

	if (node != NULL)
	{
		number = atoi(node);
	}

	temp->n = number;
	temp->prev = NULL;

	if ( *stack != NULL)
	{
		temp->next = *stack;
		(*stack)->prev = temp;
		Top_Node = *stack;
	}
	else
	{
		temp->next = NULL;
	}

	int isEmpty()
	{
		return (Top_Node == NULL);
	}*/
		
}

int search_function(char **comm, unsigned int line_c, stack_t **stack)
{

	instruction_t funcion[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	int i = 0, comp;

	while (funcion[i].opcode != NULL)
	{
		comp = strcmp(funcion[i].opcode, comm[0]);
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
	int comp;
	char *str = (char *)malloc(sizeof(char));
	char **command = (char **)malloc(32 * sizeof(char *));
	const char delim[2] = " ";
	unsigned int line_c = 1;
	int i = 0, j = 0, flag = 0;

	fp = fopen("bytecodes/00.m", "r");

	while (fgets(line, 255, fp))
	{
		comp = strcmp(line, "\n");
		str = strtok(line, delim);

		
		while (str != NULL && !(comp == 0) && i <= 1)
		{
			command[i] = str;

			i++;
			str = strtok(NULL, delim);
			flag = 1;
		}
		if (flag == 1)
			search_function(command,line_c,&stack);
		flag = 0;
		i = 0;
		line_c++;

	}
	i = 0;
	fclose(fp);
}