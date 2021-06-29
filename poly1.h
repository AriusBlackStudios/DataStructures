
// Name: Lillibeth Hunter & Jade Ainsworth
// Class: CS 3305
// Term: Summer 2021
// Instructor: Dr. Haddad
// Assignment: 2

// FILE: poly1.h
// CLASS PROVIDED:
//   class polynomial
//     A polynomial has one variable x, real number coefficients, and
//     non-negative integer exponents. Such a polynomial can be viewed
//     as having the form:
//       A[n]*x^n + A[n-1]*x^(n-1) + ... A[2]*x^2 + A[1]*x + A[0]
//     where the A[n] are the real number coefficients and x^i represents
//     the variable x raised to the i power. The coefficient A[0] is
//     called the "constant" or "zeroth" term of the polynomial.
//
// NOTES:
//   This poly1.h version works by storing the coefficients in
//   a dynamic array, as described in Section 4.6 of
//   "Data Structures and Other Objects" (2nd edition) by
//   Michael Main and Walter Savitch
//
// CONSTRUCTORS and DESTRUCTOR for the polynomial class
//   polynomial( )
//     POSTCONDITION: This polynomial has been created with all zero
//     coefficients.
//
//   polynomial(double a0)
//     POSTCONDITION: This polynomial has been create with all zero
//     coefficients, except for coefficient c for the specified exponent.
//
//   polynomial(const polynomial& source)
//     POSTCONDITION: This polynomial has been created as a copy of the source.
//
//   ~polynomial( )
//     POSTCONDITION: This polynomial has been deleted from memeory.
//
// MODIFICATION MEMBER FUNCTIONS for the polynomial class
//   void add_to_coef(double amount, unsigned int k)
//     POSTCONDITION: Adds the given amount to the coefficient of the
//     specified exponent k.
//
//   void assign_coef(double coefficient, unsigned int k)
//     POSTCONDITION: Sets the coefficient for the specified exponent k.
//
//   void clear( )
//     POSTCONDITION: All coefficients of this polynomial are set to zero.
//
//   void reserve(size_t number)
//     POSTCONDITION: The size of the array for coefficients has been changed to
//     the requested number (but not less that the size needed to store the
//     current non-zero coefficients). In effect, this guarantees that member
//     functions will not need to allocate new memory for exponents through
//     at least number-1.
//
// MODIFICATION OPERATORS for the polynomial class
//   polynomial& operator =(const polynomial& source)
//     POSTCONDITION: This polynomial is exactly the same as the
//     parameter. The return value is a reference to this polynomial.
//
//   polynomial& operator =(double a0)
//     POSTCONDITION: This polynomial has been create with all zero
//     coefficients, except for coefficient c for the specified exponent.
//
// CONSTANT MEMBER FUNCTIONS for the polynomial class
//   double coefficient(unsigned int k) const
//     POSTCONDITION: Returns coefficient at specified exponent k.
//
//   unsigned int degree( ) const
//     POSTCONDITION: The function returns the value of the largest exponent
//     with a non-zero coefficient.
//     If all coefficients are zero, then the function returns zero.
//
//   unsigned int next_term(unsigned int k) const
//     POSTCONDITION: The function returns the exponent of the next term
//     with a non-zero coefficient after specified exponent k.
//
// EVALUATION MEMBER FUNCTIONS for the polynomial class
//   double eval(double x) const
//     POSTCONDITION: The return value is the value of this polynomial with the
//     given value for the variable x.
//
//   double operator( ) (double x) const
//     Same as the eval member function.
//
// NON-MEMBER BINARY OPERATORS for the polynomial Class
//   polynomial operator -(const polynomial& p1, const polynomial& p2)
//     POSTCONDITION: return-value is a polynomial with each coefficient
//     equal the difference of the coefficients of p1 & p2 for any given
//     exponent.
//
//   polynomial operator +(const polynomial& p1, const polynomial& p2)
//     POSTCONDITION: return-value is a polynomial with each coefficient
//     equal the sum of the coefficients of p1 & p2 for any given
//     exponent.
//
// DYNAMIC MEMORY usage by the polynomial class
//    If there is insufficient dynamic memory, the following functions throw a
//    bad_alloc exception:
//    the constructors, add_to_coef, assign_coef, reserve,
//    and any of the operators with a polynomial parameter.

