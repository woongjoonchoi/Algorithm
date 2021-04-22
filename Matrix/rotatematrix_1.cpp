// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

#define R 4
#define C 4
void transpose(int arr[R][C],int r , int c)
{
    for(int i = 0 ; i< r;i++)
    {
        for(int j = i;j<c;j++)
        {
            swap(arr[i][j] ,arr[j][i]);
        }
    }
}

void reverse(int arr[R][C] , int r, int c)
{
    for(int i = 0; i<c ; i++)
    {
        for(int j = 0
         ,  k = r-1 ; j <k;j++,k--)
        {
            swap(arr[j][i],arr[k][i]);
        }
    }
}
int main()
{
    // vector<int> a = {1,2,3};
    
    // vector<int> b[10];

    // b[0] = a;

    // a.push_back(2);

    // cout<<b[0].size()<<endl;

    int arr[4][4] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    // rotate90(arr);
    // printMatrix(arr);
    transpose(arr,4,4);
    reverse(arr,4,4);
    // return 0;
    for(auto c : arr)
    {
        for(int i = 0 ; i< 4;i++) cout<<c[i]<<" ";
        cout<<endl;

    }
    return 0;
}