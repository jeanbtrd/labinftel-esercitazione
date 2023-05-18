/*!
	@file	rhombus.cpp
	@brief	Implementation file for class Rhombus
*/

#include "rhombus.h"


///////////////////////////////////////////////////////////////////////////
// Constructors - Destructor


Rhombus::Rhombus()
{
	cout << "Rhombus -- Default Constructor" << endl;
	Init();
}

Rhombus::Rhombus( const Rhombus & r)
{
	cout << "Rhombus -- Copy Constructor" << endl;
	Init(r);
}


Rhombus::Rhombus(float dH, float dV)
{
	cout << "Rhombus -- Init Constructor" << endl;

	Reset();

	if (dH <= 0) cout << "WARNING: Rhombus - constructor: horizontal diagonal should be > 0" << endl;
	else diagH = dH;

	if (dV <= 0) cout << "WARNING: Rhombus - constructor: vertical diagonal should be > 0" << endl;
	else diagV = dV;
}


Rhombus::~Rhombus()
{
	cout << "Rhombus -- Destructor" << endl;
	Reset();
}


///////////////////////////////////////////////////////////////////////////
// Operators

/// @name Assignment operator
/// @param &r reference to the rhombus to assign
/// @return reference to the rhombus assigned (for concatenating)
Rhombus & Rhombus::operator=( const Rhombus & r)
{
	Reset();
	Init(r);
	return *this;
}

/// @name Comparison operator
/// @param &r reference to the rhombus to check for comparison
/// @return boolean: true if the two rhombi coincide, false if not
bool Rhombus::operator ==( const Rhombus & X)
{

	return true;
}


/// @name Insertion operator
/// @param o stream where to insert
/// @param r rhombus to insert
ostream & operator << (ostream &o, Rhombus & r)
{
	return o;
}

/// @name Extraction operator
/// @param o stream where to extract from
/// @param r rhombus to extract
istream & operator >> (istream &i, Rhombus & r)
{
	return i;
}


///////////////////////////////////////////////////////////////////////////
// Basic handling

void Rhombus::Init()
{
	Reset();
}

/// @param r rhombus to be cloned
void Rhombus::Init(const Rhombus &r)
{
	cout << "START:\tRhombus - Init - copy" << endl;

	Reset();

    diagH = r.diagH;
    diagV = r.diagV;

	cout << "END:\tRhombus - Init - copy" << endl;
}

void Rhombus::Reset()
{
	diagH = (float)0;
	diagV = (float)0;
}

///////////////////////////////////////////////////////////////////////////
// Interface to parent class.


/// @brief calculate and return the area of the rhombus
/// @return area of the rhombus
float Rhombus::Area()
{
	return (float)((diagH*diagV)/2);
}

/// @brief calculate and return the perimeter of the rhombus
/// @return perimeter of the rhombus
float Rhombus::Perimeter()
{
	return (float)4*(GetSide());
}


///////////////////////////////////////////////////////////////////////////
// Access functions


/// @brief get horizontal diagonal of the rhombus
/// @return horizontal diagonal of the rhombus
float Rhombus::GetDiagH()
{
	return diagH;
}

/// @brief get vertical diagonal of the rhombus
/// @return vertical diagonal of the rhombus
float Rhombus::GetDiagV()
{
	return diagV;
}

/// @brief get horizontal and vertical diagonals of the rhombus
/// @param dH horizontal diagonal
/// @param dV vertical diagonal
void Rhombus::GetDiagonals(float &dH, float &dV)
{
	dH=diagH;
	dV=diagV;
}


/// @brief get length of the side of the rhombus
/// @return length of the side of the rhombus
float Rhombus::GetSide()
{
	return (float)(sqrt(diagH*diagH+diagV*diagV)/2);
}


/// @brief set horizontal diagonal of the rhombus
/// @param dH horizontal diagonal
void Rhombus::SetDiagH(float dH)
{
	if (dH < 0)
	{
		cout << "WARNING: Rhombus - SetDiagH: horizontal diagonal should be > 0" << endl;
		return;
	}
	diagH = dH;
}

/// @brief set vertical diagonal of the rhombus
/// @param dV vertical diagonal
void Rhombus::SetDiagV(float dV)
{
	if (dV < 0)
	{
		cout << "WARNING: Rhombus - SetDiagH: horizontal diagonal should be > 0" << endl;
		return;
	}
	diagV = dV;
}


/// @brief set horizontal and vertical diagonals of the rhombus
/// @param dH horizontal diagonal
/// @param dV vertical diagonal
void Rhombus::SetDim(float dH, float dV)
{
	SetDiagH(dH);
	SetDiagV(dV);
}


///////////////////////////////////////////////////////////////////////////
// Drawing

/// @brief Draws the rectangle.
/// For now it just calls the Dump.
void Rhombus::Draw()
{
	cout << "Rhombus -- Draw" << endl;

	cout << "Horizontal diagonal:\t" << diagH  << endl;
	cout << "Vertical Diagonal:\t" << diagV  << endl;
	cout << "Area:\t\t\t" << GetArea()  << endl;
	cout << "Perimeter:\t\t" << GetPerimeter()  << endl;
}


///////////////////////////////////////////////////////////////////////////
// Debug and serialization


/// @brief Write an error message.
/// @param string message to be printed.
void Rhombus::ErrorMessage( const char *string )
{
	cout << endl << "ERROR -- Rhombus --";
	cout << string << endl;
}

/// @brief Write a warning message.
/// @param string message to be printed.
void Rhombus::WarningMessage(const char *string)
{
	cout << endl << "WARNING -- Rhombus --";
	cout << string << endl;
}

/// @brief For debugging: print all about the rhombus.
void Rhombus::Dump()
{
	cout << endl;

	cout << "Rhombus -- Dump" << endl;

	cout << "Horizontal diagonal:\t" << diagH << endl;
	cout << "Vertical diagonal:\t" << diagV << endl;

	Polygon::Dump();

	cout << endl << flush;
}
