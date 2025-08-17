import java.util.*;
abstract class City {
    protected String name;
    protected List<String> famousPlaces;
    protected List<String> coolAttractions;
    protected List<String> specialEvents;
    protected String traditionalFood;
    protected String location;

    protected City(String name, List<String> places, List<String> attractions, List<String> events, String food, String location) {
        this.name = name;
        this.famousPlaces = places;
        this.coolAttractions = attractions;
        this.specialEvents = events;
        this.traditionalFood = food;
        this.location = location;
    }

    public abstract String getTraditionalFood();
    public abstract String celebrate();
    public String getLocationInSyria() {
        return location;
    }

    @Override
    public String toString() {
        return "City: " + name + ", Location: " + location;
    }
}
