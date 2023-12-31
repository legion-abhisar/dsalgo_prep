#include <iostream>

using namespace std;

class Employee {
private:
    string Name;
    string Company;
    int Age;

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

int main()
{
    Employee employee1 = Employee("Abhisar", "ABC", 25);
    employee1.IntroduceYourself();

    employee1.setName("Sandeep");
    employee1.setCompany("WBC");
    employee1.setAge(30);
    employee1.IntroduceYourself();

    Employee employee2 = Employee("Asit", "XYZ", 26);
    employee2.IntroduceYourself();

    return 0;
    
}