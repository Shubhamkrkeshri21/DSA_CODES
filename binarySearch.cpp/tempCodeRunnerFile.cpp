#include<iostream>
using namespace std;
int linear_serach(int a[],int n,int target){
   
    for(int i=0;i<n;i++){
        if(a[i]==target){
            return target;
        }
    }
    return 0;
}
int main(){
    cout<<"Hello World";
    int *a;
    int n;
    cout<<"Enter the Size of Array : ";
    cin>>n;
    cout<<"Enter the Elemnts of Array :"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int target ;
    cout<<"Enter The target : ";
    cin>>target;
   // linear_serach(a,n,target);
    cout<<"Printing the Elements of Array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" "<<end;
    }
    return 0;

}