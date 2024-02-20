#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node {
    int l, r, ind;
} Q[200010];

int sqrt_el;

// *    int sqrt_el=174;

bool cmp(node f,node s)
{
    if((f.l/sqrt_el)!=(s.l/sqrt_el))
        return (f.l/sqrt_el)<(s.l/sqrt_el);
    else
        return f.r<s.r;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sqrt_el=sqrt(n);
    int q;
    cin >> q;

    
    for (int i = 0; i < q; i++) {
        cin >> Q[i].l >> Q[i].r;
        // Q[i].l--;
        // Q[i].r--;
        Q[i].ind = i;
    }

    sort(Q, Q+q, cmp);

    // vector<int> freq(1000005, 0);
    vector<int> ans(q);

    int left = 0, right = 0, sum = 0;
    // freq[arr[0]]++;

    for (int i = 0; i < q; i++) {
        int l = Q[i].l;
        int r = Q[i].r;
        int ind = Q[i].ind;

        while (left < l) {
            // freq[arr[left]]--;
            // if (freq[arr[left]] == 0) cnt--;
            sum-=arr[left];
            left++;
        }

        while (left > l) {
            left--;
            sum+=arr[left];
            // freq[arr[left]]++;
            // if (freq[arr[left]] == 1) cnt++;
        }

        while (right <=r) {
            // freq[arr[right]]++;
            // if (freq[arr[right]] == 1) cnt++;
            sum+=arr[right];
            right++;
        }

        while (right > r+1 ) {
            right--;
            sum-=arr[right];
            // freq[arr[right]]--;
            // if (freq[arr[right]] == 0) cnt--;
        }

        ans[ind] = sum;
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
