#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};

struct digit * createDigit(int dig);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *start);
void freeNumber(struct digit *start);
int changeThrees(struct digit * start);
struct digit * readNumber(void);
//Add your own function prototypes here
int countRedun(struct digit *);

int main(void) {
    struct digit *start;
    start = readNumber();

    printf("The number ");
    printNumber(start);
    printf("contains %d redundancies.\n", countRedun(start));

    freeNumber(start);

    return 0;
}

struct digit * createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit * readNumber(void) {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c-48;
        newptr = createDigit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}

// Write your changeThrees() function here
int changeThrees(struct digit * start) {
    int count;
    struct digit *ptr;
    
    ptr = start;    
    count = 0;

    while(ptr != NULL) {
        if(ptr->num == 3) 
        {
            count++;
            ptr->num = 9;
        }
        ptr = ptr->next;
    }

    return count;
}

int countRedun(struct digit *start)
{
    int count,i,digitCount;
    struct digit *ptr;
    
    count = 0;

    for(i = 0; i < 10; i++)
    {
        ptr = start;    
        digitCount = 0;
        while(ptr != NULL) {
            if(ptr->num == i) 
            {
                digitCount++;
            }
            ptr = ptr->next;
        }
        if(digitCount > 1) //handle 1 or 0 digits
        {
            count += (digitCount - 1);
        }
    }
    return count;
}