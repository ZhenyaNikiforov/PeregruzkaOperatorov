#include <iostream>
#include <Windows.h>
using namespace std;

class Fraction
{
public:
  Fraction(int numer, int denom) //- Конструктор экземпляра Fraction;
  {
    int num = numer;
    int den = denom;

    while (den != 0) //- Находим наибольший общий делитель;
    {
      int temp = den;
      den = num % den;
      num = temp;
    };

    if (num < 0) //- Проверяем, что наиб. общ. делитель положительный;
    {
      num *= -1;
    };

    this->numerator = numer / num; //- Загружаем в поля класса сокращённую дробь;
    this->denominator = denom / num;
  };

  Fraction operator+(Fraction &other)
  {
    int unionNumerator = (this->numerator * other.denominator) + (other.numerator * this->denominator);
    int unionDenominator = this->denominator * other.denominator;

    return Fraction(unionNumerator, unionDenominator);
  };

  Fraction operator-(Fraction &other)
  {
    int unionNumerator = (this->numerator * other.denominator) - (other.numerator * this->denominator);
    int unionDenominator = this->denominator * other.denominator;

    return Fraction(unionNumerator, unionDenominator);
  };

  Fraction operator*(Fraction &other)
  {
    int unionNumerator = this->numerator * other.numerator;
    int unionDenominator = this->denominator * other.denominator;

    return Fraction(unionNumerator, unionDenominator);
  };

  Fraction operator/(Fraction &other)
  {
    int unionNumerator = this->numerator * other.denominator;
    int unionDenominator = this->denominator * other.numerator;

    return Fraction(unionNumerator, unionDenominator);
  };

  Fraction &operator++()
  {
    this->numerator = this->numerator + this->denominator;
    return *this;
  };

  Fraction operator--(int)
  {
    Fraction temp = *this;
    this->numerator = this->numerator - this->denominator;
    return temp;
  };

  void fractionShow()
  {
    cout << this->numerator << "/" << this->denominator;
  };

private:
  int numerator;
  int denominator;
};

int main()
{
  SetConsoleOutputCP(CP_UTF8);

  int numerator_1 = 1;
  int denominator_1 = 1;
  int numerator_2 = 1;
  int denominator_2 = 1;

  cout << "Введите числитель дроби 1: ";
  cin >> numerator_1;
  cout << "Введите знаменатель дроби 1: ";
  cin >> denominator_1;
  cout << "Введите числитель дроби 2: ";
  cin >> numerator_2;
  cout << "Введите знаменатель дроби 2: ";
  cin >> denominator_2;

  Fraction fraction_1(numerator_1, denominator_1); //-Первая дробь;
  Fraction fraction_2(numerator_2, denominator_2); //-Вторая дробь;

  Fraction fractionPlus = fraction_1 + fraction_2; //-Перегрузка сложения;
  Fraction fractionSub = fraction_1 - fraction_2;  //-Перегрузка вычитания;
  Fraction fractionMul = fraction_1 * fraction_2;  //-Перегрузка умножения;
  Fraction fractionDiv = fraction_1 / fraction_2;  //-Перегрузка деления;

  fraction_1.fractionShow();
  cout << " + ";
  fraction_2.fractionShow();
  cout << " = ";
  fractionPlus.fractionShow(); //-Показываем сложение;
  cout << endl;

  fraction_1.fractionShow();
  cout << " - ";
  fraction_2.fractionShow();
  cout << " = ";
  fractionSub.fractionShow(); //-Показываем вычитание;
  cout << endl;

  fraction_1.fractionShow();
  cout << " * ";
  fraction_2.fractionShow();
  cout << " = ";
  fractionMul.fractionShow(); //-Показываем умножение;
  cout << endl;

  fraction_1.fractionShow();
  cout << " / ";
  fraction_2.fractionShow();
  cout << " = ";
  fractionDiv.fractionShow(); //-Показываем деление;
  cout << endl;

  cout << "++";
  fraction_1.fractionShow();
  cout << " * ";
  fraction_2.fractionShow();
  cout << " = ";
  Fraction fractionPrefIncMul = ((++fraction_1) * (fraction_2));
  fractionPrefIncMul.fractionShow();
  cout << endl;

  cout << "Значение дроби 1 = ";
  fraction_1.fractionShow();
  cout << endl;

  fraction_1.fractionShow();
  cout << "-- * ";
  fraction_2.fractionShow();
  cout << " = ";
  Fraction fractionPostDecMul = (fraction_1-- * fraction_2);
  fractionPostDecMul.fractionShow();
  cout << endl;

  cout << "Значение дроби 1 = ";
  fraction_1.fractionShow();
  cout << endl;

  return 0;
};