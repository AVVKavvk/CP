#include <bits/stdc++.h>
using namespace std;
#define pi 3.14
#define fli(a, b) for (int i = a; i < b; i++)
#define flj(a, b) for (int j = a; j < b; j++)
#define flk(a, b) for (int k = a; k < b; k++)
#define ma(a, b) ((a) > (b) ? (a) : (b));
#define mi(a, b) ((a) < (b) ? (a) : (b));
#define pb push_back
#define pob pop_back
#define sz size()
#define p2s(a, b) std::cout << a << ' ' << b << std::endl;
#define pn(a) std::cout << a << std::endl;
#define nl std::cout << std::endl;
#define p(a) std::cout << a;
#define ps(a) std::cout << a << ' ';
#define cig(arr, n) cin.getline(arr, n)
#define sza(a) sizeof(a) / sizeof(int)
#define vec vector<char>
#define v2e vector<vector<int>>
#define v2ec vector<vector<char>>
#define vei vector<int>
#define pu(n) push_back(n);

int main()
{
    int arr[5] = {1 ,3, 4, 2, 5};
    int prefix[6] = {0};
    int t;
    cin >> t;
    while (t--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        prefix[l] += x;
        prefix[r + 1] -= x;
        // cout << prefix[l] << " " << prefix[r + 1] << endl;
    }
    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        sum += prefix[i];
        //    cout<<sum<<" ";
        arr[i] += sum;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}