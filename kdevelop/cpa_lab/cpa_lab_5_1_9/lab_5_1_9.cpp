#include <string>
#include <iostream>
using namespace std;
class Person
{
public:
        string name;
        int age;
        // Your code here
        string pname ( void )
        {
                return this -> name;
        }
};

void print(Person* person)
{
        cout << person->name << " is " << person->age << " years old" << endl;
}

int main()
{
        Person person;
        person.name = "Harry";
        person.age = 23;
        cout << "Meet " << person.pname() << ", ";
        print(&person);
        int a = 1, b = 99, c = 91;
        person.name = c = a = b = 1000;
        std::cout << a << " " << b << std::endl;
        // Your code here
        return 0;
}
