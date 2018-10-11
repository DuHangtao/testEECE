// Name: Hangtao Du
// Assignment 1
// Course Number: EECE 2160
// Date: October, 9th, 2018
#include <iostream>
#include<string>
#include <fstream>
#include <sstream>

using namespace std;

// Creating the structure car as the linked list
struct car {
    string make;
    string car_model;
    int year;
    string color;
    car *next;
};

// Print all the content in the linked list
void print_cars_list(car *);

// reads the 10 records from the file into a linked list.
void populate_linkedList(car *);

//adds a new car into the list by taking information from the user.
void add_a_car(car *);

// return all cars for a specific year. It
//should return “No Records found” if no cars exist.
void search_by_year(car *);


void print_cars_list(car *carLinkedList) {
    car *current = carLinkedList;
    if (carLinkedList == NULL){
        cout << "You do not have anything in the list, please add some cars"<< endl;
    }else {
        // Keep looping until the linked list is empty.
        // Printing the element of the linked list one by one in a meaningful way.
        while (current != NULL) {
            cout << current->make << "," << current->car_model << "," << current->year << ","
                 << current->color << endl;
            current = current->next;
        }
    }
}

void populate_linkedList(car *carLinkedList) {
    ifstream myReadFile;

    //open the .txt file.
    myReadFile.open("CarRecords.txt");
    string out;
    int counter = 0;
    int carNums = 0;

    // The fields for a car.
    string make;
    string Car_model;
    int Year;
    string Color;

    // Get the string length of the current out.
    unsigned long stringLength;

    //Keep looping until there is no more line for the file.
    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {
            myReadFile >> out;
            if (counter != 3) {
                stringLength = out.length();
                out.erase(stringLength - 1);
            }

            // Keep the value of each field in correct index
            if (counter == 0) {
                make = out;
            } else if (counter == 1) {
                Car_model = out;
            } else if (counter == 2) {
                istringstream iss(out);
                int potentialYear;
                iss >> potentialYear;
                Year = potentialYear;
            } else if (counter == 3) {
                Color = out;
            }

            //counter to keep track of the fields.
            counter++;

            // The case we get all the fields.
            if (counter == 4) {
                carLinkedList->make = make;
                carLinkedList->car_model = Car_model;
                carLinkedList->year = Year;
                carLinkedList->color = Color;
                carLinkedList->next = NULL;
                counter = 0;
                carNums++;

                // If the index is not equal to 10, make the next of the list to a new car.
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


    cout << "Please enter the year which should be an integer" << endl;
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
    int count = 0;
    cout << "Please enter the year which should be an integer" << endl;
    while (!finished) {
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
            count++;
            cout << current->make << "," << current->car_model << "," << current->year << ","
                 << current->color << endl;
        }
        current = current->next;
    }

    if (count == 0) {
        cout << "No Records found" << endl;
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
