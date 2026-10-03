// Kelas turunan untuk meja dan kursi gaming (Hierarchical Inheritance)
public class GamingFurniture extends Produk {
    private String material;
    private double bebanMaksKg;

    // Constructor default
    public GamingFurniture() {
        super();
        this.material = "";
        this.bebanMaksKg = 0.0;
    }

    // Constructor berparameter
    public GamingFurniture(String id, String nama, String brand, double harga, int stok, String material, double bebanMaksKg) {
        super(id, nama, brand, harga, stok);
        this.material = material;
        this.bebanMaksKg = bebanMaksKg;
    }

    // Getter dan Setter
    public void setMaterial(String material) {
        this.material = material;
    }

    public String getMaterial() {
        return this.material;
    }

    public void setBebanMaksKg(double bebanMaksKg) {
        this.bebanMaksKg = bebanMaksKg;
    }

    public double getBebanMaksKg() {
        return this.bebanMaksKg;
    }

    // Override getCardLines (Polimorfisme murni untuk kartu 2 kolom)
    @Override
    public java.util.List<String> getCardLines(int nomorUrut) {
        return formatCardLines(nomorUrut, "GamingFurniture", "Bahan: " + material, "Beban Maks: " + (int) bebanMaksKg + " kg");
    }

    // Override displayInfo (Polimorfisme)
    @Override
    public void displayInfo() {
        for (String line : getCardLines(1)) {
            System.out.println(line);
        }
    }
}
