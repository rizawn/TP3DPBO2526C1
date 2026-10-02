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

    // Override displayInfo (Polimorfisme)
    @Override
    public void displayInfo() {
        System.out.println("  ID Produk   : " + id);
        System.out.println("  Kategori    : GamingFurniture");
        System.out.println("  Nama Produk : " + nama);
        System.out.println("  Brand       : " + brand);
        System.out.println("  Harga       : " + formatRupiah(harga));
        System.out.println("  Stok        : " + stok + " unit");
        System.out.println("  Spesifikasi : Material: " + material + " | Beban Maks: " + (int) bebanMaksKg + " kg");
    }
}
