/*********************************************************
* Class Logarithm member functions implementation        *
* TNG033: Lab 2                                          *
**********************************************************/

#include "logarithm.h"
#include "polynomial.h"
#include <cmath>
#include <iomanip>

//Default constructor should make the exp: log_2x
Logarithm::Logarithm() : Expression() {
	
	c1 = 0.0;
	c2 = 1.0;
	b = 2;
	
	double coeff[2] = { 0, 1 };
	E = new Polynomial(1, coeff);
}

//Constructor
Logarithm::Logarithm(const Expression& E1,  double a1,  double a2,  int d) : Expression() {

	c1=a1; c2=a2; b=d;
	E = E1.clone();

}

//Copy Constructor
Logarithm::Logarithm(const Logarithm& l) {
	E = l.E->clone();
	c1 = l.c1;
	c2 = l.c2;
	b = l.b;
}

//Destructor
Logarithm::~Logarithm() {
	c1 = 0.0;
	c2 = 0.0;
	b = 0;
	delete E;
	E = nullptr;
}

void Logarithm::display(std::ostream& os) const {

	if (c1 == 0) 
		os << c2 << " *log_" << b << "(" << *E << ")";
	
	else
		os <<c1<< " + "<< c2 << " *log_" << b << "(" << *E << ")";

}

Logarithm* Logarithm::clone() const {
	return new Logarithm (*this);
}

double Logarithm::operator()(double d) const {

	double sum = 0;
	sum = c1 + c2 * (log((*E)(d)) / log(b)); //Hitta denna formel: change of base formula: log_b(x) = log_d(x) / log_d(b)
	return sum;
}

Logarithm& Logarithm::operator=(Logarithm p) {

	std::swap(c1, p.c1);
	std::swap(c2, p.c2);
	std::swap(b, p.b);
	std::swap(E, p.E);
	return *this;
}

