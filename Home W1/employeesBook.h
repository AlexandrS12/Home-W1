#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct Employee {
    char* firstName;
    char* lastName;
    char* phoneNumber;
    double salary;
};

void loadFromFile(const char* fileName);
void saveToFile(const char* fileName);
void showAll();
void searchToLast(const char* lastName);
void searchBySalary(double minSalary, double maxSalary);
void sortByLastName();
void addEmployee();
void deleteEmployee();

#endif