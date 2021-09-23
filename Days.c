#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

void readDate(struct date *);
void printDate(struct date);
struct date advanceDay(struct date); 

int main(void) {	
    struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}

void readDate(struct date *DatePtr) {
    int Year,Month,Day;

    scanf("%d %d %d",&Year,&Month,&Day);
    (*DatePtr).year = Year;
    (*DatePtr).month = Month;
    (*DatePtr).day = Day;
}

void printDate(struct date DateToPrint)
{
    printf("%02d/%02d/%d\n",DateToPrint.month,DateToPrint.day,DateToPrint.year);
}

struct date advanceDay(struct date DateNow)
{
    struct date nextDay;

    nextDay = DateNow;
    
    if(DateNow.month == 2) //Feb
    {
        if(DateNow.day == 28)
        {
            nextDay.month = 3;
            nextDay.day = 1;
        }
        else 
        {
            nextDay.day = DateNow.day + 1;
        }
    }
    else if(DateNow.month == 4 || DateNow.month == 6 ||  DateNow.month == 9 ||  DateNow.month == 11) //30 day months
    {
        if(DateNow.day == 30)
        {
            nextDay.month = DateNow.month + 1;
            nextDay.day = 1;
        }
        else 
        {
            nextDay.day = DateNow.day + 1;
        }
    }
    else if(DateNow.month == 12) //dec
    {
        if(DateNow.day == 31)
        {
            nextDay.month = 1;
            nextDay.year = DateNow.year + 1;
            nextDay.day = 1;
        }
        else 
        {
            nextDay.day = DateNow.day + 1;
        }
    }
    else //31 day months other than december
    {
        if(DateNow.day == 31)
        {
            nextDay.month = DateNow.month + 1;
            nextDay.day = 1;
        }
        else 
        {
            nextDay.day = DateNow.day + 1;
        }

    }



    return nextDay;
}

