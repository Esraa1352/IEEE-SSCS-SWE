import java.io.*;
import java.util.ArrayList;

public class Course implements Duplicate
{
private String name;
private int grade ;
private int id ;
private int courseCount;
ArrayList<Course> allCourses =new ArrayList<>();
public void setGrade(int grade)
{
        this.grade = grade;
}
public int getGrade()
{
    return grade;
}
public void setId(int id)
{
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
    this.name=name;
}


    public int findID(int tempId)
    {
        try
        {
            BufferedReader reader =new BufferedReader(new FileReader("Student.csv"));
            String line;
            while((line= reader.readLine())!=null)
            {
                String[] parts =line.split(",");
                if(Integer.parseInt(parts[3])==tempId)
                {
                    return 1;
                }
            }

        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
        return 0;
    }
    public void saveCourse(Course course) {
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter("Courses.csv", true));
            writer.write(course.toString());
            writer.newLine();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }


    }
}
