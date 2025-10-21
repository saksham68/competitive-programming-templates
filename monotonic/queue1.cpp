#include <bits/stdc++.h>
#define int long long 
using namespace std;

// minimum queue implementation 1 
// supports everything a queue supports + minimum 
// push pop front back minimum 
// this approach cannot support front and back 

struct monotonic_queue {
	deque<pair<int,int>>d;
	// maintained element inserted and elements removed 
	int inserted = 0;
	int removed = 0;
	
	void push(int x) {
		// insert elements with their index 
		while(!d.empty() && d.back().second > x) {
		   d.pop_back();
		}
		d.push_back(make_pair(inserted + 1,x));
		inserted++;
	}

	void pop() {
	   // find the index to be removed using removed 
	   // the index to be removed is removed + 1 
	   if(d.front().first == removed + 1) {
	      d.pop_front();
	   }
       removed++;
	}

	int minimum() {
		return d.front().second;
	}
};

int32_t main() {

	int n,k;
    cin >> n >> k;
    int x,a,b,c;
    cin >> x >> a >> b >> c;
    vector<int>v(n);
    v[0] = x;
    for(int i = 1; i < n; i++) {
        v[i] = ((a * v[i - 1]) % c  + b) % c;
    }
    monotonic_queue q;
    int ans = 0;

    for(int i = 0; i < n; i++) {
        q.push(v[i]);

        if(i >= k - 1) {
            ans ^= (q.minimum());
            q.pop();
        }
    }

    cout << ans << '\n';



}