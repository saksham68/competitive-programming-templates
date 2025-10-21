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
		appeared++;
	}

	void pop() {
	   // find the index to be removed using removed 
	   // the index to be removed is removed + 1 
	   if(d.front().first == removed + 1) {
	      d.pop_front();
	   }
	}

	int minimum() {
		return d.front().second();
	}
}

int32_t main() {

	int n;
	cin >> n;
	if(n == 1) {

	} else if(n == 2) {

	} else if(n == 3) {

	} else {
		
	}

}