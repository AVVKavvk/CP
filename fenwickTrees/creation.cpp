#include<bits/stdc++.h>
using namespace std ; 

 
 int fen[1000005];
 void update(int ind,int val,int n){
   while(ind<=n){
     fen[ind] += val;
     ind = ind + (ind & -ind);

      
   }
 }
 int sum(int ind){
    int res=0;
    while(ind>0){
        res+=fen[ind];
        ind=ind- ( ind & -ind );
        
    }
    return res;
 }

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int arr[n+1];
for(int i=1;i<=n;i++){
    cin>>arr[i];
    update(i,arr[i],n);
}

// int preind;
// cin>>preind;
// cout<<sum(preind);

// for(int i=1;i<=n;i++) cout<<fen[i]<<"  ";


return 0 ;
}

// 6 
// 1 1 2 3 4 5