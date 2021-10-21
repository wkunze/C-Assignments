#include <stdio.h>

int main(void) {
    FILE *ifile;  
    int i,done;
    int index;
    double grade, highgrade;
    
    ifile = fopen("gradeComparison.txt", "r"); 
                                   
    fscanf(ifile, "%lf", &highgrade); //get my class average
    index = 2;
    done = 0;

    while (fscanf(ifile, "%lf", &grade) != EOF && !done) {
        if(grade > highgrade)
        {
            done = 1;
        }
        else 
        {
            index++;
        }
    }
    
    fclose(ifile);

    if(done)
    {
        printf("No %d\n",index);
    }
    else
    {
        printf("Yes\n");
    }

    return(0);
}