

/**
 * Heading file for validation
 */ 

 #ifndef VALIDATION_H
 #define VALIDATION_H
 
 #include <stdbool.h>
 
 #define MAX_LEN 100
 #define MAX_USERS 100
 #define MAX_ROOMS 100
 #define MAX_BOOKINGS 100

 bool is_room_available(int room_number, const char *check_in, const char *check_out);

 bool validate_admin_password(const char *password);

 bool profile_exists(const char *username);

 bool is_valid_username(const char *username);
 
 bool is_valid_phone(const char *phone);
 
 #endif