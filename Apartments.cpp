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

Intuition: sorting is definitely required & a map to check if 
		   apartment is already occupied
1. Simple O(n*m) solution involves running loop m and checking if 
   the apartment satisfies condition for each n - TLE

2. Use a while loop which checks for basic conditions - O(n+m)
   If the apartment from the available apartment(k_[j]) is greater
   than the apartment(m_[i]) => none of the other available apartments
   will satisfy condition (as sorted) => i++ (skip that applicant)

   |||ly, if the k_[j] is smaller than the m_[i] => that available 
   apartment is not used => j++

   Finally, if condition satisfies, then mark the house as booked
   and i++, j++.

*/

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
