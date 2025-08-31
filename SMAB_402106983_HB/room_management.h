

/**
 * Heading file for room_managment
 */ 

 #ifndef ROOM_MANAGEMENT_H
 #define ROOM_MANAGEMENT_H
 
 #include "validation.h"
 
 // Room structure representing a hotel room

 typedef struct {
     int room_number;       
     char type[20];          
     float price;           
     char status[20];        
     char facilities[100];   
 } Room;

 typedef struct {
     float min_price;        
     float max_price;       
     char type[20];          
     char facilities[100];   
 } RoomFilter;
 
 void load_rooms(RoomFilter *filter);
 
 int compare_rooms_by_price(const void *a, const void *b);
 
 #endif