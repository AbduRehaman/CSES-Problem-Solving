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

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n,m,k;
    cin>>n>>m>>k;
    vi k_(n);
    vi m_(m);
    rep(i,0,n) cin>>k_[i];
    rep(i,0,m) cin>>m_[i];
    sort(k_.begin(), k_.end());
    sort(m_.begin(), m_.end());
    unm(int,bool) mpp;
    rep(i,0,n) mpp[i] = false;
    int ans=0;

    int i=0, j=0;
    while(i<m && j<n){
    	if(k_[j] < (m_[i]-k)){
    		j++;
    	}
    	else if((mpp[j]==false) && (k_[j]>=(m_[i]-k) && k_[j]<=(m_[i]+k))){
    		ans++;
    		mpp[j] = true;
    		j++;
    		i++;
    	}
    	else if(k_[j] > (m_[i]+k)){
    		i++;
    	}
    }

    cout<<ans;

    return 0;
}
