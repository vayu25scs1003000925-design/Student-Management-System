#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class Student
{
    private:
           int id;
           string name;
           int age;
           string course;
           float marks;

    public:
         void input()
         {
              cout <<"\nEnter Student ID :";
              cin >> id;
              cin.ignore();

              cout <<"Enter Name :";
              getline(cin, name);

              cout << "Enter Age :";
              cin >> age;
              cin.ignore();

              cout <<"Enter Course :";
              getline(cin, course);

              cout <<"Enter Marks :";
              cin >> marks;
         }       
         void display()
         {
            cout << left << setw(10) << id << setw(25)
              << name 
            <<setw(10) << age
                << setw(20) << course
            << setw(10) << marks << endl;               
         }

         int getID()
         {
            return id;

         }

         void saveToFile()
         {
            ofstream file("students.txt", ios::app);

            file << id << endl;
            file << name << endl;
            file << age << endl;
            file << course << endl;
            file << marks << endl;
            
            file.close();
         }

         bool readFromFile(ifstream &file)
         {
            if (!(file >> id))
            return false;
            file.ignore();
            getline(file, name);

            file >> age;
            file.ignore();

            getline(file, course);

            file >> marks;
            file.ignore();

            return true;
         }
};

void addStudent()
{
    Student s;

    cout << "\nADD STUDENT\n";

    s.input();
    s.saveToFile();

    cout << "\nStudent Added Successfully!\n";

}
void displayStudents()
{
    ifstream file("students.txt");

    if (!file)
    {
        cout <<"\nNO Records Found!\n";
        return;
    }

    Student s;

    cout <<"\nStudent Records\n\n";

    cout << left
        << setw(10) << "ID"
        << setw(25) << "Name"
        << setw(10) << "Age"
        << setw(20) << "course"
        << setw(10) << "Marks" << endl;
    
        cout << "-----------------------------------------------------------\n";

    while (s.readFromFile(file))
    {
        s.display();
    }

    file.close();
}
int main()
{
    int choice;

    do
    {
        /* code */
    cout << "\n===============================\n";
    cout <<"       STUDENT MANAGEMENT SYSTEM\n";
    cout <<"===================================\n";

    cout << "1. Add Student\n";
    cout << "2. Display Student\n";
    cout << "3. Search Student\n";
    cout << "4. Update Student\n";
    cout <<" 5. Delete Student\n";
    cout << "6. Exit\n";

    cout << "\nEnter Choice :";
    cin >> choice;
    
    switch (choice)
    {
        case 1:
        addStudent();
        break;

        case 2:
        displayStudents();
        break;

        case 3:
        cout << "\n(Search feature in Part 2)\n";
        break;

        case 4:
        cout << "\n(Update feature in Part 2)\n";
        break;

        case 5:
        cout << "\n(Delete feature in Part 2)\n";
        break;

        case 6:
        cout << "\nThank You!\n";
        break;

        default:
        cout << "\nInvalid Choice!\n";
    }
} while (choice != 6);
return 0;
}