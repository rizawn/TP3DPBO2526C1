import java.util.Scanner;

public class Main {
    // Helper membaca string dari terminal
    private static String bacaString(Scanner sc, String prompt) {
        System.out.print(prompt);
        return sc.nextLine().trim();
    }

    // Helper membaca integer dengan validasi
    private static int bacaInt(Scanner sc, String prompt) {
        while (true) {
            System.out.print(prompt);
            try {
                String input = sc.nextLine().trim();
                return Integer.parseInt(input);
            } catch (NumberFormatException e) {
                System.out.println("  [!] Input harus berupa angka bulat. Coba lagi.");
            }
        }
    }

    // Helper membaca double dengan validasi
    private static double bacaDouble(Scanner sc, String prompt) {
        while (true) {
            System.out.print(prompt);
            try {
                String input = sc.nextLine().trim();
                return Double.parseDouble(input);
            } catch (NumberFormatException e) {
                System.out.println("  [!] Input harus berupa angka. Coba lagi.");
            }
        }
    }

    // Menampilkan banner welcoming toko
    private static void tampilkanWelcoming() {
        System.out.println("================================================================================");
        System.out.println("  ####    ##   #####   ####  ###### #####    #    # #    # #####  ");
        System.out.println(" #    #  #  #  #    # #    # #        #      #    # #    # #    # ");
        System.out.println(" #      #    # #    # #      #####    #      ###### #    # #####  ");
        System.out.println(" #  ### ###### #    # #  ### #        #      #    # #    # #    # ");
        System.out.println(" #    # #    # #    # #    # #        #      #    # #    # #    # ");
        System.out.println("  ####  #    # #####   ####  ######   #      #    #  ####  #####  ");
        System.out.println("================================================================================");
        System.out.println("            SELAMAT DATANG DI GADGET & GAMING RIG HUB!            ");
        System.out.println("      Pusat Perakitan PC, Sparepart Laptop, Periferal & Furniture  ");
        System.out.println("                      Jl. Merdeka No. 45, Bandung                       ");
        System.out.println("================================================================================");
        System.out.println();
    }

    // Mengisi data sampel toko secara instan
    private static void muatDataSampel(TokoGadget toko) {
        toko.tambahProduk(new SparepartPc("PC-001", "RTX 4070 Gaming OC", "NVIDIA", 8499000, 5, 200, "PCIe x16"));
        toko.tambahProduk(new SparepartPc("PC-002", "Ryzen 7 5800X", "AMD", 3850000, 8, 105, "AM4"));
        toko.tambahProduk(new SparepartLaptop("LP-001", "RAM SODIMM 16GB DDR4 3200", "Kingston", 899000, 15, "DDR4 SODIMM", 24));
        toko.tambahProduk(new SparepartLaptop("LP-002", "Baterai Laptop 6-Cell", "Dell", 850000, 7, "6-Cell 11.4V", 12));
        toko.tambahProduk(new Periferal("PF-001", "Keyboard Mechanical K68", "Logitech", 1100000, 12, "Wired", "RGB Switch"));
        toko.tambahProduk(new Periferal("PF-002", "Mouse G502 X Plus", "Logitech", 1299000, 20, "Wireless", "25.600 DPI"));
        toko.tambahProduk(new GamingFurniture("GF-001", "Kursi Gaming Ergonomis", "ROG", 2500000, 4, "Mesh + Foam", 150));
        toko.tambahProduk(new GamingFurniture("GF-002", "Meja Gaming Elektrik", "Secretlab", 4200000, 3, "Steel + MDF", 100));
        System.out.println("[v] Berhasil memuat 8 data produk sampel ke dalam toko!\n");
    }

