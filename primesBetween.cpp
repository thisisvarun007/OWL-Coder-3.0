#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000

int primes[M];
void sieve(){
    memset(primes,1,sizeof(primes));
    primes[0] = primes[1] = 0;
    for (int i=2; i*i<M; i++){
        if (primes[i]){
            for (int j=i*i; j<M; j++)primes[j] = 0;
        }
    }
}

int main(){
    sieve();
    int t;
    cin>>t;
    while (t--){
        int L,R;
        cin>>L>>R;
        int d = L-R+1;
        int arr[d];
        memset(arr,1,sizeof(arr));
        for (int i=2; i*i<=d; i++){
            if (primes[i]){
                int j = 0;
                while (j<d && (arr[j]+L)%i!=0)j++;
                while (j<d){
                    arr[j] = 0;
                    j+=i;
                }
            }
        }
        int cnt = 0;
        for (int i=0; i<d; i++){
            if (1&arr[i])cnt++;
        }
        cout<<cnt<<endl;
    }
}