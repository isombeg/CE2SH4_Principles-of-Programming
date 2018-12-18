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
public class Shape {
    protected String colour;
    
    public Shape(){
        colour = "white";
    }
    
    public Shape(String someColour){
        setColour(someColour);
    }
    
    public String getColour(){
        return colour;
    }
    
    public void setColour(String someColour){
        //Colours being used are White, Blue, Red, Yellow
        String[] validColourList = {"white", "blue", "red", "yellow"};
        for (String validColour : validColourList){
            if (someColour == validColour){
                colour = someColour;
                return;
            }
        }
        
        colour = "white";
    }
    
    public int perimeter(){
        return 0;
    }
    
    public String toString(){
       return "Shape is of colour " + colour;
    }
    
}
