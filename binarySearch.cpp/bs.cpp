#include <iostream>
using namespace std;
int binary_search(int a[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (a[mid] == key)
        {
            return key;
        }

        else if (key > a[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        int mid = start + (end - start) / 2;
    }
    return -1;
}
int linear_serach(int a[], int n, int target)
{

    for (int i = 0; i < n; i++)
    {
        if (a[i] == target)
        {
            return target;
        }
    }
    return target;
}
int main()
{
   
    int a[10];
    int n;
    cout << "Enter the Size of Array : ";
    cin >> n;
    cout << "Enter the Elemnts of Array :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int target;
    cout << "Enter The target : ";
    cin >> target;
    int ans = binary_search(a, n, target);
    if (target == -1)
    {
        cout << "The Target is not found ";
    }
    else
    {
        cout << "The Target is found at " << ans << endl;
    }
    cout << "Printing the Elements of Array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " " << endl;
    }
    return 0;
}