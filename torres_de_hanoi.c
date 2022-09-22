void hanoi (int n, char ini, char aux, char fim) {
    if ( n > 0) {
        hanoi(n-1, ini, fim, aux);
        printf ("Move disco %d da torre %c para %c\n", n, ini, fim);
        hanoi(n-1, aux, ini, fim);
    }
}
