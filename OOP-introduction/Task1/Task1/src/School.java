import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class School {
    private final Map<Integer, Student> studentsID = new HashMap<>();
    private final Map<Integer, Course> coursesID = new HashMap<>();
    private final ArrayList<Student> studentsName = new ArrayList<>();
    private final DataManager dataManager = new DataManager();
    public int duplicateCourse=0;

    public void loadFromFile()
    {
        var list = dataManager.readStudent();
        studentsName.addAll(list);
        for (Student s : list) {
            studentsID.put(s.getId(), s);
        }
        for (Student cS :list)
        {
            for (Course course : cS.getCourses())
                coursesID.put((course.getId()),course);
        }

    }

    public boolean idExists(int id)
    {
        return studentsID.containsKey(id);
    }
    public boolean idCourseExists(int id)
    {
        return coursesID.containsKey(id);
    }


    public boolean nameExists(String name) {
        for (Student s : studentsName) {
            if (s.getName().equalsIgnoreCase(name)) return true;
        }
        return false;
    }

    public boolean addStudent(Student student) {
        loadFromFile();
        if (idExists(student.getId())) return false;
        studentsID.put(student.getId(), student);
        studentsName.add(student);
        for (Course course : student.getCourses()) {
            if (!idCourseExists(course.getId())) {
                coursesID.put(course.getId(), course);
            } else {
                return false;
            }
        }
        dataManager.saveStudent(student);
        return true;
    }

    public void displayStudents()
    {
        for (Student student : studentsName)
        {
            System.out.println(student);
        }
    }

}

