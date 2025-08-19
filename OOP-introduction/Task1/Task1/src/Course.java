import java.io.*;
import java.util.ArrayList;

public class Course
{
private String name;
private int grade ;
private int id ;



//setters and getters
public void setGrade(int grade)
{
    if(grade<0 || grade>100)
        throw new IllegalArgumentException("Grade can't be negative");
    else
        this.grade = grade;
}
public int getGrade()
{
    return grade;
}

public void setId(int id)
{
    if (id<0)
        this.id=id;
    else
        this.id=id;
}
public int getId()
{
    return id;
}

public String getName()
{
        return name;
}
public void setName(String name)
{
    if(name==null||name.trim().isBlank())
        throw new IllegalArgumentException("Name can't be blank");
    else
        this.name=name;
}


public Course(String name,int grade,int id)
{
    setName(name);
    setGrade(grade);
    setId(id);
}



@Override
public String toString()
{
    return name+","+grade+","+id;
}



}

