import java.util.Scanner;

public class Main {
    public static void main(String[] args)
    {
        int choice = 0  ;
        Scanner scanner =new Scanner(System.in);
        do {
            System.out.println("====================WELCOME=====================\n1.Enter Student Data\n2.Search for a Student\n3..Add Courses\n4.Remove Course\n5.Exit");
            choice=scanner.nextInt();
            switch (choice) {
                case 1:
                    Student s = new Student();
                    s.getData();
                    s.toString();
                    break;
                case 2:
                    Student s2 = new Student();
                    s2.searchStudent();
                    break;
                case 3:
                case 6:
                    System.out.println("===============BYE========================");
                    return;
                default:
                    System.out.println("Not a Valid Option");
                    break;

            }
        }
        while (choice!=3);

    }}