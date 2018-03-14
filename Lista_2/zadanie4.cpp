#include <iostream>

void move(int *tab, int n, int k){
  int tmp;
  if(k>=n){
    k = k%n;
  }
  for(int i=0; i<k; i++){
    tmp = *(tab+n-1);
    for(int j=n-1; j>0; j--){
      *(tab+j) = *(tab+j-1);
    }
    *tab = tmp;
  }
}

int main(){
  int tab[4] = {1,2,3,4};
  int len = sizeof(tab)/sizeof(*tab);

  for(int i=0; i<len; ++i){
    std::cout << tab[i];
  }
  std::cout << std::endl;

  move(tab, len, 2);

  for(int i=0; i<len; ++i){
    std::cout << tab[i];
  }

  return 0;
}
