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

ll t, n, k;
vector<ll> v;

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
		cin >> n >> k;
		bool ok = 1;
		v.resize(n);
		for(ll i = 0; i < n; i++) {
			ll curr; cin >> curr;
			v[i] = curr;
			if(i != 0) {
				if(abs(v[i] - v[i - 1]) > k) ok = 0;
			}
		}
		if(ok) {
			cout << 0 << endl; continue;
		}
		sort(v.begin(), v.end());
		ll out = 1;
		ll acc = 1;
		for(ll i = 1; i < n; i++) {
			if(abs(v[i] - v[i - 1]) <= k) {
				acc++;
				out = max(out, acc);
			} else {
				acc = 1;
			}
		}
		cout << n - out << endl;


		
	} // end test cases
} // end main