import java.beans.PropertyEditorManager;
import java.io.*;
import java.util.*;

public class Student extends Course implements Duplicate
{
    //fields
    private String name ;
    private int age;
    private int id;
    private int courseCount;
    static  public String fileName ="student.csv";
    public int studentCount ;
    ArrayList<Course> courses =new ArrayList<>();
    ArrayList<Student> students =new ArrayList<>();

    //for input
    Scanner scanner = new Scanner(System.in);

    //setters and getters
    public void setName(String name)
    {
        this.name = name;
    }
    public void setId(int id) {
        this.id = id;
    }
    public void setAge(int age)
    {
        this.age = age;
    }
    public void setCourseCount(int courseCount) {this.courseCount=courseCount;}

    public String getName()
    {
        return name;
    }
    public int getId()
    {
        return id;
    }
    public int getAge() {return age;}
    public int getCourseCount () {return courseCount;}

    //Add,Remove,Sort Courses
    public void addCourse ()
    {

        Course course = new Course();
        System.out.println("Course names:");
        String name = scanner.nextLine();
        course.setName(name);
        System.out.println("Course Id:");
        while (findID(course.getId()) == 1) {
            System.out.println("this id is taken enter another one");
            course.setId(scanner.nextInt());
        }
        System.out.println("Course Grade:");
        int grade = scanner.nextInt();
        course.setGrade(grade);
        saveCourse(course);
    }
    public void removeCourse()
    {
        int i = searchStudent();
        System.out.println("choose from the list the courses you would like to add");
        for(Course course: courses)
        {
            System.out.println("Name : "+course.getName()+" ID "+course.getId()+" Grade " );
        }
        int choice ;
        choice=scanner.nextInt();
        students.get(i).courses.remove(choice);

    }

    //registering a student
    public void getData() //this adds a student with his courses
    {
        Student student =new Student();
        System.out.println("Welcome please Enter your Name:");
        student.setName(scanner.nextLine());
        System.out.println("Welcome please Enter your Age");
        student.setAge(scanner.nextInt());
        scanner.nextLine();
        System.out.println("Welcome please Enter your ID");
        student.setId(scanner.nextInt());
        scanner.nextLine();
        while(findID(student.getId())==1)
        {
            System.out.println("this id is taken enter another one");
            student.setId(scanner.nextInt());
        }
        System.out.println("Please enter your courses\nyour Course count: ");
        int count =scanner.nextInt();
        student.setCourseCount(count);
        int i =0 ;
        System.out.println("choose from the list the courses you would like to add");
        for(Course course: courses)
        {
            System.out.println("Name : "+course.getName()+" ID "+course.getId()+" Grade " );
            i++;
        }
        int choice  ;
        for (int j=1; j<=student.courseCount;j++)
        {
            choice = scanner.nextInt();
            student.courses.add(allCourses.get(choice));
        }
        studentCount ++;
        students.add(student);
        saveStudent(student);
    }

    //editing to string
    @Override
    public String toString()
    {
        return  name +","+age +","+id ;
    }

    //store data in csv file
    public void saveStudent(Student student) {
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter(fileName, true));
            writer.write(student.toString());
            writer.newLine();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // search a student method
    public int searchStudent()
    {
        String name ;
        int i = 0;
        System.out.println("Enter the name of student you are searching for :");
        name =scanner.nextLine();
        try
        {
            BufferedReader reader =new BufferedReader(new FileReader(fileName));
            String line;
            while((line= reader.readLine())!=null)
            {
                String[] part = line.split(",");
                String foundName =part[0];
                int foundAge =Integer.parseInt(part[1]);
                int foundId =Integer.parseInt(part[2]);
                i++;
                if (foundName.equals(name))
                {
                    System.out.println("Student Found\nName :"+name+" Age :"+foundAge+" ID: "+foundId );
                    break;
                }
            }
            return i;
        }
        catch (IOException e)
        {
            e.printStackTrace();

        }
        return i;
    }

    // duplicate id of student
    public int findID(int tempId)
    {
        try
        {
            BufferedReader reader =new BufferedReader(new FileReader(fileName));
            String line;
            while((line= reader.readLine())!=null)
            {
                String[] parts =line.split(",");
                if(Integer.parseInt(parts[2])==tempId) {
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

}
