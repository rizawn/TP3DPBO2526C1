// Kelas turunan untuk komponen Laptop (Hierarchical Inheritance)
public class SparepartLaptop extends Produk {
    private String tipeKompatibel;
    private int garansiBulan;

    // Constructor default
    public SparepartLaptop() {
        super();
        this.tipeKompatibel = "";
        this.garansiBulan = 0;
    }

    // Constructor berparameter
    public SparepartLaptop(String id, String nama, String brand, double harga, int stok, String tipeKompatibel, int garansiBulan) {
        super(id, nama, brand, harga, stok);
        this.tipeKompatibel = tipeKompatibel;
        this.garansiBulan = garansiBulan;
    }

    // Getter dan Setter
    public void setTipeKompatibel(String tipeKompatibel) {
        this.tipeKompatibel = tipeKompatibel;
    }

    public String getTipeKompatibel() {
        return this.tipeKompatibel;
    }

    public void setGaransiBulan(int garansiBulan) {
        this.garansiBulan = garansiBulan;
    }

    public int getGaransiBulan() {
        return this.garansiBulan;
    }

    // Override displayInfo (Polimorfisme)
    @Override
    public void displayInfo() {
        System.out.println("  ID Produk   : " + id);
        System.out.println("  Kategori    : SparepartLaptop");
        System.out.println("  Nama Produk : " + nama);
        System.out.println("  Brand       : " + brand);
        System.out.println("  Harga       : " + formatRupiah(harga));
        System.out.println("  Stok        : " + stok + " unit");
        System.out.println("  Spesifikasi : Kompatibilitas: " + tipeKompatibel + " | Garansi: " + garansiBulan + " bln");
    }
}
