# Kelas induk (Superclass) yang merepresentasikan Produk secara umum
class Produk:
    def __init__(self, id_produk="", nama="", brand="", harga=0.0, stok=0):
        # Atribut private dengan enkapsulasi (__prefix)
        self.__id = id_produk
        self.__nama = nama
        self.__brand = brand
        self.__harga = float(harga)
        self.__stok = int(stok)

    # Helper untuk format nominal ke mata uang Rupiah (contoh: Rp 8.499.000)
    def format_rupiah(self, nilai):
        nominal = int(nilai)
        formatted = f"{nominal:,}".replace(",", ".")
        return f"Rp {formatted}"

    # Getter dan Setter
    def set_id(self, id_produk):
        self.__id = id_produk

    def get_id(self):
        return self.__id

    def set_nama(self, nama):
        self.__nama = nama

    def get_nama(self):
        return self.__nama

    def set_brand(self, brand):
        self.__brand = brand

    def get_brand(self):
        return self.__brand

    def set_harga(self, harga):
        self.__harga = float(harga)

    def get_harga(self):
        return self.__harga

    def set_stok(self, stok):
        self.__stok = int(stok)

    def get_stok(self):
        return self.__stok

    # Method display_info yang akan dioverride oleh kelas-kelas turunan (Polimorfisme)
    def display_info(self):
        raise NotImplementedError("Subclass wajib mengimplementasikan method display_info()")
