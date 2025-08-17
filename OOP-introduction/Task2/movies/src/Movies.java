import java.util.ArrayList;
import java.util.Scanner;

public class Movies
{
    int found=0;
    ArrayList<Movie> movies= new ArrayList<>();
    public int searchMovie (String checkName)
    {
        for(Movie m :movies)
        {
            if (checkName.equalsIgnoreCase(m.getName()))
            {
                found =1;
                System.out.println("This Movie is already added");
                System.out.println(m);
            }
        }
        return found ;
    }
    public void addMovie()
    {
        Movie movie =new Movie();
        Scanner scanner =new Scanner(System.in) ;
        System.out.println("Movie Name : ");
        String checkName =scanner.nextLine();
        found=searchMovie(checkName);
        if (found==1)
        {
            return;
        }
        else
        {
            movie.setName(checkName);
        }
        System.out.println("Movie Rating : ");
        movie.setRating(scanner.nextLine());
        System.out.println("Movie Watched Count : ");
        movie.setWatched(scanner.nextInt());
        movies.add(movie);
    }
    public void incByName(String tempName)
    {
        for(Movie m : movies)
        {
            if (m.getName().equalsIgnoreCase(tempName))
            {
                m.incWatched();
                found=1;
            }
        }
        if (found==0)
        {
            System.out.println("There is no such movie in our list");
        }
    }
    public void display() {
        for (Movie m : movies) {
            System.out.println(m);
        }
    }


}
