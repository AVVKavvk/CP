#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define ll long long

int n;
int fen[1030][1030];
int arr[1030][1030];

void update(int r, int c, int val) {
   int i,j;
	for (i = r; i <= n; i += i & -i)
		for (j = c; j <= n; j += j & -j)
			fen[i][j] += val;
}

ll sum(int r, int c) {
    ll sum = 0;
    int i,j;

    for (i = r; i > 0; i &= i - 1)
		for (j = c; j > 0; j &= j - 1)
			sum += fen[i][j];
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

        string str="";

        while (str!="END") {
            cin >> str;
            if (str == "SET") {
                int r, c, val;
                cin >> r >> c >> val;
                r++;
                c++;
                int temp = val - arr[r][c];
                update(r, c, temp); 
                arr[r][c] = val;

            } 
            
            else if (str == "SUM") {
                int r1,c1,r2,c2;
                cin>>r1>>c1>>r2>>c2;
                c1++;
                r1++;
                c2++;
                r2++;

                ll ans = 0;
                ans+=sum(r2,c2);
                ans-=sum(r1-1,c2);
                ans-=sum(r2,c1-1);
                ans+=sum(r1-1,c1-1);
                
                printf("%d\n",ans);
            } 
            else break;
        }
        printf("\n");
    }
    return 0;
}
