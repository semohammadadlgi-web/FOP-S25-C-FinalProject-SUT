

/**
 * This is the file that implement of room management functions occurs:
 * 
 * Its contains functions for loading, filtering, and sorting hotel rooms from the data file.
 */

   // libraries and headings
 #include "room_management.h"
 #include "file_operations.h"  
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 

 // Comparison function for sorting rooms by price

 int compare_rooms_by_price(const void *a, const void *b) {
     const Room *room_a = (const Room *)a;
     const Room *room_b = (const Room *)b;
     if (room_a->price < room_b->price) return -1;
     if (room_a->price > room_b->price) return 1;
     return 0;
 }
 
 // Loads rooms from file with optional filtering

 void load_rooms(RoomFilter *filter) {
     FILE *file = fopen(ROOM_FILE, "r");  
     if (file == NULL) return;
     // the main function for this part actually define in gui_managment.c 
 
     fclose(file);
 }