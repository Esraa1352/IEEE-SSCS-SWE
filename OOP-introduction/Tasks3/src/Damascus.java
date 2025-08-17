import java.util.*;
class Damascus extends City {
    private static Damascus instance;

    private Damascus() {
        super("Damascus",
                Arrays.asList("Umayyad Mosque", "Azem Palace"),
                Arrays.asList("Old City Tour"),
                Arrays.asList("Damascus Festival"),
                "Kibbeh",
                "Southwest Syria");
    }

    public static Damascus getInstance() {
        if (instance == null) {
            instance = new Damascus();
        }
        return instance;
    }

    @Override
    public String getTraditionalFood() {
        return "Famous dish of Damascus: " + traditionalFood;
    }

    @Override
    public String celebrate() {
        return "Damascus celebrates with traditional music and food during festivals.";
    }
}