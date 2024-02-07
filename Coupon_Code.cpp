#include <iostream>
#include <map>
using namespace std;

int solve(string coupon_code)
{
    map<char, int> mp;
    
    for(char& c: coupon_code)
    {
        mp[c]++;
    }
    
    int mini = min({mp['h'], mp['a'], mp['p'], mp['y']});
    int other_mini = min({mp['h'], mp['a'], mp['y']});
    
    if (mini == mp['p'])
    {
        return (mp['p'])/2;
    }
    else if (mini != mp['p'] && 2*mini <= mp['p'])
    {
        return mini;
    }
    else if (mini != mp['p'] && 2*mini >= mp['p'])
    {
        return (mp['p'])/2;
    }
    
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string coupon_code = "heyapppy";
    // cin >> coupon_code;
    
    int out;
    out = solve(coupon_code);
    cout << out;
    return 0;
}