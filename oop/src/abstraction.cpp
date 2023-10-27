#include <iostream>

using namespace std;

// Abstract class with virtual function
class AbstractEmployee {
    // Virtual method
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee {
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

    void AskForPromotion() {
        if (Age > 30) 
            cout << Name << " got promoted." << endl;
        else
            cout << Name << " denied promotion." << endl;
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

    Employee employee2 = Employee("Asit", "XYZ", 31);

    employee1.AskForPromotion();
    employee2.AskForPromotion();

    return 0;
    
}