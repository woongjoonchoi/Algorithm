
// C++ program to find number of ways to wear hats
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
  
// capList[i]'th vector contains the list of persons having a cap with id i
// id is between 1 to 100 so we declared an array of 101 vectors as indexing
// starts from 0.
vector<int> capList[101];
  
// dp[2^10][101] .. in dp[i][j], i denotes the mask i.e., it tells that
// how many and which persons are wearing cap. j denotes the first j caps
// used. So, dp[i][j] tells the number ways we assign j caps to mask i
// such that none of them wears the same cap
int dp[1025][101];
  
// This is used for base case, it has all the N bits set
// so, it tells whether all N persons are wearing a cap.
int allmask;

int countWaysUtil(int mask , int i)
{
    // 1.모자가 전부 할당이 되었을떄 return1 해준다.
    if(mask==allmask) return 1;

    if(dp[mask][i]!= -1 ) return dp[mask][i];


    int size = capList[i].size();

    int ways= countWaysUtil(mask,i+1);
    for(int j = 0 ;j<size;j++)
    {
        // 이미 그사람이 모자를 썻으면 pass
        if (1 << capList[i][j] && mask ) continue;

        ways = countWaysUtil(mask |  (1<<capList[i][j]),i+1);
        ways %= MOD;
        
    }

    return dp[mask][i] = ways ;
    // return 1;
}
// Reads n lines from standard input for current test case
void countWays(int n)
{
    //----------- READ INPUT --------------------------
    string temp, str;
    int x;
    getline(cin, str);  // to get rid of newline character
    for (int i=0; i<n; i++)
    {
        getline(cin, str);
        stringstream ss(str);
  
        // while there are words in the streamobject ss
        while (ss >> temp)
        {
            stringstream s;
            s << temp;
            s >> x;
  
            // add the ith person in the list of cap if with id x
            capList[x].push_back(i);
        }
    }
    //----------------------------------------------------
  
    // All mask is used to check whether all persons
    // are included or not, set all n bits as 1
    allmask = (1 << n) - 1;
  
    // Initialize all entries in dp as -1
    memset(dp, -1, sizeof dp);
  
    // Call recursive function count ways
    cout << countWaysUtil(0, 1) << endl;
}
  
// Driver Program
int main()
{ 
     int n;   // number of persons in every test case
     cin >> n;
     countWays(n);
     return 0;
}