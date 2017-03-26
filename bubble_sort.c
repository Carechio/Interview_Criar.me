#include <stdio.h>
#include <stdlib.h>

void bubblesort(int n, double *V);

int main(int argc, char const *argv[]) {
  //input
  int n = argc - 1;
  double V[n];
  for (int i = 0; i < n; i++){
    V[i] = atof(argv[i + 1]);
  }

  //ordenation
  bubblesort(n, V);

  //output
  printf("\nOrdenated values: ");
  for(int i = 0; i < n; i++){
    printf("%f ", V[i]);
  }
  printf("\n");
  return 0;
}

void bubblesort(int n, double *V){
  int i, j;
  double x;
  char changed = 'T'; //TRUE

  for (i = n - 1; i >= 0 && changed; i--){
    changed = 'F'; //FALSE
    for (j = 0; j < i; j++){
      if (V[j] > V[j+1]){
        x = V[j];
        V[j] = V[j+1];
        V[j+1] = x;
        changed = 'T'; //TRUE
      }
    }
  }
}
