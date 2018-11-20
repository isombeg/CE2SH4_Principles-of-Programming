/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab5;

/**
 *
 * @author TheYo
 */
public class SLLSet {
    
    private int size;
    private SLLNode head;
    
    public SLLSet(){
        size = 0; head = null;
    }
    
    public SLLSet(int[] sortedArray){
        size = sortedArray.length;
        head = new SLLNode(sortedArray[0], null);
        SLLNode p = head;
        
        for(int index = 1; index < size; index++, p = p.next)
            p.next = new SLLNode(sortedArray[index], null);
        
    }
    
    public int getSize(){
        return size;
    }
    
    public SLLSet copy(){
        int[] newSetArr = new int[size];
        SLLNode p = head;
        
        for(int index = 0; p != null; index++, p = p.next)
            newSetArr[index] = p.value;
        
        return new SLLSet(newSetArr);
    }
    
    public boolean isIn(int v){
        
        for(SLLNode p = head; p != null && !(p.value > v); p = p.next)
            if(p.value == v) return true;
        
        return false;
    }
    
    public void add(int v){

        if(head == null){
            head = new SLLNode(v, null);
            size++;
        }
        
        else if(isIn(v)) return;
        
        else if(v < head.value){
            head = new SLLNode(v, head);
            size++;
        }
        
        else{
            
            SLLNode p = head;
            for(p = p; p.next != null; p = p.next){
                if(p.next.value > v){
                    p.next = new SLLNode(v, p.next);
                    size++;
                    return;
                }
            }
            
            p.next = new SLLNode(v, null);
            size++;
            
            
        }
    }
    
    public void remove(int v){
        
        if(head.value == v){
            SLLNode p = head;
            head = head.next;
            p = null;
            size--;
        }
        
        if(isIn(v)){
            SLLNode p = head;
            
            for(p = p; p.next != null; p = p.next)
                
                if(p.next.value == v){
                    p.next = p.next.next;
                    size--;
                    return;
                }
            
           
            
        }
    }
    
    public SLLSet union(SLLSet s){
        SLLSet rslt = s.copy();
        
        SLLNode p;
        
        for(p = head; p != null; p = p.next)
            rslt.add(p.value);
        
        return rslt;
    }
    
    public SLLSet intersection(SLLSet s){
        SLLSet rslt = new SLLSet();
        SLLNode p;
        
        for(p = head; p != null; p = p.next)
            if(s.isIn(p.value)) rslt.add(p.value);
        
        return rslt;
    }
    
    public SLLSet difference(SLLSet s){
        SLLSet rslt = new SLLSet();
        SLLNode p;
        
        for(p = head; p != null; p = p.next)
            if(!(s.isIn(p.value))) rslt.add(p.value);
        
        for(p = s.head; p != null; p = p.next)
            if(!(isIn(p.value))) rslt.add(p.value);
        
        
        return rslt;
    }
    
    public String toString(){
        if(head == null) return " ";
        
        String rep = new String();
        for(SLLNode p = head; p != null; p = p.next)
            rep += p.value + " ";
        
        return rep;
    }
    
}
