#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
struct student *append(struct student * end, struct student * newStudptr); 
void printStudents(struct student *start);
void freeStudents(struct student *start);
void copyStr(char *, char *);

int main(void) 
{
    struct student *start, *newStudptr, *end;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);
    start = createStudent("Petra", ageP);
    end = start;
    
    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);
    
    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printStudents(start);
    freeStudents(start);

    return 0;
}

struct student *createStudent(char studentName[], int studentAge)
{
    struct student *newStudent;

    newStudent = (struct student *)malloc(1 * sizeof(struct student));

    copyStr(studentName, newStudent->name);
    newStudent->age = studentAge;
    newStudent->next = NULL;

    return newStudent;
}

void copyStr(char *oldstring, char *newstring)
{
    int letter;
    letter = 0;
    
    while(oldstring[letter] != '\0')
    {
        newstring[letter] = oldstring[letter];
        letter++;
    }

    newstring[letter] = '\0';
}

struct student *append(struct student * end, struct student * newStudptr)
{
    end->next = newStudptr;
    end = newStudptr;

    return end;
}

void printStudents(struct student *start)
{
    struct student *ptr;
    ptr = start;

    while (ptr != NULL)
    {
        printf("%s is %d years old.\n",ptr->name, ptr->age);
        ptr = ptr->next;
    }
}

void freeStudents(struct student *start)
{
    struct student *tmp;
    struct student *ptr;
    
    ptr = start;
    while (ptr != NULL)
    {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}


