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

    virtual void Work() {
        cout << Name << " is checking email, task backlog, performing task..." << endl;
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

    void Work() {
        cout << Name << " is writing " << Language  << " code" << endl;
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

    void Work() {
        cout << Name << " is teaching " << Subject << endl;
    }
};

int main()
{
    // The most common use of polymorphism is when a parent class reference is used to refer to child
    // class object.

    Developer d = Developer("Abhisar", "ABA", 25, "Python");
    Teacher t = Teacher("Santosh", "COOL", 35, "History");

    Employee* e1 = &d;
    Employee* e2 = &t;
    
    e1->Work();
    e2->Work();

    return 0;
    
}