#include <iostream>

using namespace std;

namespace stablestud {
        class stack_oop
        {
        private:
                int* stack = new int [1];
                int stack_nr_elements = 0;
        public:
                void push ( int elements ) 
                {
                        stack[stack_nr_elements++] = elements;
                }
                
                int pop ( void )
                {
                        return stack[--stack_nr_elements];
                }
        };
};

int main ( void )
{
        stablestud::stack_oop todo;
        todo.push(83);
        todo.push(21);
        todo.push(673);
        cout << todo.pop() << endl;
        cout << todo.pop() << endl;
        cout << todo.pop() << endl;
        return 0;
}
