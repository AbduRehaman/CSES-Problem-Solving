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

	Intuition: Suggested by dileep-shar.
			   Problem is similar to rotten-oranges (check it out)

			   simple concept is do multi-source bfs (in simple terms perform bfs for
			   multiple nodes at a time).

			   We initially perform multi-source bfs for monsters (after storing their location)
			   and obtain the fastest way for any monster to reach their adjacent locations (if possible)
			   to understand uncomment line 123-129

			   Then we perform single source bfs from the position of A.

			   According to the statement of the problem: "Your plan has to work in any situation; even if the monsters know your path beforehand."

			   It becomes easy to visualize, if a particular monster reaches a path before A does, then A can't use that path.
			   to understand uncomment line 148-154

			   To retrace the path, just learn the recursive technique retrace used in the code (can be applied to many problems)

			   TC - O(n^2) => We traverse each location a constant number of times and perform bfs (adjacency matrix representation has TC - O(n^2)).

*/

 
pi from[1005][1005];
bool possible=false;
 
vector<char> ans;
 
void retrace(pi node){
	pi origin = from[node.first][node.second];
	if(origin==pi(0,0)) return;
	if (origin.first == node.first + 1) ans.push_back('U');
	if (origin.first == node.first - 1) ans.push_back('D');
	if (origin.second == node.second + 1) ans.push_back('L');
	if (origin.second == node.second - 1) ans.push_back('R');
	retrace(origin);
}
 
 
void bfs(vii& maze, queue<pair<int,int>>& q, bool flag){
	int n = maze.size();
	int m = maze[0].size();
	while(!q.empty()){
		auto it = q.front();
		q.pop();
		int row = it.first;
		int col = it.second;
 
		rep(i,0,4){
			int nrow = row + deltar[i];
			int ncol = col + deltac[i];
 
			if(graph_checker(nrow,ncol,n,m)){
				if(maze[row][col]+1 < maze[nrow][ncol]){
					maze[nrow][ncol] = maze[row][col]+1;
					q.push({nrow,ncol});
					from[nrow][ncol] = it;
				}
			}
		}
		if(flag && (row==0 || row==n-1 || col==0 || col==m-1)){ //Will only execute when it's A's turn
			possible = true;
			cout<<"YES\n";
			cout<<maze[row][col]<<endl;
			retrace(it);
			return;
		}
	}
}
 
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    int n, m; 
    cin>>n>>m;
 
    vector<vector<int>> maze(n,vector<int>(m));
 
    vpi monsters;
 
    pair<int,int> A;
 
    queue<pair<int,int>> q;
 
    bool flag = false; //For monsters
 
    
 
    rep(i,0,n){
    	string s;
    	cin>>s;
    	rep(j,0,m){
    		maze[i][j] = INT_MAX;
    		if(s[j]=='M'){
    			q.push({i,j});
    			maze[i][j] = 0;
    		}
    		if(s[j]=='#'){
    			maze[i][j] = 0;
    		}
    		if(s[j]=='A'){
    			A.first = i;
    			A.second = j;
    		}
    	}
    }
 
    bfs(maze, q, flag);
 
    // rep(i,0,n){
    // 	rep(j,0,m){
    // 		cout<<maze[i][j]<<" ";
    // 	}
    // 	cout<<endl;
    // }
    // cout<<endl;
 
    q.push({A.first,A.second});
 
    flag = true; // for A

    from[A.first][A.second] = pi(0,0);
 
    maze[A.first][A.second] = 0;
 
    bfs(maze,q,flag);
 
    // rep(i,0,n){
    // 	rep(j,0,m){
    // 		cout<<maze[i][j]<<" ";
    // 	}
    // 	cout<<endl;
    // }
    // cout<<endl;
 
    if(possible){
    	reverse(ans.begin(),ans.end());
    	rep(i,0,ans.size()) cout<<ans[i];
    	cout<<endl;
    }
    else cout<<"NO\n";
 
 
    return 0;
}