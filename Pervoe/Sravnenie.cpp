#include <iostream>
//-Задание, которое было дано:
class Fraction
{
private:
  int numerator;
  int denominator;

public:
  Fraction(int numerator, int denominator)
  {
    this->numerator = numerator;
    this->denominator = denominator;
  }

  bool operator==(const Fraction &nextFraction) //-Перегрузка оператора сравнения;
  {
    return (this->numerator * nextFraction.denominator) == (nextFraction.numerator * this->denominator);
  };

  bool operator>(const Fraction &nextFraction) //-Перегрузка оператора больше;
  {
    return (this->numerator * nextFraction.denominator) > (nextFraction.numerator * this->denominator);
  };
};

int main()
{
  Fraction f1(4, 3);
  Fraction f2(6, 11);

  std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
  std::cout << "f1" << ((!(f1 == f2)) ? " != " : " not != ") << "f2" << '\n';
  std::cout << "f1" << ((!(f1 > f2) && !(f1 == f2)) ? " < " : " not < ") << "f2" << '\n';
  std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
  std::cout << "f1" << ((!(f1 > f2) || (f1 == f2)) ? " <= " : " not <= ") << "f2" << '\n';
  std::cout << "f1" << (((f1 > f2) || (f1 == f2)) ? " >= " : " not >= ") << "f2" << '\n';
  return 0;
}