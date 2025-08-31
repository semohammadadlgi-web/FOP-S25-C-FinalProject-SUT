

/**
 * Heading file for data_utilities
 */ 

 #ifndef DATE_UTILITIES_H
 #define DATE_UTILITIES_H
 
 #include <stdbool.h>
 #include <time.h>
 

 bool validate_date(const char *date);
 
 void parse_date(const char *input, char *output);
 
 int calculate_duration(const char *check_in, const char *check_out);
 
 bool is_date_in_future(const char *date);

 void get_week_range(const char *date, char *start_date, char *end_date);
 
 #endif