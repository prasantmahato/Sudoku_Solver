#include <iostream>
using namespace std;

class sudoku
{
    int SIZE;
    int UNASSIGNED;
    int grid[10][10];
    int row,col,num;
    int boxStartRow,boxStartCol;
    
    public:
    
    sudoku(int x=0)
    {   
        SIZE=x;
        UNASSIGNED,row,col,boxStartCol,boxStartRow,num=0;
        grid[SIZE][SIZE];
        manager();
    }

    void inputGrid();
    void displayGrid();

    bool FindUnassignedLocation(int &row, int &col); 
	bool isSafe(int row,int col,int num); 
	bool SolveSudoku();
	bool UsedInRow(int row, int num); 
	bool UsedInCol(int col, int num);
	bool UsedInBox(int boxStartRow, int boxStartCol, int num);
    
    void manager()
    {
        inputGrid();
        cout<<"\nGiven Sudoku Puzzle: "<<endl;
        displayGrid();
        
        if (SolveSudoku() == true) 
	    {
	    	cout<<"\nSolved Puzzle: "<<endl;
	    	displayGrid(); 
	    }
	    else
	    	cout << "No solution exists"; 
        }

    ~sudoku()
    {   cout<<"\nTHANK YOU, HAVE A NICE DAY.."<<endl;   }

};

void sudoku::inputGrid()
{
    cout<<"\nEnter the puzzle, (Put 0 in place of missing values): "<<endl;
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            cin>>grid[i][j];
}

void sudoku::displayGrid()
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {   
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool sudoku :: SolveSudoku() 
{ 
	//	int row, col; 
    if (!FindUnassignedLocation(row,col)) 
	    return true; 

	for (int num = 1; num <= SIZE; num++) 
	{ 
        if (isSafe(row,col,num)) 
		{ 
		    grid[row][col] = num; 
            if (SolveSudoku()) 
				return true; 

			grid[row][col] = UNASSIGNED; 
		} 
	} 
	return false; 
}

bool sudoku::FindUnassignedLocation(int &row, int &col) 
{ 
	for (row = 0; row < SIZE; row++) 
		for (col = 0; col < SIZE; col++) 
			if (grid[row][col] == UNASSIGNED) 
				return true; 
	return false; 
} 

bool sudoku :: UsedInRow(int row, int num) 
{ 
	for (int col = 0; col < SIZE; col++) 
		if (grid[row][col] == num) 
			return true; 
	return false; 
} 


bool sudoku :: UsedInCol(int col, int num) 
{ 
	for (int row = 0; row < SIZE; row++) 
		if (grid[row][col] == num) 
			return true; 
	return false; 
} 


bool sudoku :: UsedInBox(int boxStartRow, int boxStartCol, int num) 
{ 
	for (int row = 0; row < 3; row++) 
		for (int col = 0; col < 3; col++) 
			if (grid[row + boxStartRow][col + boxStartCol] == num) 
				return true; 
	return false; 
} 

bool sudoku :: isSafe(int row, int col, int num)
{ 
	if(SIZE<9)
	    return (
			!UsedInRow(row,num) && 
		   	!UsedInCol(col,num) && 
		    grid[row][col] == UNASSIGNED
		   );
    else
        return (
			!UsedInRow(row, num) && 
		   	!UsedInCol(col, num) && 
            !UsedInBox(row - row % 3, col - col % 3, num) &&	 
		    grid[row][col] == UNASSIGNED
		   );
} 

int main()
{
    int size;
    cout<<"\nPlease enter the size of sudoku: ";
    cin>>size;
    
    sudoku game(size);

    return 0;
}
