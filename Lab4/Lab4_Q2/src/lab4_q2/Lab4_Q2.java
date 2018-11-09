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
        Point p1 = new Point(2.0, 3.0),
                p2 = new Point(2.0, 3.0),
                p3 = new Point(4.5, 4.5);
        
        System.out.println(p1.isEqual(p2));
        System.out.println(p2.isEqual(p3));
        
        System.out.println(p3.toString());
        System.out.println(p3.symmetric().toString());
    }
    
}
