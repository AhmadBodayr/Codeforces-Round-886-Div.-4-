using namespace std;
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
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
ll t, n;

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
		ll row = -1, col = -1;
		string out = "";
		vector<string> grid;
		grid.resize(8);
		bool done = 0;
		for(ll i = 0; i < 8; i++) {
			string curr; cin >> curr;
			grid[i] = curr;
			for(ll j = 0; j < 8 && !done; j++) if(grid[i][j] != '.') 
				row = i, col = j, done = 1;
		}
		for(ll i = row; i < 8; i++) {
			if(grid[i][col] == '.') break;
			out += grid[i][col];
		}
		cout << out << endl;


		
	} // end test cases
} // end main