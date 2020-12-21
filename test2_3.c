#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main() {

	FILE *fp;
	char line[50];
	int comp;
	char *str = (char *)malloc(sizeof(char));
	char **command = (char **)malloc(32 * sizeof(char *));
	const char delim[2] = " ";
	int n = 1, i = 0, j = 0;

	fp = fopen("bytecodes/00.m", "r");

	while (fgets(line, 255, fp))
	{
		comp = strcmp(line, "\n");
		str = strtok(line, delim);
		//comp = strcmp(str)
		
		while (str != NULL && !(comp == 0) && i <= 2)
		{
			command[j] = str;
			printf("%s \n", command[j]);
			i++;
			j++;
			str = strtok(NULL, delim);
		}
		
		i = 0;
		n++;
		//str = "\001";
	}
	i = 0;
	fclose(fp);
}
