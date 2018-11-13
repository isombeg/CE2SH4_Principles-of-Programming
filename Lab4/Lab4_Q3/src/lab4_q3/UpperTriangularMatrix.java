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
public class UpperTriangularMatrix {
    
    private int size, matrixData[];
    
    public UpperTriangularMatrix(int n){
        size = n;
        matrixData = new int[size * size];
    }
    
    public UpperTriangularMatrix(Matrix upTriM) throws IllegalArgumentException {
        
        if(upTriM.isUpperTr() && upTriM.getRowDim() == upTriM.getColDim()){
            size = upTriM.getRowDim();
            matrixData = new int[size * size];
            
            for(int rowNum = 0; rowNum < size; rowNum++){
                for(int colNum = 0; colNum < size; colNum++)
                    matrixData[colNum + size * rowNum] = upTriM.getElement(rowNum, colNum);
            }
        }
        
        else throw new IllegalArgumentException("Argument must be an Upper Triangular Matrix");
    }
    
    public int getDim(){
        return size;
    }
    
    public int getElement(int i, int j) throws IndexOutOfBoundsException{
        
        if(i < size && j < size){
            return matrixData[j + i*size];
        }
        
        else throw new IndexOutOfBoundsException("Location doesn't exist within this matrix");
    }
    
    public void setElement(int x, int i, int j) throws IndexOutOfBoundsException, IllegalArgumentException{
        
        if(!(i < j) && x != 0) throw new IllegalArgumentException("Incorrect Argument");
        else if(!(i < size) || !(j < size)) throw new IndexOutOfBoundsException("Invalid Indexes");
        
        else matrixData[j + i*size] = x;
    }
    
    public Matrix fullMatrix(){
        
        int[][] newData = new int[size][size];
        
        for(int rowNum = 0; rowNum < size; rowNum++){
            for(int colNum = 0; colNum < size; colNum++)
                newData[rowNum][colNum] = matrixData[colNum + size*rowNum];
        }
        
        return new Matrix(newData);
    }
    
    public void print1DArray(){
        for(int rowNum = 0; rowNum < size; rowNum++){
            for(int colNum = rowNum; colNum < size; colNum++)
                System.out.print(matrixData[colNum + size * rowNum] + "  ");
        }
        System.out.println("");
    }
    
    public String toString(){
        String totStr = new String();
        
        for(int rowNum = 0; rowNum < size; rowNum++){
            for(int colNum = 0; colNum < size; colNum++)
                totStr += matrixData[colNum + size * rowNum] + "  ";
            
            totStr += "\n";
        }
        
        return totStr;
    }
    
    public int getDet(){
        int det = 1;
        
        for(int rowNum = 0; rowNum < size; rowNum++) det *= matrixData[rowNum * size + rowNum];
        
        return det;
    }
    
    public double[] effSolve(double[] b) throws IllegalArgumentException {

        
        if(this.getDet() == 0) throw new IllegalArgumentException("Incorrect Argument");
        
        else{
            double[] x = new double[size];
        
            for(int rowNum = 0; rowNum < size; rowNum++)
                for(int colNum = 0; colNum < size; colNum++)
                    x[rowNum] += b[rowNum] * (double)matrixData[rowNum + colNum*size] / this.getDet();
            
            return x;
        }
    }
}
