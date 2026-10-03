from Produk import Produk

# Kelas turunan untuk komponen PC Desktop (Hierarchical Inheritance)
class SparepartPc(Produk):
    def __init__(self, id_produk="", nama="", brand="", harga=0.0, stok=0, daya_watt=0, form_factor=""):
        # Memanggil konstruktor superclass
        super().__init__(id_produk, nama, brand, harga, stok)
        self.__daya_watt = int(daya_watt)
        self.__form_factor = form_factor

    # Getter dan Setter
    def set_daya_watt(self, daya_watt):
        self.__daya_watt = int(daya_watt)

    def get_daya_watt(self):
        return self.__daya_watt

    def set_form_factor(self, form_factor):
        self.__form_factor = form_factor

    def get_form_factor(self):
        return self.__form_factor

    # Override get_card_lines (Polimorfisme murni untuk kartu 2 kolom)
    def get_card_lines(self, nomor_urut):
        return self.format_card_lines(nomor_urut, "SparepartPc", f"Daya: {self.__daya_watt} W", f"Form: {self.__form_factor}")

    # Override display_info (Polimorfisme murni)
    def display_info(self):
        for line in self.get_card_lines(1):
            print(line)

