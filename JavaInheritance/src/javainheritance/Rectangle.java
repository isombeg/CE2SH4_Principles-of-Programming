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
public class Rectangle extends Shape{
    private int width, height;
    
    public void setWidth(int someWidth){
        width = someWidth > 0 ? someWidth : 1;
    }
    
    public void setHeight(int someHeight){
        height = someHeight > 0 ? someHeight : 2;
    }
    
    public Rectangle(){
        width = 1; height = 2;
    }
    
    public Rectangle(int someWidth, int someHeight, String someColour){
        super(someColour);
        setWidth(someWidth);
        setHeight(someHeight);
    }
    
    public String toString(){
        return "Rectange, Colour: " + colour + ", Width: " + width + ", Height: " + height;
    }
    
    public int perimeter(){
        return 2*width + 2*height;
    }
}
