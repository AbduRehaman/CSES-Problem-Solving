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
vi deltar = {1,0,-1,0};
vi deltac = {0,1,0,-1};
bool graph_checker(int row, int col, int n, int m){
	if(row>=0 && row<n && col>=0 && col<m) return true;
	else return false;
}
 

/*

	Intuition:	perform bfs, update the path.
				Only part to learn is retrace, i.e, printing the path

				Learn the from array and retrace method, very useful in other questions as well

				TC - O(N^2) => N - total number of nodes.

*/


char c;

bool possible=false;

pi from[1005][1005];
string ans="";

void retrace(pi node, pi& A){
	pi origin = from[node.first][node.second];
	// cout<<node.first<<" "<<node.second<<" -> "<<origin.first<<" "<<origin.second<<endl;
	

	if(origin.first == node.first+1) ans.push_back('U');
	if(origin.first == node.first-1) ans.push_back('D');
	if(origin.second == node.second+1) ans.push_back('L');
	if(origin.second == node.second-1) ans.push_back('R');
	if(origin==pi(A.first,A.second)) return;
	retrace(origin,A);
}

void bfs(vii& maze, queue<pi>& q, pi& B, pi& A){
	int n = maze.size();
	int m = maze[0].size();

	while(!q.empty()){
		auto it = q.front();
		int row = it.first;
		int col = it.second;
		q.pop();

		if(row == B.first && col == B.second){
			possible = true;
			cout<<"YES\n";
			cout<<maze[row][col]<<endl;
			// from[A.first][A.second] = pi(0,0);
			retrace(it,A);
			return;
		}

		rep(i,0,4){
			int nrow = row + deltar[i];
			int ncol = col + deltac[i];

			if(graph_checker(nrow,ncol,n,m) ){
				if(maze[row][col]+1<maze[nrow][ncol]){
					maze[nrow][ncol] = maze[row][col] + 1;
					q.push({nrow,ncol});
					from[nrow][ncol] = it;
				}
				
			}
		}
		
	}
}

// void print(vii& maze){
// 	rep(i,0,maze.size()){
// 		rep(j,0,maze[0].size()){
// 			cout<<maze[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}
// 	cout<<endl;
// }

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n,m;
    cin>>n>>m;

    vii maze(n,vi(m));

    pi A, B;

    rep(i,0,n){
    	rep(j,0,m){
    		cin>>c;
    		maze[i][j] = INT_MAX;
    		if(c=='#') maze[i][j] = 0;
    		if(c=='A'){
    			A.first = i;
    			A.second = j;
    		}
    		if(c=='B'){
    			B.first = i;
    			B.second = j;
    		}
    	}
    }

    // print(maze);
    maze[A.first][A.second] = 0;

    queue<pi> q;
    q.push(A);
    bfs(maze, q, B, A);

    // print(maze);
 
    if(possible){
    	reverse(ans.begin(), ans.end());
    	cout<<ans<<endl;
    }
    else cout<<"NO\n";
 
    return 0;
}