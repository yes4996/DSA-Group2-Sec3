
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
void deleteEmployee(Employee employees[], int &count, int id) {
    int index = searchEmployee(employees, count, id);
    if (index == -1) {
        cout << "Employee not found." << endl;
        return;
    }
 
    for (int i = index; i < count - 1; i++) {
        employees[i] = employees[i + 1];
    }
    count--;
    cout << "Employee deleted successfully." << endl;
}
void displayEmployees(Employee employees[], int count) {
    if (count == 0) {
        cout << "No employees to display." << endl;
        return;
    }
    
    cout << "\nEmployee List:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "ID: " << employees[i].id
             << ", Name: " << employees[i].name
             << ", Position: " << employees[i].position
             << ", Daily Wage: " << employees[i].dailyWage << endl;
    }
}

void addAttendanceRecord(AttendanceNode*& head, int employeeID, int day, bool present) {
    AttendanceNode* newNode = new AttendanceNode;
    newNode->employeeID = employeeID;
    newNode->day = day;
    newNode->present = present;
    newNode->next = head;
    head = newNode;
    cout << "Attendance record added." << endl;
}

void displayAttendanceForEmployee(AttendanceNode* head, int employeeID) {
    bool found = false;
    AttendanceNode* current = head;
    while (current != NULL) {
        if (current->employeeID == employeeID) {
            cout << "Day: " << current->day 
                 << ", Attendance: " << (current->present ? "Present" : "Absent") << endl;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << "No attendance records found for employee ID " << employeeID << endl;
    }
}

bool updateAttendanceRecord(AttendanceNode* head, int employeeID, int day, bool newStatus) {
    AttendanceNode* current = head;
    while (current != nullptr) {
        if (current->employeeID == employeeID && current->day == day) {
            current->present = newStatus;
            return true;
        }
        current = current->next;
    }
    return false;
}


bool deleteAttendanceRecord(AttendanceNode*& head, int employeeID, int day) {
    AttendanceNode* current = head;
    AttendanceNode* prev = nullptr;
    while (current != nullptr) {
        if (current->employeeID == employeeID && current->day == day) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

void displayAllAttendance(AttendanceNode* head) {
    if (head == nullptr) {
        cout << "No attendance records available." << endl;
        return;
    }
    
    cout << "\nAttendance Records:" << endl;
    AttendanceNode* current = head;
    while (current != NULL) {
        cout << "Employee ID: " << current->employeeID
             << ", Day: " << current->day
             << ", Attendance: " << (current->present ? "Present" : "Absent") << endl;
        current = current->next;
    }
}

