package lab4_q1;

public  class Student{

	private int id;
	private int grade;
	private String name;

//constructor; initializes id to n, name to someName and grade to 0
	public Student (int n, String someName ){
		this.id = n;
                this.name = someName;
                this.grade = 0;
	}

	//sets the grade to mark if 0<=mark <=100; if mark is < 0, grade is set to 0; if mark > 100; grade is set to 100.
	public void setGrade( int mark ){
		if(mark >= 0 && mark <= 100) grade = mark;
                
                else grade = mark < 0 ? 0 : 100;
	}

	//returns grade
	public int getGrade( ){
		return grade;
    }


	//returns ID
	public int getId( ){
		return id;
    }

    //returns the student's name
    public String getName(){
       return name;
    }

	// increases grade by adding to it the bonus, up to the limit of 100, and returns the new grade
	public int increaseGrade( int bonus ){
            grade = grade + bonus < 100 ? grade + bonus : 100;
            return grade;
	}

	//compares the grades of this student and that student
	//and returns true if this student has higher grade, false otherwise
	public boolean gradeIsHigher(Student that){
            return grade > that.getGrade();
	}

	//static method that returns the highest grade of the students in array a
	public static int highestGrade(Student[] a){
            int max = 0;
            for(int memNum = 0; memNum < a.length; memNum++)
                max = a[memNum].getGrade() > max ? a[memNum].getGrade(): max;
                
            return max;
	}

	//returns a string representation of the object
	//(example: The student Robert Ford has the iD 6574 and the grade 100)
	public String toString(){
            return "The student " + name + " has the iD " + id + " and the grade " + grade;
	}

} // end of class definition
