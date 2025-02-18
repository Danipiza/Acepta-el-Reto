#include <iostream>
#include <climits>
#include <vector>
#include <map>
#include <string>

using namespace std;


// ----------------------------------------------------------

using namespace std; // libreria standard
// para poder usar cin, cout, string, otras librerias...



void comprueba_pais(string num, string& pais) {
	map<string, string> mapa;
	mapa["0"]="EEUU"; mapa["380"]="Bulgaria"; mapa["50"]="Inglaterra";
	mapa["539"]="Irlanda"; mapa["560"]="Portugal"; mapa["70"]="Noruega";
	mapa["759"]="Venezuela"; mapa["850"]="Cuba"; mapa["890"]="India";
		
	// variable de entrada/salida
	// se utiliza un mapa para reducir la complejidad
	pais="Desconocido";
	string id="";
	for(int i=0;i<3;i++){
		id+=num[i];
		if(mapa.count(id)>0) {
			pais=mapa[id];
			break;
		}
	}
}


bool EAN(int digitos, string num, string& salida) {
	bool ret;
	
	int codigo_error=num[digitos-1]-'0', suma = 0;

	int tmp=0, aux=(digitos==8?1:0);
	for(int i=digitos-2;i>=0;i--){
		tmp=1;
		if((i+aux)%2==1) tmp=3;
		
		suma+=(num[i]-'0')*tmp;
	}


	int sum_multiplo=suma%10;
	if(sum_multiplo!=0) sum_multiplo=10-sum_multiplo;		
	ret=sum_multiplo==codigo_error;

	if(ret && digitos==13) comprueba_pais(num, salida);

	return ret;
}

bool resuelveCaso() {	
	string num;
	cin >> num;
	if(num=="0") return false;

	
	int digitos=num.size();	
	if(digitos<8){ // si es inferior a 8 hay que añadir 0s
		while(num.size()<8) num="0"+num;
		digitos=8;
	}
	else if (digitos>8) { // si distinto de 8 e inferior a 13 hay que añadir 0s
		while(num.size()<13) num="0"+num;
		digitos=13;
	}
	

	string pais="";
	bool salida=EAN(digitos,num,pais);

	if (salida) {
		cout << "SI";
		if (digitos==13) cout << " " << pais;
	}
	else cout << "NO";
	cout << "\n";
	
	return true;	
}



int main() {
	//ios_base::sync_with_stdio(false);

	while (resuelveCaso());


	return 0;
}