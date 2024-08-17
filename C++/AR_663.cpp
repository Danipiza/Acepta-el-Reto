#include <iostream>

using namespace std;

bool resuelveCaso() {
	int n = 0;
	cin >> n;
	if(n> 0) n--;
	
	cout << n << "\n";
}

int main(){
	int n=0;
	cin >> n;
	for (int i = 0; i < n; i++)
		resuelveCaso();
		
	return 0;
}