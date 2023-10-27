#include <iostream>

using namespace std;

class Employee {
private:
    string Company;
    int Age;

protected:
    string Name;

public:
    void setName(string name) {
        Name = name;
    }

    string getName() {
        return Name;
    }

    void setCompany(string company) {
        Company = company;
    }

    string getCompany() {
        return Company;
    }

    void setAge(int age) {
        if(age >= 18)
            Age = age;
    }

    int getAge() {
        return Age;
    }

    void IntroduceYourself() {
        cout << "Name: " << Name << endl;
        cout << "Company: " << Company << endl;
        cout << "Age: " << Age << endl;
    }

    // Default constructor
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }
};

class Developer: public Employee {
public:
    string Language;

    Developer(string name, string company, int age, string language) 
        :Employee(name, company, age)
    {
        Language = language;
    }

    void FixBug() {
        cout << Name << " fixed bug using " << Language << endl;
    }

};

class Teacher:public Employee {
public:
    string Subject;
    void PrepareLesson() {
        cout << getName() << " is preparing " << Subject << endl;
    }

    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age)
    {
        Subject = subject;
    }
};

int main()
{
    Employee employee1 = Employee("Abhisar", "ABC", 25);
    Employee employee2 = Employee("Asit", "XYZ", 26);

    Developer developer1 = Developer("Abhisar", "ABA", 25, "Python");
    developer1.FixBug();
    developer1.IntroduceYourself();

    Teacher t = Teacher("Santosh", "COOL", 35, "History");
    t.PrepareLesson();
    t.IntroduceYourself();

    return 0;
    
}