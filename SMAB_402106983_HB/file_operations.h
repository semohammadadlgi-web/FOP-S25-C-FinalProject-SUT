

/**
 * Heading file for file_operations
 */ 

 #ifndef FILE_OPERATIONS_H
 #define FILE_OPERATIONS_H
 
 #include "booking_operations.h"
 #include "room_management.h"
 
 #define ROOM_FILE "data/rooms.txt"              
 #define BOOKING_FILE "data/bookings.txt"       
 #define USER_FILE "data/users.txt"              
 #define USER_PROFILE_FILE "data/user_profiles.txt" 
 #define ADMIN_PASS_FILE "data/admin_pass.txt" 

 void initialize_files();

 void change_admin_password(const char *new_password);

 void save_user_profile(const char *username, const char *full_name, const char *id_number, const char *email, const char *address, const char *phone); 
                       
 void get_user_profile(const char *username, char *full_name, char *id_number, char *email, char *address, char *phone); 
                     
 bool register_user(const char *username, const char *phone);

 bool validate_user_credentials(const char *username, const char *phone);

 bool username_exists(const char *username);
 
 #endif