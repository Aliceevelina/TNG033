/*********************************************************
* Class Expression member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "expression.h"
#include <cmath> //fabs-absolute value for floating type numbers


bool Expression::isRoot(double x) const // Test if x is a root of f. *this is the expression, x is the value. Compares if it´s smaller than Epsilon (can´t compare with 0)
{
	return(fabs((*this)(x)) < EPSILON); 
}

std::ostream& operator<<(std::ostream& os, const Expression& b) {
	
	b.display(os); //Calling the function display in Expression depending on if it´s a polynomial or logarithm 
	return os;
}
