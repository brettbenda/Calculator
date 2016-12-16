# Calculator
Scientific calculator 

This code using the Shunting Yard algorithm to create a scientific calculator that preserves the order of operations. Addition, subtraction,
division, multiplcation, exponentiation as well as sine, cosine, and natural logarithm functions are supported. The constants Pi and e are
already saved as variables with the appropriate values. There is built in support for string variables. To create a variable, use 
the following format:

let variableName = [some mathmatical expression]

Example inputs:

INPUT: 1 + 2 - 3
OUTPUT: 0

INPUT: let X = 7
OUTPUT: 7
INPUT: 2 * X
OUTPUT: 14
INPUT: let Y = ( 2 * X ) / 7
OUTPUT: 2
INPUT: sin( Y * PI )
OUTPUT: 0

INPUT: log( e ^ 2 )
OUTPUT: 2

NOTE: every expression must be seperated by atleast once space, e.g. 2 + 3 + 6, NOT 2+3+6.
