#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void test_case(int& tc) {
	int l;
	cin >> l;
	ll overflow = 4294967295; // equal to 2^32 - 1
	stack<pair<ll, ll>> val_stack;
	val_stack.push(make_pair(0, 0));
	for (int i = 0; i < l; i++) {
		string command;
		cin >> command;
		if (command == "for") {
			ll n;
			cin >> n;
			val_stack.push(make_pair(n, 0));
		} else if (command == "add") {
			if (val_stack.top().second + 1 > overflow) {
				cout << "OVERFLOW!!!\n";
				return;
			}
			val_stack.top().second++;
		} else {
			pair<ll, ll> prev_top = val_stack.top();
			val_stack.pop();
			ll res = prev_top.first * prev_top.second;
			if (res > overflow || val_stack.top().second + res > overflow) {
				cout << "OVERFLOW!!!\n";
				return;
			}
			val_stack.top().second += res;
		}
	}
	cout << val_stack.top().second << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	// cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
