#include <iostream>
#include <vector>
#include<bits/stdc++.h>
// #include<algorithm>
using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int>ans(n);
//     for(int i=0;i<n;i++){
//         cin>>ans[i];
//     }
//     int p=n/2;
//     cout<<p<<endl;
//     sort(ans.begin(),ans.end());
//     cout<< ans[p]<<endl;

//     return 0;
// }
int main(){
    int n;
    cin>>n;
    if(n==1){cout<<"O";}
    else if(n==2){cout<<"Two";}
    else if(n==3){cout<<"Three";}
    else if(n==4){cout<<"Four";}
    else if(n==5){cout<<"Five";}
    else if(n==6){cout<<"Six";}
    else if(n==7){cout<<"Seven";}
    else if(n==8){cout<<"Eight";}
    else if(n==9){cout<<"Nine";}
   else{
    cout<<"Greater than 9";
   }

}