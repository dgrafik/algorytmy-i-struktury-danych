#include <iostream>
#include <fstream>
#define n 256

void calcASCII(const std::string & fileName, int tab[]){
  char c;
  std::ifstream file;

  file.open(fileName);
  while(!file.eof() ){
    file.get(c);
    tab[c]++;
  }
  file.close();
}

int main(){
  int ascii_tab[n] = {};
  calcASCII("zadanie9_sample.txt", ascii_tab);
  for(int i=0; i<n; ++i){
    if(ascii_tab[i] != 0)
      std::cout << "Znak: " << (char)i << " ilość wystąpień: " << ascii_tab[i] << std::endl;
  }
}
