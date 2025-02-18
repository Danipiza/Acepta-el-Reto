#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int main() {
	int N;
	cin >> N;
	unordered_map<int, int> mapa;
	int a;
	while (N!=0) {
		mapa.clear();
		
		for (int i = 0; i < N; i++) {
			cin >> a;
			mapa[a]++;
		}
		int ret = 0;
		for (auto a : mapa) {
			ret += a.second / 2;
		}
		cout << ret << "\n";
		cin >> N;
	}

	return 0;
}