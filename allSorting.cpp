#include <iostream>
using namespace std;
void bubbleSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
void conquer(int *a, int s, int mid, int e)
{
    int merged[e - s + 1];
    int x = 0;
    int index1 = s;
    int index2 = mid + 1;
    while (index1 <= mid && index2 <= e)
    {
        if (a[index1] <= a[index2])
        {
            merged[x++] = a[index1];
        }
        else
        {
            merged[x++] = a[index2];
        }
    }
    while (index1 <= mid)
    {
        merged[x++] = a[index1];
    }
    while (index2 <= e)
    {
        merged[x++] = a[index2];
    }
    for (int i = 0, j = s; i < (e - s + 1); i++, j++)
    {
        a[j] = merged[i];
    }
}
void MergeSort(int *a, int s, int e)
{

    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    MergeSort(a, s, mid);
    MergeSort(a, mid + 1, e);
    conquer(a, s, mid, e);
}
void SelectionSort(int *arr, int n)
{

    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {

        min_idx = i;
        cout<<"Printing Minimum index: "<<min_idx<<endl;;
        for (j = i + 1; j < n; j++)
        {
            cout<<"Array for j: "<<arr[j]<<endl<<"Array of min_ind"<<arr[min_idx]<<endl;
            if (arr[j] < arr[min_idx]){
                cout<<"Printing Min_indx: "<<min_idx<<" -> J:"<<j<<endl;
                min_idx = j;
            }

        }

        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}
void InsertionSort(int *a, int n)
{
    int i, j, current;
    for (i = 1; i < n; i++)
    {
        current = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > current)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = current;
    }
}
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int *arr;
    int n;
    cout << "Enter the size of Array : ";
    cin >> n;
    cout << "Enter the Elements of Array " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int s = 0;
    int e = n - 1;
    print(arr, n);
    while (1)
    {
        cout<<"\n\n-------------------------------------------->ALL SORTING IS HERE<----------------------------------------------------\n\n";
        cout << "\n\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n4.MergedSort\n";
        int ch;
        cout << "Enter the choice you want: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            bubbleSort(arr, n);
            print(arr, n);
            break;
        case 2:
            SelectionSort(arr, n);
            print(arr, n);
            break;
        case 3:
            InsertionSort(arr, n);
            print(arr, n);
            break;
        case 4:
            MergeSort(arr, s, e);
            print(arr, n);
            break;
        default:
            break;
        }
    }
    return 0;
}
