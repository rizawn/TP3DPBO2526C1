#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
#include "TokoGadget.cpp"
#include "SparepartPc.cpp"
#include "SparepartLaptop.cpp"
#include "Periferal.cpp"
#include "GamingFurniture.cpp"

using namespace std;

// Helper membaca input string dengan spasi
string bacaString(const string& prompt) {
    cout << prompt;
    string val;
    getline(cin >> ws, val);
    return val;
}

// Helper membaca integer
int bacaInt(const string& prompt) {
    cout << prompt;
    int val;
    while (!(cin >> val)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "  [!] Input harus angka bulat. Coba lagi: ";
    }
    return val;
}

// Helper membaca double
double bacaDouble(const string& prompt) {
    cout << prompt;
    double val;
    while (!(cin >> val)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "  [!] Input harus angka. Coba lagi: ";
    }
    return val;
}

// Menampilkan banner welcoming toko
void tampilkanWelcoming() {
    cout << "=========================================================================================================" << endl;
    cout << "  ▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄        ▄▄▄▄▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄▄  " << endl;
    cout << "  ████  █▒▒▒▒▒▒▒▒▒▒█ ████████████      █▒▒▒▒▒▒▒▒▒▒█ ████████████ █▒▒▒▒▒▒▒▒▒▒█ ████████████ █▒▒▒▒▒▒▒▒▒▒█  " << endl;
    cout << "  █▓▓█  ▀▀▀▀▀▀▀▀█░░█ █▓▓█▀▀▀▀▄▓▓█      █░░█▀▀▀▀▀▀▀▀ ▀▀▀▀▄▓▓█▀▀▀▀ █░░█▀▀▀▀▄░░█ █▓▓█▀▀▀▀▄▓▓█ █░░█▀▀▀▀▀▀▀▀  " << endl;
    cout << "  █▒▒█   ▄▄▄▄▄▄▄█  █ █▒▒█▄▄▄▄█▒▒█      █  █▄▄▄▄▄▄▄      █▒▒█     █  █    █  █ █▒▒█▄▄▄▄█▒▒█ █  █▄▄▄▄▄▄▄▄  " << endl;
    cout << "  █░░█  █░░░░░░░░░░█ █░░░░░░░░░░█      █░░░░░░░░░░█     █░░█     █░░█    █░░█ █░░░░░░░░░░█ █░░░░░░░░░░█  " << endl;
    cout << "  █  █  █▒▒▄▀▀▀▀▀▀▀  █  █▀▀▀▀▄  █       ▀▀▀▀▀▀▀▄▒▒█     █  █     █▒▒█    █▒▒█ █  █▀▀▀█▄ ▀▄ █▒▒█▀▀▀▀▀▀▀▀  " << endl;
    cout << "  █░░█  █▓▓█▄▄▄▄▄▄▄▄ █░░█    █░░█      ▄▄▄▄▄▄▄▄█▓▓█     █░░█     █▓▓█▄▄▄▄█▓▓█ █░░█    █░░█ █▓▓█▄▄▄▄▄▄▄▄  " << endl;
    cout << "  █▒▒█  ████████████ █▒▒█    █▒▒█      ████████████     █▒▒█     ████████████ █▒▒█    █▒▒█ ████████████  " << endl;
    cout << "  ▀▀▀▀   ▀▀▀▀▀▀▀▀▀▀▀ ▀▀▀▀    ▀▀▀▀      ▀▀▀▀▀▀▀▀▀▀▀      ▀▀▀▀      ▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀    ▀▀▀▀ ▀▀▀▀▀▀▀▀▀▀▀▀  " << endl;
    cout << "=========================================================================================================" << endl;
    cout << "                                       SELAMAT DATANG DI IZA STORE!                                      " << endl;
    cout << "                  Pusat Komputer, Laptop, Periferal & Gaming Furniture Terlengkap                        " << endl;
    cout << "                                   Jl. itu  No. itulah, kota itu                                         " << endl;
    cout << "=========================================================================================================" << endl;
    cout << endl;
}

// Mengisi data sampel toko secara instan
void muatDataSampel(TokoGadget& toko) {
    toko.tambahProduk(new SparepartPc("PC-001", "RTX 4070 Gaming OC", "NVIDIA", 8499000.0, 5, 200, "PCIe x16"));
    toko.tambahProduk(new SparepartPc("PC-002", "Ryzen 7 5800X", "AMD", 3850000.0, 8, 105, "AM4"));
    toko.tambahProduk(new SparepartLaptop("LP-001", "RAM SODIMM 16GB DDR4 3200", "Kingston", 899000.0, 15, "DDR4 SODIMM", 24));
    toko.tambahProduk(new SparepartLaptop("LP-002", "Baterai Laptop 6-Cell", "Dell", 850000.0, 7, "6-Cell 11.4V", 12));
    toko.tambahProduk(new Periferal("PF-001", "Keyboard Mechanical K68", "Logitech", 1100000.0, 12, "Wired", "RGB Switch"));
    toko.tambahProduk(new Periferal("PF-002", "Mouse G502 X Plus", "Logitech", 1299000.0, 20, "Wireless", "25.600 DPI"));
    toko.tambahProduk(new GamingFurniture("GF-001", "Kursi Gaming Ergonomis", "ROG", 2500000.0, 4, "Mesh + Foam", 150.0));
    toko.tambahProduk(new GamingFurniture("GF-002", "Meja Gaming Elektrik", "Secretlab", 4200000.0, 3, "Steel + MDF", 100.0));
    cout << "[v] Berhasil memuat 8 data produk sampel ke dalam toko!" << endl << endl;
}

