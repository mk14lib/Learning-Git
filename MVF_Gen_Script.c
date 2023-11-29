#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char checksum[10] = {0, };
    char filename[255] = "./0000";
    char modelmode[5];
    printf("Please provide the file checksum   : ");
    scanf("%[^\n]", checksum);
    
    for(int i=2; i < 10; i++)
    {
        checksum[i-2] = checksum[i];
    }
    
    char chksum[10] = "0000";
    strcat(chksum, checksum);
   
    printf("Please input the model mode\t   : ");
    scanf("%s", modelmode);
    int i = 0;
    while(modelmode[i] != '\0')
    {
        modelmode[i] = toupper(modelmode[i]);
        i++;
    }
    
    strcat(filename, checksum);
    strcat(filename, "_");
    strcat(filename, modelmode);
    strcat(filename, "_");
    strcat(filename, "Flash.mvf");
   
    FILE *fp = fopen(filename, "w");
    
    char menuname[100];
    printf("Please input the Display Menu name : ");
 
    scanf("%s", menuname);
    fputs("[Model] : ", fp);
    fputs(menuname, fp);
    
    fputs("\n[Password] : ffffffffffffffffffffffff\n", fp);
    fputs("[Address] : ff00\n", fp);
    fputs("[File_name] : ", fp);
    
    char filetype[10];
    printf("Please provide the extension\t   : ");
    scanf("%s", filetype);
    if (!(strcmp(filetype, "bin\0")))
    {
        fputs(chksum, fp);
        fputs(".bin", fp);
    }
    else if (!(strcmp(filetype, "hex\0")))
    {
        fputs(chksum, fp);
        fputs(".hex", fp);
    }
    else
    {
        fputs(chksum, fp);
        fputs(".",fp);
        fputs(filetype, fp);
    }
    
    
    fputs("\n[MCU_Mode] : ", fp);
    fputs(modelmode, fp);
    
    fputs("\n[Checksum] : \n", fp);
    fputs(chksum, fp);
    fputs("\n", fp);
    fputs(chksum, fp);
    fputs("\n[eof]", fp);

    // checksum-modelmode-flash.mvf
    puts("\n********************************************");
    printf(".........File generated successfully........\n");
    printf("Generated Filename: %s", filename);
    puts("\n********************************************");
    
    rewind(fp);
    fclose(fp);
	getch();
    return 0;
}
