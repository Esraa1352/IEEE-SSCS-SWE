import java.util.*;
class Tartus extends City {
    private static Tartus instance;

    private Tartus() {
        super("Tartus",
                Arrays.asList("Citadel of Tartus", "Tartus Corniche"),
                Arrays.asList("Mediterranean beaches"),
                Arrays.asList("Sea Festival"),
                "Fish Sayadieh",
                "Western Syria");
    }

    public static Tartus getInstance() {
        if (instance == null) {
            instance = new Tartus();
        }
        return instance;
    }

    @Override
    public String getTraditionalFood() {
        return "Famous dish of Tartus: " + traditionalFood;
    }

    @Override
    public String celebrate() {
        return "Tartus celebrates with seaside festivals and seafood feasts.";
    }
}