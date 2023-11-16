/*
	Write C program to accept string from the user and 
	calculate the length and display it without using strlen?
*/

#include <stdio.h>
#include <string.h>

void printStringLength(char []);

void printStringLength(char array[])
{
	int i = 0;
	while(array[i] != '\0')
	{
		i++;
	}
	printf("%d\n", i);
}


int main()
{
	char string[100];
	scanf("%[^\n]", string);
	printStringLength(string);
}