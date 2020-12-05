/*********************************************************
* Class Polynomial member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "polynomial.h"
#include <cmath>

//Default constructor
Polynomial::Polynomial()
{
	degree = 0;
	coeff = new double[degree + 1];
}

//Constructor that creates a polynomial from an array with doubles 
Polynomial::Polynomial(int deg, const double c[]) : Expression()
{
	degree = deg + 1;
	coeff = new double[degree];
	for (int i = 0; i < degree; i++) {
		coeff[i] = c[i];
	}
}

//Conversion constructor 
Polynomial::Polynomial(double x) : Expression()
{
	degree = 0;
	coeff = new double(x);
	/*degree = 1;
	coeff = new double[degree];
	coeff[0] = x;*/
}

//Copy constructor
Polynomial::Polynomial(const Polynomial& p) : Polynomial(p.degree - 1, p.coeff){  //varför är detta sättet mer "preferred" än att lägga i funktionen?
}

//Destructor
Polynomial::~Polynomial(){
	delete[] coeff;
	coeff = nullptr;
	degree = 0;
}

Polynomial* Polynomial::clone() const {
	return new Polynomial(*this);
}
 
void Polynomial::display(std::ostream& os) const {

	for (int i = 0; i < degree; i++) {

		if (abs(coeff[i]) > EPSILON) { //Not display coefficents that are equal to 0

			if (i == 0) os << std::fixed << std::setprecision(2) << coeff[i];
		   
			else os << std::fixed << std::setprecision(2) << " + " << coeff[i] << " * X^" << i;
		}

	}
}


Polynomial& Polynomial::operator=(Polynomial p) {

	std::swap(degree, p.degree);
	std::swap(coeff, p.coeff);
	
	return *this;
}

//Returns the value of a polynomial´s coefficient in slot x
double Polynomial::operator[](int x) const { 

	return coeff[x];
}

double& Polynomial::operator[](int x) {

	return coeff[x];
}

//returns the sum of the poly when x is d
double Polynomial::operator()(double d) const {

	double sum = 0;
	for (int i = 0; i < degree; i++) {
		sum += coeff[i] * pow(d, i);
	}
	return sum;
}

//*this+q
Polynomial Polynomial::operator+(const Polynomial&q) const { 
														
	Polynomial p = *this;

	for (int i = 0; i < q.degree; i++) {
	 p.coeff[i] += q.coeff[i];
	}

	return p;
}

//x+q
Polynomial operator+(double x, const Polynomial& q) { 

	Polynomial polly(q);
	polly[0] += x;

	return polly;
}

//*this+x
Polynomial Polynomial::operator+(double x) {
	
	coeff[0] += x;

	return *this;
}
