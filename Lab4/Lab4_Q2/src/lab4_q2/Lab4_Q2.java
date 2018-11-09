/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab4_q2;

/**
 *
 * @author TheYo
 */
public class Lab4_Q2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        //Test subjects
        
        Point 
                p1 = new Point(2.0, 3.0),
                p2 = new Point(2.0, 3.0),
                p3 = new Point(4.5, 4.5);
        
        Segment
                s1 = new Segment(),
                s2 = new Segment(0,0,7,2),
                s3 = new Segment(-1,4,8,8),
                s4 = new Segment(11,11,-11,-11);
        
        
        System.out.println(p1.isEqual(p2));
        System.out.println(p2.isEqual(p3));
        
        System.out.println(p3.toString());
        System.out.println(p3.symmetric().toString());
        
        //Testing segment constructors and toString methods
        System.out.println("\nTesting segment constructors and toString methods\n");
        System.out.println("Expected output: (0.0, 0.0), (1.0, 1.0), Real output: " + s1);
        System.out.println("Expected output: (0.0, 7.0), (0.0, 2.0), Real output: " + s2);
        System.out.println("Expected output: (-1.0, 8.0), (4.0, 8.0), Real output: " + s3);
        System.out.println("Expected output: (11.0, -11.0), (11.0, -11.0), Real output: " + s4);
        
        //Testing Segment method getX1
        System.out.println("\nTesting Segment method getX1\n");
        System.out.println("Case: s1.getX1()\n Expected Output: 0.0, Real Output: " + s1.getX1());
        System.out.println("Case: s3.getX1()\n Expected Output: -1.0, Real Output: " + s3.getX1());
        
        //Testing Segment method getY1
        System.out.println("\nTesting Segment method getX2\n");
        System.out.println("Case: s2.getY1()\n Expected Output: 7.0, Real Output: " + s2.getY1());
        System.out.println("Case: s4.getY1()\n Expected Output: -11.0, Real Output: " + s4.getY1());
        
        //Testing Segment method getX2
        
        
        //Testing Segment method getY2
        
        
        //Testing Segment method getEnd1
        
        
        //Testing Segment method getEnd2
        
        
        //Testing segment method isLonger
        
        
        //Testing Segment method midPoint
        
        
       //Testing Segment method isEqual
       
       
       //Testing Segment method longest
       
       
       
    }
    
}
