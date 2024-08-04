#include <iostream>
using namespace std;
int print_array(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int reverse_a(int *a, int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        swap(a[start], a[end]);
        start++;
        end--;
    }
    // print_array(a,n);
}
int extreamP(int *a, int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        if (start == end)
        {
            cout << a[end] << endl;
        }
        else
        {
            swap(a[start], a[end]);
            cout << a[start] << " ";

            cout << a[end] << " ";
        }
        start++;
        end--;
    }
}
void movezR(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            a[i] = a[i];
        }
        else
        {
            swap(a[i],a[i+1]);
          //  a[i] = a[i + 1];
        }
    }
}
int main()
{
    int *a;
    int n;
    cout << "Enter the Size of Array : ";
    cin >> n;
    cout << "Enter the Elements you want " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // reverse_a(a, n);
    // print_array(a, n);
    cout << endl;
    cout << "Printing Extream Value " << endl;
    extreamP(a, n);
    cout << endl;
    print_array(a, n);
    cout << endl;

    while (1>0)
    {
        cout << "\nEnter the Choice you want ?\n"
             << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            reverse_a(a, n);
            print_array(a, n);
            reverse_a(a, n);
            break;
        case 2:
            print_array(a, n);
            break;
        case 3:
            extreamP(a, n);
            print_array(a, n);
            break;
        case 4:
            movezR(a, n);
            print_array(a, n);
            break;
        default:
            break;
        }
    }
}