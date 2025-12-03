// main.c
#include <stdio.h>
#include "parking.h"

int main() {
    int choice;

    loadFromFile();  // Load previous data

    while (1) {
        printf("\n=== PARKING MANAGEMENT SYSTEM ===\n");
        printf("1. Add Vehicle\n");
        printf("2. Remove Vehicle\n");
        printf("3. Display All Vehicles\n");
        printf("4. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addVehicle();
                break;
            case 2:
                removeVehicle();
                break;
            case 3:
                displayVehicles();
                break;
            case 4:
                saveToFile();
                printf("\nData Saved. Exiting...\n");
                return 0;
            default:
                printf("Invalid Choice! Try again.\n");
        }
    }

    return 0;
}
