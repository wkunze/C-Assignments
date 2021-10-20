#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int NumberofPlants;
    double PriceofPlants;

    if(argc == 3)
    {
        NumberofPlants = atoi(argv[1]);
        PriceofPlants = atof(argv[2]);
        printf("%d plants for %.2lf dollars each cost %.2lf dollars.\n",NumberofPlants,PriceofPlants,(double)NumberofPlants * PriceofPlants);

    }
    else 
    {
        printf("Invalid Input.\n");
    }

    return 0;
}
