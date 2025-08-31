

/**
 * This is the file that implement of booking-related functions occurs:
 * 
 * it contains functions for managing bookings, calculating revenue,and generating receipts.
 */

 // libraries and headings
 #include "booking_operations.h"
 #include "file_operations.h"
 #include <stdio.h>
 #include <string.h>
 #include <time.h>
 

 //Calculates of daily revenue for a specific date

 float calculate_daily_revenue(const char *date) {
     FILE *file = fopen(BOOKING_FILE, "r");
     if (file == NULL) return 0.0;
 
     float revenue = 0.0;
     char line[MAX_LEN * 3];
     char username[MAX_LEN], status[20], booking_date[20], check_in_date[20], check_out_date[20];
     int room_number, booking_id;
     float total_price;
 
     
     while (fgets(line, sizeof(line), file)) {
         
         sscanf(line, "%[^:]:%d:%[^:]:%[^:]:%[^:]:%f:%[^:]:%d",
                username, &room_number, booking_date,
                check_in_date, check_out_date, &total_price,
                status, &booking_id);
         
         if (strncmp(booking_date, date, 10) == 0 && strcmp(status, "active") == 0) {
             revenue += total_price;
         }
     }
     fclose(file);
     
     return revenue;
 }
 
 // Calculates weekly revenue for a specific date

 float calculate_weekly_revenue(const char *date) {
     char start_date[11], end_date[11];

     get_week_range(date, start_date, end_date);
 
     FILE *file = fopen(BOOKING_FILE, "r");
     if (file == NULL) return 0.0;
 
     float revenue = 0.0;
     char line[MAX_LEN * 3];
     char username[MAX_LEN], status[20], booking_date[20], check_in_date[20], check_out_date[20];
     int room_number, booking_id;
     float total_price;
     

     while (fgets(line, sizeof(line), file)) {

         sscanf(line, "%[^:]:%d:%[^:]:%[^:]:%[^:]:%f:%[^:]:%d",
                username, &room_number, booking_date,
                check_in_date, check_out_date, &total_price,
                status, &booking_id);
         
         char booking_date_only[11];
         strncpy(booking_date_only, booking_date, 10);
         booking_date_only[10] = '\0';
 
         if (strcmp(booking_date_only, start_date) >= 0 && 
             strcmp(booking_date_only, end_date) <= 0 && 
             strcmp(status, "active") == 0) {
             revenue += total_price;
         }
     }
     fclose(file);
     
     return revenue;
 }
 
//** this two function acctually Implement in gui_management.c **/
// Displays a booking receipt
 void display_receipt(Booking *booking) {
 }
// Loads receipt history for a user
 void load_receipt_history(const char *username) {
 }