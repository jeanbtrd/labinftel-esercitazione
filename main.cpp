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

    return 0;
}
