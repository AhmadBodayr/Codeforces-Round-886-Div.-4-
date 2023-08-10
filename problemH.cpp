#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll; 					
typedef unsigned long long ull; 
typedef long double ld;
#define inf 1000000000000000005
//////////////////Library///////////////////////////////////
class Trie {
private:
	Trie* child[26];
	bool isLeaf;
public:
	Trie() {
		memset(child, 0, sizeof(child));
		isLeaf = 0;
	}

	void insert(char* str) {
		if(*str == '\0') isLeaf = 1;
		else {
			int curr = *str - '0';
			if(child[curr] == 0) child[curr] = new Trie();
			child[curr] -> insert(str + 1);
		}
	} 

	bool wordExist(char* str) {
		if(*str == '\0') return isLeaf;
		int curr = *str - '0';
		if(child[curr] == 0) return false;
		return child[curr] -> wordExist(str + 1); 
	}

	bool prefExist(char* str) {
		if(*str == '\0') return true;
		int curr = *str - '0';
		if(child[curr] == 0) return false;
		return child[curr] -> wordExist(str + 1);
	}
};

class DSU {
private:
    vector<int> root;
    vector<int> rank;
public:
    DSU(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
/////////////////////////////////End library/////////////////////////////////////
ll t, n, m;
vector<vector<pair<ll, ll>>> graph;
vector<bool> visited;
vector<ll> cost;
bool ok = 1;

bool dfs(ll node) {
	visited[node] = 1;
	for(auto [child, d]: graph[node]) {
		if(!visited[child]) {
			cost[child] = cost[node] + d;
			ok &= dfs(child);
		} else {
			if(cost[child] != d + cost[node]) {
				ok = 0; break;
			}
		}
	}
	return ok;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL); 	

	// #ifndef ONLINE_JUDGDE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);	
	// #endif
	///////////////////////////////////////////////////////////////
	cin >> t;
	while(t--) {
		ok = 1;
		cin >> n >> m;
		visited.clear(), visited.resize(n, 0);
		graph.clear(), graph.resize(n);
		cost.clear(), cost.resize(n, 0);
		for(ll i = 0; i < m; i++) {
			ll a, b, d; cin >> a >> b >> d;
			a--, b--;
			graph[a].push_back({b, d});
			graph[b].push_back({a, -d});
		}
		
		for(ll i = 0; i < n && ok; i++) {
			if(!visited[i]) {
				ok &= dfs(i);
			}
		}
		cout << (ok ? "YES" : "NO") << endl;

		
	} // end test cases
} // end main


