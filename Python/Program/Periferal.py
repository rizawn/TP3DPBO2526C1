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

    # Override get_card_lines (Polimorfisme murni untuk kartu 2 kolom)
    def get_card_lines(self, nomor_urut):
        return self.format_card_lines(nomor_urut, "Periferal", f"Koneksi: {self.__koneksi}", f"Fitur: {self.__tipe_fitur}")

    # Override display_info (Polimorfisme murni)
    def display_info(self):
        for line in self.get_card_lines(1):
            print(line)

