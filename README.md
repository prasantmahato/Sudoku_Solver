# Sudoku_Solver
This a program to solve the popular puzzle game named Sudoku, in which you are given a grid with few numbers and you have to fill the rest.

## TOOK HELP FROM GFG

APPROACH:
->Sudoku can be solved by one by one assigning numbers to empty cells. 
->Before assigning a number, we check whether it is safe to assign. 
->We check that the same number is not present in the current row, current column and current 3X3 subgrid. 
->After checking for safety, we assign the number, and recursively check whether this assignment leads to   a solution or not. 
->If the assignment doesn’t lead to a solution, then we try the next number for the current empty cell. 
->And if none of the number (1 to 9) leads to a solution, return false and print no solution exists.


ALGORITHM:

STEP 1:
    Create a function that checks after assigning the current index the grid becomes unsafe or not.   Keep Hashmap for a row, column and boxes. If any number has a frequency greater than 1 in the hashMap return false else return true; hashMap can be avoided by using loops.

STEP 2:
    Create a recursive function which takes a grid.

STEP 3:
    Check for any unassigned location. If present then assign a number from 1 to 9, check if assigning the number to current index makes the grid unsafe or not, if safe then recursively call the function for all safe cases from 0 to 9. if any recursive call returns true, end the loop and return true. If no recursive call returns true then return false.

STEP 4:
    If there is no unassigned location then return true.



