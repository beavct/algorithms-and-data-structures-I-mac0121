void mergesort (int p, int r, int v[])
{
   if (p < r-1) {                 
      int q = (p + r)/2;         
      mergesort (p, q, v);        
      mergesort (q, r, v);        
      intercala (p, q, r, v);     
   }
}

void troca (int v[], int i, int j){
  int aux;
   aux = v[j];
   v[j] = v[i];
   v[i] = aux;
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
