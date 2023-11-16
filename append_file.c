#include <stdio.h>

int main()
{
	// r w a, xtended versions: r+ w+ a+
	FILE *fp = fopen("./new.txt", "a+"); // append extended
	char string[100];
	scanf("%[^\n]", string);
	fputs(string, fp);
	fclose(fp);
	return 0;
}