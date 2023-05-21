
# Table of Contents

1.  [Dealing polygons](#org9c644a2)
    1.  [Quickstart](#org6cb8230)
    2.  [How to use](#orga30d1f0)



<a id="org9c644a2"></a>

# Dealing polygons


<a id="org6cb8230"></a>

## Quickstart

Clone the repository  

    git clone https://github.com/jeanbtrd/labinftel-esercitazione.git

Compile it  

    g++ *.cpp -o labinftel-esercitazione

Run it  

    ./labinftel-esercitazione


<a id="orga30d1f0"></a>

## How to use

Upon running the executable, you will be prompted for an action.  

1.  Rectangle  
    Press `1` to create a rectangle.  
    You will then be prompted for its parameters:  
    -   Width
    -   Length
2.  Rhombus  
    Press `2` to create a rhombus.  
    You will then be prompted for its parameters:  
    -   Horizontal diagonal
    -   Vertical diagonal
3.  RightTriangle  
    Press `3` to create a rhombus.  
    You will then be prompted for its parameters:  
    -   Base
    -   Altitude
4.  Draw  
    Press `4` to draw the currently existing polygons.  
    Example output:  
    
        Rectangle -- Draw
        Lenght:		14.2
        Width:		12.3
        Area:		174.66
        Perimeter:	53
5.  Delete a polygon  
    Press `5` to delete a polygon.  
    You will be shown a numbered list of the currently existing polygons.  
    Then you will be prompted for the number of the one you want to delete.
6.  Exit  
    Press `6` to end the program.

