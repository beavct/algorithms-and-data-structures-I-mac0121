//Recursão: 
long fatorial (int n) {
    if (n == 0) {
        return 1;
    }
    return (n * fatorial(n - 1));
}
// prova por indução 

long pot dois (int n) {
    if (n == 0) return 1;
    return (2 * potdois(n - 1));
}

long fatorialIterativo (int n) {
    int resultado = 1;
    int i; 

    for (i = 2; i  <= n; i++) {
    // invariante de laço: resultado = i!
    // não muda dentro do laço, sempre verdade independente do i
    // prova de uma indução basicamente 
        resultado *= i;
    }

    return resultado;
}

double maior (double V[]  int n) {
//retorna o maior valor dentro de um vetor
    double aux;

    if (n == 1) return v[0];
    aux = maior(V, n - 1); 
    //exclui a última célula

    if (aux > v[n - 1]) return aux;
    return v[n - 1];
}

long fibonacci (int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return(fibonacci(n - 1) + fibonacci(n - 2));
}
// árvore de recursão 
// a quantidade de chamadas aumenta de forma exponencial
// tempo de execução exponencial, faz trabalho repetido 
// para problemas com números grandes a recursão, é boa, mas pra esses casos acima é meio inútil e a versão iterativa é mais rápida 

//Top-Down:
//Evitar trabalho a toa, no mesmo exemplo no de Fibonacci, podemos alocar um vetor de tamanho n e ir guardando os resultados que podem ser usados nas próximas chamadas da função. 
//Programação dinâmica: recursão com Top-Down ou Bottom-Up com memorização 
//Algoritmo:
long fibonacci (int n) {
    long *fib = malloc ((n + 1) * sizeof(long));
    int i, res;
    
    for (i = 2; i <= n; i++) {
    //iniciar o vetor com -1
        fib[i] = -1;
    }
    fib[0] = 1;
    fib[1] = 1;

    res = fibonacciRec(n, fib);
    free(fib);
    return res;
}
long fibonacciaRec (int n, long *V) {
    if (V[n] == -1) {
        fib[n] = fibonacciRec(n - 1, V) + fibonacciRec(n - 2, V)
        return (fibonacciRec(n - 1, V) + fibonacciRec(n - 2, V));
    }
    return fib[n];
}
