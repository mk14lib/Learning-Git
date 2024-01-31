#include <iostream>
#include <exception>
using namespace std;

// using exception predefined class methods
class myException: public exception {
    public:
    const char* what() const throw() {
        return  "Divisible by Zero error.";
    }
};

// user-defined exceptions
class demo
{
    private:
    int x;
    
    public:
    demo(int i)
    {
        try {
            if (i == 0)
            {
                throw "Zero not allowed.";
            }
            x = i;
            show();
        } 
        catch (const char *msg) {
            cout << "Exception caught: ";
            cout << msg << endl;
        }
        
    }
    
    void show() 
    {
        cout << "Value of x: " << x << endl;
    }
};

int main()
{
    demo demo1(0), demo2(1);
    
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    try {
        if (y == 0)
        {
            myException z;
            throw z;
        }
        else
        {
            cout << x/y << endl;
        }
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}