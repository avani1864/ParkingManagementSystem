// parking.c
#include <stdio.h>
#include <string.h>
#include "parking.h"

Vehicle parkingList[MAX];
int count = 0;

// Load data from file when system starts
void loadFromFile() {
    FILE *fp = fopen("parking_data.txt", "r");
    if (fp != NULL) {
        fread(&count, sizeof(int), 1, fp);
        fread(parkingList, sizeof(Vehicle), count, fp);
        fclose(fp);
    }
}

// Save data to file
void saveToFile() {
    FILE *fp = fopen("parking_data.txt", "w");
    fwrite(&count, sizeof(int), 1, fp);
    fwrite(parkingList, sizeof(Vehicle), count, fp);
    fclose(fp);
}

// Calculate parking charges
float calculateCharge(Vehicle *v) {
    if (strcmp(v->type, "car") == 0)
        return v->hours * 20;
    else if (strcmp(v->type, "bike") == 0)
        return v->hours * 10;
    else if (strcmp(v->type, "truck") == 0)
        return v->hours * 30;
    else
        return v->hours * 15;
}

// Add a new vehicle
void addVehicle() {
    if (count >= MAX) {
        printf("\nParking Full!\n");
        return;
    }

    Vehicle v;
    v.id = count + 1;

    printf("\nEnter Vehicle Type (car/bike/truck): ");
    scanf("%s", v.type);

    printf("Enter Vehicle Number: ");
    scanf("%s", v.number);

    printf("Enter Hours Parked: ");
    scanf("%d", &v.hours);

    v.charge = calculateCharge(&v);

    parkingList[count] = v;
    count++;

    printf("\nVehicle Added Successfully! Charge = %.2f\n", v.charge);
}

// Remove a vehicle by ID
void removeVehicle() {
    int id;
    printf("\nEnter Vehicle ID to remove: ");
    scanf("%d", &id);

    if (id <= 0 || id > count) {
        printf("Invalid ID!\n");
        return;
    }

    for (int i = id - 1; i < count - 1; i++) {
        parkingList[i] = parkingList[i + 1];
        parkingList[i].id = i + 1; // update ID numbers
    }

    count--;
    printf("Vehicle Removed Successfully!\n");
}

// Display all vehicles
void displayVehicles() {
    if (count == 0) {
        printf("\nNo vehicles parked.\n");
        return;
    }

    printf("\n----- CURRENTLY PARKED VEHICLES -----\n");
    printf("ID\tType\tNumber\tHours\tCharge\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%s\t%d\t%.2f\n",
               parkingList[i].id,
               parkingList[i].type,
               parkingList[i].number,
               parkingList[i].hours,
               parkingList[i].charge);
    }
}
