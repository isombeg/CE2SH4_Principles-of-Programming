package lab4_q2;

//represents segment lines; fields end1 and end2 represent the two endpoints of the segment line
//uses class Point defined previously
public class Segment {
    private Point end1;
    private Point end2;

    public Segment(double x1, double x2, double y1,double y2){
        this.end1 = new Point(x1, y1);
        this.end2 = new Point(x2, y2);
    }
    /*initializes end1 to a Point with coordinates x1, y1,
     and end2 to a Point with coordinates x2, y2 */

    public Segment(){
        this.end1 = new Point(0,0);
        this.end2 = new Point(1,1);
    }
    /* no argument public constructor which initializes end1 to a
    Point with coordinates 0,0, and end2 to a Point with coordinates 1,1 */

    public double getX1(){ return this.end1.getX(); }/* returns the field x of end1 */
    public double getY1(){ return this.end1.getY(); }/* returns the field y of end1 */
    public double getX2(){ return this.end2.getX(); }/* returns the field x of end2 */
    public double getY2(){ return this.end2.getY(); }/* returns the field y of end2 */

    public Point getEnd1(){
        return new Point(this.getX1(), this.getY1());
    }//returns a new point with the same coordinates as end1
    
    public Point getEnd2(){
        return new Point(this.getX1(), this.getY1());
    }//returns a new point with the same coordinates as end2

    public double length(){ return this.end1.distanceTo(this.end2); }
    /* returns the length of this segment;
            it MUST use the method distanceTo() from class Point */

    public boolean isLonger(Segment other){
        return this.end1.distanceTo(this.end2) > other.getEnd1().distanceTo(other.getEnd2());
    }
    /* returns true
     if this Segment is longer than the other Segment and false otherwise;
     it MUST use method length() */

    public Point midPoint(){
        return new Point((this.getX1() + this.getX2())/2, (this.getY1() + this.getY2())/2);
    
    }/* returns a new Point representing
    	the middle of this Segment (it creates a new Point object
    	and returns a reference to it); note the coordinates of the middle are the averages of the coordinates of the end points*/

    public boolean isEqual(Segment other){
        return
                (this.end1.isEqual(other.getEnd1()) && this.end2.isEqual(other.getEnd2()))
                || (this.end1.isEqual(other.getEnd2()) && this.end2.isEqual(other.getEnd1()));
    }
    //returns true if this segment is equal to the other segment;
    //two segment lines are eqaul if they have the same end points, but not necessarily in the same order

    public static double longest(Segment[] arr){
        double maxLen = 0;
        for(int index = 0; index < arr.length; index++)
            if(arr[index].length() > maxLen) maxLen = arr[index].length();
        
        return maxLen;
    }
    /* returns the length
        of the longest Segment in the array; it MUST use method isLonger()*/

    //returns a string representation of the segment line
    public String toString(){
        return "This segment has ends with coordinates (" + this.getX1() + ", " + this.getY1() + ") and (" + this.getX2() + ", " + this.getY2();
    }
}//end class SEgment
