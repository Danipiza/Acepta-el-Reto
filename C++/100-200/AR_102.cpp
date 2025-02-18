#include <iostream>
#include <climits>
#include <string>

using namespace std;


// ----------------------------------------------------------

using namespace std; // libreria standard
// para poder usar cin, cout, string, otras librerias...


int cuenta_vocales(string s) {
    int ret=0;
    int i=0,n=s.size();
    char c;

    // FOR EACH
    // for(char c: s){
    while (i<n) {
        c=s[i++];
        if(c>96) {
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') ret++;
        }
        else {
            if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U') ret++;
        }
    }
    /* FOR EACH
    for(char c: s){
        
    }
    */

    return ret;
}

string decodificar(string s) {
    string ret="";
           
    int i=1,n=s.size();
    int desplazamiento='p'-s[0],tmp;
    char c;

    while(i<n) {
        c=s[i];
        if (c>='A' && c<='Z') {
            tmp=c+desplazamiento;

            if(tmp<'A') tmp = 'Z'+1-('A'-tmp);
            else if(tmp>'Z') tmp = 'A'-1+(tmp-'Z');

            ret+=tmp;
        }
        else if(c>='a' && c<='z') {
            tmp=c+desplazamiento;

            if(tmp<'a') tmp='z'+1-('a'-tmp);
            else if(tmp>'z') tmp = 'a'-1+(tmp-'z');

            ret+=tmp;
        }

        i++;
    }

    return ret;
}

bool resuelveCaso() {
    string s, s_decodificado;
    getline(cin, s);
    
    s_decodificado=decodificar(s);
    if(s_decodificado=="FIN") return false;
    
    cout << cuenta_vocales(s_decodificado) << "\n";

    return true;
}


int main() {
    //ios_base::sync_with_stdio(false);

    while (resuelveCaso());


    return 0;
}