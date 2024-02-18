#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T = 2; 
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; 
		double B; 
		double C;
        
        A = 100.345;
        B = 2006.008;
        C = 2331.41592653498;
    
		/* Enter your code here */
        cout << left << hex << showbase << nouppercase << (int)A << endl;
        cout << right << setw(0xf) << fixed << setprecision(2) << showpos << setfill('_') << B << endl; // 0xf = 15
        cout << noshowpos << setprecision(9) << scientific << C << endl;
	}
	return 0;

}