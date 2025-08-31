

/**
 * This is the file that implement of input validation functions occurs:
 * 
 * Its contains functions for validating user inputs, credentials,and business rules to ensure data integrity.
 */

   // libraries and headings
 #include "validation.h"
 #include "file_operations.h"
 #include <string.h>
 #include <stdio.h>
 #include <ctype.h>
 
 // Checks if a room is available for given dates

 bool is_room_available(int room_number, const char *check_in, const char *check_out) {
     FILE *file = fopen(BOOKING_FILE, "r");
     if (!file) return true; 
 
     char line[MAX_LEN * 3];
     char username[MAX_LEN], status[20], booking_date[20], check_in_date[20], check_out_date[20];
     int booking_room_number, booking_id;
     float total_price;
 

     while (fgets(line, sizeof(line), file)) {

         sscanf(line, "%[^:]:%d:%[^:]:%[^:]:%[^:]:%f:%[^:]:%d", username, &booking_room_number, booking_date, check_in_date, check_out_date, &total_price, 
                status, &booking_id);
 
         if (booking_room_number == room_number && strcmp(status, "active") == 0) {

             if (!(strcmp(check_out, check_in_date) <= 0 || strcmp(check_in, check_out_date) >= 0)) {
                 fclose(file);
                 return false; 
             }
         }
     }
     fclose(file);
     return true; 
 }
 

 // Validates administrator password

 bool validate_admin_password(const char *password) {
     FILE *file = fopen(ADMIN_PASS_FILE, "r");
     if (file == NULL) {

         file = fopen(ADMIN_PASS_FILE, "w");
         fprintf(file, "admin123\n");
         fclose(file);
         return strcmp(password, "admin123") == 0;
     }
 
     char stored_password[MAX_LEN];
     fgets(stored_password, sizeof(stored_password), file);
     fclose(file);
     

     stored_password[strcspn(stored_password, "\n")] = 0;
     
     return strcmp(password, stored_password) == 0;
 }
 
 // Checks if a user profile exists

 bool profile_exists(const char *username) {
     FILE *file = fopen(USER_PROFILE_FILE, "r");
     if (file == NULL) {
         return false; 
     }
 
     char line[MAX_LEN * 4];

     while (fgets(line, sizeof(line), file)) {
         char saved_username[MAX_LEN];

         sscanf(line, "%[^:]:", saved_username);
         if (strcmp(username, saved_username) == 0) {
             fclose(file);
             return true; 
         }
     }
     fclose(file);
     return false; 
 }
 
 // Validates username format

 bool is_valid_username(const char *username) {
     if (username == NULL || strlen(username) < 3 || strlen(username) > 20) {
         return false;
     }
     
     if (!isalpha(username[0])) {
         return false;
     }
     
     for (int i = 0; username[i] != '\0'; i++) {
         if (!isalnum(username[i]) && username[i] != '_') {
             return false;
         }
     }
     return true;
 }
 
 // Validates phone number format

 bool is_valid_phone(const char *phone) {
     if (phone == NULL || strlen(phone) < 10 || strlen(phone) > 15) {
         return false;
     }
     
     for (int i = 0; phone[i] != '\0'; i++) {
         if (!isdigit(phone[i])) {
             return false;
         }
     }
     return true;
 }