#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'commonChild' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */
#define METHOD2

#ifdef METHOD1
// Method-1: recursive approach -- more time consuming
int longestcommonChild(string s1, string s2, int i, int j) {
    if (i == (int)s1.length() || j == (int)s2.length())
        return 0;
        
    if (s1[i] == s2[j])
    {
        return 1 + longestcommonChild(s1, s2, i+1, j+1);
    }
    
    return max(longestcommonChild(s1, s2, i, j+1), longestcommonChild(s1, s2, i+1, j));
}

int commonChild(string s1, string s2)
{
    return longestcommonChild(s1, s2, 0, 0);
}
#endif

#ifdef METHOD2
// Method-2: Dynamic programming -- approach (segmentation fault)
int buffer[5000][5000];

int commonChild(string s1, string s2)
{
    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = 0;
    
    for(int i = 0; i < len1; ++i)
    {
        for(int j = 0; j < len2; ++j)
        {
            if (s1[i] == s2[j])
            {
                buffer[i+1][j+1] = buffer[i][j] + 1;
                len3 = max(len3, buffer[i+1][j+1]);
            }
            else
            {
                buffer[i+1][j+1] = max(max(buffer[i][j], buffer[i][j+1]), buffer[i+1][j]);
            }
        }
    }
    return len3;
}
#endif

int main()
{
    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    cout << result << "\n";

    return 0;
}

// ABCDEF 
// FBDAMN
// BD - 2

// SHINCHAN
// NOHARAAA
// NHA - 3

// HARRY
// SALLY
// AY - 2