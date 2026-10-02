import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.Locale;

// Kelas abstrak induk (Superclass) yang merepresentasikan produk secara umum
public abstract class Produk {
    protected String id;
    protected String nama;
    protected String brand;
    protected double harga;
    protected int stok;

    // Constructor default
    public Produk() {
        this.id = "";
        this.nama = "";
        this.brand = "";
        this.harga = 0.0;
        this.stok = 0;
    }

    // Constructor berparameter
    public Produk(String id, String nama, String brand, double harga, int stok) {
        this.id = id;
        this.nama = nama;
        this.brand = brand;
        this.harga = harga;
        this.stok = stok;
    }

    // Helper untuk memformat angka harga ke format Rupiah (contoh: Rp 8.499.000)
    protected String formatRupiah(double nilai) {
        DecimalFormat kursIndonesia = (DecimalFormat) DecimalFormat.getCurrencyInstance();
        DecimalFormatSymbols formatRp = new DecimalFormatSymbols(Locale.forLanguageTag("id-ID"));
        formatRp.setCurrencySymbol("Rp ");
        formatRp.setMonetaryDecimalSeparator(',');
        formatRp.setGroupingSeparator('.');
        kursIndonesia.setDecimalFormatSymbols(formatRp);
        kursIndonesia.setMaximumFractionDigits(0);
        return kursIndonesia.format(nilai);
    }

    // Getter dan Setter
    public void setId(String id) {
        this.id = id;
    }

    public String getId() {
        return this.id;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public String getNama() {
        return this.nama;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public String getBrand() {
        return this.brand;
    }

    public void setHarga(double harga) {
        this.harga = harga;
    }

    public double getHarga() {
        return this.harga;
    }

    public void setStok(int stok) {
        this.stok = stok;
    }

    public int getStok() {
        return this.stok;
    }

    // Method displayInfo yang wajib dioverride oleh semua subclass (Polimorfisme)
    public abstract void displayInfo();
}
