#include <iostream>
using namespace std;
 
class Student
{
private:
    int rollNo;
    int marks;
    static int count;
 
public:
    Student()
    {
        rollNo = 0;
        marks = 0;
        count++;
    }
 
    void setData(int rollNo, int marks)
    {
        this->rollNo = rollNo;
        this->marks = marks;
    }
 
    void display();
 
    static void showCount()
    {
        cout << "Total students created: " << count << endl;
    }
 
    friend class Teacher;
};
 
int Student::count = 0;
 
inline void Student::display()
{
    cout << "Roll No: " << rollNo << endl;
    cout << "Marks: " << marks << endl;
}
 
class Teacher
{
public:
    void showResult(Student &s)
    {
        cout << "Result: ";
        if (s.marks >= 40)
        {
            cout << "Pass";
        }
        else
        {
            cout << "Fail";
        }
        cout << endl;
    }
};
 
int main()
{
    int r1, m1, r2, m2;
 
    cout << "Enter roll number of first student: ";
    cin >> r1;
    cout << "Enter marks of first student: ";
    cin >> m1;
    cout << "Enter roll number of second student: ";
    cin >> r2;
    cout << "Enter marks of second student: ";
    cin >> m2;
 
    Student s1, s2;
    Teacher t;
 
    s1.setData(r1, m1);
    s2.setData(r2, m2);
 
    cout << "\nFirst Student:" << endl;
    s1.display();
    t.showResult(s1);
 
    cout << "\nSecond Student:" << endl;
    s2.display();
    t.showResult(s2);
 
    cout << endl;
    Student::showCount();
 
    return 0;
}
