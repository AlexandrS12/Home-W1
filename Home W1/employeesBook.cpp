#include <iostream>
#include <cstring>
#include <fstream>
#include "employeesBook.h"

using namespace std;

const int MAX_EMPLOYEES = 100;
Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void loadFromFile(const char* fileName) {
    ifstream file(fileName);

    if (!file) {
        cout << "Error when opening a file." << endl;
        return;
    }

    employeeCount = 0;

    while (file && employeeCount < MAX_EMPLOYEES) {
        employees[employeeCount].firstName = new char[100];
        employees[employeeCount].lastName = new char[100];
        employees[employeeCount].phoneNumber = new char[12];

        if (file >> employees[employeeCount].firstName &&
            file.ignore() &&
            file >> employees[employeeCount].lastName &&
            file.ignore() &&
            file >> employees[employeeCount].phoneNumber &&
            file.ignore() &&
            file >> employees[employeeCount].salary) {
            employeeCount++;
        }
        else {
            break;
        }
    }

    file.close();

    cout << "Workers successfully loaded from file." << endl;
}

void saveToFile(const char* fileName) {
    ofstream file(fileName);

    if (!file) {
        cout << "Error when opening a file." << endl;
        return;
    }

    for (int i = 0; i < employeeCount; i++) {
        file << employees[i].firstName << '\t'
            << employees[i].lastName << '\t'
            << employees[i].phoneNumber << '\t'
            << employees[i].salary << '\n';
    }

    file.close();

    cout << "Workers successfully saved to file." << endl;
}

void showAll() {
    if (employeeCount == 0) {
        cout << "There are no employees!" << endl;
        return;
    }

    cout << "Workers:" << endl;

    for (int i = 0; i < employeeCount; i++) {
        cout << "Worker #" << i << endl;
        cout << "Last name: " << employees[i].lastName << endl;
        cout << "First name: " << employees[i].firstName << endl;
        cout << "Phone number: " << employees[i].phoneNumber << endl;
        cout << "Salary: " << employees[i].salary << endl;
        cout << "-----------------------" << endl;
    }
}

void searchToLast(const char* lastName) {
    bool found = false;

    cout << "Result:\n";
    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(employees[i].lastName, lastName) == 0) {
            cout << "Last name: " << employees[i].lastName << endl;
            cout << "First name: " << employees[i].firstName << endl;
            cout << "Phone number: " << employees[i].phoneNumber << endl;
            cout << "Salary: " << employees[i].salary << endl;
            cout << "-----------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Worker with surname '" << lastName << "' was not found." << endl;
    }
}

void searchBySalary(double minSalary, double maxSalary) {
    bool found = false;

    cout << "Result:\n";
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].salary >= minSalary && employees[i].salary <= maxSalary) {
            cout << "Last name: " << employees[i].lastName << endl;
            cout << "First name: " << employees[i].firstName << endl;
            cout << "Phone number: " << employees[i].phoneNumber << endl;
            cout << "Salary: " << employees[i].salary << endl;
            cout << "-----------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Workers with salary u wrote not found!" << endl;
    }
}

void sortByLastName() {
    for (int i = 0; i < employeeCount - 1; i++) {
        for (int j = 0; j < employeeCount - i - 1; j++) {
            if (strcmp(employees[j].lastName, employees[j + 1].lastName) > 0) {
                Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }

    cout << "Workers sorted by last name." << endl;
}

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        cout << "The workers book is filled." << endl;
        return;
    }

    employees[employeeCount].firstName = new char[100];
    employees[employeeCount].lastName = new char[100];
    employees[employeeCount].phoneNumber = new char[12];

    cout << "Enter last name of worker: ";
    cin >> employees[employeeCount].lastName;
    if (!isalpha(employees[employeeCount].lastName[0])) {
        cout << "Invalid last name. Try again!" << endl;
        return;
    }

    cout << "Enter worker`s first name: ";
    cin >> employees[employeeCount].firstName;
    if (!isalpha(employees[employeeCount].firstName[0])) {
        cout << "Invalid first name. Try again!" << endl;
        return;
    }


    do {
        cout << "Enter worker's phone number (in 0671171600 form): ";
        cin >> employees[employeeCount].phoneNumber;

        if (strlen(employees[employeeCount].phoneNumber) != 10) {
            cout << "Invalid phone number Please enter a 10N number" << endl;
        }
        else {
            bool valid = true;
            for (int i = 0; i < 10; i++) {
                if (!isdigit(employees[employeeCount].phoneNumber[i])) {
                    cout << "Error! Please enter N only." << endl;
                    valid = false;
                    break;
                }
            }
            if (valid) {
                break;
            }
        }
    } while (true);


    cout << "Enter the worker`s salary: ";
    cin >> employees[employeeCount].salary;
    if (cin.fail() || employees[employeeCount].salary < 0) {
        cout << "Error! enter salary > 0! " << endl;
        return;
    }

    employeeCount++;

    cout << "Worker successfully added." << endl;
}

void deleteEmployee() {
    if (employeeCount == 0) {
        cout << "There are no workers to delete." << endl;
        return;
    }

    cout << "Enter the last name of the worker to delete: ";
    char lastName[100];
    cin >> lastName;

    bool found = false;

    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(employees[i].lastName, lastName) == 0) {
            delete[] employees[i].firstName;
            delete[] employees[i].lastName;
            delete[] employees[i].phoneNumber;

            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }

            employeeCount--;
            found = true;
            cout << "The worker with the surname '" << lastName << "' has been successfully deleted." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Worker with surname '" << lastName << "' was not found." << endl;
    }
}