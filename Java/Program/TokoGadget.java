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

    // Menampilkan katalog produk secara polimorfik (2 kotak kesamping)
    public void tampilkanKatalog() {
        tampilkanKatalog("");
    }

    public void tampilkanKatalog(String label) {
        System.out.println("================================================================================");
        System.out.println(centerText(namaToko, 80));
        System.out.println(centerText(alamat, 80));
        System.out.println("================================================================================");

        if (daftarProduk.isEmpty()) {
            System.out.println(centerText("KATALOG PRODUK (Katalog masih kosong!)", 80));
            System.out.println("================================================================================");
            System.out.println(" [!] Katalog masih kosong! (Belum ada produk).");
            System.out.println("     Silakan gunakan menu [2] Tambah Produk atau [3] Muat Data Sampel Awal.");
        } else {
            String headerCount = "KATALOG PRODUK (" + daftarProduk.size() + " Produk)";
            if (daftarProduk.size() == 1) {
                headerCount = "KATALOG PRODUK (1 Produk)";
            }
            System.out.println(centerText(headerCount, 80));
            System.out.println("================================================================================");

            for (int i = 0; i < daftarProduk.size(); i += 2) {
                java.util.List<String> card1 = daftarProduk.get(i).getCardLines(i + 1);
                boolean hasSecond = (i + 1 < daftarProduk.size());
                java.util.List<String> card2 = hasSecond ? daftarProduk.get(i + 1).getCardLines(i + 2) : null;

                for (int lineIdx = 0; lineIdx < card1.size(); lineIdx++) {
                    if (card2 != null) {
                        System.out.println(card1.get(lineIdx) + "  " + card2.get(lineIdx));
                    } else {
                        System.out.println(card1.get(lineIdx));
                    }
                }
                if (i + 2 < daftarProduk.size()) {
                    System.out.println();
                }
            }
        }

        System.out.println("================================================================================");
        System.out.println();
    }
}
