#include <stdio.h>
#include <stdlib.h>

int takeStones(int n);

int main(int argc, char const *argv[]) {
  int n; //number of stones on the board
  int T; //number of plays
  scanf("%d", &T);
  if(T < 1 || T > 100) return 0;

  int winner[T];
  for(int i = 0; i < T; i++){
    scanf("%d", &n);
    if(n < 1 || n > 100) return 0;
    winner[i] = takeStones(n);
  }
  
  //output
  for(int i = 0; i < T; i++){
    if(winner[i] == 1)printf("First\n");
    else if(winner[i] == 2)printf("Second\n");
  }
  return 0;
}

//receives the number of stones on the board
//returns the winner (1 or 2)
int takeStones(int n){
  int attempt;
  n = n%7; //answers are pariodic. Whith period = 7
  if(n >= 5){
    attempt = takeStones(n - 5);
    if(attempt == 2) return 1;
  }
  if(n >= 3){
    attempt = takeStones(n - 3);
    if(attempt == 2) return 1;
  }
  if(n >= 2){
    attempt = takeStones(n - 2);
    if(attempt == 2) return 1;
  }
  if(n < 2) return 2;
  return 2;
}
