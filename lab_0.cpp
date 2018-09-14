#include <iostream>
using namespace std;

int main ()
{

int i;
bool finished = true;

while(finished) {
cout << "Main menu: \n\n1. Print the array\n2. Add one element\n3. Remove last element\n4. Exit\n\nSelect an option: ";

cin >> i;

if (cin.fail())
   {
cin.clear();
cin.ignore(); 
      cout << "You did not input a number, Please enter again.\n" << endl;
   }
else {
if(i < 1 || i > 4){
cin.clear();
cin.ignore();
      cout << "The option does not exist, pleas enter again.\n" << endl;
}
else if (i == 1){
cout << "You selected\"Print the array\"\n" << endl;
}
else if (i == 2){
cout << "You selected\"Add one element\"\n" << endl;
}
else if (i == 3){
cout << "You selected\"Remove last elementt\"\n" << endl;
}
else {
cout << "You selected\"Exit\"\n " << endl;
finished = false;
}
}
}
return 0;
}
