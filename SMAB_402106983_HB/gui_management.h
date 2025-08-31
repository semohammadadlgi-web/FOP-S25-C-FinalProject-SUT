

/**
 * Heading file for gui_management
 */

 #ifndef GUI_MANAGEMENT_H
 #define GUI_MANAGEMENT_H
 
 #include <gtk/gtk.h>
 #include "booking_operations.h"
 #include "room_management.h"
 
 extern GtkWidget *window;        
 extern GtkWidget *stack;         
 extern GtkWidget *status_label;  
 extern char current_user[MAX_LEN]; 
 extern bool is_admin_logged_in; 
 
 void initialize_gui(int argc, char *argv[]);
 void show_main_menu();
 void show_customer_login();
 void show_customer_menu();
 void show_admin_login();
 void show_admin_menu();
 void show_room_browse();
 void show_booking_manage();
 void show_receipt_history();
 void show_admin_bookings();
 void show_admin_change_password_screen();
 void update_status(const char *message);
 
 void on_customer_login_clicked(GtkWidget *widget, gpointer data);
 void on_admin_login_clicked(GtkWidget *widget, gpointer data);
 void on_back_to_main_clicked(GtkWidget *widget, gpointer data);
 void on_customer_login_submit_clicked(GtkWidget *widget, gpointer data);
 void on_admin_login_submit_clicked(GtkWidget *widget, gpointer data);
 void on_browse_rooms_clicked(GtkWidget *widget, gpointer data);
 void on_view_bookings_clicked(GtkWidget *widget, gpointer data);
 void on_view_receipt_history_clicked(GtkWidget *widget, gpointer data);
 void on_filter_rooms_clicked(GtkWidget *widget, gpointer data);
 void on_book_room_clicked(GtkWidget *widget, gpointer data);
 void on_cancel_booking_clicked(GtkWidget *widget, gpointer data);
 void on_admin_change_password_clicked(GtkWidget *widget, gpointer data);
 void on_admin_view_revenue_clicked(GtkWidget *widget, gpointer data);
 void on_admin_filter_bookings_clicked(GtkWidget *widget, gpointer data);
 void on_sign_up_clicked(GtkWidget *widget, gpointer data);
 void on_sign_up_submit_clicked(GtkWidget *widget, gpointer data);
 void on_back_to_login_clicked(GtkWidget *widget, gpointer data);
 void on_manage_profile_clicked(GtkWidget *widget, gpointer data);
 
 
 #endif