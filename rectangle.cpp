/*!
@file	rectangle.cpp
@brief	Implementation file for class Rectangle
*/

#include "rectangle.h"

///////////////////////////////////////////////////////////////////////////
// Constructors - Destructor


Rectangle::Rectangle()
{
	cout << "START:\tRectangle - constructor - default" << endl;
	Init();
	cout << "END:\tRectangle - constructor - default" << endl;

}

Rectangle::Rectangle( const Rectangle & r)
{
	cout << "START:\tRectangle - constructor - copy" << endl;
	Init(r);
	cout << "END:\tRectangle - constructor - copy" << endl;
}


Rectangle::Rectangle(float w, float l)
{
	cout << "START:\tRectangle - constructor - init" << endl;
	Reset();

	if (w <= 0) cout << "WARNING: Rectangle - constructor: width should be > 0" << endl;
	else width = w;

	if (l <= 0) cout << "WARNING: Rectangle - constructor: length should be > 0" << endl;
	else length = l;

	cout << "END:\tRectangle - constructor - init" << endl;
}

Rectangle::~Rectangle()
{
	cout << "START:\tRectangle - destructor" << endl;
	Reset();
	cout << "END:\tRectangle - destructor" << endl;
}

///////////////////////////////////////////////////////////////////////////
// Operators

/// @name Assignment operator
/// @param &r reference to the rectangle to assign
/// @return reference to the rectangle assigned (for concatenating)
Rectangle& Rectangle::operator=( const Rectangle & r)
{
	Reset();
	Init(r);
	return *this;
}

/// @name Comparison operator
/// @param &r reference to the rectangle to check for comparison
/// @return boolean: true if the two rectangles coincide, false if not
bool Rectangle::operator==( const Rectangle & r)
{
    return (( r.width == width && r.length == length ) ? true : false);
}


/// @name Insertion operator
/// @param o stream where to insert
/// @param r rectangle to insert
ostream & operator << (ostream &o, Rectangle & r)
{
	return o;
}

/// @name Extraction operator
/// @param o stream where to extract from
/// @param r rectangle to extract
istream & operator >> (istream &i, Rectangle & X)
{
	return i;
}



///////////////////////////////////////////////////////////////////////////
// Basic handling

void Rectangle::Init()
{
	cout << "START:\tRectangle - Init - Default" << endl;
	Reset();
	cout << "END:\tRectangle - Init - Default" << endl;
}

/// @param r rectangle to be cloned
void Rectangle::Init(const Rectangle &r)
{
	cout << "START:\tRectangle - Init - copy" << endl;

	Reset();

	width = r.width;
	length = r.length;

	cout << "END:\tRectangle - Init - copy" << endl;
}

void Rectangle::Reset()
{
	cout << "START:\tRectangle - Reset" << endl;
	width = 0;
	length = 0;
	cout << "END:\tRectangle - Reset" << endl;
}

///////////////////////////////////////////////////////////////////////////
// Interface to parent class.

/// @brief calculate and return the area of the rectangle
/// @return area of the rectangle
float Rectangle::Area()
{
	return (float)(width*length);
}

/// @brief calculate and return the perimeter of the rectangle
/// @return perimeter of the rectangle
float Rectangle::Perimeter()
{
	return (float)(2*(width+length));
}


///////////////////////////////////////////////////////////////////////////
// Access functions

/// @brief get width of the rectangle
/// @return width of the rectangle
float Rectangle::GetWidth()
{
    return width;
}

/// @brief get length of the rectangle
/// @return length of the rectangle
float Rectangle::GetLength()
{
    return length;
}

/// @brief get width and length of the rectangle
/// @param w width
/// @param l length
void Rectangle::GetDim(float &w, float &l)
{
    w=width;
    l=length;
}


/// @brief set width of the rectangle
/// @param w width
void Rectangle::SetWidth(float w)
{
	if (w < 0)
    {
		cout << "WARNING: Rectangle - SetWidth: width should be > 0" << endl;
		return;
	}
	width = w;
}

/// @brief set length of the rectangle
/// @param l length
void Rectangle::SetLength(float l)
{
	if (l < 0)
    {
		cout << "WARNING: Rectangle - SetLength: length should be > 0" << endl;
		return;
	}
	length = l;
}

/// @brief set width and length of the rectangle
/// @param w width
/// @param l length
void Rectangle::SetDim(float w, float l)
{
	SetWidth(w);
	SetLength(l);
}


///////////////////////////////////////////////////////////////////////////
// Drawing

/// @brief Draws the rectangle.
/// For now it just calls the Dump.
void Rectangle::Draw()
{
	Dump();
}


///////////////////////////////////////////////////////////////////////////
// Debug and serialization

/// @brief Write an error message.
/// @param string message to be printed.
void Rectangle::ErrorMessage( const char *string )
{
	cout << endl << "ERROR -- Rectangle --";
	cout << string << endl;
}

/// @brief Write a warning message.
/// @param string message to be printed.
void Rectangle::WarningMessage(const char *string)
{
	cout << endl << "WARNING -- Rectangle --";
	cout << string << endl;
}

/// @brief For debugging: print all about the rectangle.
void Rectangle::Dump()
{
	cout << "Lenght: " << length  << endl;
	cout << "Width: " << width  << endl;
}
