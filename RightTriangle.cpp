/*!
@file	RightTriangle.cpp
@brief	Implementation file for class RightTriangle
*/

#include "RightTriangle.h"

///////////////////////////////////////////////////////////////////////////
// Constructors - Destructor


RightTriangle::RightTriangle()
{
	cout << "START:\tRightTriangle - constructor - default" << endl;
	Init();
	cout << "END:\tRightTriangle - constructor - default" << endl;

}

RightTriangle::RightTriangle( const RightTriangle & t)
{
	cout << "START:\tRightTriangle - constructor - copy" << endl;
	Init(t);
	cout << "END:\tRightTriangle - constructor - copy" << endl;
}

RightTriangle::~RightTriangle()
{
	cout << "START:\tRightTriangle - destructor" << endl;
	Reset();
	cout << "END:\tRightTriangle - destructor" << endl;
}

///////////////////////////////////////////////////////////////////////////
// Operators

/// @name Assignment operator
/// @param &r reference to the RightTriangle to assign
/// @return reference to the RightTriangle assigned (for concatenating)
RightTriangle& RightTriangle::operator=( const RightTriangle & t)
{
	Reset();
	Init(t);
	return *this;
}

/// @name Comparison operator
/// @param &t reference to the object to check for comparison
/// @return boolean: true if the two objects coincide, false if not
bool RightTriangle::operator==( const RightTriangle & t)
{
	return false;
}


/// @name Insertion operator
/// @param &o reference to the stream where to insert
/// @param &r reference to the object to insert
ostream & operator << (ostream &o, RightTriangle & r)
{
	return o;
}

/// @name Extraction operator
/// @param &i reference to the stream where to extract from
/// @param &t reference to the RightTriangle to extract
istream & operator >> (istream &i, RightTriangle & t)
{
	return i;
}



///////////////////////////////////////////////////////////////////////////
// Basic handling

void RightTriangle::Init()
{
	cout << "START:\tRightTriangle - Init - Default" << endl;
	Reset();
	cout << "END:\tRightTriangle - Init - Default" << endl;
}

/// @param &t reference to the RightTriangle to be cloned
void RightTriangle::Init(const RightTriangle &r)
{
	cout << "START:\tRightTriangle - Init - copy" << endl;
	Reset();
	base = r.base;
	altitude = r.altitude;
	cout << "END:\tRightTriangle - Init - copy" << endl;
}

void RightTriangle::Reset()
{
	cout << "START:\tRightTriangle - Reset" << endl;
	base = altitude = 0.;
	cout << "END:\tRightTriangle - Reset" << endl;
}

///////////////////////////////////////////////////////////////////////////
// Interface to parent class.

float RightTriangle::Area()
{
	return (float) (base * altitude) / 2;
}


float RightTriangle::Perimeter()
{
	return (float) base + altitude + GetHypotenuse();
}

///////////////////////////////////////////////////////////////////////////
// Access functions


// Getters

/// @brief Computes and returns the hypotenuse of the right triangle.
/// @return The hypotenuse, computed using the pythagorean theorem.
float RightTriangle::GetHypotenuse()
{
	// Pythagorean theorem.
	return (float) sqrt( (base * base) + (altitude * altitude) ) ;
}

/// @brief Returns the base of the right triangle.
/// @return The base of the right triangle.
float RightTriangle::GetBase()
{
	return base;
}

/// @brief Returns the altitude of the right triangle.
/// @return The altitude of the right triangle.
float RightTriangle::GetAltitude()
{
	return altitude;
}

/// @brief Lets you access base and altitude at the same time
/// @param Two referenced floats, in which will be put the values of base and altitude respectively.
void RightTriangle::GetCathetes( float & b, float & a )
{
	b = base;
	a = altitude;
}


// Setters

/// @brief Lets you set the base of the right triangle
/// @param The float value you want to set the base to.
void RightTriangle::SetBase(float b)
{
	base = b;
}

/// @brief Lets you set the altitude of the right triangle
/// @param The float value you want to set the altitude to.
void RightTriangle::SetAltitude(float a)
{
	altitude = a;
}


///////////////////////////////////////////////////////////////////////////
// Drawing

/// @brief Draws the right triangle.
/// For now it just calls the Dump.
void RightTriangle::Draw()
{
	Dump();
}

///////////////////////////////////////////////////////////////////////////
// Debug and serialization

/// @brief Write an error message.
/// @param string message to be printed.
void RightTriangle::ErrorMessage( const char *string )
{
	cout << endl << "ERROR -- RightTriangle --";
	cout << string << endl;
}

/// @brief Write a warning message.
/// @param string message to be printed.
void RightTriangle::WarningMessage(const char *string)
{
	cout << endl << "WARNING -- RightTriangle --";
	cout << string << endl;
}

/// @brief For debugging: print all about the RightTriangle.
void RightTriangle::Dump()
{
	cout << "START:\tRightTriangle -- Dump" << endl;
	cout << "Base: " << base << endl;
	cout << "Altitude: " << altitude << endl;
	cout << "END:\tRightTriangle -- Dump" << endl;
}