    // Menu Tambah Produk berdasarkan kategori
    private static void menuTambahProduk(TokoGadget toko, Scanner sc) {
        System.out.println("================================================================================");
        System.out.println("                    FORM PILIH KATEGORI PRODUK BARU                            ");
        System.out.println("================================================================================");
        System.out.println("  1. Sparepart PC Desktop     (GPU, CPU, PSU, RAM Desktop, dll)");
        System.out.println("  2. Sparepart Laptop         (RAM SODIMM, Baterai, Layar LCD, dll)");
        System.out.println("  3. Periferal Desktop        (Keyboard, Mouse, Headset, Webcam, dll)");
        System.out.println("  4. Gaming Furniture         (Kursi Gaming, Meja Gaming, Monitor Stand)");
        System.out.println("  5. Batal / Kembali ke Menu Utama");
        System.out.println("--------------------------------------------------------------------------------");
        int kategori = bacaInt(sc, "Pilih kategori produk (1-5): ");
        System.out.println();

        if (kategori == 1) {
            System.out.println("--------------------------------------------------------------------------------");
            System.out.println("                 INPUT DATA: SPAREPART PC DESKTOP                              ");
            System.out.println("--------------------------------------------------------------------------------");
            String id = bacaString(sc, "  ID Produk          : ");
            String nama = bacaString(sc, "  Nama Produk        : ");
            String brand = bacaString(sc, "  Brand / Merk       : ");
            double harga = bacaDouble(sc, "  Harga Satuan (Rp)  : ");
            int stok = bacaInt(sc, "  Jumlah Stok (unit) : ");
            int daya = bacaInt(sc, "  Konsumsi Daya (W)  : ");
            String formFactor = bacaString(sc, "  Form Factor / Slot : ");
            System.out.println("--------------------------------------------------------------------------------");

            toko.tambahProduk(new SparepartPc(id, nama, brand, harga, stok, daya, formFactor));
            System.out.println("[v] Sukses! Produk Sparepart PC Desktop berhasil ditambahkan ke inventaris toko.\n");

        } else if (kategori == 2) {
            System.out.println("--------------------------------------------------------------------------------");
            System.out.println("                 INPUT DATA: SPAREPART LAPTOP                                  ");
            System.out.println("--------------------------------------------------------------------------------");
            String id = bacaString(sc, "  ID Produk          : ");
            String nama = bacaString(sc, "  Nama Produk        : ");
            String brand = bacaString(sc, "  Brand / Merk       : ");
            double harga = bacaDouble(sc, "  Harga Satuan (Rp)  : ");
            int stok = bacaInt(sc, "  Jumlah Stok (unit) : ");
            String kompatibel = bacaString(sc, "  Tipe Kompatibilitas: ");
            int garansi = bacaInt(sc, "  Garansi Resmi (bln): ");
            System.out.println("--------------------------------------------------------------------------------");

            toko.tambahProduk(new SparepartLaptop(id, nama, brand, harga, stok, kompatibel, garansi));
            System.out.println("[v] Sukses! Produk Sparepart Laptop berhasil ditambahkan ke inventaris toko.\n");

        } else if (kategori == 3) {
            System.out.println("--------------------------------------------------------------------------------");
            System.out.println("                 INPUT DATA: PERIFERAL DESKTOP                                 ");
            System.out.println("--------------------------------------------------------------------------------");
            String id = bacaString(sc, "  ID Produk          : ");
            String nama = bacaString(sc, "  Nama Produk        : ");
            String brand = bacaString(sc, "  Brand / Merk       : ");
            double harga = bacaDouble(sc, "  Harga Satuan (Rp)  : ");
            int stok = bacaInt(sc, "  Jumlah Stok (unit) : ");
            String koneksi = bacaString(sc, "  Konektivitas       : ");
            String fitur = bacaString(sc, "  Fitur Unggulan     : ");
            System.out.println("--------------------------------------------------------------------------------");

            toko.tambahProduk(new Periferal(id, nama, brand, harga, stok, koneksi, fitur));
            System.out.println("[v] Sukses! Produk Periferal Desktop berhasil ditambahkan ke inventaris toko.\n");

        } else if (kategori == 4) {
            System.out.println("--------------------------------------------------------------------------------");
            System.out.println("                 INPUT DATA: GAMING FURNITURE                                  ");
            System.out.println("--------------------------------------------------------------------------------");
            String id = bacaString(sc, "  ID Produk          : ");
            String nama = bacaString(sc, "  Nama Produk        : ");
            String brand = bacaString(sc, "  Brand / Merk       : ");
            double harga = bacaDouble(sc, "  Harga Satuan (Rp)  : ");
            int stok = bacaInt(sc, "  Jumlah Stok (unit) : ");
            String material = bacaString(sc, "  Bahan / Material   : ");
            double beban = bacaDouble(sc, "  Beban Maksimal (kg): ");
            System.out.println("--------------------------------------------------------------------------------");

            toko.tambahProduk(new GamingFurniture(id, nama, brand, harga, stok, material, beban));
            System.out.println("[v] Sukses! Produk Gaming Furniture berhasil ditambahkan ke inventaris toko.\n");

        } else if (kategori == 5) {
            System.out.println(">> Kembali ke Menu Utama.\n");
        } else {
            System.out.println("[!] Pilihan kategori tidak valid.\n");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        TokoGadget toko = new TokoGadget("Gadget & Gaming Rig Hub", "Jl. Merdeka No. 45, Bandung");

        tampilkanWelcoming();

        int pilihan = 0;
        while (pilihan != 4) {
            System.out.println("================================================================================");
            System.out.println("                                  MENU UTAMA                                    ");
            System.out.println("================================================================================");
            System.out.println("  1. Lihat Katalog Produk Toko");
            System.out.println("  2. Tambah Produk Baru (Pilih Kategori)");
            System.out.println("  3. Muat Data Sampel Awal (8 Produk Default)");
            System.out.println("  4. Keluar dari Toko");
            System.out.println("--------------------------------------------------------------------------------");
            pilihan = bacaInt(sc, "Pilih aksi (1-4): ");
            System.out.println();

            switch (pilihan) {
                case 1:
                    String label = (toko.getJumlahProduk() == 0) ? "DATA KOSONG / SEBELUM INPUT" : "LIVE STATUS";
                    toko.tampilkanKatalog(label);
                    break;
                case 2:
                    menuTambahProduk(toko, sc);
                    break;
                case 3:
                    muatDataSampel(toko);
                    break;
                case 4:
                    System.out.println("================================================================================");
                    System.out.println(" Terima kasih telah berkunjung ke Toko Gadget & Gaming Rig Hub! Sampai jumpa!   ");
                    System.out.println("================================================================================");
                    break;
                default:
                    System.out.println("[!] Pilihan menu tidak valid. Silakan pilih 1 - 4.\n");
                    break;
            }
        }

        sc.close();
    }
}
