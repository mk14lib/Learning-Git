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
    
    /* seekp -- seek put */
    // position to the start of the file
    // write.seekp(0);
    
    // position to the nth position from beginning of the file
    // write.seekp(n, ios::beg);
    
    write << buffer << endl;
    
    cout << "Enter your age: ";
    getline(cin, buffer);
    write << buffer << endl;
    write.close();
    
    // read from a file
    fstream read;
    read.open("a.txt", ios::in);
    
    // positive for seekg(n, ios::cur)
    long int n = 5;
    
    // negative for seekg(n, ios::end)
    // long int n = -5;
    
    /* seek get - seekg */
    // position to the nth byte of read (assumes ios::beg)
    // read.seekg(n);
    
    // position n bytes forward in read
    // read.seekg(n, ios::cur); ---> characters
    
    // position n bytes back from end of read
    // read.seekg(n, ios::end); <--- characters
    
    // position at end of read
    // read.seekg(0, ios::end); <--- end of file
    
    
    
    getline(read, buffer);
    cout << buffer << endl;
    
    getline(read, buffer);
    cout << buffer << endl;
    read.close();
    
    return 0;
}