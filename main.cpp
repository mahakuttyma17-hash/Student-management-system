#include <iostream>
#include <fstream>
using namespace std;

    int main() {

        // FILE CHECK
        ifstream check("data.txt");

        if (!check) {
            ofstream create("data.txt");
            cout << "No data file found. Creating new file...\n";
            create.close();
        }
        else {
            cout << "Data file loaded successfully!\n";
        }

        check.close();

    int choice;

    do {
        cout << "========================\n";
        cout << "   STUDENT SYSTEM\n";
        cout << "========================\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        // ---------------- ADD ----------------
        if (choice == 1) {
            int roll, age;
            string name, course;

            cout << "Enter Roll: ";
            cin >> roll;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Age: ";
            cin >> age;

            cout << "Enter Course: ";
            cin >> course;

            ofstream file("data.txt", ios::app);
            file << roll << " " << name << " " << age << " " << course << endl;
            file.close();

            cout << "Student Added!\n";
        }

        // ---------------- DISPLAY ----------------
        else if (choice == 2) {
            int roll, age;
            string name, course;

            ifstream file("data.txt");

            cout << "\n--- STUDENT LIST ---\n";

            while (file >> roll >> name >> age >> course) {
                cout << roll << " " << name << " " << age << " " << course << endl;
            }

            file.close();
        }

        // ---------------- UPDATE ----------------
        else if (choice == 3) {
            int roll;
            cout << "Enter Roll to update: ";
            cin >> roll;

            ifstream file("data.txt");
            ofstream temp("temp.txt");

            int r, age;
            string name, course;
            bool found = false;

            while (file >> r >> name >> age >> course) {
                if (r == roll) {
                    cout << "Enter New Name: ";
                    cin >> name;

                    cout << "Enter New Age: ";
                    cin >> age;

                    cout << "Enter New Course: ";
                    cin >> course;

                    temp << r << " " << name << " " << age << " " << course << endl;
                    found = true;
                }
                else {
                    temp << r << " " << name << " " << age << " " << course << endl;
                }
            }

            file.close();
            temp.close();

            remove("data.txt");
            rename("temp.txt", "data.txt");

            if (found)
                cout << "Student Updated!\n";
            else
                cout << "Student Not Found!\n";
        }

        // ---------------- DELETE ----------------
        else if (choice == 4) {
            int roll;
            cout << "Enter Roll to delete: ";
            cin >> roll;

            ifstream file("data.txt");
            ofstream temp("temp.txt");

            int r, age;
            string name, course;
            bool found = false;

            while (file >> r >> name >> age >> course) {
                if (r != roll) {
                    temp << r << " " << name << " " << age << " " << course << endl;
                }
                else {
                    found = true;
                }
            }

            file.close();
            temp.close();

            remove("data.txt");
            rename("temp.txt", "data.txt");

            if (found)
                cout << "Student Deleted!\n";
            else
                cout << "Student Not Found!\n";
        }

    } while (choice != 5);

    return 0;
}