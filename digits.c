#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit * next;
};

struct digit * createDigit(int dig);
struct digit * append( struct digit *, struct digit *);

int main(void) {
    int i;
    int digits[3] = {5,3,7};
    struct digit *start, *newdigitptr, *end;

    start = createDigit(digits[0]);
    end = start;
    for(i = 1; i < 3; i++)
    {
        newdigitptr = createDigit(digits[i]);
        end = append(end,newdigitptr);
    }

    free(start);
    free(end);
    return 0;
}

struct digit * createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit *append( struct digit *end, struct digit *newdigitptr)
{
    end->next = newdigitptr;
    end = newdigitptr;

    return end;
}