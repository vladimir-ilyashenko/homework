//#include "stdafx.h"
#include <iostream>


using namespace std;

int get_days_in_month (int month_number){
  if (month_number == 1 || month_number == 3 || month_number == 5 || month_number == 7 || month_number == 8 || month_number == 10 || month_number == 12 ) {
    return 31;
  }
  else if (month_number == 4 || month_number == 6 || month_number == 9 || month_number == 11 ) {
    return 30;
  }
  else {
    return 28;
  }
}

int get_days_in_year (int year_number) {
  int days = 365;
  if (year_number % 4 == 0) {
    days += 1;
    if (year_number % 100 == 0) {
      days -= 1;
      if (year_number % 400 == 0) {
        days += 1;
      }
    }
  }
  return days;
}

int calculate_days_in_months (int month, int year) {
  int days = 0;
  while (month > 1) {
    if (get_days_in_year(year) == 366 && month == 3) {
      days = days + 29;
    }
    else {
      days = days + get_days_in_month(month - 1);
    }
    month --;
  }
  return days;
}

int calculate_days_in_years (int year) {
  int days = 0;
  while (year > 1)
  {
    days = days + get_days_in_year(year - 1);
    year --;
  }
  return days;
}

int main()
{
  int first_day;
  int second_day;
  int first_month;
  int second_month;
  int first_year;
  int second_year;

  cout << "Enter first date day" << endl;
  cin >> first_day;
  cout << "Enter first date month" << endl;
  cin >> first_month;
  cout << "Enter first date year" << endl;
  cin >> first_year;

  cout << "Enter second date day" << endl;
  cin >> second_day;
  cout << "Enter second date month" << endl;
  cin >> second_month;
  cout << "Enter second date year" << endl;
  cin >> second_year;

  int diff = 0;
  int first_date_days = first_day;
  int second_date_days = second_day;

  first_date_days = first_date_days + calculate_days_in_months(first_month, first_year);
  second_date_days = second_date_days + calculate_days_in_months(second_month, second_year);

  first_date_days = first_date_days + calculate_days_in_years(first_year);
  second_date_days = second_date_days + calculate_days_in_years(second_year);

  diff = second_date_days - first_date_days;

  cout << "Difference is: " << diff << endl;

  return 0;
}
