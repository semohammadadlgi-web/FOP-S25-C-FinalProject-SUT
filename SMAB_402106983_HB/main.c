


// SMAB //    // 402106983 //   //FOP//

/**
 * This is the file that contain Main entry point for the Hotel Booking System (project):
 * 
 * Generally its contains the main function and global variable definitions.
 * It initializes the system and starts the GUI (in this project we use gtk libary) main loop.
 */

 // libraries and headings
 #include <gtk/gtk.h>
 #include "gui_management.h"
 #include "file_operations.h"
 
 // Global variable definitions (this ones declared in gui_management.h)

 GtkWidget *window = NULL;              
 GtkWidget *stack = NULL;               
 GtkWidget *status_label = NULL;        
 char current_user[MAX_LEN] = "";       
 bool is_admin_logged_in = false; 

 /**
  * Main function :
  * Initializes the data files and starts the GUI application.
  */

 int main(int argc, char *argv[]) {
     // Initialize data files 
     initialize_files();
     
     // Start the GUI application
     initialize_gui(argc, argv);
     
     // Run the GTK main loop (it will be blocked until application exits)
     gtk_main();
     
     return 0;
 }