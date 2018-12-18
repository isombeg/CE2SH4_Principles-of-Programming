/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javainheritance;

/**
 *
 * @author TheYo
 */
public class Triangle extends Shape{
    private int side1, side2, side3;
    
    public void setSides(int sideA, int sideB, int sideC){
        
        if(sideA < sideB + sideC && sideB < sideC + sideA && sideC < sideA + sideC){
            side1 = sideA; side2 = sideB; side3 = sideC;
        }
        
        else{
            side1 = 1; side2 = 1; side3 = 1;
        }
    }
    
    public Triangle(){
        side1 = 1; side2 = 1; side3 = 1;
    }
    
    public Triangle(int sideA, int sideB, int sideC, String someColour){
        super(someColour);
        setSides(sideA, sideB, sideC);
    }
    
    public String toString(){
        return "Triange, side1: " + side1 + ", side2: " + side2 + ", side3: " + side3;
    }
    
    public int perimeter(){
        return side1 + side2 + side3;
    }
}
