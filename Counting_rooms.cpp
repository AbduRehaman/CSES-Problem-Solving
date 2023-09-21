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

	Intuition: Don't use BFS (as for this case travelling level wise, might cause cases
			   where we might visit same node more than once and mark it) - TLE

			   Use DFS (as it depends on visited matrix, we can simply check if the node was
			   previously visited) - Accepted

			   To visualize uncomment the following lines: (52-60), (83) and (91)

			   TC - O(n*m)

*/
 
char c;

void dfs(vii& maze, vii& vis, int row, int col){
	vis[row][col] = 1;

	rep(i,0,4){
		int nrow = row+deltar[i];
		int ncol = col+deltac[i];

		if(graph_checker(nrow,ncol,maze.size(),maze[0].size()) 
			&& vis[nrow][ncol]==0 && maze[nrow][ncol]==1){

			maze[nrow][ncol] = 0;

			dfs(maze, vis, nrow, ncol);
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

    rep(i,0,n){
    	rep(j,0,m){
    		cin>>c;
    		if(c=='#') maze[i][j] = 0;
    		else maze[i][j] = 1;
    	}
    }

    int count=0;

    vii vis(n,vi(m,0));

    // print(maze);

    rep(i,0,n){
    	rep(j,0,m){
    		if(maze[i][j]==1){
    			maze[i][j] = 0;
    			count++;
    			dfs(maze, vis, i, j);
    			// print(maze);
    		}
    	}
    }

    cout<<count<<endl;
 
    
 
    return 0;
}