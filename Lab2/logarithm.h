/*************************
* Class Logarithm        *
* TNG033: Lab 2          *
**************************/


#ifndef LOGARITHM_H
#define LOGARITHM_H

#include <iostream>

#include "expression.h"

//FUNCTION OVERRIDING: A redefinition of base class function in its derived class. Same return type and parameters.
//Likea creating a new version of the function in the base class to the derived class

class Logarithm : public Expression
{
public:
	Logarithm(); //Default constructor
	Logarithm(const Expression& E, double a1,  double a2,  int d); //Constructor that creates a logarithmic expression 
	Logarithm(const Logarithm& l); //Copy constructor
	virtual ~Logarithm(); //Default destructor
	virtual double operator()(double d) const override; //Calculation function, returns the sum of the expression when x is d 
	virtual Logarithm* clone() const override; //Clone function
	Logarithm& operator=(Logarithm p); //Assignment operator
	
protected:

	void display(std::ostream& os) const override;
	double c1, c2;
	int b;
	Expression* E;
};

#endif
