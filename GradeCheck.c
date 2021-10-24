#include <stdio.h>

int main(void) 
{
    FILE *ofile;  
    int lastgrade;
    int newgrade;

    scanf("%d",&newgrade);

    ofile = fopen("myGrades.txt", "r"); 
                                   
    while (fscanf(ofile, "%d", &lastgrade) != EOF);
    
    fclose(ofile);

    if(lastgrade != newgrade)
    {
        ofile = fopen("myGrades.txt", "a"); 
        fprintf(ofile," %d",newgrade);
        fclose(ofile);
    }

    ofile = fopen("myGrades.txt", "r"); 
    while (fscanf(ofile, "%d", &lastgrade) != EOF)
    {
        printf("%d ",lastgrade);
    }
    printf("\n");

    return(0);
}