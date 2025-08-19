import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner =new Scanner(System.in);
        School school = new School();
        DataManager dataManager = new DataManager();
        school.loadFromFile();
        while (true) {
            System.out.println("\n==== School Menu ====");
            System.out.println("1. Add Student");
            System.out.println("2. Show Students");
            System.out.println("3. Search Student");
            System.out.println("4. Exit");
            System.out.print("Choose an option: ");

            int choice = scanner.nextInt();
            scanner.nextLine();
            switch (choice) {
                case 1:
                    System.out.print("Enter name: ");
                    String name = scanner.nextLine();
                    System.out.print("Enter age: ");
                    int age = scanner.nextInt();
                    scanner.nextLine();
                    System.out.print("Enter ID: ");
                    int id = scanner.nextInt();
                    List<Course> courses = new ArrayList<>();
                    int validation = 0;
                    do {
                        System.out.println("1.Add Course\n2.Exit");
                        validation = scanner.nextInt();
                        scanner.nextLine(); // consume newline
                        if (validation == 1) {
                            System.out.print("Enter name: ");
                            String cName = scanner.nextLine();
                            System.out.print("Enter Grade: ");
                            int cGrade = scanner.nextInt();
                            scanner.nextLine();
                            System.out.print("Enter ID: ");
                            int cID = scanner.nextInt();
                            scanner.nextLine();
                            Course course = new Course(cName, cGrade, cID);
                            courses.add(course);
                            System.out.println("✅ Course added");
                        } else if (validation != 2) {
                            System.out.println("Not a valid choice");
                        }
                    } while (validation != 2);

                    boolean check =school.addStudent(new Student(name, age, id, courses));
                    if(check)
                        System.out.println("✅ Student added.");
                    else
                        System.out.println("⚠️ Failed ,Repeated ID");
                    break;

                case 2:
                    school.displayStudents();
                    break;
                case 3:
                    System.out.print("Enter name: ");
                    String searchName = scanner.nextLine();
                    if(school.nameExists(searchName))
                        System.out.println("✅ Student "+searchName+" Found");
                    else
                        System.out.println("️⚠️ This Student wasn't Found ");
                    break;
                case 4:
                    System.out.println("👋 Exiting program...");
                    scanner.close();
                    return;

                default:
                    System.out.println("⚠️ Invalid option. Try again.");
            }
        }
    }
}