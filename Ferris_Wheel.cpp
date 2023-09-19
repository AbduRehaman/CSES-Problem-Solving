#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;
typedef vector<vector<int>> vii;
#define unm(a, b) unordered_map<a, b>
#define uns(a) unordered_set<a>

/*

Intuition: 
		   sort - as we need to compare values of weights

		   Start with two extremes, i=0 and j=n-1;

		   If their sum is less than or equal to x then ans++, i++, j--;

		   else we can be sure that weights[j] will require a new gondola as sorted
		   so ans++, j--;

		   Run this loop till i<=j

		   TC - O(n)

*/

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, x;
    cin>>n>>x;
    vi weights(n);
    rep(i,0,n) cin>>weights[i];

    sort(weights.begin(), weights.end());
    int ans=0;

    int i = 0, j = weights.size()-1;

    while(i<=j){
    	if((weights[i] + weights[j]) <= x){
    		ans++;
    		i++;
    		j--;
    	}
    	else{
		ans++;
		j--;
    	}
    }

    cout<<ans;

    return 0;
}
