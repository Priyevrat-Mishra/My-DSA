#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    vector<int> marks;
    double percentage;
    char grade;

public:
    Student() {}

    Student(int r, string n, vector<int> m)
    {
        rollNo = r;
        name = n;
        marks = m;
        calculatePercentage();
        assignGrade();
    }

    int getRollNo() const { return rollNo; }
    double getPercentage() const { return percentage; }

    void calculatePercentage()
    {
        int sum = 0;
        for (int m : marks)
            sum += m;
        percentage = sum / (double)marks.size();
    }

    void assignGrade()
    {
        if (percentage >= 90)
            grade = 'A';
        else if (percentage >= 75)
            grade = 'B';
        else if (percentage >= 60)
            grade = 'C';
        else if (percentage >= 40)
            grade = 'D';
        else
            grade = 'F';
    }

    void display() const
    {
        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nPercentage: " << percentage;
        cout << "\nGrade: " << grade << endl;
    }

    string serialize() const
    {
        string data = to_string(rollNo) + "," + name;
        for (int m : marks)
            data += "," + to_string(m);
        return data;
    }
};

class ResultManager
{
private:
    vector<Student> students;

public:
    void loadFromFile()
    {
        ifstream file("students.txt");
        if (!file)
            return;

        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string temp;

            getline(ss, temp, ',');
            int roll = stoi(temp);

            string name;
            getline(ss, name, ',');

            vector<int> marks;
            while (getline(ss, temp, ','))
            {
                marks.push_back(stoi(temp));
            }

            students.push_back(Student(roll, name, marks));
        }
        file.close();
    }

    void saveToFile()
    {
        ofstream file("students.txt");
        for (auto &s : students)
            file << s.serialize() << endl;
        file.close();
    }

    void addStudent()
    {
        int roll;
        string name;
        vector<int> marks(5);

        cout << "Enter Roll Number: ";
        cin >> roll;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter marks for 5 subjects:\n";
        for (int i = 0; i < 5; i++)
            cin >> marks[i];

        students.push_back(Student(roll, name, marks));
        saveToFile();

        cout << "Student added successfully!\n";
    }

    void displayAll()
    {
        if (students.empty())
        {
            cout << "No records found.\n";
            return;
        }

        for (auto &s : students)
            s.display();
    }

    void searchStudent()
    {
        int roll;
        cout << "Enter Roll Number to search: ";
        cin >> roll;

        for (auto &s : students)
        {
            if (s.getRollNo() == roll)
            {
                s.display();
                return;
            }
        }

        cout << "Student not found.\n";
    }

    void rankStudents()
    {
        if (students.empty())
        {
            cout << "No records to rank.\n";
            return;
        }

        sort(students.begin(), students.end(),
             [](Student &a, Student &b)
             {
                 return a.getPercentage() > b.getPercentage();
             });

        cout << "\n--- Ranking by Percentage ---\n";
        for (int i = 0; i < students.size(); i++){
            cout << "Rank " << i + 1 << ": ";
            students[i].display();
        }
    }
};

int main(){
    ResultManager manager;
    manager.loadFromFile();

    int choice;
    do{
        cout << "\n===== STUDENT RESULT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Rank Students\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice){
        case 1:
            manager.addStudent();
            break;
        case 2:
            manager.displayAll();
            break;
        case 3:
            manager.searchStudent();
            break;
        case 4:
            manager.rankStudents();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}