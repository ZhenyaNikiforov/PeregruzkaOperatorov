#include <iostream>
//-Задание, которое было дано:
class Fraction
{
private:
  int numerator_;
  int denominator_;

public:
  Fraction(int numerator, int denominator)
  {
    this->numerator_ = numerator;
    this->denominator_ = denominator;
  }
  //- Пошла моя отсебятина...
  int mul(int a, int b) //-Функция вычисления числителей;
  {
    return a * b;
  };

  bool operator==(Fraction &nextFraction) //-Перегрузка оператора сравнения;
  {
    return (mul(this->numerator_, nextFraction.denominator_) == mul(nextFraction.numerator_, this->denominator_));
  };

  bool operator!=(Fraction &nextFraction) //-Перегрузка оператора неравенства;
  {
    return (mul(this->numerator_, nextFraction.denominator_) != mul(nextFraction.numerator_, this->denominator_));
  };

  bool operator<(Fraction &nextFraction) //-Перегрузка оператора меньше;
  {
    return (mul(this->numerator_, nextFraction.denominator_) < mul(nextFraction.numerator_, this->denominator_));
  };

  bool operator>(Fraction &nextFraction) //-Перегрузка оператора больше;
  {
    return (mul(this->numerator_, nextFraction.denominator_) > mul(nextFraction.numerator_, this->denominator_));
  };

  bool operator<=(Fraction &nextFraction) //-Перегрузка оператора меньше или равно;
  {
    return (mul(this->numerator_, nextFraction.denominator_) <= mul(nextFraction.numerator_, this->denominator_));
  };

  bool operator>=(Fraction &nextFraction) //-Перегрузка оператора больше или равно;
  {
    return (mul(this->numerator_, nextFraction.denominator_) >= mul(nextFraction.numerator_, this->denominator_));
  };
};

int main()
{
  Fraction f1(4, 3);
  Fraction f2(6, 11);

  std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
  std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
  std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
  std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
  std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
  std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
  return 0;
}