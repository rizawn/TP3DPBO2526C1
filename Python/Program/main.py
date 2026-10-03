import sys
if hasattr(sys.stdout, 'reconfigure'):
    sys.stdout.reconfigure(encoding='utf-8')

from TokoGadget import TokoGadget
from SparepartPc import SparepartPc
from SparepartLaptop import SparepartLaptop
from Periferal import Periferal
from GamingFurniture import GamingFurniture

def baca_str(prompt):
    return input(prompt).strip()

def baca_int(prompt):
    while True:
        try:
            return int(input(prompt).strip())
        except ValueError:
            print("  [!] Input harus berupa angka bulat. Coba lagi.")

def baca_float(prompt):
    while True:
        try:
            return float(input(prompt).strip())
        except ValueError:
            print("  [!] Input harus berupa angka. Coba lagi.")

def tampilkan_welcoming():
    print("=" * 105)
    print("  ▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄        ▄▄▄▄▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄▄  ")
    print("  ████  █▒▒▒▒▒▒▒▒▒▒█ ████████████      █▒▒▒▒▒▒▒▒▒▒█ ████████████ █▒▒▒▒▒▒▒▒▒▒█ ████████████ █▒▒▒▒▒▒▒▒▒▒█  ")
    print("  █▓▓█  ▀▀▀▀▀▀▀▀█░░█ █▓▓█▀▀▀▀▄▓▓█      █░░█▀▀▀▀▀▀▀▀ ▀▀▀▀▄▓▓█▀▀▀▀ █░░█▀▀▀▀▄░░█ █▓▓█▀▀▀▀▄▓▓█ █░░█▀▀▀▀▀▀▀▀  ")
    print("  █▒▒█   ▄▄▄▄▄▄▄█  █ █▒▒█▄▄▄▄█▒▒█      █  █▄▄▄▄▄▄▄      █▒▒█     █  █    █  █ █▒▒█▄▄▄▄█▒▒█ █  █▄▄▄▄▄▄▄▄  ")
    print("  █░░█  █░░░░░░░░░░█ █░░░░░░░░░░█      █░░░░░░░░░░█     █░░█     █░░█    █░░█ █░░░░░░░░░░█ █░░░░░░░░░░█  ")
    print("  █  █  █▒▒▄▀▀▀▀▀▀▀  █  █▀▀▀▀▄  █       ▀▀▀▀▀▀▀▄▒▒█     █  █     █▒▒█    █▒▒█ █  █▀▀▀█▄ ▀▄ █▒▒█▀▀▀▀▀▀▀▀  ")
    print("  █░░█  █▓▓█▄▄▄▄▄▄▄▄ █░░█    █░░█      ▄▄▄▄▄▄▄▄█▓▓█     █░░█     █▓▓█▄▄▄▄█▓▓█ █░░█    █░░█ █▓▓█▄▄▄▄▄▄▄▄  ")
    print("  █▒▒█  ████████████ █▒▒█    █▒▒█      ████████████     █▒▒█     ████████████ █▒▒█    █▒▒█ ████████████  ")
    print("  ▀▀▀▀   ▀▀▀▀▀▀▀▀▀▀▀ ▀▀▀▀    ▀▀▀▀      ▀▀▀▀▀▀▀▀▀▀▀      ▀▀▀▀      ▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀    ▀▀▀▀ ▀▀▀▀▀▀▀▀▀▀▀▀  ")
    print("=" * 105)
    print("                                       SELAMAT DATANG DI IZA STORE!                                      ")
    print("                  Pusat Komputer, Laptop, Periferal & Gaming Furniture Terlengkap                        ")
    print("                                   Jl. itu  No. itulah, kota itu                                         ")
    print("=" * 105)
    print()

def muat_data_sampel(toko):
    toko.tambahProduk(SparepartPc("PC-001", "RTX 4070 Gaming OC", "NVIDIA", 8499000, 5, 200, "PCIe x16"))
    toko.tambahProduk(SparepartPc("PC-002", "Ryzen 7 5800X", "AMD", 3850000, 8, 105, "AM4"))
    toko.tambahProduk(SparepartLaptop("LP-001", "RAM SODIMM 16GB DDR4 3200", "Kingston", 899000, 15, "DDR4 SODIMM", 24))
    toko.tambahProduk(SparepartLaptop("LP-002", "Baterai Laptop 6-Cell", "Dell", 850000, 7, "6-Cell 11.4V", 12))
    toko.tambahProduk(Periferal("PF-001", "Keyboard Mechanical K68", "Logitech", 1100000, 12, "Wired", "RGB Switch"))
    toko.tambahProduk(Periferal("PF-002", "Mouse G502 X Plus", "Logitech", 1299000, 20, "Wireless", "25.600 DPI"))
    toko.tambahProduk(GamingFurniture("GF-001", "Kursi Gaming Ergonomis", "ROG", 2500000, 4, "Mesh + Foam", 150))
    toko.tambahProduk(GamingFurniture("GF-002", "Meja Gaming Elektrik", "Secretlab", 4200000, 3, "Steel + MDF", 100))
    print("[v] Berhasil memuat 8 data produk sampel ke dalam toko!\n")

