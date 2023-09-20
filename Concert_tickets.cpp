#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;
typedef vector<vector<int>> vii;
typedef vector<long long> vll;
typedef vector<long long int> vlli;
#define unm(a, b) unordered_map<a, b>
#define uns(a) unordered_set<a>

/*

prerequisites - learn about an awesome datastructure available in STL cpp
				called: multiset

				Also learn about upper_bound and lower_bound

Intuition:	sorting is necessary - but multiset handles it

			Store all tickets in multiset.

			Now for each customer identify the best possible option
			through binary search (can use upper_bound to make life easy)

			If there is such a ticket - print it (remember upper_bound points to
			the next bigger element, so make sure to decrement the iterator)
			and remove from multiset

			Else print -1 as no such ticket available

			TC - O(nlogn) + O(mlogn) (to binary search for every m in n) => O((n+m)logn)

*/

int h,t;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin>>n>>m;
    multiset<int> tickets;
    rep(i,0,n){
    	cin>>h;
    	tickets.insert(h);
    }

    rep(i,0,m){
    	cin>>t;
    	auto it = tickets.upper_bound(t);
    	if(it == tickets.begin()){
    		cout<<-1<<endl;
    	}
    	else{
    		cout<<*(--it)<<endl;
    		tickets.erase(it);
    	}
    }


    return 0;
}
