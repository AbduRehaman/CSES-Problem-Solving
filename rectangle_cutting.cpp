#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a; i<b; i++)
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vpi;

// Just uncomment the print statements to get intuition

int main() {

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	
	int n,m;
	cin>>n>>m;

	vector<vector<int>> dp(n+2,vector<int>(m+2,1e9));

	//example take n=2,m=3
	rep(i,1,n+1){
		rep(j,1,m+1){
			if(i==j){
				dp[i][j] = 0;
			}
			else if(i==1){
				dp[i][j] = j-1;
			}
			else if(j==1){
				dp[i][j] = i-1;
			}
			else{
			rep(x,1,j){
				dp[i][j] = min(dp[i][j],(dp[i][x] + dp[i][j-x] + 1));
				// cout<<"col"<<endl;
				// cout<<i<<","<<x<<" ";
				// cout<<i<<","<<j-x<<" "<<(dp[i][x] + dp[i][j-x] + 1)<<endl;
			}
			rep(x,1,i){
				dp[i][j] = min(dp[i][j],(dp[x][j] + dp[i-x][j] + 1));
				// cout<<"row"<<endl;
				// cout<<x<<","<<j<<" ";
				// cout<<i-x<<","<<j<<" "<<(dp[x][j] + dp[i-x][j] + 1)<<endl;
			}
		}
			// cout<<i<<" "<<j<<"->"<<dp[i][j]<<endl;
		}

		
	}
	cout<<dp[n][m];

    return 0;
}
