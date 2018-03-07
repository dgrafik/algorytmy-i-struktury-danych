#include <iostream>
#include <math.h>

struct Result{
    int minimum;
    int maximum;
};

Result maxmin(int tab[], int len){
    Result result;
    int i = len % 2 == 0 ? 2 : 1;
    if (i == 2){
        if (tab[0]<tab[1]){
          result.minimum = tab[0];
          result.maximum = tab[1];

        }
        else{
          result.minimum = tab[1];
          result.maximum = tab[0];
        }
    }
    else{
        result.minimum = tab[0];
        result.maximum = tab[0];
    }

    for(int j = i; j < len-1; j+=2){
        if (tab[j] > tab[j+1]){
            if(tab[j] > result.maximum) {result.maximum = tab[j];}
            if(tab[j+1] < result.minimum) {result.minimum = tab[j+1];}
        }
        else
        {
            if (tab[j+1] > result.maximum) {result.maximum = tab[j+1];}
            if (tab[j] < result.minimum) {result.minimum = tab[j];}
        }
    }
    return result;
}

int main()
{
    int t[] = {72,9,1,2454,221,0};
    Result s = maxmin(t, 6);
    std::cout << "min " << s.minimum << std::endl;
    std::cout << "max " << s.maximum << std::endl;

    int t1[] = {72,9,1,2454,221};
    Result s1 = maxmin(t1, 5);
    std::cout << "min " << s1.minimum << std::endl;
    std::cout << "max " << s1.maximum << std::endl;

    return 0;
}
