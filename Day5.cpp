//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    int a = 1,b = 1;
	    int mod = 1e9+7;
	    while (--N){
	        int aa = b,bb = (a+b)%mod;
	        a = aa;
	        b = bb;
	    }
	    int v = (a+b)%mod;
	    return (1LL*v*v)%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends