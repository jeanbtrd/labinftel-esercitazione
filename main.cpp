/*!
@file	main.cpp
@brief	Testing RightTriangle class
*/

#include <iostream>

#include "RightTriangle.h"

using namespace std;

int main()
{

	// The default constructor should build a RightTriangle object.
	RightTriangle rt;
	cout << endl;

	// The rt object should have the default values of 0 and 0.
	cout << "TEST:\t" << " -------------------- ";
	cout << "Default Constructor" << " -------------------- " << endl;
	rt.Dump();
	cout << endl;

	// Test SetBase and SetAltitude
	cout << "TEST:\t" << " -------------------- ";
	cout << "SetBase" << " -------------------- " << endl;
	cout << "Give it a negative value, get an error:" << endl;
	rt.SetBase( -30. );
	cout << "\nGive it a positive value, all good:" << endl;
	rt.SetBase( 2147.435432 );
	rt.Dump();
	cout << endl;

	cout << "TEST:\t" << " -------------------- ";
	cout << "SetAltitude" << " -------------------- " << endl;
	cout << "Give it a negative value, get an error:" << endl;
	rt.SetAltitude( -3390.33333 );
	cout << "\nGive it a positive value, all good:" << endl;
	rt.SetAltitude( 3390.33333 );
	rt.Dump();
	cout << endl;


	// Test GetBase and GetAltitude
	cout << "TEST:\t" << " -------------------- ";
	cout << "GetBase" << " -------------------- " << endl;
	cout << rt.GetBase() << endl;
	cout << endl;

	cout << "TEST:\t" << " -------------------- ";
	cout << "GetAltitude" << " -------------------- " << endl;
	cout << rt.GetAltitude() << endl;
	cout << endl;

	// Test GetCathetes
	cout << "TEST:\t" << " -------------------- ";
	cout << "GetCathetes" << " -------------------- " << endl;
	float b,a;
	rt.GetCathetes( b , a );
	cout << "B: " << b << "\tA: " << a << endl;
	cout << endl;

	// Test copy constructor
	cout << "TEST:\t" << " -------------------- ";
	cout << "Copy Constructor" << " -------------------- " << endl;

	RightTriangle rt2(rt);
	rt2.Dump();

	cout << endl;

	// Test comparison operator: should return true
	cout << "TEST:\t" << " -------------------- ";
	cout << "Comparison Operator" << " -------------------- " << endl;
	cout << "Should return:\ttrue" << endl;

	if ( rt == rt2 ) cout << "true:\tThey're the same." << endl;
	else cout << "false:\tThey're different." << endl;

	cout << endl;

	// Test SetCathetes
	cout << "TEST:\t" << " -------------------- ";
	cout << "SetCathetes" << " -------------------- " << endl;

	rt2.SetCathetes( -35.55, 41.34 );
	rt2.Dump();

	// Test comparison operator: should return false
	cout << "TEST:\t" << " -------------------- ";
	cout << "Comparison Operator" << " -------------------- " << endl;
	cout << "Should return:\tfalse" << endl;

	if ( rt == rt2 ) cout << "true:\tThey're the same." << endl;
	else cout << "false:\tThey're different." << endl;


	// Test Init constructor
	cout << "TEST:\t" << " -------------------- ";
	cout << "Init constructor" << " -------------------- " << endl;

	cout << "Bad value (negative):" << endl;
	RightTriangle rt3( -78. , 5.54 );
	rt3.Dump();

	cout << "Good value:" << endl;
	RightTriangle rt4( 78. , 5.54 );
	rt4.Dump();


	// Test GetHypotenuse
	cout << "TEST:\t" << " -------------------- ";
	cout << "GetHypotenuse" << " -------------------- " << endl;

	cout << "\nrt:\t"; rt.Dump();
	cout << "Hypotenuse:\t" << rt.GetHypotenuse() << endl;

	cout << "\nrt2:\t"; rt2.Dump();
	cout << "Hypotenuse:\t" << rt2.GetHypotenuse() << endl;

	cout << "\nrt3:\t"; rt3.Dump();
	cout << "Hypotenuse:\t" << rt3.GetHypotenuse() << endl;

	cout << "\nrt4:\t"; rt4.Dump();
	cout << "Hypotenuse:\t" << rt4.GetHypotenuse() << endl;

	cout << endl;


	// Test GetPerimeter
	cout << "TEST:\t" << " -------------------- ";
	cout << "GetPerimeter" << " -------------------- " << endl;
	cout << "NB: function of parent class polygon" << endl;

	cout << "\nrt:\t"; rt.Dump();
	cout << "Perimeter:\t" << rt.GetPerimeter() << endl;

	cout << "\nrt2:\t"; rt2.Dump();
	cout << "Perimeter:\t" << rt2.GetPerimeter() << endl;

	cout << "\nrt3:\t"; rt3.Dump();
	cout << "Perimeter:\t" << rt3.GetPerimeter() << endl;

	cout << "\nrt4:\t"; rt4.Dump();
	cout << "Perimeter:\t" << rt4.GetPerimeter() << endl;

	cout << endl;

	// Test GetArea
	cout << "TEST:\t" << " -------------------- ";
	cout << "GetArea" << " -------------------- " << endl;
	cout << "NB: function of parent class polygon" << endl;

	cout << "\nrt:\t"; rt.Dump();
	cout << "Area:\t" << rt.GetArea() << endl;

	cout << "\nrt2:\t"; rt2.Dump();
	cout << "Area:\t" << rt2.GetArea() << endl;

	cout << "\nrt3:\t"; rt3.Dump();
	cout << "Area:\t" << rt3.GetArea() << endl;

	cout << "\nrt4:\t"; rt4.Dump();
	cout << "Area:\t" << rt4.GetArea() << endl;

	cout << endl;

	// Test assignment operator
	cout << "TEST:\t" << " -------------------- ";
	cout << "Assignment operator" << " -------------------- " << endl;
	rt = rt2 = rt3 = rt4;
	rt.Dump();
	rt2.Dump();
	rt3.Dump();
	rt4.Dump();


    return 0;
}
