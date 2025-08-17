import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Movies moviesCollection = new Movies();
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n1. Add Movie");
            System.out.println("2. Increment Watched Count");
            System.out.println("3. Display All Movies");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    moviesCollection.addMovie();
                    break;
                case 2:
                    System.out.print("Enter movie name to increment: ");
                    String name = scanner.nextLine();
                    moviesCollection.incByName(name);
                    break;
                case 3:
                    moviesCollection.display();
                    break;
                case 4:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice, try again.");
            }

        } while (choice != 4);

        scanner.close();
    }
}
