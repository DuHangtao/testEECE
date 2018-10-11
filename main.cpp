// Name: Hangtao Du
// Assignment 1
// Course Number: EECE 2160
// Date: October, 9th, 2018
#include <iostream>
#include <iostream>
#include<string>
#include <fstream>
#include <sstream>

using namespace std;

class car {
    string make;
    string car_model;
    string year;
    string color;

public:
    car(string new_make, string new_car_model, string new_year, string new_color) {
        make = new_make;
        car_model = new_car_model;
        year = new_year;
        color = new_color;
    }

    car() {
    }

    ~car() {
    }

    void populate_array(int index) {
        ifstream myReadFile;
        myReadFile.open("CarRecords.txt");
        string out;
        char toBeDeleted[] = ",";
        int counter = 0;
        int carsIndex = 0;

        string make;
        string Car_model;
        string Year;
        string Color;

        unsigned long stringLength;

        if (myReadFile.is_open()) {
            while (!myReadFile.eof()) {
                myReadFile >> out;
                if (counter != 3) {
                    stringLength = out.length();
                    out.erase(stringLength - 1);
                }


                if (counter == 0) {
                    make = out;
                } else if (counter == 1) {
                    Car_model = out;
                } else if (counter == 2) {
                    Year = out;
                } else if (counter == 3) {
                    Color = out;
                }
                counter++;
                if (counter == 4) {
                    if (carsIndex == index) {
                        this->make = make;
                        this->year = Year;
                        this->car_model = Car_model;
                        this->color = Color;
                    }
                    counter = 0;
                    carsIndex++;
                }
            }
        }
        myReadFile.close();
    }

    static void print_cars_array(car carList[]) {
        int i = 0;
        for (i = 0; i < 10; i++) {
            car currentCar = carList[i];
            cout << currentCar.make << "," << currentCar.car_model << "," << currentCar.year << ","
                 << currentCar.color << endl;
        }

    }

    static void sort_cars_by_year(car carList[]) {
        car temp;
        int i, j;
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 9; j++) {
                int number1 = std::stoi(carList[j].year);
                int number2 = std::stoi(carList[j + 1].year);
                if (number1 > number2) {
                    temp = carList[j + 1];
                    carList[j + 1] = carList[j];
                    carList[j] = temp;
                }
            }
        }
    }


    static void search_by_make(car carList[]) {
        int counter = 0;

        if (!carList) {
            cout << "The cars array is totally empty, please inserting car records" << endl;
        } else {
            string currentMake;
            cout << "Please enter the name of the make" << endl;
            cin >> currentMake;
            int i = 0;
            for (i = 0; i < 10; i++) {
                string str(carList[i].make);
                if (str == currentMake) {
                    car currentCar = carList[i];
                    cout << currentCar.make << "," << currentCar.car_model << "," << currentCar.year << ","
                         << currentCar.color << endl;
                    counter++;
                }
            }
        }
        if (counter == 0) {
            cout << "No Records found" << endl;
        }
    }


};

int main() {
    car allCars[10];
    int i;
    bool finished = false;
    int count = 0;

    while (!finished) {
        cout
                << "MENU - Select an option: \n\n"
                   "1. Print the cars array\n"
                   "2. Insert car records into an array\n"
                   "3. Sort cars by year\n"
                   "4. Search cars by make\n"
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
                count++;
                cout << "You selected\"Print the cars array\"\n" << endl;
                car::print_cars_array(allCars);
            } else if (i == 2) {
                count++;
                cout << "You selected\"Insert car records into an array\"\n" << endl;
                int j = 0;
                for (j = 0; j < 10; j++) {
                    allCars[j].populate_array(j);
                }
                cout << "You successfully inserted the records" << endl;
            } else if (i == 3) {
                count++;
                cout << "You selected\"Sort cars by year\"\n" << endl;
                car::sort_cars_by_year(allCars);
                cout << "You successfully sort the records" << endl;
            } else if (i == 4) {
                count++;
                cout << "You selected\"Search cars by make\"\n " << endl;
                car::search_by_make(allCars);
            } else {
                cout << "You selected\"Exit\"\n " << endl;
                if (count != 0) {
                }
                finished = true;
            }
        }
    }
    return 0;
}
