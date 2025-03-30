
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
