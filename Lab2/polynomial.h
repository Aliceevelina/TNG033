/*************************
* Class Polynomial       *
* TNG033: Lab 2          *
**************************/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

#include "expression.h"


class Polynomial : public Expression
{

public:

	Polynomial(); // Default constructor
	Polynomial(int deg, const double c[]); //Constructor that creates a polynomial from an array with doubles 
	Polynomial(double x);//Conversion constructor 
	Polynomial(const Polynomial& p); //Copy constructor
	virtual ~Polynomial(); //Destructor
	Polynomial& operator=(Polynomial p);//Assignment operator 
	Polynomial operator+(const Polynomial& q) const;//Addition operator, of two polynomials p+q
	Polynomial operator+(double x); //Addition operator, adds a constant x to the poly q (q+x)
	virtual double operator()(double d) const override;
	const double& operator[](int x) const;
	double& operator[](int x);
    virtual Polynomial* clone() const override;

protected:

	virtual void display(std::ostream& os) const override;
    int degree;
	double *coeff;

};

Polynomial operator+(double x, const Polynomial& q);//Addition operator, adds a constant x to the poly q (x+q)


#endif



