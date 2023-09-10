#include <iostream>
#include "employeesBook.h"

using namespace std;

int main() {
    const char* fileName = "employees.txt";

    while (true) {
        cout << "Menu:" << endl;
        cout << "[1] Load workers from the file " << endl;
        cout << "[2] Save workers to file " << endl;
        cout << "[3] Show all workers " << endl;
        cout << "[4] Search by surname " << endl;
        cout << "[5] Search by salary " << endl;
        cout << "[6] Sort by last name " << endl;
        cout << "[7] Add worker " << endl;
        cout << "[8] Delete worker " << endl;
        cout << "[9] Exit " << endl;

        int choice;
        cout << "Select this menu option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            loadFromFile(fileName);
            break;
        case 2:
            saveToFile(fileName);
            break;
        case 3:
            showAll();
            break;
        case 4:
            cout << "Enter the last name to start searching: ";
            char lastName[100];
            cin.ignore();
            cin.getline(lastName, sizeof(lastName));
            searchToLast(lastName);
            break;
        case 5:
            double minSalary, maxSalary;
            cout << "Enter min salary: ";
            while (!(cin >> minSalary)) {
                cout << "Error!: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (minSalary < 0) {
                cout << "Error! enter value higher 0." << endl;
                break;
            }

            cout << "Enter the max salary: ";
            while (!(cin >> maxSalary)) {
                cout << "Error: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            searchBySalary(minSalary, maxSalary);
            break;
        case 6:
            sortByLastName();
            break;
        case 7:
            addEmployee();
            break;
        case 8:
            deleteEmployee();
            break;
        case 9:
            return 0;
        default:
            cout << "Wrong input!Try again!" << endl;
            break;
        }
    }

    return 0;
}