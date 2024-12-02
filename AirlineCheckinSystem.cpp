//
#include "AirlineCheckinSystem.h"
#include <sstream>

// Constructor: Load data from file
AirlineCheckinSystem::AirlineCheckinSystem() {
    loadData();
}

// Destructor: Clean up dynamically allocated memory
AirlineCheckinSystem::~AirlineCheckinSystem() {
    deletePassengers();
}

// Helper function to display a single passenger
void AirlineCheckinSystem::displayPassenger(const Passenger* passenger) {
    cout << setw(10) << passenger->id
         << setw(20) << passenger->name
         << setw(15) << (passenger->carryOnOnly ? "Yes" : "No")
         << setw(15) << passenger->checkedBags
         << setw(15) << (passenger->checkinType == CheckinType::Counter ? "Counter" : "Kiosk")
         << "\n";
}

// Add a new passenger
void AirlineCheckinSystem::addPassenger() {
    Passenger* newPassenger = new Passenger;
    cout << "Enter Passenger ID: ";
    cin >> newPassenger->id;
    cin.ignore(); // Clear input buffer
    cout << "Enter Passenger Name: ";
    getline(cin, newPassenger->name);
    cout << "Carry-on only (1 for Yes, 0 for No): ";
    cin >> newPassenger->carryOnOnly;

    if (newPassenger->carryOnOnly) {
        newPassenger->checkedBags = 0;
        newPassenger->checkinType = CheckinType::Kiosk;
    } else {
        cout << "Number of checked bags: ";
        cin >> newPassenger->checkedBags;
        newPassenger->checkinType = CheckinType::Counter;
    }

    passengers.push_back(newPassenger);
    cout << "Passenger added successfully!\n";
}

// Check in a passenger
void AirlineCheckinSystem::checkInPassenger() {
    string passengerID;
    cout << "Enter Passenger ID for check-in: ";
    cin >> passengerID;

    for (const auto& passenger : passengers) {
        if (passenger->id == passengerID) {
            cout << "Passenger found:\n";
            displayPassenger(passenger);
            cout << "Check-in successful!\n";
            return;
        }
    }

    cout << "Passenger not found.\n";
}

// Display all passengers
void AirlineCheckinSystem::displayAllPassengers() {
    cout << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Carry-on"
         << setw(15) << "Bags"
         << setw(15) << "Check-in\n";

    for (const auto& passenger : passengers) {
        displayPassenger(passenger);
    }
}

// Save passenger data to file
void AirlineCheckinSystem::saveData() {
    ofstream outFile("PassengerData.txt");
    for (const auto& passenger : passengers) {
        outFile << passenger->id << ","
                << passenger->name << ","
                << passenger->carryOnOnly << ","
                << passenger->checkedBags << ","
                << static_cast<int>(passenger->checkinType) << "\n";
    }
    outFile.close();
}

// Load passenger data from file
void AirlineCheckinSystem::loadData() {
    ifstream inFile("PassengerData.txt");
    if (!inFile) return;

    string line;
    while (getline(inFile, line)) {
        Passenger* newPassenger = new Passenger;
        stringstream ss(line);
        string token;

        getline(ss, token, ',');
        newPassenger->id = token;

        getline(ss, token, ',');
        newPassenger->name = token;

        getline(ss, token, ',');
        newPassenger->carryOnOnly = stoi(token);

        getline(ss, token, ',');
        newPassenger->checkedBags = stoi(token);

        getline(ss, token, ',');
        newPassenger->checkinType = static_cast<CheckinType>(stoi(token));

        passengers.push_back(newPassenger);
    }

    inFile.close();
}

// Free dynamically allocated memory
void AirlineCheckinSystem::deletePassengers() {
    for (auto& passenger : passengers) {
        delete passenger;
    }
    passengers.clear();
}

// Save data and exit program
void AirlineCheckinSystem::saveAndExit() {
    saveData();
    cout << "Data saved successfully. Exiting program.\n";
}

