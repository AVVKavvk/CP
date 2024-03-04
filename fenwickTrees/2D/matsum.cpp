#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define ll long long

int n;
int fen[1030][1030];
int arr[1030][1030];
void update(int fenNo, int index, int val) {
    while (index <= n) {
        fen[fenNo][index] += val;
        index+=index & (-index);
    }
}

ll sum(int fenNo, int index) {
    ll sum = 0;
    while (index > 0) {
        sum += fen[fenNo][index];
        index-=index & (-index);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        memset(fen, 0, sizeof fen);
        memset(arr,0,sizeof arr);
        cin >> n;
        // vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));

        string str = "";

        while (str != "END") {
            cin >> str;
            if (str == "SET") {
                int fenNo, index, val;
                cin >> fenNo >> index >> val;
                fenNo++;
                index++;
                int temp = val - arr[fenNo][index];
                update(fenNo, index, temp); 
                arr[fenNo][index] = val;
            } else if (str == "SUM") {
                int l1, r1, l2, r2;
                cin >> l1 >> r1 >> l2 >> r2;
                l1++;
                r1++;
                l2++;
                r2++;
                ll ans = 0;
                for (int i = l1; i <= l2; i++) {
                    ans += (sum(i, r2) - sum(i, r1 - 1));
                }
                cout << ans << endl;
            } 
        }
        cout<<"\n";
    }
    return 0;
}
