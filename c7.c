#include <stdio.h>

int calculateN(int year, int month, int day) {
    // This function should calculate the N value based on your specific method.
    // For now, it's a placeholder and needs to be implemented correctly.

    // Simple placeholder for demonstration: count days since 0001-01-01
    int n = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    
    // Add the days for the months passed in the current year
    int daysInMonths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    for (int i = 0; i < month - 1; i++) {
        n += daysInMonths[i];
    }

    // Add a day if it's a leap year and we're past February
    if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        n++;
    }

    // Add the days in the current month
    n += day;

    return n;
}

const char* dayOfWeek(int n) {
    const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return days[n % 7];
}

int main() {
    int year, month, day;
    printf("Enter year, month, day (YYYY MM DD): ");
    scanf("%d %d %d", &year, &month, &day);

    int n = calculateN(year, month, day) - 621049;
    printf("The day of the week is: %s\n", dayOfWeek(n));

    return 0;
}
