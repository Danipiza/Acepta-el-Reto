#include <iostream>
#include <vector>


using namespace std;

// Pre: true
int sum(const vector<int>& v) {
    int r = 0;
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i
    for (int i = 0; i < v.size(); ++i)
        r += v[i];
    return r;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    int n;
    cin >> n;	
	if (n == 0)
		return false;

	int x;
	cin >> x;
	int maxGlobal = x, maxNinos = x;
	int ninos = 1;
	int i = 1;
	while (i < n) {
		cin >> x;
		if (x > maxGlobal) maxGlobal = x;
		if (x <= maxNinos) {
			ninos = i + 1;
			maxNinos = maxGlobal;
		}
		i++;
	}


	// write solution
	cout << ninos << '\n';


	return true;
}
int main() {
	while (solve());
	return 0;
}