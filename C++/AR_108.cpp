#include <iostream>
#include <vector>
#include <map>
#include <float.h>

// ----------------------------------------------------------

using namespace std; // libreria standard
// para poder usar cin, cout, string, otras librerias...

using vs=vector<string>;

map<char, string> mapa={{'D', "DESAYUNOS"}, 
						{'A', "COMIDAS"}, 
						{'M', "MERIENDAS"}, 
						{'I', "CENAS"}, 
						{'C', "COPAS"}};

string conversion(char categoria) {
	if 		(categoria=='D') return "DESAYUNOS";
	else if (categoria=='A') return "COMIDAS";
	else if (categoria=='M') return "MERIENDAS";
	else if (categoria=='I') return "CENAS";
	else if (categoria=='C') return "COPAS";
}

string categoria_maximo(map<char, double> ventas) {
	string ret="EMPATE";

	double maximo_valor=-DBL_MAX;
	int count=0;

	for (auto categoria: ventas) {
		if (maximo_valor<categoria.second) {
			maximo_valor=categoria.second;

			ret=conversion(categoria.first);
			count=1;
		}
		else if (categoria.second==maximo_valor) count++;
	}
	
	if (count>1) ret="EMPATE";

	return ret;
}

string categoria_minimo(map<char, double> ventas) {
	string ret="EMPATE";

	double minimo_valor=DBL_MAX;
	int count=0;

	for (auto categoria: ventas) {
		if (minimo_valor>categoria.second) {
			minimo_valor=categoria.second;

			ret=conversion(categoria.first);
			count=1;
		}
		else if (minimo_valor==categoria.second) count++;
	}

	if (count>1) ret="EMPATE";

	return ret;
}

int main() {
	map<char, double> ventas;
	ventas['D']=0; ventas['A']=0;
	ventas['M']=0; ventas['I']=0;
	ventas['C']=0;

	double total=0;
	int num_ventas_comidas=0, num_ventas_total=0;

	string aux;
	
	char categoria;
	double valor;
	while (cin >> categoria >> valor) {


		if (categoria=='N' && valor==0) {
			aux = "NO";
			if (ventas['A']/num_ventas_comidas>(total/num_ventas_total)) aux = "SI";

			cout << categoria_maximo(ventas) << "#" << categoria_minimo(ventas) << "#" << aux << "\n";			
			
			
			ventas['D']=0; ventas['A']=0;
			ventas['M']=0; ventas['I']=0;
			ventas['C']=0;

			total=0;
			num_ventas_total=0; num_ventas_comidas=0;
		}
		else {
			ventas[categoria] += valor;
			if (categoria == 'A') num_ventas_comidas++;
			total += valor;
			num_ventas_total++;
		}
	}

	return 0;
}

/* 

# -- USANDO MAPAS -------------------------------------------------------------

bool resuelveCaso() {
	map<char, double> ventas;
	ventas['D']=0; ventas['A']=0;
	ventas['M']=0; ventas['I']=0;
	ventas['C']=0;
	
	char categoria;
	double valor;
	
	
	cin >> categoria >> valor;
	if (!cin) return false;

	double total=0;
	int num_ventas_comidas=0, num_ventas_total=0;

	while(categoria!='N' && valor!=0){	

		ventas[categoria]+=valor;
		if (categoria=='A') num_ventas_comidas++;
		total+=valor;
		num_ventas_total++;

		cin >> categoria >> valor;
	}

	string comidas_mayor="NO";
	if (ventas['A']/num_ventas_comidas>(total/num_ventas_total)) comidas_mayor="SI";
	cout << categoria_maximo(ventas) << "#" << categoria_minimo(ventas) << '#' << comidas_mayor << "\n";

	
	
	return true;	
}



int main() {
	//ios_base::sync_with_stdio(false);

	while (resuelveCaso());


	return 0;
}*/
