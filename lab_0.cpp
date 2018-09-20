#include <iostream>

using namespace std;

// Initialize the three global variables associated with the vector with valid values,
// and allocate memory for the vector with an initial capacity of just 2 elements.
void Initialize();

// Free the memory associated with the vector.
void Finalize();

// This function will print debug information on the screen,
// including the old and new capacities of the vector.
void Grow();

//ask the user to enter a double floating number, which will be the new value added at the end of the vector.
void AddElement();

// Removing the element form the end of the array,
// if the vector is empty and the user selects this option,
// a proper error message should be displayed, indicating that there are no elements left to remove.
void RemoveElement();

// Display the current content of the vector.
void PrintVector();

// When the user deletes elements from the vector and its occupancy becomes lower than 30% of the total capacity,
// the program will reallocate the vector with half of its original capacity, maintaining its content intact.
void shrink();


// This is a pointer to the first element in a sequence of elements.
double *V;

// This variable represents the number of elements inserted in the array so far by the user.
int Count;

//This variable represents the space currently allocated for the array,
// given in number of elements.
int size;

// The entry of the program, excuting the command according to the user's inout.
// The program ends until the user enters '4'.
int main() {

    int i;
    bool finished = false;

    Initialize();

    while (!finished) {
        cout
                << "Main menu: \n\n1. Print the array\n2. Add one element\n3. Remove last element\n4. Exit\n\nSelect an option: ";

        cin >> i;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "You did not input a number, Please enter again.\n" << endl;
        } else {
            if (i < 1 || i > 4) {
                cin.clear();
                cin.ignore();
                cout << "The option does not exist, pleas enter again.\n" << endl;
            } else if (i == 1) {
                cout << "You selected\"Print the array\"\n" << endl;
                PrintVector();
            } else if (i == 2) {
                cout << "You selected\"Add one element\"\n" << endl;
                AddElement();
            } else if (i == 3) {
                cout << "You selected\"Remove last elementt\"\n" << endl;
                RemoveElement();
            } else {
                cout << "You selected\"Exit\"\n " << endl;
                finished = true;
            }
        }
    }
    Finalize();
    return 0;
}


void Initialize() {
    Count = 0;
    size = 2;
    V = NULL;
    V = new double[size];
}

void Finalize() {
    delete[] V;
}

void Grow() {
    int copyOfSize = size;
    double *nV = NULL;

    size = copyOfSize * 2;

    nV = new double[size];

    for (int i = 0; i < copyOfSize; i++) {
        nV[i] = V[i];
    }

    Finalize();

    V = nV;

    cout << "Vector grown" << endl;
    cout << "Previous capacity: " << copyOfSize << " elements" << endl;
    cout << "New capacity: " << size << " elements" << endl;
}

void AddElement() {

    double userInput;
    bool isADouble = false;

    while (!isADouble) {
        cout << "Enter the new element: " << endl;

        cin >> userInput;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "You did not input a double, Please enter again." << endl;
        } else {
            isADouble = true;
            if (Count < size) {
                V[Count] = userInput;
                Count++;
            } else {
                Grow();
                V[Count] = userInput;
                Count++;
            }
        }
    }
    return;
}

void PrintVector() {
    cout << "The size of the array is " << size << endl;
    cout << "All elements in the array are: " << endl;
    if (Count == 0) {
        cout << "The array is totally empty, you can add something into it." << endl;
    }
    for (int i = 0; i < Count; i++) {
        cout << V[i] << endl;
    }
    cout << "\n" << endl;
}

void RemoveElement() {

    if (Count == 0) {
        cout << "There are no elements left to remove." << endl;
    } else {
        V[Count - 1] = NULL;
        Count--;
    }

    if (Count < 0.3 * size) {
        shrink();
    }
}

void shrink() {
    if (size < 2) {
        cout << "The size of the array can not less than 1" << endl;
    } else if (Count > 0.3 * size) {
        cout << "The total occupancy is higher than 30% of the total capacity, "
                "you are not allowed to shrink the array" << endl;
    } else {
        int copyOfSize = size;

        size = copyOfSize / 2;

        double *nV = new double[size];

        for (int i = 0; i < copyOfSize; i++) {
            nV[i] = V[i];
        }

        Finalize();

        V = nV;

        cout << "Vector shrink" << endl;
        cout << "Previous capacity: " << copyOfSize << " elements" << endl;
        cout << "New capacity: " << size << " elements" << endl;
    }
}






