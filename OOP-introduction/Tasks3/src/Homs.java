import java.util.*;
class Homs extends City {
    private static Homs instance;

    private Homs() {
        super("Homs",
                Arrays.asList("Khalid ibn al-Walid Mosque"),
                Arrays.asList("Al-Baath Garden"),
                Arrays.asList("Homs Cultural Festival"),
                "Kibbeh Homs",
                "Central Syria");
    }

    public static Homs getInstance() {
        if (instance == null) {
            instance = new Homs();
        }
        return instance;
    }

    @Override
    public String getTraditionalFood() {
        return "Famous dish of Homs: " + traditionalFood;
    }

    @Override
    public String celebrate() {
        return "Homs celebrates with cultural performances and street events.";
    }
}
