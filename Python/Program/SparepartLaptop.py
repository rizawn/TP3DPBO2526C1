from Produk import Produk

# Kelas turunan untuk komponen Laptop (Hierarchical Inheritance)
class SparepartLaptop(Produk):
    def __init__(self, id_produk="", nama="", brand="", harga=0.0, stok=0, tipe_kompatibel="", garansi_bulan=0):
        # Memanggil konstruktor superclass
        super().__init__(id_produk, nama, brand, harga, stok)
        self.__tipe_kompatibel = tipe_kompatibel
        self.__garansi_bulan = int(garansi_bulan)

    # Getter dan Setter
    def set_tipe_kompatibel(self, tipe_kompatibel):
        self.__tipe_kompatibel = tipe_kompatibel

    def get_tipe_kompatibel(self):
        return self.__tipe_kompatibel

    def set_garansi_bulan(self, garansi_bulan):
        self.__garansi_bulan = int(garansi_bulan)

    def get_garansi_bulan(self):
        return self.__garansi_bulan

    # Override get_card_lines (Polimorfisme murni untuk kartu 2 kolom)
    def get_card_lines(self, nomor_urut):
        return self.format_card_lines(nomor_urut, "SparepartLaptop", f"Modul: {self.__tipe_kompatibel}", f"Garansi: {self.__garansi_bulan} bln")

    # Override display_info (Polimorfisme murni)
    def display_info(self):
        for line in self.get_card_lines(1):
            print(line)

