/*!
@file	RightTriangle.cpp
@brief	Implementation file for class RightTriangle
*/

#include "RightTriangle.h"

///////////////////////////////////////////////////////////////////////////
// Constructors - Destructor


// Default constructor
RightTriangle::RightTriangle()
{
	cout << "RightTriangle -- Default Constructor" << endl;
	Init();
}

// Copy constructor
RightTriangle::RightTriangle( const RightTriangle & t)
{
	cout << "RightTriangle -- Copy Constructor" << endl;
	Init(t);
}

// Init constructor
RightTriangle::RightTriangle( float b, float a )
{
	cout << "RightTriangle -- Init Constructor" << endl;

	if (b < 0. || a < 0.)
	{
		ErrorMessage("Value not valid.");
		Init();
	}
	else
	{
		base = b;
		altitude = a;
	}
}

// Destructor
RightTriangle::~RightTriangle()
{
	cout << "RightTriangle -- Destructor" << endl;
	Reset();
}

///////////////////////////////////////////////////////////////////////////
// Operators

/// @name Assignment operator
/// @param &r reference to the RightTriangle to assign
/// @return reference to the RightTriangle assigned (for concatenating)
RightTriangle& RightTriangle::operator=( const RightTriangle & r)
{
	Reset();
	Init(r);
	return *this;
}

/// @name Comparison operator
/// @param &r reference to the triangle to check for comparison
/// @return boolean: true if the two right triangles have the same cathetes, false if not.
bool RightTriangle::operator==( const RightTriangle & r)
{
    return (( r.base == base && r.altitude == altitude ) ? true : false);
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
	cout << "RightTriangle -- Default Init handler" << endl;

	Reset();
}

/// @param &t reference to the RightTriangle to be cloned
void RightTriangle::Init(const RightTriangle &r)
{
	cout << "RightTriangle -- Copy Init handler" << endl;

	Reset();

	// No need for a guard:
	// All r object descriptors must have been checked when set.
	base = r.base;
	altitude = r.altitude;
}

void RightTriangle::Reset()
{
	cout << "RightTriangle -- Reset handler" << endl;

	base = altitude = 0.;
}

///////////////////////////////////////////////////////////////////////////
// Interface to parent class.

/// @brief Computes and returns the area of the right triangle.
/// @return The computed area of the right triangle.
float RightTriangle::Area()
{
	return (float) (base * altitude) / 2;
}


/// @brief Computes and returns the perimeter of the right triangle.
/// @return The computed perimeter of the right triangle.
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
	if (b < 0) { ErrorMessage("Value not valid."); return; }
	base = b;
}

/// @brief Lets you set the altitude of the right triangle
/// @param The float value you want to set the altitude to.
void RightTriangle::SetAltitude(float a)
{
	if (a < 0) { ErrorMessage("Value not valid."); return; }
	altitude = a;
}

/// @brief Lets you set both base and altitude of the right triangle
/// @param b float to set the base to
/// @param a float to set the altitude to
void RightTriangle::SetCathetes(float b, float a)
{
	if (b < 0 || a < 0) { ErrorMessage("Value not valid."); return; }
	SetBase(b);
	SetAltitude(a);
}


///////////////////////////////////////////////////////////////////////////
// Drawing

/// @brief Draws the right triangle.
/// For now it just calls the Dump.
void RightTriangle::Draw()
{
	cout << "RightTriangle -- Draw" << endl;

	cout << "Base:\t\t" << base  << endl;
	cout << "Altitude:\t" << altitude  << endl;
	cout << "Area:\t\t" << GetArea()  << endl;
	cout << "Perimeter:\t" << GetPerimeter()  << endl;
}

///////////////////////////////////////////////////////////////////////////
// Debug and serialization

/// @brief Write an error message.
/// @param string message to be printed.
void RightTriangle::ErrorMessage( const char *string )
{
	cout << endl << "ERROR -- RightTriangle --\t";
	cout << string << endl << endl;
}

/// @brief Write a warning message.
/// @param string message to be printed.
void RightTriangle::WarningMessage(const char *string)
{
	cout << endl << "WARNING -- RightTriangle --\t";
	cout << string << endl << endl;
}

/// @brief For debugging: print all about the RightTriangle.
void RightTriangle::Dump()
{
	cout << endl;

	cout << "RightTriangle -- Dump" << endl;

	cout << "Base\t\t" << base << endl;
	cout << "Altitude\t" << altitude << endl;

	Polygon::Dump();

	cout << endl << flush;
}
