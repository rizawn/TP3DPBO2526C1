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

    # Menampilkan katalog produk secara polimorfik (2 kotak kesamping)
    def tampilkanKatalog(self, label=""):
        print("=" * 80)
        print(f"{self.__nama_toko:^80}")
        print(f"{self.__alamat:^80}")
        print("=" * 80)

        if len(self.__daftar_produk) == 0:
            print(f"{'KATALOG PRODUK (Katalog masih kosong!)':^80}")
            print("=" * 80)
            print(" [!] Katalog masih kosong! (Belum ada produk).")
            print("     Silakan gunakan menu [2] Tambah Produk atau [3] Muat Data Sampel Awal.")
        else:
            header_count = f"KATALOG PRODUK ({len(self.__daftar_produk)} Produk)"
            if len(self.__daftar_produk) == 1:
                header_count = "KATALOG PRODUK (1 Produk)"
            print(f"{header_count:^80}")
            print("=" * 80)

            for i in range(0, len(self.__daftar_produk), 2):
                card1 = self.__daftar_produk[i].get_card_lines(i + 1)
                has_second = (i + 1 < len(self.__daftar_produk))
                card2 = self.__daftar_produk[i + 1].get_card_lines(i + 2) if has_second else None

                for line_idx in range(len(card1)):
                    if card2:
                        print(f"{card1[line_idx]}  {card2[line_idx]}")
                    else:
                        print(card1[line_idx])
                if i + 2 < len(self.__daftar_produk):
                    print()

        print("=" * 80)
        print()

    def tampilkan_katalog(self, label=""):
        self.tampilkanKatalog(label)

