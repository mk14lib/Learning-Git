#include <iostream>
#include <vector>
#include <string>
// #include <pthread.h>
#include <iomanip>
using namespace std;

void* callback1(void *params)
{
    cout << "hello world" << endl;
    pthread_exit((int*)0);
}

void* callback2(void *params)
{
    cout << "goodbye world" << endl;
    pthread_exit((int*)0);
}

int main()
{
    pthread_t thread1, thread2;
    
    int retval1 = pthread_create(&thread1, NULL, callback1, NULL);
    cout << "Error List: " << endl 
    << "Deadlock: " << setw(10)<< EDEADLK << endl << 
    "Thread Conflict: " << setw(7)<< EINVAL << endl 
    << "Thread ID not found: " << setw(4)<< ESRCH << endl;
    
    pthread_join(thread1, (void**)0);
    int retval2 = pthread_create(&thread2, NULL, callback2, NULL);
    pthread_exit((int*)0);
    return 0;
}