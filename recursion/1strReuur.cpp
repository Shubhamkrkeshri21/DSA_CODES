#include <iostream>
#include <cmath>
#define mod 1000000007
using namespace std;
// int add(int a, int b)
// {
//     return log(pow(2, a), pow(2, b));
// }
int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    int ans = n * fact(n - 1);
    return ans;
}
int NCount(int m)
{
    int n = 0;
    if (m == 1)
        return 1;
    // cout<<n+m<<endl;
    cout << m << " ";
    return NCount(m - 1);
}

long long int power(long long x, long long n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    long long int val = power(x, n / 2);
    if (n % 2 == 0)
        return (val * val) % mod;
    else
        return (val * val * x) % mod;
}

int countGoodNumbers(long long n)
{
    long long int even = n / 2 + n % 2, odd = n / 2, sum = 1;
    return (power(5, even) * power(4, odd)) % mod;
}

int fib(int m)
{
    if (m == 0)
        return 0;
    if (m == 1)
    {
        return 1;
    }
    int ans = fib(m - 1) + fib(m - 2);
    cout << ans << " ";
    //  cout << endl;
    return ans;
}
int power(int n)
{
    if (n == 0)
        return 1;
    int ans = 2 * power(n - 1);
    return ans;
}
int main()
{
    while (1)
    {
        int l;
        cout << "Enter the choice you want " << endl;
        cin >> l;
        switch (l)
        {
        case 1:
            cout << "Factorial of a Number " << endl;
            int n;
            cout << "Enter the number you want for factorial -> ";
            cin >> n;
            cout << fact(n) << endl;
            break;
        case 2:
            cout << "Counting of a Number " << endl;
            int m;
            cout << "Enter the number you want for Counting -> ";
            cin >> m;
            cout << NCount(m) << endl;
            break;

        case 3:
            cout << "Power of a Number " << endl;
            int p;
            cout << "Enter the number you want for Power -> ";
            cin >> p;
            cout << power(p) << endl;
            break;
        case 4:
            cout << "Fibonacci series  of a Number " << endl;
            int f;
            cout << "Enter the number you want for Fibinacci series -> ";
            cin >> f;
            cout << fib(f) << endl;
            break;
         case 5:
            cout << "count good number " << endl;
            long long n1;
            cout << "Enter the number you want for Addition -> ";
            cin >>n1;
            cout <<countGoodNumbers(n) << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}
