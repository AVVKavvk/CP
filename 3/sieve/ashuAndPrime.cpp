#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int N=1000000;
int sieve[1000001];
int freq[1000001];
void createSieve(){
	for(int i=2;i<=N;i++) {sieve[i]=1;freq[i]=1;};  

	for(int i=2;i*i<=N;i++){
		if(sieve[i]==1)
		{
			// freq[i]++;                       //?  can't be work instead of increase freq in above loop 
												//? because loop runs for i*i<=n  and 2<=x<=n  
												//? so freq[x] where x>i*i is zero
		for(int j=i*i;j<=N;j=j+i){
			if(sieve[j]==1) {freq[i]++;
			
			sieve[j]=0;}
		}
		}
	}

}
int main() {
    createSieve();
	int t;
	cin>>t;
	while(t--){
        int n;
		cin>>n;
		cout<<freq[n]<<endl;
	}
}