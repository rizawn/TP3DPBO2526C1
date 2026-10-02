from Produk import Produk

# Kelas turunan untuk periferal desktop (Hierarchical Inheritance)
class Periferal(Produk):
    def __init__(self, id_produk="", nama="", brand="", harga=0.0, stok=0, koneksi="", tipe_fitur=""):
        # Memanggil konstruktor superclass
        super().__init__(id_produk, nama, brand, harga, stok)
        self.__koneksi = koneksi
        self.__tipe_fitur = tipe_fitur

    # Getter dan Setter
    def set_koneksi(self, koneksi):
        self.__koneksi = koneksi

    def get_koneksi(self):
        return self.__koneksi

    def set_tipe_fitur(self, tipe_fitur):
        self.__tipe_fitur = tipe_fitur

    def get_tipe_fitur(self):
        return self.__tipe_fitur

    # Override display_info (Polimorfisme)
    def display_info(self):
        print(f"  ID Produk   : {self.get_id()}")
        print(f"  Kategori    : Periferal")
        print(f"  Nama Produk : {self.get_nama()}")
        print(f"  Brand       : {self.get_brand()}")
        print(f"  Harga       : {self.format_rupiah(self.get_harga())}")
        print(f"  Stok        : {self.get_stok()} unit")
        print(f"  Spesifikasi : Koneksi: {self.__koneksi} | Fitur: {self.__tipe_fitur}")
