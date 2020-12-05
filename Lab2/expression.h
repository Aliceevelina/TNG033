/*************************
* Class Expression       *
* TNG033: Lab 2          *
**************************/

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream> //std::cout, std::fixed
#include <iomanip> // std::setprecision

const double EPSILON = 1.0e-5;

// VIRTUAL FUNCTIONS: It is used to tell the compiler to use dynamic linkage or late binding, compiler determines the type of object during
// run time and then binds the function call

class Expression
{

public:
	Expression() = default; //Default constructor
	virtual  ~Expression() = default; //Default destructor
	bool isRoot(double x) const; //Is x a root of the function f? 
    virtual double operator()(double d) const = 0; //Evaluates the function for a variable x as d
    virtual Expression* clone() const = 0; // 
	Expression& operator=(const Expression& p) = delete; //Assignment operator

protected:

	friend std::ostream& operator<<(std::ostream& os, const Expression& b); //Displays an expression. 
	virtual void display(std::ostream& os) const = 0;//which function to call is decided during execution time
};


#endif



/*************************
* THEORY QUESTIONS       *
**************************/
//1) Investigate the reason(s) for having the member function clone. If the idea is to make copies of object that are instances of class Expression
    //then aren´t the copy constructor in each of the derives classes of Expression enough?

//Constructors cannot be virtual functions, soloution is to add a virtual member function (clone()) to do the copying.



//2)
/*double v1[4] = { 2.2 4.4 2.0 5.0 };
const Polynomial pp{ 3, v1 }; 
Should comiple : pp = 2.2 + 4.4 * X + 2.0 * X ^ 2 + 5.0 * X ^ 3 (Visst ? )

pp[2] = 3.3; //Ändrar värdet i slot 2 till 3.3
Should compile: 2.2 + 4.4 * X + 3.3 * X ^ 2 + 5.0 * X ^ 3 (Visst ? )*/