#include <iostream>
#include "Complex.h"
using namespace std;
Complex::Complex(double real, double imag) {
  this->real = real;
  this->imag = imag;
}
 
Complex::Complex(const Complex& otherComplex) {
  real = otherComplex.real;
  imag = otherComplex.imag;
}
 
ostream& operator <<(ostream& out, const Complex& c) {
  out << c.real << "+" << c.imag << "i";
  return out;
}
 
Complex Complex:: operator +(const Complex& c) {
  double tmpreal = real + c.real;
  double tmpimag = imag + c.imag;
 
  Complex tmp(tmpreal, tmpimag);
 
  return tmp;
}
 
Complex Complex:: operator -(const Complex& c) {
  double tmpreal = real - c.real;
  double tmpimag = imag - c.imag;
 
  Complex tmp(tmpreal, tmpimag);
 
  return tmp;
}
 
Complex Complex:: operator *(const Complex& c) {
  double tmpreal = real * c.real - imag * c.imag;
  double tmpimag = imag * c.real + real * c.imag;
 
  Complex tmp(tmpreal, tmpimag);
 
  return tmp;
}
 
Complex Complex:: operator /(const Complex& c) {
  double t = c.real * c.real + c.imag * c.imag;
  double tmpreal = (real * c.real + imag * c.imag) / t;
  double tmpimag = (imag * c.real - real * c.imag) / t;
 
  Complex tmp(tmpreal, tmpimag);
 
  return tmp;
}
 
Complex& Complex:: operator = (const Complex& otherComplex) {
  real = otherComplex.real;
  imag = otherComplex.imag;
  return *this;
}
 
Complex& Complex:: operator += (const Complex& otherComplex) {
  *this = *this + otherComplex;
  return *this;
}
 
Complex& Complex:: operator -= (const Complex& otherComplex) {
  *this = *this - otherComplex;
  return *this;
}
 
Complex& Complex:: operator *= (const Complex& otherComplex) {
  *this = *this * otherComplex;
  return *this;
}
 
// a / b, b != 0
Complex& Complex:: operator /= (const Complex& otherComplex) {
  *this = *this / otherComplex;
  return *this;
}
 
bool Complex:: operator == (const Complex& otherComplex) {
  if (real == otherComplex.real && imag == otherComplex.imag)
    return true;
  else
    return false;
}
 
bool Complex:: operator != (const Complex& otherComplex) {
  return !(*this == otherComplex);
}
