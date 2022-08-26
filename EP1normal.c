#include <stdio.h>

int conjec_collatz (int n);

int main () {
    int i, f, j, n, passos = 0;

    printf ("Digite o inicio intervalo desejado:\n");
    scanf ("%d", &i);
    printf ("Digite o fim do intervalo desejado:\n");
    scanf ("%d", &f);

    for (j = i; j <= f; j++) {
        n = j;
        while (n != 1) {
            n = conjec_collatz(n);
            passos++;
        }
        printf ("=> O numero de passos necessarios para o %d convergir para 1 foram %d.\n", j, passos);
        passos = 0;
    }

    return 0;
}

int conjec_collatz (int n) {
    int eh_par;
    eh_par = n % 2 == 0;
    
    if (eh_par) {
        n = n / 2;
    }
    else if (!eh_par) {
        n = (3 * n) + 1;
    }
    return n;
}
