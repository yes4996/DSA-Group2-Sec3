
#include <iostream>
#include<string>
using namespace std;

const int MAX_EMPLOYEES = 100;

struct Employee {
    int id;
    string name;
    string position;
    double dailyWage;
};

struct AttendanceNode {
    int employeeID;
    int day;            
    bool present;
    AttendanceNode* next;
};
void addEmployee(Employee employees[], int &count) {
    if (count >= MAX_EMPLOYEES) {
        cout << "Employee list is full." << endl;
        return;
    }
    
    Employee emp;
    cout << "Enter employee ID: ";
    cin >> emp.id;
    cin.ignore();

    cout << "Enter employee name: ";
    getline(cin, emp.name);

    cout << "Enter employee position: ";
    getline(cin, emp.position);

    cout << "Enter employee daily wage: ";
    cin >> emp.dailyWage;
    
    employees[count++] = emp;
    cout << "Employee added successfully." << endl;
}


int searchEmployee(Employee employees[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Update an existing employee's details.
void updateEmployee(Employee employees[], int count, int id) {
    int index = searchEmployee(employees, count, id);
    if (index == -1) {
        cout << "Employee not found." << endl;
        return;
    }
    
    cout << "Updating details for employee " << employees[index].name << endl;
    cin.ignore(); // flush input
    
    cout << "Enter new name (press enter to keep [" << employees[index].name << "]): ";
    string newName;
    getline(cin, newName);
    if (!newName.empty()) {
        employees[index].name = newName;
    }

    cout << "Enter new position (press enter to keep [" << employees[index].position << "]): ";
    string newPosition;
    getline(cin, newPosition);
    if (!newPosition.empty()) {
        employees[index].position = newPosition;
    }
    
    cout << "Enter new daily wage (or -1 to keep [" << employees[index].dailyWage << "]): ";
    double newWage;
    cin >> newWage;
    if (newWage >= 0) {
        employees[index].dailyWage = newWage;
    }
    
    cout << "Employee updated successfully." << endl;
}
