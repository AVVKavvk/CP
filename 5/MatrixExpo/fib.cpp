#include<bits/stdc++.h>
using namespace std ; 
#define pi 3.14
int fib(int n){
    int ans[2][2];
    ans[0][0]=1;ans[0][1]=0;ans[1][0]=0;ans[1][1]=1;
    int base[2][2];
    base[0][0]=1;base[0][1]=1;base[1][0]=1;base[1][1]=0;

    n=n-1;

    while(n>0){
        if(n&1){
            n--;
            int temp[2][2];
            temp[0][0]=ans[0][0]*base[0][0] + ans[0][1]*base[1][0];
            temp[0][1]=ans[0][0]*base[0][1] + ans[0][1]*base[1][1];
            temp[1][0]=ans[1][0]*base[0][0] + ans[1][1]*base[1][0];
            temp[1][1]=ans[1][0]*base[0][1] + ans[1][1]*base[1][1];
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    ans[i][j]=temp[i][j];
                }
            }
            
        }
        else{
            n=n/2;

            int temp[2][2];
            temp[0][0]=base[0][0]*base[0][0] + base[0][1]*base[1][0];
            temp[0][1]=base[0][0]*base[0][1] + base[0][1]*base[1][1];
            temp[1][0]=base[1][0]*base[0][0] + base[1][1]*base[1][0];
            temp[1][1]=base[1][0]*base[0][1] + base[1][1]*base[1][1];
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    base[i][j]=temp[i][j];
                }
            }
        }
    }

    return ans[0][0];

}
 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

//*        give fibonaci in    log(n)

int t=1;
// cin>>t;
while(t--){ 
int n;
cin>>n;
cout<<fib(n);
}
return 0 ;
}