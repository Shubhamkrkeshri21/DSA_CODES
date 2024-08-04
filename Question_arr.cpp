#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool valid(string &v)
{
    int n = v.length() - 1;
    if (n > 8 || n < 30 || isalpha(v[0]))
    {
        return true;
    }
    return false;
}
void sequence(string &q){
    stack<int>s;
    
}

int pascalTriangle(int &n)
{
    int tri[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0||j==i){
                tri[i][j]=1;
            }
            else{
                tri[i][j]=tri[i-1][j-1]+tri[i-1][j];
            }
            cout<<tri[i][j]<<" ";
        }
        cout<<endl;
    }
    
}


void rotataeM(vector<vector<int>> &a, int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "printing i" << i << " j " << j << " " << a[i][j] << " Printing" << j << " j " << " " << "i " << i << a[j][i] << endl;
            swap(a[i][j], a[j][i]);
        }
    }
    cout << "printing the valur of here :" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            reverse(a[i].begin(), a[i].end());
        }
        cout << endl;
    }
}
int main()
{
    // int v[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};         // 1,2,3]
    // vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // int n = 3;      // [4,5,6]
    // rotataeM(v, n); //[7,8,9]
    // // cout<<ans;
    // cout << "Printing the value : " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int  s ;
    cout<<"Enter the numebr : ";
    cin>>s;
    pascalTriangle(s);


    return 0;
}