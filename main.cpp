//
#include "AirlineCheckinSystem.h"

int main() {
    AirlineCheckinSystem system;

    int choice;
    do {
        cout << "\n--- Airline Check-in System ---\n";
        cout << "1. Add Passenger\n";
        cout << "2. Check-in Passenger\n";
        cout << "3. Display All Passengers\n";
        cout << "4. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addPassenger();
                break;
            case 2:
                system.checkInPassenger();
                break;
            case 3:
                system.displayAllPassengers();
                break;
            case 4:
                system.saveAndExit();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
