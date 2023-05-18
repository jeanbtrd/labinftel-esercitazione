/*!
@file	rhombus.h
@brief	Declaration of the class Rhombus
*/

#ifndef Rhombus__DEF
#define Rhombus__DEF

#include<math.h>

#include "polygon.h"

/*!
@class	Rhombus
@brief	Rhombus is a class describing a polygon with four sides which are parallel in couples.

A rhombus can be completely described by using the length of its diagonals: the segments connecting the two couples of non-adjacent (ie not sharing a rhombus side) vertices.
*/
class Rhombus : public Polygon
{
private:
	float diagH;
	float diagV;

	float Side();

public:

	/// @defgroup Constructors Constructors
	/// @{
	/// @name Constructors
	/// @{

	/// Default constructor
	Rhombus();
	/// Copy constructor
	Rhombus(const Rhombus &r);
	/// Init constructor
	Rhombus( float dH, float dV);
	/// Destructor
	~Rhombus();
	//@}
	//@}

	/// @name Operators.
	/// @{

	/// Assignment
	Rhombus& operator=(const Rhombus &r);
	/// Comparison
	bool operator==(const Rhombus &r);
	/// Stream insertion
	friend ostream & operator << ( ostream &o, Rhombus &r);
	/// Stream extraction
	friend istream & operator >> ( istream &i, Rhombus &r);
	//@}

	/// @name Basic handling.
	/// @{

	/// Init default initializer
	void Init();
	/// Init copy initializer
	void Init( const Rhombus &r);
	/// Object eraser
	void Reset();
	//@}


	/// @name Interface to parent class
	/// @{
	float Area();
	float Perimeter();
	///@}


	/// @defgroup AccessFunctions Access Functions
	/// @{
	/// @name Getters
	/// @{
	void GetDiagonals(float &dH, float &dV);
	float GetDiagH();
	float GetDiagV();
	float GetSide();
	/// @}
	/// @name Setters.
	/// @{
	void SetDiagH(float dH);
	void SetDiagV(float dV);
	void SetDim(float dH, float dV);
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
