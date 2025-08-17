import java.util.*;
class CityFactory {
    private static Map<String, City> cities = new HashMap<>();

    public static City getCity(String name) {
        name = name.toLowerCase();
        switch (name) {
            case "damascus":
                cities.putIfAbsent(name, Damascus.getInstance());
                break;
            case "homs":
                cities.putIfAbsent(name, Homs.getInstance());
                break;
            case "tartus":
                cities.putIfAbsent(name, Tartus.getInstance());
                break;
            default:
                throw new IllegalArgumentException("City not recognized: " + name);
        }
        return cities.get(name);
    }

    public static Collection<City> getAllCities() {
        return cities.values();
    }
}