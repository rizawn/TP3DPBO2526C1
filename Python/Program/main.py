from TokoGadget import TokoGadget
from SparepartPc import SparepartPc
from SparepartLaptop import SparepartLaptop
from Periferal import Periferal
from GamingFurniture import GamingFurniture

def main():
    # 1. Inisialisasi objek TokoGadget
    toko = TokoGadget("Gadget & Gaming Rig Hub", "Jl. Merdeka No. 45, Bandung")

    # 2. Memasukkan 8 data seed awal
    toko.tambahProduk(SparepartPc("PC-001", "RTX 4070 Gaming OC", "NVIDIA", 8499000, 5, 200, "PCIe x16"))
    toko.tambahProduk(SparepartPc("PC-002", "Ryzen 7 5800X", "AMD", 3850000, 8, 105, "AM4"))
    toko.tambahProduk(SparepartLaptop("LP-001", "RAM SODIMM 16GB DDR4 3200", "Kingston", 899000, 15, "DDR4 SODIMM", 24))
    toko.tambahProduk(SparepartLaptop("LP-002", "Baterai Laptop 6-Cell", "Dell", 850000, 7, "6-Cell 11.4V", 12))
    toko.tambahProduk(Periferal("PF-001", "Keyboard Mechanical K68", "Logitech", 1100000, 12, "Wired", "RGB Switch"))
    toko.tambahProduk(Periferal("PF-002", "Mouse G502 X Plus", "Logitech", 1299000, 20, "Wireless", "25.600 DPI"))
    toko.tambahProduk(GamingFurniture("GF-001", "Kursi Gaming Ergonomis", "ROG", 2500000, 4, "Mesh + Foam", 150))
    toko.tambahProduk(GamingFurniture("GF-002", "Meja Gaming Elektrik", "Secretlab", 4200000, 3, "Steel + MDF", 100))

    # 3. Menampilkan katalog SEBELUM penambahan
    toko.tampilkanKatalog("SEBELUM PENAMBAHAN")

    # Notifikasi penambahan data
    print(">> Menambahkan 3 produk baru ke inventaris toko...\n")

    # 4. Menambahkan 3 data produk baru
    toko.tambahProduk(SparepartPc("PC-003", "PSU RM850x 80+ Gold", "Corsair", 1750000, 6, 850, "ATX"))
    toko.tambahProduk(Periferal("PF-003", "Headset Cloud Stinger 2", "HyperX", 599000, 18, "Wired", "Surround 7.1"))
    toko.tambahProduk(GamingFurniture("GF-003", "Monitor Stand Riser", "Razer", 650000, 9, "Aluminium", 20))

    # 5. Menampilkan katalog SESUDAH penambahan
    toko.tampilkanKatalog("SESUDAH PENAMBAHAN")

if __name__ == "__main__":
    main()
