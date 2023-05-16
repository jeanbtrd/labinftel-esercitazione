/*!
@file	RightTriangle.h
@brief	Declaration of the class RightTriangle
*/

#ifndef RightTriangle__DEF
#define RightTriangle__DEF

#include <iostream>
#include <cmath>

#include "polygon.h"

using namespace std;

/*!
@class RightTriangle
@brief RightTriangle is a class ...
*/
class RightTriangle : public Polygon
{
private:
	float base;
	float altitude;

public:

	/// @defgroup Constructors Constructors
	/// @{
	/// @name Constructors
	/// @{

	/// Default constructor

	RightTriangle();

	/// Copy constructor
	RightTriangle(const RightTriangle & r);

	/// Init constructor
	/// RightTriangle( args );

	/// Destructor
	virtual ~RightTriangle();

	///@}
	///@}

	/// @name Operators
	/// @{

	/// Assignment
	RightTriangle& operator=(const RightTriangle &r);
	/// Comparison
	bool operator==(const RightTriangle &r);
	/// Stream insertion
	friend ostream & operator << ( ostream &o, RightTriangle &r);
	/// Stream extraction
	friend istream & operator >> ( istream &i, RightTriangle &r);
	/// @}

	/// @name Basic handling
	/// @{

	/// Init default initializer
	void Init();
	/// Init copy initializer
	void Init( const RightTriangle &r);
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
	float GetHypotenuse();
	float GetBase();
	float GetAltitude();
	void GetCathetes( float & b, float & a );
	/// @}
	/// @name Setters
	/// @{
	void SetBase(float b);
	void SetAltitude(float a);
	void SetCathetes(float b, float a);
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
