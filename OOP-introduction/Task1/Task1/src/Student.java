import java.util.ArrayList;
import java.util.List;

public final class Student {
    //fields
    private String name;
    private int age;
    private int id;
    private List<Course> courses;

    //setters and getters
    public void setName(String name) {
        if (name.trim().isEmpty())
            throw new IllegalArgumentException("Name cannot be empty.");
        else
            this.name = name;
    }

    public void setId(int id) {
        if (id < 0)
            throw new IllegalArgumentException("ID must be non-negative.");
        this.id = id;
    }

    public void setAge(int age) {
        if (age < 15 || age > 30)
            throw new IllegalArgumentException("Age must be between 15 and 30.");
        else
            this.age = age;
    }

    public void setCourses(List<Course> course) {
        this.courses = new ArrayList<>(course);
    }

    public List<Course> getCourses() {
        return new ArrayList<>(courses);
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }

    public int getAge() {
        return age;
    }


    public Student(String name, int age, int id, List<Course> courses) {
        setName(name);
        setAge(age);
        setId(id);
        setCourses(courses);
    }


    //editing to string
    public String toString()
    {
        return name + "," + age + "," + id+","+courses;
    }
    public String toCSV() {
        return name + "," + age + "," + id;
    }


}