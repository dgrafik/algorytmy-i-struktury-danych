#include <iostream>
#define n 100

bool numbersTable[n + 1];

int main()
{
		for(int i = 0; i<n+1; i++){
			numbersTable[i] = true;
		}
    for (int i = 2; i*i <= n; ++i )
    {
        if (numbersTable[i] == false)
            continue;
        for (int j = 2*i ; j <= n; j += i)
            numbersTable[j] = false;
    }

    for (int i = 2; i <= n; i++)
        if (numbersTable[i] == true)
            std::cout << i << std::endl;
    return 0;
}
