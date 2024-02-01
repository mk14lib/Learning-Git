#include <iostream>
using namespace std;
// suppress warnings 
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"


void* printSomething(void* params)
{
    long int tid = (long int)params;
    cout << "Thread id: " << tid << endl;
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread[5];
    
    int retval = 0;
    for(int i = 0; i < 5; i++) {
        retval = pthread_create(&thread[i], NULL, printSomething, (void*) (i+1));
        
        // prints in sequentially manner.. wait for others to complete
        // pthread_join(thread[i], (void**)0); 
        if (retval)
        {
            cout << "thread not created." << endl;
            pthread_exit(NULL); 
            exit(1);
        }
    }
    
    pthread_exit(NULL);
    return 0;
}