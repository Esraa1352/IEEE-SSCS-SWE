import java.io.*;
import java.util.ArrayList;
import java.util.List;



public class DataManager {
    static public String fileName = "student.csv";

    //store data in csv file
    public void saveStudent(Student student) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName, true));) {
            writer.write(student.toCSV());
            for (Course c : student.getCourses())
            {
                writer.write("," + c.toString());
            }
            writer.newLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public List<Student> readStudent()
    {
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            ArrayList<Student> students = new ArrayList<>();
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");

                // Basic student info
                String Name = parts[0];
                int Age = Integer.parseInt(parts[1]);
                int Id = Integer.parseInt(parts[2]);

                // Read courses in groups of 3
                List<Course> newCourse = new ArrayList<>();
                for (int i = 3; i + 2 < parts.length; i += 3) {
                    String courseName = parts[i];
                    int courseGrade = Integer.parseInt(parts[i + 1]);
                    int courseID = Integer.parseInt(parts[i + 2]);
                    Course course = new Course(courseName, courseGrade, courseID);
                    newCourse.add(course);
                }

                // Create student
                Student student = new Student(Name, Age, Id, newCourse);
                students.add(student);
            }
            return students;

        } catch (IllegalArgumentException e) {
            System.err.println("Invalid data: " + e.getMessage());
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
        }

        return new ArrayList<>();
    }


}
