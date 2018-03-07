#include <iostream>

class ulamek{
  private:
    int licznik;
    int mianownik;

  public:
    ulamek(int _licznik, int _mianownik=1)
    {
      licznik = _licznik;
      mianownik = _mianownik;
    }

    ulamek operator+(ulamek& u){
      return ulamek(licznik * u.mianownik + u.licznik*mianownik, mianownik*u.mianownik);
    }

    ulamek operator- (ulamek& u)
    {
        return ulamek(licznik*u.mianownik-u.licznik*mianownik, mianownik*u.mianownik);
    }
    ulamek operator* (ulamek& u)
    {
        return ulamek(licznik*u.licznik, mianownik*u.mianownik);
    }
    ulamek operator/ (ulamek& u)
    {
        return ulamek(licznik*u.mianownik, u.licznik*mianownik);
    }
    friend std::ostream &operator<<(std::ostream &op, const ulamek& u)
    {
        if (u.licznik == u.mianownik) return op << 1;
        return op << u.licznik << "/" << u.mianownik;
    }
};

int main()
{
    ulamek Ulamek(1,5);
    ulamek Ulamek2(2,33);
    std::cout << Ulamek << std::endl;
    std::cout << Ulamek+Ulamek2 << std::endl;

    return 0;
}
