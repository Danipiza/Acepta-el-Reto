#include<iostream>
#include<vector>

using namespace std;

int numAbadias(vector <int> const& v) {
	int abadias = 1, max = v[v.size()-1];
	
	for (int i = v.size()-2; i >= 0; --i) {
		if (v[i] > max) {
			abadias++;
			max = v[i];
		}
	}
	return abadias;
}

bool resuelveCaso() {
    int n;
    cin >> n;

    if (n == 0)
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cout << numAbadias(v) << endl;

    return true;
    }

int main() {
	while (resuelveCaso());
	return 0;
}