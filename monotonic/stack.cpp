#include <bits/stdc++.h>
using namespace std;
#define int long long 


// should support everything a stack supports + minimum operation 
// push pop top minimum 
struct monotonic_stack {
	stack<pair<int,int>> s;

	void push(int x) {
		s.push((s.empty() ? make_pair(x,x): make_pair(x,min(x,s.top().second))));
	}

	void pop() {
		s.pop();
	}

	void top() {
		return s.top().first;
	}

	int minimum() {
		return s.top().second;
	}
};

int32_t main() {

	monotonic_stack s;

   while(true) {
      int n;
      cin >> n;
      if(n == 1) {
      	// insert
      	int a;
      	cin >> a;
      	s.push(a);
      } else if(n == 2) {
      // remove
      	s.pop();
      } else if(n == 69) {
      	return 0;
      } else {
      	// find minimum 
      	cout << s.minimum();
      }
   }

   return 0;
	
}