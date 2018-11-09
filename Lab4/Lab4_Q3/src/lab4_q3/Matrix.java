/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab4_q3;

/**
 *
 * @author TheYo
 */


public class Matrix{
	private int[][]  matrixData;	// integer array to store integer data
	private int    rowsNum;	// number of rows
	private int    colsNum;	// number of columns

	public Matrix( int row, int col ){ //constructor1
            rowsNum = row <= 0 ? 3 : row;
            colsNum = col <= 0 ? 3 : col;
            matrixData = new int[rowsNum][colsNum];
		
            /* constructs a row-by-col matrix with all elements equal to 0;
		if row<=0 then the number of rows of the matrix is set to 3;
		likewise, if col<=0 the number of columns of the matrix is set to 3. */

	}//end first constructor


	public Matrix( int[][] table) // constructor2
	{
		/* constructs a matrix out of the two dimensional array table,
		   with the same number of rows, columns, and the same element in each
		 position as array table. */

		rowsNum = table.length;
		colsNum = table[0].length;
		matrixData = new int[rowsNum][colsNum]; // allocates memory for the 2D array
		
                //loop to fill the array with values:
		for (int i=0; i<rowsNum; i++)
			for(int j=0; j<colsNum; j++)
				matrixData[i][j] = table[i][j];

	}//end second constructor


	public int getRowDim(){
            return rowsNum;
        }
        
        public int getColDim(){
            return colsNum;
        }
        
        public int getElement(int i, int j) throws IndexOutOfBoundsException
	{
		/* if i and j are valid indices of this matrix,
		   then the element on row i and column j of this matrix
		   is returned; otherwise it throws an exception with message "Invalid indexes".*/

            if  ( i >= 0 && i < rowsNum && j >= 0 && j < colsNum) {
                return matrixData[i][j];
            }
            else {
                throw new IndexOutOfBoundsException("Invalid indexes.");
            }

	}//end getElement

	public boolean setElement(int  x, int i, int j)
	{
	      	  /* if i and j are valid indexes of this matrix, then the element on  row i and
                       column j of this matrix is assigned the value  x and true is returned;
                       otherwise false is returned and no change in the matrix is performed */
            
            if  ( i >= 0 && i < rowsNum && j >= 0 && j < colsNum) {
                matrixData[i][j] = x;
                return true;
            }
            
            else return false;
	}//end setElement

	public Matrix copy()
	{ /* returns a deep copy of this Matrix */
		return new Matrix(matrixData);
	}//end copy

	public void addTo( Matrix m ) throws ArithmeticException
	{
		/*adds Matrix m to this Matrix; it throws an exception message "Invalid operation"
		  if the matrix addition is not defined*/

            
            if (this.getColDim() == m.getColDim() && this.getRowDim() == m.getRowDim()) {
			//add matrices here
                for(int row = 0; row < rowsNum; row++)
                    for(int col = 0; col < colsNum; col++)
                        matrixData[row][col] += m.getElement(row, col);
            }
            
            else throw new ArithmeticException("Invalid operation");

	}

public Matrix subMatrix(int i, int j) throws ArithmeticException
{
    /*  returns a new Matrix object, which represents a submatrix of this Matrix,
    	formed out of rows 0 through i and columns 0 through j;
    	 the method should first check if values i and j are within the required range,
    	 and throw an exception if any of them is not. The exception detail message should read: "Submatrix not defined".
    	 Note: The new object should be constructed in such a way that changes in the new matrix do not affect
    	    this Matrix. */
    
    if  ( i >= 0 && i < rowsNum && j >= 0 && j < colsNum) {
        int[][] newTable = new int[i][j];
        
        for(int row = 0; row < rowsNum; row++){
            for(int col = 0; col < colsNum; col++)
                newTable[i][j] = matrixData[i][j];
        }
        
        return new Matrix(newTable);
    }
    
    else throw new ArithmeticException("Submatrix not defined");

}



        public String toString(  )
	{
		/* returns a string representing the matrix,
		   with each row on a line, and the elements in each row being separated by 2 blank spaces. */

		String output = new String(); // creates an empty string
        	for(int i = 0; i < rowsNum; i++){
                    for(int j = 0; j < colsNum; j++){
        		output += matrixData[i][j] + "  ";
                    }
                    output += "\n";
        	}
       		 return output;

	}//end toString

	// write the remaining methods
        
        public boolean isUpperTr(){
            for(int row = 0; row < rowsNum; row++){
                for(int col = 0; col < colsNum; col++){
                    if(col < row && matrixData[col][row] != 0) return false;
                }
            }
            
            return true;
        }
        
        public static Matrix sum(Matrix[] matArray) throws ArithmeticException {
            
            Matrix rslt = new Matrix(matArray[0].getRowDim(), matArray[0].getColDim());
            
            for(int matIndex = 0; matIndex < matArray.length; matIndex++)
                rslt.addTo(matArray[matIndex]);
            
            return rslt;
        }
	


}//end class
