/* A função recebe vetores crescentes v[p..q]  e v[q+1..r]
   e rearranja v[p..r] em ordem crescente. */

void  intercala (int p, int q, int r, int v[])  {
  int n1, n2;
  int * A, * B;                     
  int i, j, k;

   
  n1 = q - p + 1;
  n2 = r - q;
  
  A = malloc (n1 * sizeof (int));      
  B = malloc (n2 * sizeof (int));      

  for (i = 0; i < n1; i++)
    A[i] = v[p+i];

  for (i = 0; i < n2; i++)
    B[i] = v[q+1 + i];

  
  i = 0, j = 0;
  k = p;
  while (i < n1 && j < n2) {                
    if (A[i] <= B[j])
      v[k] = A[i++];  
    else
      v[k] = B[j++];
    k++;
  }

  while (i < n1)
    v[k++] = A[i++];         
  while (j < n2)
    v[k++] = B[j++];

  free(A);
  free(B);
}


/* A função mergesort rearranja o vetor 
   v[p..r] em ordem crescente. */

void mergeSort (int p, int r, int v[]) {
  int q;
  
  if (p < r) {                 
    q = (p + r)/2;         
    mergeSort(p, q, v);       
    mergeSort(q+1, r, v);       
    intercala(p, q, r, v);    
  }
  
}





void insertionSort (int A[], int n) {
  int i, chave, j;
  /* a cada iteração, teremos o vetor A[1..i] ordenado */
  /* começamos de A[i], porque obviamente o vetor em A[0..0] está 
     trivialmente ordenado */
     
  for (i = 1; i < n; i++) {
    chave = A[i];
    j = i - 1;

    /* encontra a posicao correta de chave (A[i])
       no vetor A[0..i-1] */
    while (j >= 0 && A[j] > chave) {
      A[j + 1] = A[j];
      j = j - 1;
    }
    A[j + 1] = chave;
  }
}






int particiona (int v[], int ini, int fim) {
  int i, j, pivo;

  pivo = v[fim];
  i = ini;
  for (j = ini; j < fim; j++){
    if (v[j] <= pivo){
      troca(v, i, j);
      i++;
    } 
  }
  troca(v, i, fim);

  return i;
}

void quicksort (int v[], int ini, int fim) {
  int x;

  if (ini < fim){
    x = particiona(v, ini, fim);
    quicksort(v, ini, x - 1);
    quicksort(v, x + 1, fim);
  }
}
