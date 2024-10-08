#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int cuenta_vocales(char* s) {
    int ret=0;
    int i=0, n=strlen(s);
    char c;

    while (i<n) {
        c=s[i++];
        if (islower(c)) {
            if (c=='a' || c=='e' || c=='i' || 
            c=='o' || c=='u') ret++;
        } 
        else {
            if (c=='A' || c=='E' || c=='I' || 
            c=='O' || c=='U') ret++;
        }
    }

    return ret;
}

void decodificar(char* s, char* ret) {
    int i=1, j=0, n=strlen(s);
    int desplazamiento='p'-s[0];
    char c;
    

    while (i<n) {
        c=s[i];
        if (isupper(c)) {
            int tmp=c+desplazamiento;

            if (tmp<'A')      tmp='Z'+1-('A'-tmp);
            else if (tmp>'Z') tmp='A'-1+(tmp-'Z');
            
            ret[j++]=tmp;
        } 
        else if (islower(c)) {
            int tmp=c+desplazamiento;

            if (tmp<'a')      tmp='z'+1-('a'-tmp);
            else if (tmp>'z') tmp='a'-1+(tmp-'z');
            
            ret[j++]=tmp;
        }
        i++;
    }

    ret[j]='\0';
}

int resuelveCaso() {
    char s[MAX_LENGTH], s_decodificado[MAX_LENGTH];
    if (fgets(s, MAX_LENGTH, stdin)==NULL) return 0;

    s[strcspn(s, "\n")]=0;  // Elimina el salto de linea

    decodificar(s, s_decodificado);
    if (strcmp(s_decodificado, "FIN")==0) return 0;

    printf("%d\n", cuenta_vocales(s_decodificado));

    return 1;
}

int main() {
    while (resuelveCaso());
    return 0;
}