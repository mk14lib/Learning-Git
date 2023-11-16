/*
	Write C program to accept to integer from user and inverse it and 
	display result for example if input is 123 the output should be 321? 
*/

#include <stdio.h>

int main()
{
	int num = 0;
	scanf("%d", &num);
	int result = 0;
	printf("%d - ", num);
	while(num != 0)
	{
		result = result*10 + (num % 10);
		num = num / 10;	
	}
	printf("%d\n", result);
	return 0;
}