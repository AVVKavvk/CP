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
    int arr[4][4] = {{1, 1, 2, 2}, {1, 1, 2, 2}, {2, 2, 1, 1}, {2, 1, 2, 1}};
    int prefix[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            prefix[i][j] = arr[i][j];
            if (i - 1 >= 0)
                prefix[i][j] += prefix[i - 1][j];
            if (j - 1 >= 0)
                prefix[i][j] += prefix[i][j - 1];
            if (i - 1 >= 0 && j - 1 >= 0)
                prefix[i][j] -= prefix[i - 1][j - 1];
        }
    }
    int i1 = 2, j1 = 3, i2 = 3, j2 = 3;
    int s = 0;
    s += prefix[i2][j2];
    // cout << s << ' ';
    if (i1 - 1 >= 0)
    {

        s -= prefix[i1 - 1][j2];
        //    cout << prefix[i1 - 1][j2] << " ";
    }
    if (j1 - 1 >= 0)
    {

        s -= prefix[i2][j1 - 1];
        // cout << prefix[i2][j1 - 1] << " ";
    }
    if (i1 - 1 >= 0 && j1 - 1 >= 0)
    {

        s += prefix[i1 - 1][j1 - 1];
        // cout << prefix[i1 - 1][j1 - 1] << " ";
    }
    cout << s << " ";
    return 0;
}