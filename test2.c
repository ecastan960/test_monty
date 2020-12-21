#include <stdio.h>

main(int argc, char *argv[]) {

	FILE *fp;
	char buff[255] ;
	int n = 1;

	fp = fopen(argv[1], "r");
	fscanf(fp, "%s", buff);

	while (buff[0] != '\0')
	{
		printf("%d : %s\n",n, buff );
		buff[0] = '\0';
		fscanf(fp, "%s", buff);
		n++;
	}
	fclose(fp);
}
