#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};

int is_leap_year(int year) {
    // A leap year is divisible by 4, but not by 100 unless also divisible by 400
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int day_of_year(struct date d) {
    int days_per_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int day_of_year = 0;

    // Adjust for leap year
    if (is_leap_year(d.year)) {
        days_per_month[1] = 29; // February has 29 days in a leap year
    }

    // Sum the days in the previous months
    for (int i = 0; i < d.month - 1; i++) {
        day_of_year += days_per_month[i];
    }

    // Add the days in the current month
    day_of_year += d.day;

    return day_of_year;
}

int main() {
    struct date d;

    printf("Enter date (MM DD YYYY): ");
    scanf("%d %d %d", &d.month, &d.day, &d.year);

    printf("The day of the year is: %d\n", day_of_year(d));

    return 0;
}
