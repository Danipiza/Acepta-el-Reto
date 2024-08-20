#include <iostream>
#include <climits>
#include <vector>

using namespace std;


// ----------------------------------------------------------

using namespace std; // libreria standard
// para poder usar cin, cout, string, otras librerias...

using vi=vector<int>;



double calcula_altura(double x, vector<int> const& f) {
	double ret=0;
	// Inicialmente empieza con la constante
	double exponente = 1;
	int n=f.size();

	// FOR EACH
	//for (int coef : f) {
	for (int i=0;i<n;i++) {
		ret+=f[i]*exponente;
		exponente*=x;
	}
	return ret;
}

double calcula_area(int area, vi& f) {    
	double ret=0.0;
	double base, altura;
	for (int i=0;i<area;i++) {
		base=1.0/(double)area;
		altura=calcula_altura(i*base, f);

		if (altura<0) continue;
		else if (altura>1) altura=1;

		ret+=base*altura;
	}
	return ret;
}

bool resuelveCaso() {	
	int grado;
	cin >> grado;
	if(grado==20) return false;

	vi f(grado+1);
	for (int i=0;i<grado+1;i++) cin >> f[grado-i];

	int n;
	cin >> n;
	double area_cain=calcula_area(n,f);	

	if (area_cain<0.4999) cout << "ABEL\n";
	else if (area_cain>0.5001) cout << "CAIN\n";
	else cout << "JUSTO\n";
	
	return true;	
}



int main() {
	//ios_base::sync_with_stdio(false);

	while (resuelveCaso());


	return 0;
}