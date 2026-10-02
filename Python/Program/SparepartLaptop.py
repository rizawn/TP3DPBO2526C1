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

    # Override display_info (Polimorfisme)
    def display_info(self):
        print(f"  ID Produk   : {self.get_id()}")
        print(f"  Kategori    : SparepartLaptop")
        print(f"  Nama Produk : {self.get_nama()}")
        print(f"  Brand       : {self.get_brand()}")
        print(f"  Harga       : {self.format_rupiah(self.get_harga())}")
        print(f"  Stok        : {self.get_stok()} unit")
        print(f"  Spesifikasi : Kompatibilitas: {self.__tipe_kompatibel} | Garansi: {self.__garansi_bulan} bln")
