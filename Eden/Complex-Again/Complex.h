#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;
class Complex {
  friend ostream& operator <<(ostream&, const Complex&);
 
 public:
  Complex(double = 0, double = 0);
  Complex(const Complex& otherComplex);
 
  Complex& operator = (const Complex& otherComplex);
  Complex& operator += (const Complex& otherComplex);
  Complex& operator -= (const Complex& otherComplex);
  Complex& operator *= (const Complex& otherComplex);
  Complex& operator /= (const Complex& otherComplex);
 
  Complex operator +(const Complex&);
  Complex operator -(const Complex&);
  Complex operator *(const Complex&);
  Complex operator /(const Complex&);
 
  bool operator == (const Complex& otherComplex);
  bool operator != (const Complex& otherComplex);
 
  void SetReal(double re) {
    real = re;
  }
  void SetImag(double im) {
    imag = im;
  }
 
 private:
  double real;
  double imag;
};
#endif
