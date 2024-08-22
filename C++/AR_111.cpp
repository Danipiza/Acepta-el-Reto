#include <iostream>
#include <vector>
#include <string>
#include <map>


// ----------------------------------------------------------

using namespace std; // libreria standard
// para poder usar cin, cout, string, otras librerias...

using vs=vector<string>;



int conversion(char nivel) {
	int ret=2; // s
	
	if(nivel=='d') ret=6;
	else if (nivel=='p') ret=10;
	else if (nivel=='f') ret=14;

	return ret;
}


string configuracion_electronica(int electrones) {	
	vs niveles={ "1s", "2s", "2p", "3s", "3p",
				 "4s", "3d", "4p", "5s", "4d",
				 "5p", "6s", "4f", "5d", "6p",
				 "7s", "5f", "6d", "7p" };

	map<char, int> mapa;
	mapa['s']=2; mapa['p']=6; 
	mapa['d']=10; mapa['f']=14;

	string ret="";
	
	int i=0, tmp;
	//tmp=conversion(niveles[i][1]);
	tmp=mapa[niveles[i][1]];

	while (electrones>tmp) {						
		electrones-=tmp;

		ret+=niveles[i]+to_string(tmp)+" ";				

		i++;
		//tmp=conversion(niveles[i][1]);
		tmp=mapa[niveles[i][1]];
	}
	ret+=niveles[i]+to_string(electrones);
	//cout << niveles[i] << electrones << '\n';

	return ret;
}


bool resuelveCaso() {	
	string elemento;

	cin >> elemento;
	if (elemento=="Exit") return false;

	int electrones;
	cin >> electrones;
	
	string salida=configuracion_electronica(electrones);
	cout << salida << "\n";
	
	return true;	
}



int main() {
	//ios_base::sync_with_stdio(false);

	while (resuelveCaso());


	return 0;
}
(c) Acepta el reto, 2013 - 2024
