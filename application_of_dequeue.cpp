#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> d(arr, arr+n);
    
    // find the max in the given window size
    auto max = *max_element(d.begin(), d.begin()+k);
    cout << max;
    
    // queue size is reduced as we keep poping it 
    while(d.size() > k)
    {
		// backup the front and pop it out
        auto front = d.front();
        d.pop_front();
        
		// check if the element at the tail of window is greater than or equal to max value
        if (d[k-1] >= max)
        {
			// update the max value 
            max = d[k-1];
        }
		// else check if front value equal to max value
        else if (front == max)
        {
			// then find the new max value in the given window
            max = *max_element(d.begin(), d.begin()+k);
        }
        cout << " " << max;
    }
    
    
    cout << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
