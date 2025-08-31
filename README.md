
// SMAB //    // 402106983 //   //FOP//

 ## Hotel Booking Project ##
  =======================

A graphical hotel booking system programmed by C language

 ## Features 
----------
# Core Functionality
- User Registration & Authentication - (signup and login system, ...)
- Room Management - (Browse, filter, and book available rooms, ...)
- Booking System - (With Data, Price and Facilities, ...)
- Admin Dashboard - (View profit, change password, View booked room, ...) 
- Receipt Generation 

# Validation & Security
- Date validation and conflict checking
- Input sanitization and format verification
- Admin password protection
- Room availability checking

# Administrative Features
- View all bookings and filter results
- Revenue reporting (daily & weekly)
- Password management
- System monitoring

# How to Compile the application
gcc main.c gui_management.c booking_operations.c room_management.c \
    file_operations.c date_utilities.c validation.c \
    -o hotel-system `pkg-config --cflags --libs gtk+-3.0` -lm
    
** Code Files contains several comments that try to clarify the process **

Thank you for your attention

