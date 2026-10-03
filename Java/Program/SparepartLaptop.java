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

    // Override getCardLines (Polimorfisme murni untuk kartu 2 kolom)
    @Override
    public java.util.List<String> getCardLines(int nomorUrut) {
        return formatCardLines(nomorUrut, "SparepartLaptop", "Modul: " + tipeKompatibel, "Garansi: " + garansiBulan + " bln");
    }

    // Override displayInfo (Polimorfisme)
    @Override
    public void displayInfo() {
        for (String line : getCardLines(1)) {
            System.out.println(line);
        }
    }
}
