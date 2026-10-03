// Kelas turunan untuk periferal desktop (Hierarchical Inheritance)
public class Periferal extends Produk {
    private String koneksi;
    private String tipeFitur;

    // Constructor default
    public Periferal() {
        super();
        this.koneksi = "";
        this.tipeFitur = "";
    }

    // Constructor berparameter
    public Periferal(String id, String nama, String brand, double harga, int stok, String koneksi, String tipeFitur) {
        super(id, nama, brand, harga, stok);
        this.koneksi = koneksi;
        this.tipeFitur = tipeFitur;
    }

    // Getter dan Setter
    public void setKoneksi(String koneksi) {
        this.koneksi = koneksi;
    }

    public String getKoneksi() {
        return this.koneksi;
    }

    public void setTipeFitur(String tipeFitur) {
        this.tipeFitur = tipeFitur;
    }

    public String getTipeFitur() {
        return this.tipeFitur;
    }

    // Override getCardLines (Polimorfisme murni untuk kartu 2 kolom)
    @Override
    public java.util.List<String> getCardLines(int nomorUrut) {
        return formatCardLines(nomorUrut, "Periferal", "Koneksi: " + koneksi, "Fitur: " + tipeFitur);
    }

    // Override displayInfo (Polimorfisme)
    @Override
    public void displayInfo() {
        for (String line : getCardLines(1)) {
            System.out.println(line);
        }
    }
}
