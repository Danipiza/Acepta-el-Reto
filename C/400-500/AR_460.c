#include <stdio.h>
#include <string.h>

#define MAX_LEN 102  // 101 dígitos + 1 para '\0'

void baseDiez(char *n, char *ret) {
    int i;
    int len = strlen(n);
    int pos = 0;

    for (i = 0; i < len; ++i) {
        ret[pos++] = n[i];
        if (i != len - 1) {
            ret[pos++] = '0';
        }
    }
    ret[pos] = '\0';  // Asegurar terminación de la cadena
}

int resuelveCaso() {
    char n[MAX_LEN];  // Buffer para leer el número grande
    if (scanf("%101s", n) != 1) return 0;

    char ret[MAX_LEN * 2];  // Espacio suficiente para la salida
    baseDiez(n, ret);

    printf("%s\n", ret);
    return 1;
}

int main() {
    while (resuelveCaso());
    return 0;
}
