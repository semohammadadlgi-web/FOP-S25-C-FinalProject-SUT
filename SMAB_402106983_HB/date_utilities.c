

/**
 * This is the file that implement of date handling and validation functions occurs:
 * 
 * Its contains date-related functions for parsing, validating, and calculating date differences.
 */

  // libraries and headings
 #include "date_utilities.h"
 #include <stdio.h>      
 #include <string.h>      
 #include <ctype.h>        
 #include <time.h>         
 

 //  Validates a date string in YYYY-MM-DD format (the format must be this or the program crash(when you are bokking a room))


 bool validate_date(const char *date) {
     int y, m, d;
     // Parse the date string into components
     if (sscanf(date, "%d-%d-%d", &y, &m, &d) != 3) return false;
     // Validate ranges
     return (y >= 2024 && m >= 1 && m <= 12 && d >= 1 && d <= 31);
 }
 

 // Parses various date formats into YYYY-MM-DD format


 void parse_date(const char *input, char *output) {
     int y, m, d;

     if (sscanf(input, "%d-%d-%d", &y, &m, &d) == 3) {
         sprintf(output, "%04d-%02d-%02d", y, m, d);
     } 

     else if (sscanf(input, "%d/%d/%d", &d, &m, &y) == 3) {
         sprintf(output, "%04d-%02d-%02d", y, m, d);
     } 

     else {
         strcpy(output, "invalid");
     }
 }
 

 // Calculates the number of nights between two dates


 int calculate_duration(const char *check_in, const char *check_out) {
     struct tm tm1 = {0}, tm2 = {0};

     sscanf(check_in, "%d-%d-%d", &tm1.tm_year, &tm1.tm_mon, &tm1.tm_mday);

     sscanf(check_out, "%d-%d-%d", &tm2.tm_year, &tm2.tm_mon, &tm2.tm_mday);
     
     tm1.tm_year -= 1900; 
     tm1.tm_mon -= 1;
     tm2.tm_year -= 1900;
     tm2.tm_mon -= 1;
     
     time_t t1 = mktime(&tm1);
     time_t t2 = mktime(&tm2);
     
     return (t2 - t1) / (60 * 60 * 24);
 }
 

 // Checks if a date is today or in the future (so no scaming in booking happen)

 bool is_date_in_future(const char *date) {
     time_t now = time(NULL);
     struct tm *now_tm = localtime(&now);
     char today[11];

     strftime(today, sizeof(today), "%Y-%m-%d", now_tm);
     
     return strcmp(date, today) >= 0;
 }
 

 //  Calculates the start and end dates of the week for a given date

 void get_week_range(const char *date, char *start_date, char *end_date) {
     int year, month, day;

     sscanf(date, "%d-%d-%d", &year, &month, &day);
 
     struct tm tm = {0};
     tm.tm_year = year - 1900;
     tm.tm_mon = month - 1;
     tm.tm_mday = day;

     mktime(&tm);
 
     int days_to_monday = (tm.tm_wday == 0) ? -6 : 1 - tm.tm_wday;
     
     struct tm monday = tm;
     monday.tm_mday += days_to_monday;
     mktime(&monday); 
 
     struct tm sunday = monday;
     sunday.tm_mday += 6;
     mktime(&sunday); 
 
     strftime(start_date, 11, "%Y-%m-%d", &monday);
     strftime(end_date, 11, "%Y-%m-%d", &sunday);
 }