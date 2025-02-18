#include <iostream>
#include <string>

// ----------------------------------------------------------

using namespace std; // libreria standard
// para poder usar cin, cout, string, otras librerias...


bool es_calambur(string frase1, string frase2) {
	bool ret=true;

	int i=0,j=0;
	int n=frase1.size(), m=frase2.size();
	
	if (n!=m) ret=false;

	while (ret && i<n) {
		if(frase1[i]!=frase2[i]) ret=false;
		i++; 
	}

	return ret;
}

string eliminar_mayusculas(string& frase) {
	string ret="";

	int n=frase.size();
	char c;
	for(int i=0;i<n;i++){
		c=frase[i];
		if(c>='a' && c<='z') ret+=c;
		else {
			if(c>='A' && c<='Z') ret+=c+32;
		}
	}

	return ret;
}

/*
Yo lo coloco y ella lo quita.
Y o l o c o l o c o y e l l a l o q u i t a.
*/

void resuelveCaso() {
	string frase1, frase2;
	getline(cin, frase1);
	getline(cin, frase2);

	frase1=eliminar_mayusculas(frase1);
	frase2=eliminar_mayusculas(frase2);

	if (es_calambur(frase1, frase2)) cout << "SI\n";
	else cout << "NO\n";
}



int main() {
	//ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	string aux;
	getline(cin, aux);
	for(int i=0;i<N;i++) resuelveCaso();


	return 0;
}