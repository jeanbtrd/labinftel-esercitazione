/*!
@file	main.cpp
@brief	Using polygons.
*/

#include <iostream>

#include "rectangle.h"
#include "rhombus.h"
#include "RightTriangle.h"

// The maximum number of polygons that can be created here.
#define MAX_POLYGONS 100

using namespace std;

int main() {

	// This flag tells the program if we want to exit it.
	bool exit = false;

	// This variable is for storing user's choice about what to do next.
	int choice = -1;

	// This array stores the polygons of this program.
	Polygon * polygons[MAX_POLYGONS];

	// Initialize all its entries to NULL
	for ( int i = 0; i < MAX_POLYGONS; i++) polygons[i] = NULL;

	// Count the number of polygons in existence.
	int polyCount = 0;


	// Welcome the user.
	cout << "-------- Welcome --------" << endl << endl;


	// The while loop gets exited if and only if the user decides to end the program, which turns the exit flag to true.
	while (!exit)
	{
		// Prompt the user for the next action
		cout << endl;
		cout << "-------- What now? --------" << endl;
		cout << "1 - Rectangle" << endl;
		cout << "2 - Rhombus" << endl;
		cout << "3 - RightTriangle" << endl;
		cout << "4 - Draw" << endl;
		cout << "5 - Delete a polygon" << endl;
		cout << "6 - Exit" << endl;

		// Get user choice
		scanf("%d", &choice);
		//cin >> choice;


		// This switch statement does the action requested by the user.
		switch (choice)
		{

			// 1 - Rectangle
			case 1:
			{
				// Create the rectangle by default
				Rectangle * p = new Rectangle;

				// Prompt the user for the parameters of the rectangle
				cout << "You have chosen to create a Rectangle, now I need its parameters:" << endl;
				cout << "If none are given, it will be created with default values." << endl;

				// Get the parameters
				float w, l;
				cout << "Width:\t"; scanf("%f", &w);
				cout << "Length:\t"; scanf("%f", &l);

				// Give these parameters to the rectangle
				p->SetDim(w,l);
				polygons[polyCount] = p;

				// Update the polygons count.
				polyCount++;

				break;
			}

			// 2 - Rhombus
			case 2:
			{
				// Create the rectangle by default
				Rhombus * p = new Rhombus;

				cout << "You have chosen to create a Rhombus, now I need its parameters:" << endl;
				cout << "If none are given, it will be created with the default values." << endl;

				// Prompt the user for the parameters of the Rhombus
				float dh, dv;
				cout << "Horizontal diagonal:\t"; scanf("%f", &dh);
				cout << "Vertical diagonal:\t"; scanf("%f", &dv);

				// Give these parameters to the Rhombus
				p->SetDim(dh,dv);
				polygons[polyCount] = p;

				// Update the polygons count
				polyCount++;

				break;
			}

			// 3 - RightTriangle
			case 3:
			{
				// Create the rectangle by default
				RightTriangle * p = new RightTriangle;

				cout << "You have chosen to create a Right Triangle, now I need its parameters:" << endl;
				cout << "If none are given, it will be created with the default values." << endl;

				// Prompt the user for the parameters of the RightTriangle
				float b, a;
				cout << "Base:\t\t"; scanf("%f", &b);
				cout << "Altitude:\t"; scanf("%f", &a);

				// Give these parameters to the RightTriangle
				p->SetCathetes(b,a);
				polygons[polyCount] = p;

				// Update the polygons count.
				polyCount++;

				break;
			}

			// 4 - Draw
			case 4:
			{
				// Tell the user what is about to happen
				cout << "Drawing all polygons:" << endl;

				// Cycle through the polygons array, drawing each one.
				for (int i = 0; i < polyCount; i++)
				{
					cout << endl;
					polygons[i]->Draw();
				}

				break;
			}

			// 5 - Delete a polygon
			case 5:
			{
				// Display to the user a numbered list of existing polygons
				cout << "You decided to erase a polygon." << endl;
				cout << "Here is a numbered list of current polygons:" << endl;
				for (int i = 0; i < polyCount; i++)
				{
					cout << "Polygon P" << i << ":" << endl;
					polygons[i]->Draw();
				}

				// Prompt user for the number of the polygon to delete
				cout << "Which one do you want to delete?" << endl;
				for (int i = 0; i < polyCount; i++) cout << "P" << i << ", ";
				cout << "?" << endl;

				int p = -1;
				scanf("%d", &p);
				while (p < 1 || p > polyCount)
				{
					cout << "Enter a valid choice:" << endl;
					scanf("%d", &p);
				}

				// Delete the chosen polygon
				delete polygons[p];
				polygons[p] = NULL;

				// Reorder the array
				int np = p + 1;
				while (polygons[np] != NULL)
				{
					polygons[p] = polygons[np];
					p++; np++;
				}
				break;
			}



			// 6 - Exit
			case 6:
			{
				// Delete all polygons
				for (int i = 0; i < polyCount; i++)
				{
					delete polygons[i];
				}

				// Set the exit flag to true
				exit = true;

				break;
			}

			default:
			{
			cout << "Choice not valid. Please enter one of the available choices:" << endl;
			break;
			}
		}


	}


    return 0;
}