def menu_tambah_produk(toko):
    print("=" * 80)
    print("                    FORM PILIH KATEGORI PRODUK BARU                            ")
    print("=" * 80)
    print("  1. Sparepart PC Desktop     (GPU, CPU, PSU, RAM Desktop, dll)")
    print("  2. Sparepart Laptop         (RAM SODIMM, Baterai, Layar LCD, dll)")
    print("  3. Periferal Desktop        (Keyboard, Mouse, Headset, Webcam, dll)")
    print("  4. Gaming Furniture         (Kursi Gaming, Meja Gaming, Monitor Stand)")
    print("  5. Batal / Kembali ke Menu Utama")
    print("-" * 80)
    kategori = baca_int("Pilih kategori produk (1-5): ")
    print()

    if kategori == 1:
        print("-" * 80)
        print("                 INPUT DATA: SPAREPART PC DESKTOP                              ")
        print("-" * 80)
        id_p = baca_str("  ID Produk          : ")
        nama = baca_str("  Nama Produk        : ")
        brand = baca_str("  Brand / Merk       : ")
        harga = baca_float("  Harga Satuan (Rp)  : ")
        stok = baca_int("  Jumlah Stok (unit) : ")
        daya = baca_int("  Konsumsi Daya (W)  : ")
        form_factor = baca_str("  Form Factor / Slot : ")
        print("-" * 80)
        toko.tambahProduk(SparepartPc(id_p, nama, brand, harga, stok, daya, form_factor))
        print("[v] Sukses! Produk Sparepart PC Desktop berhasil ditambahkan ke inventaris toko.\n")

    elif kategori == 2:
        print("-" * 80)
        print("                 INPUT DATA: SPAREPART LAPTOP                                  ")
        print("-" * 80)
        id_p = baca_str("  ID Produk          : ")
        nama = baca_str("  Nama Produk        : ")
        brand = baca_str("  Brand / Merk       : ")
        harga = baca_float("  Harga Satuan (Rp)  : ")
        stok = baca_int("  Jumlah Stok (unit) : ")
        kompatibel = baca_str("  Tipe Kompatibilitas: ")
        garansi = baca_int("  Garansi Resmi (bln): ")
        print("-" * 80)
        toko.tambahProduk(SparepartLaptop(id_p, nama, brand, harga, stok, kompatibel, garansi))
        print("[v] Sukses! Produk Sparepart Laptop berhasil ditambahkan ke inventaris toko.\n")

    elif kategori == 3:
        print("-" * 80)
        print("                 INPUT DATA: PERIFERAL DESKTOP                                 ")
        print("-" * 80)
        id_p = baca_str("  ID Produk          : ")
        nama = baca_str("  Nama Produk        : ")
        brand = baca_str("  Brand / Merk       : ")
        harga = baca_float("  Harga Satuan (Rp)  : ")
        stok = baca_int("  Jumlah Stok (unit) : ")
        koneksi = baca_str("  Konektivitas       : ")
        fitur = baca_str("  Fitur Unggulan     : ")
        print("-" * 80)
        toko.tambahProduk(Periferal(id_p, nama, brand, harga, stok, koneksi, fitur))
        print("[v] Sukses! Produk Periferal Desktop berhasil ditambahkan ke inventaris toko.\n")

    elif kategori == 4:
        print("-" * 80)
        print("                 INPUT DATA: GAMING FURNITURE                                  ")
        print("-" * 80)
        id_p = baca_str("  ID Produk          : ")
        nama = baca_str("  Nama Produk        : ")
        brand = baca_str("  Brand / Merk       : ")
        harga = baca_float("  Harga Satuan (Rp)  : ")
        stok = baca_int("  Jumlah Stok (unit) : ")
        material = baca_str("  Bahan / Material   : ")
        beban = baca_float("  Beban Maksimal (kg): ")
        print("-" * 80)
        toko.tambahProduk(GamingFurniture(id_p, nama, brand, harga, stok, material, beban))
        print("[v] Sukses! Produk Gaming Furniture berhasil ditambahkan ke inventaris toko.\n")

    elif kategori == 5:
        print(">> Kembali ke Menu Utama.\n")
    else:
        print("[!] Pilihan kategori tidak valid.\n")

def main():
    toko = TokoGadget("IZA STORE", "Jl. itu  No. itulah, kota itu")
    tampilkan_welcoming()

    pilihan = 0
    while pilihan != 4:
        print("=" * 80)
        print("                                  MENU UTAMA                                    ")
        print("=" * 80)
        print("  1. Lihat Katalog Produk Toko")
        print("  2. Tambah Produk Baru (Pilih Kategori)")
        print("  3. Muat Data Sampel Awal (8 Produk Default)")
        print("  4. Keluar dari Toko")
        print("-" * 80)
        pilihan = baca_int("Pilih aksi (1-4): ")
        print()

        if pilihan == 1:
            toko.tampilkanKatalog()
        elif pilihan == 2:
            menu_tambah_produk(toko)
        elif pilihan == 3:
            muat_data_sampel(toko)
        elif pilihan == 4:
            print("=" * 80)
            print("       Terima kasih telah berkunjung ke Toko IZA STORE! Sampai jumpa!           ")
            print("=" * 80)
        else:
            print("[!] Pilihan menu tidak valid. Silakan pilih 1 - 4.\n")

if __name__ == "__main__":
    main()
