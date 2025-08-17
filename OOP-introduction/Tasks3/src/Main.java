public class Main {
    public static void main(String[] args) {
        City damascus = CityFactory.getCity("Damascus");
        City homs = CityFactory.getCity("Homs");
        City tartus = CityFactory.getCity("Tartus");

        System.out.println(damascus);
        System.out.println(damascus.getTraditionalFood());
        System.out.println(damascus.celebrate());

        System.out.println(homs);
        System.out.println(homs.getTraditionalFood());
        System.out.println(homs.celebrate());

        System.out.println(tartus);
        System.out.println(tartus.getTraditionalFood());
        System.out.println(tartus.celebrate());

        System.out.println("\nAll stored cities:");
        for (City city : CityFactory.getAllCities()) {
            System.out.println(city);
        }
    }
}