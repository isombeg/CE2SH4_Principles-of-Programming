/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab4_q1;

/**
 *
 * @author TheYo
 */
public class Lab4_Q1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Student student1 = new Student(56, "Guy-Jacques");
        System.out.println("Student1: " + student1.getId() + " " + student1.getName());
        
        student1.setGrade(78);
        System.out.println("student1 grade: " + student1.getGrade());
        
        student1.setGrade(190);
        System.out.println("student1 grade: " + student1.getGrade());
        
        student1.setGrade(-91);
        System.out.println("student1 grade: " + student1.getGrade());
        
        student1.increaseGrade(91);
        System.out.println("student1 grade: " + student1.getGrade());
        
        student1.increaseGrade(56);
        System.out.println("student1 grade: " + student1.getGrade());
        
        Student student2 = new Student(68, "Isombe");
        student2.setGrade(88);
        if(student1.gradeIsHigher(student2)) System.out.println("Student 1 has higher grade");
        else System.out.println("Student 1 does not have a higher grade");
        
        System.out.println(student1.toString());
        System.out.println(student2.toString());
        
        Student[] classList = new Student[5];
        
        for(int index = 0; index < classList.length; index++){
            classList[index] = new Student(index, "Anon");
            classList[index].setGrade(index*10);
        }
        
        System.out.println(Student.highestGrade(classList));
    }
    
}//
