// parking.h
#ifndef PARKING_H
#define PARKING_H

#define MAX 100

// Structure for storing vehicle details
typedef struct {
    int id;
    char type[20];
    char number[20];
    int hours;
    float charge;
} Vehicle;

// Function declarations
void addVehicle();
void removeVehicle();
void displayVehicles();
float calculateCharge(Vehicle *v);
void saveToFile();
void loadFromFile();

#endif
