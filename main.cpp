// Name: Hangtao Du
// Assignment 1
// Course Number: EECE 2160
// Date: October, 9th, 2018
#include <iostream>
#include<string>
#include <fstream>
#include <sstream>

using namespace std;
struct car {
    string make;
    string car_model;
    int year;
    string color;
    car *next;
};

void print_cars_list(car *);

void populate_linkedList(car *);

void add_a_car(car *);

void search_by_year(car *);


void print_cars_list(car *carLinkedList) {
    car *current = carLinkedList;

    // Keep looping until the linked list is empty
    // Printing the element of the linked list one by one in a meaningful way.
    while (current != nullptr) {
        cout << current->make << "," << current->car_model << "," << current->year << ","
             << current->color << endl;
        current = current->next;
    }
}

void populate_linkedList(car *carLinkedList) {
    ifstream myReadFile;
    myReadFile.open("CarRecords.txt");
    string out;
    char toBeDeleted[] = ",";
    int counter = 0;
    int carNums = 0;

    string make;
    string Car_model;
    int Year;
    string Color;
    unsigned long stringLength;

    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {
            myReadFile >> out;
            if (counter != 3){
                stringLength = out.length();
                out.erase(stringLength-1);
            }

            if (counter == 0) {
                make = out;
            } else if (counter == 1) {
                Car_model = out;
            } else if (counter == 2) {
                int potentialYear = atoi(out.c_str());
                Year = potentialYear;
            } else if (counter == 3) {
                Color = out;
            }
            counter++;
            if (counter == 4) {
                carLinkedList->make = make;
                carLinkedList->car_model = Car_model;
                carLinkedList->year = Year;
                carLinkedList->color = Color;
                carLinkedList->next = NULL;
                counter = 0;
                carNums++;
                if (carNums < 10) {
                    carLinkedList->next = new car;
                    carLinkedList = carLinkedList->next;
                }
            }
        }
    }
    myReadFile.close();
}


void add_a_car(car *carLinkedList) {
    car *current = carLinkedList;

    while (current->next != NULL) {
        current = current->next;
    }


    string newMake;
    string newCarModel;
    int newYear;
    string newColor;

    cout << "Please enter the make" << endl;
    cin >> newMake;

    cout << "Please enter the car model" << endl;
    cin >> newCarModel;

    cout << "Please enter the year" << endl;
    cin >> newYear;

    cout << "Please enter the color" << endl;
    cin >> newColor;

    car *newCar = new car;

    newCar->make = newMake;
    newCar->car_model = newCarModel;
    newCar->year = newYear;
    newCar->color = newColor;
    newCar->next = NULL;

    current->next = newCar;
}


void search_by_year(car *carLinkedList) {
    bool finished = false;
    int i;
    car *current = carLinkedList;

    while (!finished) {
        cout << "Please enter the year which should be an integer" << endl;
        cin >> i;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "You did not input a integer number, Please enter again.\n" << endl;
        } else {
            finished = true;
        }
    }

    while (current != NULL) {
        if (current->year == i) {
            cout << current->make << "," << current->car_model << "," << current->year << ","
                 << current->color << endl;
        }
        current = current->next;
    }
}


int main() {
    car *carLinkedList = new car;
    int i;
    bool finished = false;

    while (!finished) {
        cout
                << "MENU - Select an option: \n\n"
                   "1. Print the cars list\n"
                   "2. Insert car records into an list\n"
                   "3. Add a car into the list\n"
                   "4. Search cars by year\n"
                   "5. Exit\n";
        cin >> i;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "You did not input a integer number, Please enter again.\n" << endl;
        } else {
            if (i < 1 || i > 5) {
                cin.clear();
                cin.ignore();
                cout << "The option does not exist, pleas enter again.\n" << endl;

            } else if (i == 1) {
                cout << "You selected\"Print the cars list\"\n" << endl;
                print_cars_list(carLinkedList);

            } else if (i == 2) {
                cout << "You selected\"Insert car records into an list\"\n" << endl;
                populate_linkedList(carLinkedList);

            } else if (i == 3) {
                cout << "You selected\"Add a car into the list\"\n" << endl;
                add_a_car(carLinkedList);

            } else if (i == 4) {
                cout << "You selected\"Search cars by year\"\n " << endl;
                search_by_year(carLinkedList);
            } else {
                cout << "You selected\"Exit\"\n " << endl;
                finished = true;
            }
        }
    }
    return 0;
}
