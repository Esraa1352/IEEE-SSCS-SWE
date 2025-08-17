public class Movie
{
    private String name ;
    private String rating;
    private int watched;
    public void setName(String name)
    {

        if (name.isBlank())
           System.out.println("name of movie can't be blank");
        else
            this.name=name;
    }
    public void setRating(String rating)
    {
        if (rating.equals("G") || rating.equals("PG") ||rating.equals("PG-13")||rating.equals("R"))
        {
         this.rating = rating;
        }
        else
        {
            System.out.println("this is not a valid rating");
            
    }}
    public void setWatched (int count)
    {
        if(count >=0)
            this.watched=count;
        else
            System.out.println("this is not a valid number");
    }

    public String getName() {
        return name;
    }
    public int getWatched()
    {
        return watched;
    }
    public String getRating()
    {
        return rating;
    }
    public void incWatched()
    {
        setWatched(++watched);
    }
    public String toString()
    {
        return "Name: " + name + " Rating: " + rating + " Watched: " + watched + " Times";
    }

}
