int compare_dates(Date d1, Date d2) {
    if (d1.year < d2.year || (d1.year == d2.year && d1.month < d2.month) || (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day))
        return -1;
    else if (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day)
        return 0;
    else
        return 1;
}
