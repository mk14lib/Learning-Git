#include <iostream>
#include <sstream>
using namespace std;


int someVar;
// namespace declaration (aviods same name collisions)
namespace test 
{
    int value() { return 5; }
    int a = 6;
}

namespace test1
{
    int value() { return 7; }
    int a = 8;
}

// namespace aliasing
namespace test2 = test1;

// generic template
template <class sometype>
sometype sum (sometype a, sometype b)
{
    return a+b;
}

// parameterized template
template <class t, int N>
t function( t val )
{
    return N * val;
}

int main()
{
 
    int value = 1;
    decltype(value) copy;
    
    // reading entire line from console
    string str;
    getline(cin, str);
    cout << str << endl;
    
    // Extraction of numbers from string using stringstream
    string mystring = "1234";
    stringstream(mystring) >> value;
    cout << value << endl;
    
    // template usage
    cout << sum<int>(4, 5) << endl;
    cout << sum<float>(4.0, 5.8) << endl;
    
    // parameterized template call
    cout << function<int, 3>(10) << endl;
    
    // namespace usage
    cout << test::value() << endl;
    cout << test::a << endl;
    {
        using namespace test2; 
        cout << test1::value() << endl;
        cout << a << endl;
    }
    
    // outer scope
    int x = 10;
    {
        // inner scope
        int x = 20;
        cout << x << endl;
    }
    cout << x << endl;
    
    // static variables goes to initialized data of the data segment (global and static variables are always initialized to 0)
    // local variables goes to uninitialized data of the data segment (.bss)
    
    /*
        environmental variables
        stack 
        heap
        uninitialized data(.bss) block start by symbol
        initialized data
        text / code
    */
    cout << "This is a global variable: " << someVar << endl;
    
    return 0; 
}