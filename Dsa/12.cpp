#include <iostream>
#include <fstream>
#include<bits/stdc++.h>

using namespace std;

struct Record {
    int recordID;
    string name;
};

void insertRecord() {
    Record record;

    cout << "Enter Record ID: ";
    cin >> record.recordID;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, record.name);

    ofstream file("records.txt", ios::binary | ios::app);
    file.write(reinterpret_cast<const char*>(&record), sizeof(Record));
    file.close();

    cout << "Record inserted successfully!" << endl;
}

void deleteRecord(int recordID) {
    ifstream file("records.txt", ios::binary);
    ofstream tempFile("temp.txt", ios::binary);

    Record record;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&record), sizeof(Record))) {
        if (record.recordID != recordID) {
            tempFile.write(reinterpret_cast<const char*>(&record), sizeof(Record));
        } else {
            found = true;
        }
    }

    file.close();
    tempFile.close();

    remove("records.txt");
    rename("temp.txt", "records.txt");

    if (found) {
        cout << "Record deleted successfully!" << endl;
    } else {
        cout << "Record not found!" << endl;
    }
}



int main() {
    int choice;
    int recordID;

    do {
        cout << "=========== Direct Access File ===========" << endl;
        cout << "1. Insert Record" << endl;
        cout << "2. Delete Record" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertRecord();
                break;
            case 2:
                cout << "Enter Record ID: ";
                cin >> recordID;
                deleteRecord(recordID);
                break;
                
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice !=4);

    return 0;
}
