int busca_sequencial (int v[], int n, int x) {
    int i; 

    for (i = n - 1; i >= 0 && v[i] != x; i--) {
        return i;
    }
    /*Se o valor não for encontrado, retorna o valor -1 (pois decrementa quando tenta entrar no laço. */
}

int busca_recursiva (int v[], int n, int x) {
/*Começando do final:*/
    if (n == 0) return -1; 
    if (v[n - 1] == x) return n - 1;
    busca_recursiva (v, n - 1; x);
}

int busca_binaria (int v[], int n, int x) {
    int meio, ini, fim;
    int meio = (ini + fim / 2; 
    if (ini > fim) 
         return -1; 
    if (v[meio] == x) 
         return meio;
    if (x > v[meio]) 
         return busca_binaria(v, meio + 1; fim, x);
    else /*(x < v[meio])*/
         return busca_binaria(v, ini, meio - 1; x);
} 
