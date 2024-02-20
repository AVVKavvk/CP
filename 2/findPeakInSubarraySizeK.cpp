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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n = 8;
    int arr[8] = {1, 6, 4, 6, 2, 4, 1, 2};
    int k = 6;
    int peak = 0;
    for (int i = 1; i < k-1; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            peak++;
    }

    int l = 1;
    int r = k - 1;
    int cnt = peak;
    while (r < n-1)
    {
        if (arr[r] > arr[r - 1] && arr[r] > arr[r + 1])
            peak++;
        if (arr[l] > arr[l - 1] && arr[l] > arr[l + 1])
            peak--;
        cnt = max(cnt, peak);
        r++;
        l++;
    }

    cout << cnt;
    return 0;
}