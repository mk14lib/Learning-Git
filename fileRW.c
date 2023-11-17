#include <stdio.h>

int main()
{
    FILE *fp = fopen("new.txt", "a+");
    char string[100];
    scanf("%[^\n]", string);
    fputs(string, fp);
    rewind(fp);
    int c;
    while((c = fgetc(fp)) != EOF)
    {
        putchar(c);
    }
    fclose(fp);
    return 0;
}
