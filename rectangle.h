/*!
@file	rectangle.h
@brief	Declaration of the class Rectangle
*/

#ifndef Rectangle__DEF
#define Rectangle__DEF


#include "polygon.h"

/*!
@class Rectangle
@brief Rectangle is a class describing a polygon with four rect (90 deg) angles.

The Rectangle having four rect angles implies it having four sides, which are parallel in couples.
*/
class Rectangle : public Polygon
{
private:
	float width;
	float length;

public:

	/// @defgroup Constructors Constructors
	/// @{
	/// @name Constructors
	/// @{

	/// Default constructor
	Rectangle();
	/// Copy constructor
	Rectangle(const Rectangle & r);
	/// Init constructor
	Rectangle( float w, float l);
	/// Destructor
	~Rectangle();
	///@}
	///@}

	/// @name Operators
	/// @{

	/// Assignment
	Rectangle& operator=(const Rectangle &r);
	/// Comparison
	bool operator==(const Rectangle &r);
	/// Stream insertion
	friend ostream & operator << ( ostream &o, Rectangle &r);
	/// Stream extraction
	friend istream & operator >> ( istream &i, Rectangle &r);
	/// @}

	/// @name Basic handling
	/// @{

	/// Init default initializer
	void Init();
	/// Init copy initializer
	void Init( const Rectangle &r);
	/// Object eraser
	void Reset();
	/// @}


	/// @name Interface to parent class
	/// @{
	float Area();
	float Perimeter();
	/// @}

	/// @defgroup AccessFunctions Access Functions
	/// @{
	/// @name Getters
	/// @{
	void GetDim(float &w, float &l);
	float GetLength();
	float GetWidth();
	/// @}
	/// @name Setters
	/// @{
	void SetLength(float l);
	void SetWidth(float w);
	void SetDim(float w, float l);
	/// @}
	/// @}

	/// @name drawing
	/// @{
	void Draw();
	/// @}

	/// @name Debug and serialization
	/// @{
	void ErrorMessage(const char *string);
	void WarningMessage(const char *string);
	void Dump();
	///@}

};

#endif
