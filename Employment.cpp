
#include <iostream>

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
