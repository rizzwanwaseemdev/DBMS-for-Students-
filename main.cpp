#include <iostream>
using namespace std;

struct Student {
    string firstName;
    string lastName;
    string rollNumber;
    string course;
    string className;
    string contact;
};

Student students[25];
int total = 0;

void enter() {
    int choice;
    cout << "How many students do you want to enter: ";
    cin >> choice;

    if (total + choice > 25) {
        cout << "Cannot add more than 25 students!" << endl;
        return;
    }

    if (total == 0) {
        total = choice;
        for (int i = 0; i < choice; i++) {
            cout << "\nEnter data of student " << i + 1 << ": " << endl;
            cout << "\nEnter First Name: ";
            cin >> students[i].firstName;
            cout << "Enter Last Name: ";
            cin >> students[i].lastName;
            cout << "Enter Roll number: ";
            cin >> students[i].rollNumber;
            cout << "Enter Course: ";
            cin >> students[i].course;
            cout << "Enter Class Section: ";
            cin >> students[i].className;
            cout << "Enter Contact: ";
            cin >> students[i].contact;
        }
    } else {
        for (int i = total; i < total + choice; i++) {
            cout << "\nEnter data of student " << i + 1 << ": " << endl;
            cout << "\nEnter First Name: ";
            cin >> students[i].firstName;
            cout << "Enter Last Name: ";
            cin >> students[i].lastName;
            cout << "Enter Roll number: ";
            cin >> students[i].rollNumber;
            cout << "Enter Course: ";
            cin >> students[i].course;
            cout << "Enter Class Section: ";
            cin >> students[i].className;
            cout << "Enter Contact: ";
            cin >> students[i].contact;
        }
        total = total + choice;
    }
}

void show() {
    if (total == 0) {
        cout << "\nNo Data!" << endl;
    } else {
        for (int i = 0; i < total; i++) {
            cout << "\nData of student: " << i + 1 << "\n\n";
            cout << "First Name: " << students[i].firstName << endl;
            cout << "Last Name: " << students[i].lastName << endl;
            cout << "Roll Number: " << students[i].rollNumber << endl;
            cout << "Course: " << students[i].course << endl;
            cout << "Class Section: " << students[i].className << endl;
            cout << "Contact: " << students[i].contact << endl;
        }
    }
}

void search() {
    if (total == 0) {
        cout << "No Data!" << endl;
    } else {
        string rollNo;
        cout << "\nEnter Roll number of the student you want to search: ";
        cin >> rollNo;

        bool found = false;
        for (int i = 0; i < total; i++) {
            if (rollNo == students[i].rollNumber) {
                cout << "\nData of student:\n";
                cout << "First Name: " << students[i].firstName << endl;
                cout << "Last Name: " << students[i].lastName << endl;
                cout << "Roll Number: " << students[i].rollNumber << endl;
                cout << "Course: " << students[i].course << endl;
                cout << "Class Section: " << students[i].className << endl;
                cout << "Contact: " << students[i].contact << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "\nNo student found with roll number " << rollNo << endl;
        }
    }
}

void update() {
    if (total == 0) {
        cout << "No Data!" << endl;
    } else {
        string rollNo;
        cout << "\nEnter Roll number of student which you want to search: ";
        cin >> rollNo;
        bool found = false;
        for (int i = 0; i < total; i++) {
            if (rollNo == students[i].rollNumber) {
                cout << "Previous Data of the student: " << endl << endl;
                cout << "First Name: " << students[i].firstName << endl;
                cout << "Last Name: " << students[i].lastName << endl;
                cout << "Roll Number: " << students[i].rollNumber << endl;
                cout << "Course: " << students[i].course << endl;
                cout << "Class Section: " << students[i].className << endl;
                cout << "Contact: " << students[i].contact << endl;
                cout << "\nEnter new data: " << endl << endl;
                cout << "First Name: ";
                cin >> students[i].firstName;
                cout << "Last Name: ";
                cin >> students[i].lastName;
                cout << "Roll Number: ";
                cin >> students[i].rollNumber;
                cout << "Course: ";
                cin >> students[i].course;
                cout << "Class Section: ";
                cin >> students[i].className;
                cout << "Contact: ";
                cin >> students[i].contact;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No Student found with Roll number " << rollNo << endl;
        }
    }
}

void deleteRecord() {
    if (total == 0) {
        cout << "No Data!" << endl;
    } else {
        int x;
        cout << "Press 1 to delete all data records." << endl;
        cout << "Press 2 to delete specific data record." << endl;
        cin >> x;

        if (x == 1) {
            int choice;
            cout<<"\nAre you sure you want to delete ALL data records?"<<endl;
            cout<<"Press 1 for YES / Press 0 for NO"<<endl;
            cin>>choice;
            if(choice == 1){
                total = 0;
                cout << "\nAll data records DELETED!" <<endl;
            }
        } else if (x == 2) {
            string rollNum;
            cout << "Enter Roll number of the student whose data you want to delete: ";
            cin >> rollNum;
            for (int i = 0; i < total; i++) {
                if (rollNum == students[i].rollNumber) {
                    for (int j = i; j < total - 1; j++) {
                        students[j] = students[j + 1];
                    }
                    total--;
                    cout << "Data of Roll number " << rollNum << " has been removed." << endl;
                    break;
                }
            }
        } else {
            cout << "Invalid Input!" << endl;
        }
    }
}

int main() {
    int value;
    cout << "\nData Base Management System (DBMS) for Students." << endl;

    while (true) {
        cout << "\nPress 1 to Enter data" << endl;
        cout << "Press 2 to Show data" << endl;
        cout << "Press 3 to Search data" << endl;
        cout << "Press 4 to Update data" << endl;
        cout << "Press 5 to Delete data" << endl;
        cout << "Press 6 to Exit." << endl;
        cin >> value;

        switch (value) {
            case 1:
                enter();
                break;
            case 2:
                show();
                break;
            case 3:
                search();
                break;
            case 4:
                update();
                break;
            case 5:
                deleteRecord();
                break;
            case 6:
                cout<<"Exiting Program..."<<endl;
                exit(0);
                break;
            default:
                cout << "Invalid input!" << endl;
                break;
        }
    }
    return 0;
}
