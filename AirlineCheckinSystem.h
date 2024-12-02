//
#ifndef AIRLINECHECKINSYSTEM_H
#define AIRLINECHECKINSYSTEM_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

enum class CheckinType { Counter, Kiosk };

struct Passenger {
    string id;
    string name;
    bool carryOnOnly;
    int checkedBags;
    CheckinType checkinType;
};

class AirlineCheckinSystem {
private:
    vector<Passenger*> passengers;

    void displayPassenger(const Passenger* passenger);
    void saveData();
    void loadData();
    void deletePassengers(); // To free allocated memory

public:
    AirlineCheckinSystem();
    ~AirlineCheckinSystem(); // Destructor to clean up dynamic memory
    void addPassenger();
    void checkInPassenger();
    void displayAllPassengers();
    void saveAndExit();
};

#endif

