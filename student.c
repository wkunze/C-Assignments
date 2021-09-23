#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
struct student *append(struct student * end, struct student * newStudptr); 
void copyStr(char *, char *);

int main(void) 
{
    struct student *start, *newStudptr, *end, *tmp;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);
    start = createStudent("Petra", ageP);
    end = start;
    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);
    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printf("%s is %d years old.\n", start->name, start->age);
    printf("%s is %d years old.\n", start->next->name, start->next->age);
    printf("%s is %d years old.\n", start->next->next->name, start->next->next->age);

    tmp = start->next;
    free(start);
    start = tmp;
    tmp = start->next;
    free(start);
    free(tmp);

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
