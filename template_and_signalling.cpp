#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <csignal>
using namespace std;

// signal handler, callback function
void callback_fn(int signum)
{
    cout << "Received interrupt: " << signum << endl;
    exit(signum);
}


// function template
template <typename T> T add (T a, T b)
{
    return (a+b);
}

// class template
template <class T> class Stack {
    private:
    vector<T> buffer;
    
    public:
    void push(T const& elem) 
    {
        buffer.push_back(elem);
    }
    
    void pop() 
    {
        if (buffer.empty())
        {
            throw out_of_range("Stack<>::pop(): Stack is empty");
        }
        buffer.pop_back();
    }
    
    T top() const
    {
        if (buffer.empty())
        {
            throw out_of_range("Stack<>::top(): Stack is empty");
        }
        return buffer.back();
    }
    
    bool empty() const {
        return buffer.empty();
    }
};

int main()
{
    
    try 
    {
        Stack<int> intStack;
        intStack.push(10);
        intStack.push(14);
        cout << intStack.top() << endl;
        
        intStack.pop();
        cout << intStack.top() << endl;
        
        intStack.pop();
        intStack.pop();
    } 
    catch(exception const& e)
    {
        cerr << "Exception: " << e.what() << endl;    
    }
    // raise(SIGFPE);
    
    int a;
    decltype(a) b;
    b = 10;
    cout << b << endl;
    
    // Signals
    cout << SIGINT << ", " << SIGILL <<  ", " << SIGABRT << ", " << SIGFPE << ", " << SIGSEGV << ", " << SIGTERM << endl;
    
    // attention is mostly given to KEYBOARD interrupt
    // signal(SIGINT, callback_fn);
    
    signal(SIGFPE, callback_fn);
    
    int i = 0;
    
    while(++i)
    {
        if (i == 3)
        {
            // raise any interrupt signal as per requirement
            raise(SIGFPE);
        }
    }
    return 0;
    
}