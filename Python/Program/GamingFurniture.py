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

    # Override display_info (Polimorfisme)
    def display_info(self):
        print(f"  ID Produk   : {self.get_id()}")
        print(f"  Kategori    : GamingFurniture")
        print(f"  Nama Produk : {self.get_nama()}")
        print(f"  Brand       : {self.get_brand()}")
        print(f"  Harga       : {self.format_rupiah(self.get_harga())}")
        print(f"  Stok        : {self.get_stok()} unit")
        print(f"  Spesifikasi : Material: {self.__material} | Beban Maks: {int(self.__beban_maks_kg)} kg")
