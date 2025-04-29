#include<stdio.h>

#define TRUE 1
#define FALSE 0

int days_in_month[] = {0 , 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int input_year()
{
  int year;
  printf("Enter year: ");
  scanf("%d", &year);
  return year;
}

int determineLeapYear(int year)
{
  if (year % 4 == FALSE && year % 100 != FALSE || year % 400 == FALSE)
   {
      days_in_month[2] = 29; // February has 29 days in a leap year
      return TRUE;
   }
   else{
      days_in_month[2] = 28; // February has 28 days in a non-leap year
      return FALSE;
   }
}

int determinedaycode(int year){
  int daycode;
  int d1,d2,d3;
  d1 = (year - 1) % 4; // leap year
  d2 = (year - 1) % 100; // week day
  d3 = (year - 1) % 400; // month
  daycode = ( year + d1 - d2 + d3) % 7; // day code
  return daycode;
}

void calender(int year, int daycode)
{
   int month ,day;
   for (month = 1; month <= 12; month++)
   {
      printf("\n\n\t\t\t\t%s %d\n", months[month - 1], year);
      printf("Sun Mon Tue Wed Thu Fri Sat\n");
      for (day = 1; day <= days_in_month[month]; day++)
      {
         if (day == 1)
         {
            for (int i = 0; i < daycode; i++)
            {
               printf("    ");
            }
         }
         printf("%3d ", day);
         if ((day + daycode) % 7 == 0)
         {
            printf("\n");
         }
      }
      daycode = (daycode + days_in_month[month]) % 7;
   }
    printf("\n\n");
    printf("Press any key to continue...\n");
    getchar();
}

int main()
{
    int year, daycode;
    year = input_year();
    determineLeapYear(year);
    daycode = determinedaycode(year);
    calender(year, daycode);
    return 0;
}
