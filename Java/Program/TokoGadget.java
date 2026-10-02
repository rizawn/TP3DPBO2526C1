import java.util.ArrayList;

// Kelas TokoGadget yang menerapkan konsep Composition (has-a)
// TokoGadget memiliki kumpulan objek Produk yang disimpan dalam bentuk Array of Objects (ArrayList<Produk>)
public class TokoGadget {
    private String namaToko;
    private String alamat;
    private ArrayList<Produk> daftarProduk;

    // Constructor default
    public TokoGadget() {
        this.namaToko = "";
        this.alamat = "";
        this.daftarProduk = new ArrayList<>();
    }

    // Constructor berparameter
    public TokoGadget(String namaToko, String alamat) {
        this.namaToko = namaToko;
        this.alamat = alamat;
        this.daftarProduk = new ArrayList<>();
    }

    // Getter dan Setter
    public void setNamaToko(String namaToko) {
        this.namaToko = namaToko;
    }

    public String getNamaToko() {
        return this.namaToko;
    }

    public void setAlamat(String alamat) {
        this.alamat = alamat;
    }

    public String getAlamat() {
        return this.alamat;
    }

    // Menambahkan produk ke dalam daftar (Array of Objects)
    public void tambahProduk(Produk produk) {
        if (produk != null) {
            this.daftarProduk.add(produk);
        }
    }

    // Mengembalikan total jumlah produk
    public int getJumlahProduk() {
        return this.daftarProduk.size();
    }

    // Helper untuk membuat teks rata tengah
    private String centerText(String text, int width) {
        int padding = (width - text.length()) / 2;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < padding; i++) sb.append(" ");
        sb.append(text);
        while (sb.length() < width) sb.append(" ");
        return sb.toString();
    }

    // Menampilkan katalog produk secara polimorfik
    public void tampilkanKatalog(String label) {
        System.out.println("================================================================================");
        System.out.println(centerText(namaToko, 80));
        System.out.println(centerText(alamat, 80));
        System.out.println("================================================================================");
        System.out.println(" KATALOG PRODUK [" + label + "] (Jumlah: " + daftarProduk.size() + " Produk)");
        System.out.println("================================================================================");

        for (int i = 0; i < daftarProduk.size(); i++) {
            System.out.println("[" + (i + 1) + "]");
            // Pemanggilan dinamis murni polimorfisme tanpa pengecekan tipe if-else
            daftarProduk.get(i).displayInfo();
            if (i < daftarProduk.size() - 1) {
                System.out.println("--------------------------------------------------------------------------------");
            }
        }
        System.out.println("================================================================================");
        System.out.println();
    }
}
