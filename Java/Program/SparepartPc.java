// Kelas turunan untuk komponen PC Desktop (Hierarchical Inheritance)
public class SparepartPc extends Produk {
    private int dayaWatt;
    private String formFactor;

    // Constructor default
    public SparepartPc() {
        super();
        this.dayaWatt = 0;
        this.formFactor = "";
    }

    // Constructor berparameter
    public SparepartPc(String id, String nama, String brand, double harga, int stok, int dayaWatt, String formFactor) {
        super(id, nama, brand, harga, stok);
        this.dayaWatt = dayaWatt;
        this.formFactor = formFactor;
    }

    // Getter dan Setter
    public void setDayaWatt(int dayaWatt) {
        this.dayaWatt = dayaWatt;
    }

    public int getDayaWatt() {
        return this.dayaWatt;
    }

    public void setFormFactor(String formFactor) {
        this.formFactor = formFactor;
    }

    public String getFormFactor() {
        return this.formFactor;
    }

    // Override displayInfo (Polimorfisme)
    @Override
    public void displayInfo() {
        System.out.println("  ID Produk   : " + id);
        System.out.println("  Kategori    : SparepartPc");
        System.out.println("  Nama Produk : " + nama);
        System.out.println("  Brand       : " + brand);
        System.out.println("  Harga       : " + formatRupiah(harga));
        System.out.println("  Stok        : " + stok + " unit");
        System.out.println("  Spesifikasi : Daya: " + dayaWatt + " W | Form Factor: " + formFactor);
    }
}
