#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// file read write operations
int main()
{
    // data buffer
    string buffer;
    cout << "Enter your name: ";
    getline(cin, buffer);
    
    // write to a file 
    fstream write;
    
    // available modes --> app, in, out, trunc, ate
    write.open("a.txt", ios::app);
    write << buffer << endl;
    
    cout << "Enter your age: ";
    getline(cin, buffer);
    write << buffer << endl;
    write.close();
    
    // read from a file
    fstream read;
    read.open("a.txt", ios::in);
    getline(read, buffer);
    cout << buffer << endl;
    
    getline(read, buffer);
    cout << buffer << endl;
    read.close();
    return 0;
}