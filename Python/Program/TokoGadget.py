# Kelas TokoGadget yang menerapkan konsep Composition (has-a)
# TokoGadget memiliki kumpulan objek Produk yang disimpan dalam bentuk Array of Objects (list)
class TokoGadget:
    def __init__(self, nama_toko="", alamat=""):
        self.__nama_toko = nama_toko
        self.__alamat = alamat
        self.__daftar_produk = []  # Array of Objects (Composition)

    # Getter dan Setter
    def set_nama_toko(self, nama_toko):
        self.__nama_toko = nama_toko

    def get_nama_toko(self):
        return self.__nama_toko

    def set_alamat(self, alamat):
        self.__alamat = alamat

    def get_alamat(self):
        return self.__alamat

    # Menambahkan produk ke dalam daftar
    def tambahProduk(self, produk):
        if produk is not None:
            self.__daftar_produk.append(produk)

    # Alias snake_case untuk konsistensi Python
    def tambah_produk(self, produk):
        self.tambahProduk(produk)

    # Mengembalikan total jumlah produk
    def getJumlahProduk(self):
        return len(self.__daftar_produk)

    def get_jumlah_produk(self):
        return self.getJumlahProduk()

    # Menampilkan katalog produk secara polimorfik
    def tampilkanKatalog(self, label=""):
        print("=" * 80)
        print(f"{self.__nama_toko:^80}")
        print(f"{self.__alamat:^80}")
        print("=" * 80)
        print(f" KATALOG PRODUK [{label}] (Jumlah: {len(self.__daftar_produk)} Produk)")
        print("=" * 80)

        if len(self.__daftar_produk) == 0:
            print(" [!] Katalog produk toko saat ini masih kosong (0 Produk).")
            print("     Silakan gunakan menu [2] Tambah Produk atau [3] Muat Data Sampel.")
        else:
            for i, produk in enumerate(self.__daftar_produk):
                print(f"[{i + 1}]")
                # Pemanggilan dinamis murni polimorfisme tanpa pengecekan tipe if-else
                produk.display_info()
                if i < len(self.__daftar_produk) - 1:
                    print("-" * 80)

        print("=" * 80)
        print()

    def tampilkan_katalog(self, label=""):
        self.tampilkanKatalog(label)
