#include <iostream>
#include <math.h>

int iter(int a, int b){
   int result = 1;
   while (b > 0){
       if(b%2 == 0){
           a = a * a;
           b = b/2;
       }
       else{
           result = result * a;
           b --;
       }
   }
   return result;
}

int non_iter(int a, unsigned int b){
    if(b == 0){return 1;}
    if(b == 1){return a;}

  int d = non_iter(a, b / 2);
  if(b % 2 == 0){
    return d * d;
  }else{
    return a * d * d;
  }
}


int main()
{
    std::cout << iter(7,3) << std::endl;
    std::cout << non_iter(7,3) << std::endl;
    std::cout << pow(7,3) << std::endl;

}
