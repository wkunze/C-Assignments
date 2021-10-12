#include "stdio.h"
#include "math.h"

int main(void)
{
    int userentry;
    double root;
    double euler;

    scanf("%d",&userentry);
    root = pow((double)userentry,0.5);

    printf("%.8lf\n",root);
    euler = exp(1);
    printf("%.10lf\n",euler);

    printf("gcc -std=c11 -Wall -fmax-errors=10 maths.c -Wextra -lm -o maths\n");

    return 0;
}
