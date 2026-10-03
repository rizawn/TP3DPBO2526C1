from Produk import Produk

# Kelas turunan untuk meja dan kursi gaming (Hierarchical Inheritance)
class GamingFurniture(Produk):
    def __init__(self, id_produk="", nama="", brand="", harga=0.0, stok=0, material="", beban_maks_kg=0.0):
        # Memanggil konstruktor superclass
        super().__init__(id_produk, nama, brand, harga, stok)
        self.__material = material
        self.__beban_maks_kg = float(beban_maks_kg)

    # Getter dan Setter
    def set_material(self, material):
        self.__material = material

    def get_material(self):
        return self.__material

    def set_beban_maks_kg(self, beban_maks_kg):
        self.__beban_maks_kg = float(beban_maks_kg)

    def get_beban_maks_kg(self):
        return self.__beban_maks_kg

    # Override get_card_lines (Polimorfisme murni untuk kartu 2 kolom)
    def get_card_lines(self, nomor_urut):
        return self.format_card_lines(nomor_urut, "GamingFurniture", f"Bahan: {self.__material}", f"Beban Maks: {int(self.__beban_maks_kg)} kg")

    # Override display_info (Polimorfisme murni)
    def display_info(self):
        for line in self.get_card_lines(1):
            print(line)

