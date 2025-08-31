

/**
 * Heading filr for booking_operations
 */

 #ifndef BOOKING_OPERATIONS_H
 #define BOOKING_OPERATIONS_H
 
 #include "validation.h"
 #include "date_utilities.h"
 
 typedef struct {
     int booking_id;             
     int room_number;            
     char username[MAX_LEN];    
     char booking_date[20];      
     char check_in_date[20];     
     char check_out_date[20];    
     float total_price;          
     char status[20];            
 } Booking;
 
 typedef struct {
     int booking_id;           
     char username[MAX_LEN];    
     char start_date[20];       
     char end_date[20];          
 } BookingFilter;
 
 void load_user_bookings(const char *username);
 
 void load_all_bookings(BookingFilter *filter);
 
 float calculate_daily_revenue(const char *date);
 
 float calculate_weekly_revenue(const char *date);
 
 void display_receipt(Booking *booking);

 void load_receipt_history(const char *username);
 
 #endif