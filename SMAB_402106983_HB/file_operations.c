

/**
 * This is the file that implement of file operations occurs:
 * 
 * Its Contains functions for handling all file operations including user data, room data, bookings, and system configuration.
 */

   // libraries and headings
 #include "file_operations.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/stat.h>  
 

 // Initializes all data files required by the project manual

 void initialize_files() {

     #ifdef _WIN32
         system("mkdir data 2>nul");  
     #else
         mkdir("data", 0755);      // this line was forced to write because compiler keep giving eror about implicit declaration of function
     #endif
     
     FILE *file;
     
     file = fopen(ROOM_FILE, "r");
     if (file == NULL) {
         file = fopen(ROOM_FILE, "w");

         fprintf(file, "101:Single:100.00:Available:WiFi,TV,AC\n");
         fprintf(file, "102:Double:150.00:Available:WiFi,TV,AC,Meal Service\n");
         fprintf(file, "103:Suite:300.00:Available:WiFi,TV,AC,Meal Service,Jacuzzi\n");
         fprintf(file, "104:Single:120.00:Available:WiFi,TV,AC,Balcony\n");
         fprintf(file, "105:Double:180.00:Available:WiFi,TV,AC,Meal Service,Balcony\n"); 
          // more rooms can be add in rooms.txt manually
         fclose(file);
     } else {
         fclose(file);
     }
 
     file = fopen(BOOKING_FILE, "r");
     if (file == NULL) {
         file = fopen(BOOKING_FILE, "w");
         fclose(file);
     } else {
         fclose(file);
     }
 
     file = fopen(USER_FILE, "r");
     if (file == NULL) {
         file = fopen(USER_FILE, "w");
         fclose(file);
     } else {
         fclose(file);
     }
 
     file = fopen(USER_PROFILE_FILE, "r");
     if (file == NULL) {
         file = fopen(USER_PROFILE_FILE, "w");
         fclose(file);
     } else {
         fclose(file);
     }
 
     file = fopen(ADMIN_PASS_FILE, "r");
     if (file == NULL) {
         file = fopen(ADMIN_PASS_FILE, "w");
         fprintf(file, "admin123\n");  // Default admin password (it can change by progarm itself or changing it in admin_pass.txt manually)
         fclose(file);
     } else {
         fclose(file);
     }
 }
 

 // Changes the admin password

 void change_admin_password(const char *new_password) {
     FILE *file = fopen(ADMIN_PASS_FILE, "w");
     if (file == NULL) {
         return; 
     }
     fprintf(file, "%s\n", new_password);
     fclose(file);
 }
 

 // Saves user profile information

 void save_user_profile(const char *username, const char *full_name, const char *id_number, const char *email, const char *address, const char *phone) {                   
     
    FILE *file = fopen(USER_PROFILE_FILE, "r");
     if (file != NULL) {
         char line[MAX_LEN * 4];
         char temp_file[] = "data/temp_profiles.txt";
         FILE *temp = fopen(temp_file, "w");
         
         int found = 0;

         while (fgets(line, sizeof(line), file)) {
             char saved_username[MAX_LEN];
             sscanf(line, "%[^:]:", saved_username);
             
             if (strcmp(username, saved_username) == 0) {

                 fprintf(temp, "%s:%s:%s:%s:%s:%s\n", username, full_name, id_number, email, address, phone);

                 found = 1;

             } else {

                 fputs(line, temp);
             }
         }
         
         if (!found) {

             fprintf(temp, "%s:%s:%s:%s:%s:%s\n", username, full_name, id_number, email, address, phone); 
                    
         }
         
         fclose(file);
         fclose(temp);
         
         remove(USER_PROFILE_FILE);
         rename(temp_file, USER_PROFILE_FILE);
         return;
     }
     
     file = fopen(USER_PROFILE_FILE, "a");
     if (file == NULL) return;
     fprintf(file, "%s:%s:%s:%s:%s:%s\n", username, full_name, id_number, email, address, phone); 
            
     fclose(file);
 }
 

 // Retrieves user profile information

 void get_user_profile(const char *username, char *full_name, char *id_number, char *email, char *address, char *phone) { 
                     
     FILE *file = fopen(USER_PROFILE_FILE, "r");
     if (file == NULL) {

         strcpy(full_name, "");
         strcpy(id_number, "");
         strcpy(email, "");
         strcpy(address, "");
         strcpy(phone, "");
         return;
     }
 
     char line[MAX_LEN * 4];
     char current_username[MAX_LEN];

     while (fgets(line, sizeof(line), file)) {

         sscanf(line, "%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]", current_username, full_name, id_number, email, address, phone); 
               
         if (strcmp(username, current_username) == 0) {
             fclose(file);

         }
     }
     fclose(file);
     
     strcpy(full_name, "");
     strcpy(id_number, "");
     strcpy(email, "");
     strcpy(address, "");
     strcpy(phone, "");
 }
 

 // Registers a new user

 bool register_user(const char *username, const char *phone) {
     if (username_exists(username)) {
         return false; 
     }
     
     FILE *file = fopen(USER_FILE, "a");
     if (file == NULL) return false;
     

     fprintf(file, "%s:%s\n", username, phone);
     fclose(file);
     return true;
 }
 

 // Validates user credentials

 bool validate_user_credentials(const char *username, const char *phone) {
     FILE *file = fopen(USER_FILE, "r");
     if (file == NULL) return false;
 
     char line[MAX_LEN];

     while (fgets(line, sizeof(line), file)) {
         char saved_username[MAX_LEN], saved_phone[15];

         sscanf(line, "%[^:]:%s", saved_username, saved_phone);
         if (strcmp(username, saved_username) == 0 && strcmp(phone, saved_phone) == 0) {
             fclose(file);
             return true; 
         }
     }
     fclose(file);
     return false; 
 }
 

  // Checks if a username already exists

 bool username_exists(const char *username) {
     FILE *file = fopen(USER_FILE, "r");
     if (file == NULL) return false;
 
     char line[MAX_LEN];

     while (fgets(line, sizeof(line), file)) {
         char saved_username[MAX_LEN], saved_phone[15];

         sscanf(line, "%[^:]:%s", saved_username, saved_phone);
         if (strcmp(username, saved_username) == 0) {
             fclose(file);
             return true; 
         }
     }
     fclose(file);
     return false; 
 }