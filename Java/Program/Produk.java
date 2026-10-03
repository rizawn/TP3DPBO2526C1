import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.ArrayList;
import java.util.List;
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

    // Helper untuk memotong atau melengkapi string ke panjang tepat N karakter
    protected String padTrunc(String text, int targetLen) {
        if (text.length() > targetLen) {
            if (targetLen > 3) {
                return text.substring(0, targetLen - 3) + "...";
            }
            return text.substring(0, targetLen);
        }
        StringBuilder sb = new StringBuilder(text);
        while (sb.length() < targetLen) {
            sb.append(" ");
        }
        return sb.toString();
    }

    // Helper membuat satu baris kartu dengan border vertikal
    protected String formatCardRow(String text) {
        return "| " + padTrunc(text, 35) + " |";
    }

    // Helper pembentuk kumpulan baris kartu 39-karakter
    protected List<String> formatCardLines(int nomorUrut, String kategori, String spek1, String spek2) {
        StringBuilder sepSb = new StringBuilder("+");
        for (int i = 0; i < 37; i++) sepSb.append("-");
        sepSb.append("+");
        String sep = sepSb.toString();

        List<String> lines = new ArrayList<>();
        lines.add(sep);
        lines.add(formatCardRow("[" + nomorUrut + "] " + nama));
        lines.add(sep);
        lines.add(formatCardRow("ID Produk   : " + id));
        lines.add(formatCardRow("Kategori    : " + kategori));
        lines.add(formatCardRow("Brand       : " + brand));
        lines.add(formatCardRow("Harga       : " + formatRupiah(harga)));
        lines.add(formatCardRow("Stok        : " + stok + " unit"));
        lines.add(formatCardRow("Spesifikasi : " + spek1));
        lines.add(formatCardRow("              " + spek2));
        lines.add(sep);
        return lines;
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

    // Method polimorfik murni untuk menghasilkan baris-baris kartu produk
    public abstract List<String> getCardLines(int nomorUrut);

    // Method displayInfo yang wajib dioverride oleh semua subclass (Polimorfisme)
    public abstract void displayInfo();
}
