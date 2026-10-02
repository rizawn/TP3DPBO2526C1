#include <iostream>
#include "TokoGadget.cpp"
#include "SparepartPc.cpp"
#include "SparepartLaptop.cpp"
#include "Periferal.cpp"
#include "GamingFurniture.cpp"

using namespace std;

int main() {
    // 1. Inisialisasi objek TokoGadget
    TokoGadget toko("Gadget & Gaming Rig Hub", "Jl. Merdeka No. 45, Bandung");

    // 2. Memasukkan 8 data seed awal ke dalam toko
    toko.tambahProduk(new SparepartPc("PC-001", "RTX 4070 Gaming OC", "NVIDIA", 8499000.0, 5, 200, "PCIe x16"));
    toko.tambahProduk(new SparepartPc("PC-002", "Ryzen 7 5800X", "AMD", 3850000.0, 8, 105, "AM4"));
    toko.tambahProduk(new SparepartLaptop("LP-001", "RAM SODIMM 16GB DDR4 3200", "Kingston", 899000.0, 15, "DDR4 SODIMM", 24));
    toko.tambahProduk(new SparepartLaptop("LP-002", "Baterai Laptop 6-Cell", "Dell", 850000.0, 7, "6-Cell 11.4V", 12));
    toko.tambahProduk(new Periferal("PF-001", "Keyboard Mechanical K68", "Logitech", 1100000.0, 12, "Wired", "RGB Switch"));
    toko.tambahProduk(new Periferal("PF-002", "Mouse G502 X Plus", "Logitech", 1299000.0, 20, "Wireless", "25.600 DPI"));
    toko.tambahProduk(new GamingFurniture("GF-001", "Kursi Gaming Ergonomis", "ROG", 2500000.0, 4, "Mesh + Foam", 150.0));
    toko.tambahProduk(new GamingFurniture("GF-002", "Meja Gaming Elektrik", "Secretlab", 4200000.0, 3, "Steel + MDF", 100.0));

    // 3. Menampilkan katalog SEBELUM penambahan data
    toko.tampilkanKatalog("SEBELUM PENAMBAHAN");

    // Pesan jeda / notifikasi penambahan data
    cout << ">> Menambahkan 3 produk baru ke inventaris toko..." << endl;
    cout << endl;

    // 4. Menambahkan 3 data produk baru
    toko.tambahProduk(new SparepartPc("PC-003", "PSU RM850x 80+ Gold", "Corsair", 1750000.0, 6, 850, "ATX"));
    toko.tambahProduk(new Periferal("PF-003", "Headset Cloud Stinger 2", "HyperX", 599000.0, 18, "Wired", "Surround 7.1"));
    toko.tambahProduk(new GamingFurniture("GF-003", "Monitor Stand Riser", "Razer", 650000.0, 9, "Aluminium", 20.0));

    // 5. Menampilkan katalog SESUDAH penambahan data
    toko.tampilkanKatalog("SESUDAH PENAMBAHAN");

    return 0;
}
