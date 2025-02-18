#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string baseDiez(string n) {		

	string ret = "";
	
	for (int i = 0; i < n.size(); ++i) {
		ret += n[i];
		if(i != n.size() -1 ) ret += "0";
	}

	/*--i;
	while (i >= 0) {
		string auxS = n[i] + "0";
		ret = auxS + ret;

		i--;
	}*/


	return ret;
}

bool resuelveCaso() {
	string n = "";
	cin >> n;
	if (!cin)
		return false;
	
	cout << baseDiez(n) << "\n";

	return true;
}

int main() {

	while (resuelveCaso()) {}

	return 0;
}