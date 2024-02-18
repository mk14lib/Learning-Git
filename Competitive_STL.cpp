#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <list>
#include <forward_list>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    //<----------------PAIRS-------------->
    pair<int, pair<int, int>> a = {1, {2, 3}}; 
    // a = make_pair(1, make_pair(2,3));
    cout << "Pair: ";
    cout << " {" << a.first << ", {" << a.second.first << " " << a.second.second << "}} " <<endl;
    
    //<----------------VECTORS------------>
    cout << "Vector: ";
    vector<int> v{8,5,6,1,4};
    vector<int> v1(5, 6);
    cout << "Size: " << v.size();
    reverse_copy(v.begin(), v.end(), v1.begin());
    // vector<int>::reverse_iterator it = v.rbegin();
    // vector<int>::reverse_iterator it = v.cbegin(); // constant iterator
    cout << "\tBefore Swap: ";
    for(auto it = v.begin(); it != v.end(); it++) cout << *it << " ";
    v.swap(v1);
    cout << "\tAfter Swap: ";
    for(auto it = v.begin(); it != v.end(); it++) cout << *it << " ";
    cout << "\tFront: " << v.front() << ", Back: " << v.back() << endl;
    v.clear();
    cout << "Cleared!" << endl;
    if (v.empty()) cout << "Empty: Yes" << endl;
    v.push_back(3);
    v.pop_back();
    
    //<----------------LISTS------------>
    cout << "List: \n";
    // singly linked list
    forward_list<int> s;
    
    // doubly linked list
    list<int> d;
    
    // Note: Vector performs better than list
    
    //<-----------------DEQUE--------------->
    cout << "Deque: ";
    deque<int> dq;
    dq.push_back(54);
    cout << dq.front() << " ";
    dq.push_front(64);
    cout << dq.front() << endl;
    
    //<-------------------STACK----------------->
    cout << "Stack: ";
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.emplace(4); // Last item
    cout << "Top: " << st.top() << " Size: " << st.size() << " Poping out!, " << "Size: " << st.size();
    st.pop();
    if (st.empty()) cout << " Empty Stack";
    else cout << " Not Empty Stack";
    // st.swap(st1);
    
    cout << endl;
    //<---------------------QUEUE---------------->
    cout << "Queue: ";
    queue<int> q;
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    cout << "Front: " << q.front();
    cout << " Back: " << q.back();
    q.pop();
    cout << endl;
    //<---------------------PRIORITY_QUEUE-------->
    cout << "Priority Queue: ";
    priority_queue <int> maxheap;
    priority_queue <int, vector<int>, greater<int>> minheap;
    
    // minheap: returns least element when popped.
    // maxheap: returns maximum element when popped.
    
    maxheap.push(45);
    maxheap.push(25);
    maxheap.emplace(15);
    maxheap.push(89);    
    
    minheap.push(45);
    minheap.push(25);
    minheap.push(15);
    minheap.emplace(89);
    
    cout << "Maxheap top: " << maxheap.top() << " Minheap top: " << minheap.top() << endl;
    minheap.pop();
    
    //<-----------------SET---------------->
    cout << "Set: ";
    set <int> se; // ascending order
    // set <int, greater<int>> se; // descending order
    se.insert(3);
    se.insert(5);
    se.emplace(6);
    se.insert(7);
    // se.erase(5); // all occurrences of 5 will be deleted
    for(auto i : se) cout << i << " "; 
    cout << "Count of 6: " <<se.count(6) << " Upper_bound: " << *se.upper_bound(3) << " Lower_bound: " << *se.lower_bound(6) << endl;
    auto itr = se.find(5);
    
    //<-------------------MAP/DICTIONARY------------------>
    cout << "Map: ";
    map<string, int> m; // key, value -- SORTED BY KEY
    m.insert(make_pair("hello", 123));
    m.insert(make_pair("world", 456));
    m.insert(make_pair("!!!!!", 789));
    auto itr1 = m.find("hello");
    
    // works with integer keys
    // cout << *m.upper_bound();
    // cout << *m.lower_bound();
    for(auto it = m.begin(); it != m.end(); ++it) cout << it->first << " " << it->second << endl;
    
    // <----------------__builtin_popcount()--------------->
    cout << "Builtin Popcount: ";
    int n = 123;
    cout << "Number bits set in 123: " << __builtin_popcount(n) << endl;
    
    // <----------------__builtin_popcountll()--------------->
    cout << "Builtin Popcountll: ";
    long long num = 123456667778678;
    cout << "Number bits set in 123456667778678: " << __builtin_popcountll(num) << endl;
    
    //<--------------------------next_permutation-------------->
    string str = "389";
    cout << "Next permutations: ";
    
    do {
        cout << str << " ";
    }while(next_permutation(str.begin(), str.end()));
    cout << endl;
    
    //<------------------maximum-&-minimum-element------------>
    vector<int> test{3,7,2,5,8,9,6};
    cout << "Min and max elements: ";
    auto mm = minmax_element(test.begin(), test.end());
    cout << *mm.first << " "<<  *mm.second << endl;
    return 0;
}