// Menu Tambah Produk berdasarkan kategori
void menuTambahProduk(TokoGadget& toko) {
    int kategori;
    cout << "================================================================================" << endl;
    cout << "                    FORM PILIH KATEGORI PRODUK BARU                            " << endl;
    cout << "================================================================================" << endl;
    cout << "  1. Sparepart PC Desktop     (GPU, CPU, PSU, RAM Desktop, dll)" << endl;
    cout << "  2. Sparepart Laptop         (RAM SODIMM, Baterai, Layar LCD, dll)" << endl;
    cout << "  3. Periferal Desktop        (Keyboard, Mouse, Headset, Webcam, dll)" << endl;
    cout << "  4. Gaming Furniture         (Kursi Gaming, Meja Gaming, Monitor Stand)" << endl;
    cout << "  5. Batal / Kembali ke Menu Utama" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    kategori = bacaInt("Pilih kategori produk (1-5): ");
    cout << endl;

    if (kategori == 1) {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "                 INPUT DATA: SPAREPART PC DESKTOP                              " << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        string id = bacaString("  ID Produk          : ");
        string nama = bacaString("  Nama Produk        : ");
        string brand = bacaString("  Brand / Merk       : ");
        double harga = bacaDouble("  Harga Satuan (Rp)  : ");
        int stok = bacaInt("  Jumlah Stok (unit) : ");
        int daya = bacaInt("  Konsumsi Daya (W)  : ");
        string formFactor = bacaString("  Form Factor / Slot : ");
        cout << "--------------------------------------------------------------------------------" << endl;

        toko.tambahProduk(new SparepartPc(id, nama, brand, harga, stok, daya, formFactor));
        cout << "[v] Sukses! Produk Sparepart PC Desktop berhasil ditambahkan ke inventaris toko." << endl << endl;

    } else if (kategori == 2) {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "                 INPUT DATA: SPAREPART LAPTOP                                  " << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        string id = bacaString("  ID Produk          : ");
        string nama = bacaString("  Nama Produk        : ");
        string brand = bacaString("  Brand / Merk       : ");
        double harga = bacaDouble("  Harga Satuan (Rp)  : ");
        int stok = bacaInt("  Jumlah Stok (unit) : ");
        string kompatibilitas = bacaString("  Tipe Kompatibilitas: ");
        int garansi = bacaInt("  Garansi Resmi (bln): ");
        cout << "--------------------------------------------------------------------------------" << endl;

        toko.tambahProduk(new SparepartLaptop(id, nama, brand, harga, stok, kompatibilitas, garansi));
        cout << "[v] Sukses! Produk Sparepart Laptop berhasil ditambahkan ke inventaris toko." << endl << endl;

    } else if (kategori == 3) {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "                 INPUT DATA: PERIFERAL DESKTOP                                 " << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        string id = bacaString("  ID Produk          : ");
        string nama = bacaString("  Nama Produk        : ");
        string brand = bacaString("  Brand / Merk       : ");
        double harga = bacaDouble("  Harga Satuan (Rp)  : ");
        int stok = bacaInt("  Jumlah Stok (unit) : ");
        string koneksi = bacaString("  Konektivitas       : ");
        string fitur = bacaString("  Fitur Unggulan     : ");
        cout << "--------------------------------------------------------------------------------" << endl;

        toko.tambahProduk(new Periferal(id, nama, brand, harga, stok, koneksi, fitur));
        cout << "[v] Sukses! Produk Periferal Desktop berhasil ditambahkan ke inventaris toko." << endl << endl;

    } else if (kategori == 4) {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "                 INPUT DATA: GAMING FURNITURE                                  " << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        string id = bacaString("  ID Produk          : ");
        string nama = bacaString("  Nama Produk        : ");
        string brand = bacaString("  Brand / Merk       : ");
        double harga = bacaDouble("  Harga Satuan (Rp)  : ");
        int stok = bacaInt("  Jumlah Stok (unit) : ");
        string material = bacaString("  Bahan / Material   : ");
        double bebanMaks = bacaDouble("  Beban Maksimal (kg): ");
        cout << "--------------------------------------------------------------------------------" << endl;

        toko.tambahProduk(new GamingFurniture(id, nama, brand, harga, stok, material, bebanMaks));
        cout << "[v] Sukses! Produk Gaming Furniture berhasil ditambahkan ke inventaris toko." << endl << endl;

    } else if (kategori == 5) {
        cout << ">> Kembali ke Menu Utama." << endl << endl;
    } else {
        cout << "[!] Pilihan kategori tidak valid." << endl << endl;
    }
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    // 1. Inisialisasi toko
    TokoGadget toko("IZA STORE", "Jl. itu  No. itulah, kota itu");

    // 2. Welcoming entrance
    tampilkanWelcoming();

    int pilihan = 0;
    while (pilihan != 4) {
        cout << "================================================================================" << endl;
        cout << "                                  MENU UTAMA                                    " << endl;
        cout << "================================================================================" << endl;
        cout << "  1. Lihat Katalog Produk Toko" << endl;
        cout << "  2. Tambah Produk Baru (Pilih Kategori)" << endl;
        cout << "  3. Muat Data Sampel Awal (8 Produk Default)" << endl;
        cout << "  4. Keluar dari Toko" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        pilihan = bacaInt("Pilih aksi (1-4): ");
        cout << endl;

        switch (pilihan) {
            case 1:
                toko.tampilkanKatalog();
                break;
            case 2:
                menuTambahProduk(toko);
                break;
            case 3:
                muatDataSampel(toko);
                break;
            case 4:
                cout << "================================================================================" << endl;
                cout << "         Terima kasih telah berkunjung ke IZA STORE! Sampai jumpa!              " << endl;
                cout << "================================================================================" << endl;
                break;
            default:
                cout << "[!] Pilihan menu tidak valid. Silakan pilih 1 - 4." << endl << endl;
                break;
        }
    }

    return 0;
}