//UNDERSTANDINGNOTES
//exponents are the indexes
//coefficients are values in array

#ifndef POLY1_H
#define POLY1_H
#include <cstdlib>  // Provides size_t type
#include <iostream> // Provides istream and ostream
#include <vector>
// If your compiler does not support namespaces, then please delete the
// following line and the set of brackets that follow.


class polynomial
{
public:
    // CONSTRUCTORS and DESTRUCTOR
    polynomial();
	polynomial(double a0);
    polynomial(const polynomial& source);
	/*{
	//polynomial p = new polynomial[source.capacity];
	data = new polynomial[source.capacity];
	capacity =  source.capacity;
	used = source.used;
	copy(source.data, source.data + used, data);
	}*/
	
    ~polynomial()
	{
		delete[]data;
	}

    // MODIFICATION MEMBER FUNCTIONS
    void add_to_coef(double amount, unsigned int k)
	{
		data.coefficient(k)+= amount;
	}
    void assign_coef(double coefficient, unsigned int k)
	{
		data[k]=coefficient;
	}
    void clear()
	{
		for(int i = 0; i < capacity; i++)
		{
			data[i] =0;
		}
	}
    void reserve(size_t number);
/*	{
		polynomial *larger_array;
		
		if(number == capacity)
			return;
		if(number < used)
			number = used;
			
		larger_array = new polynomial[number];
		std::copy(data, data+ used, larger_array);
		delete[]data;
		data = larger_array;
		capacity = number;
	}*/


    // MODIFICATION OPERATORS
	polynomial& operator=(const polynomial& source)
	{
		polynomial *new_data;
		
	/*	//check for self-assesment
		if (this== &source)
			return;
		*/
		//if the array is too big reset the array
		if(capacity != source.capacity)
		{
			new_data = new double[source.capacity];
			delete [ ] data;
			data = new_data;
			capacity = source.capacity;
		}
		used = source.used;
	}
    polynomial& operator=(double a0) // in line function
    {
        clear();
        assign_coef(a0, 0);
        return *this;
    }

    // CONSTANT MEMBER FUNCTIONS
    double coefficient(unsigned int k) const
	{
		double coefficient;
			coefficient = data[k];
		return coefficient;
	}
    unsigned int degree() const
	{
		//return the highest exponent
		//iterate from right to left finding the highest
		//??how to iterate from right to left??
		//start at the end (used)
		for(int i = used; i > 0; i--)
		{
			if(data[i] > 0)
			{
				//stop after finding one > 0 
				return i;
				break;
			}
		}
	}
    unsigned int next_term(unsigned int k) const;

    // EVALUATION MEMBER FUNCTIONS
    double eval(double x) const;
    double operator()(double x) const // in line function
    {
        return eval(x);
    }

private:
	double *data;
	size_t used;
	size_t capacity;
};

// NON-MEMBER BINARY OPERATORS
	polynomial operator+(const polynomial& p1, const polynomial& p2)
	{
		polynomial answer(p1.coefficient() + p2.coefficient());
		
		answer += p1;
		answer += p2;
		return answer;
	}
	polynomial operator-(const polynomial& p1, const polynomial& p2)
	{
		polynomial answer = p1 - p2;
		return answer;
	}

	std::ostream& operator<<(std::ostream& os, const polynomial& test)
	{
		return os;
	}
	
	polynomial::polynomial()
	{
		//initalize array
		//initialize capacity
		capacity = 5;
		used=0;
		data = new polynomial[capacity];
		//loop through and fill up with 0s
		for(int i = 0; i < capacity; i++)
		{
			data[i] =0;
		}
		
	}
	
	polynomial::polynomial(double a0)
	{
		capacity=5;
		used =1;
		data = new polynomial[capacity];
		
		data[0]=a0;
		for(int i = used; i < capacity; i++)
		{
			data[i]=0;
		}
	}
	
	polynomial::polynomial(const polynomial& source)
	{
		//double check whats happening
		data = new polynomial[source.capacity];
		capacity =  source.capacity;
		used = source.used;
		std::copy(source.data, source.data + used, data);
	}

#endif
