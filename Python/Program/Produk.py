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

    def _pad_trunc(self, text, target_len):
        if len(text) > target_len:
            if target_len > 3:
                return text[:target_len - 3] + "..."
            return text[:target_len]
        return text.ljust(target_len)

    def _format_card_row(self, text):
        return f"| {self._pad_trunc(text, 35)} |"

    def format_card_lines(self, nomor_urut, kategori, spek1, spek2):
        sep = "+" + "-" * 37 + "+"
        return [
            sep,
            self._format_card_row(f"[{nomor_urut}] {self.__nama}"),
            sep,
            self._format_card_row(f"ID Produk   : {self.__id}"),
            self._format_card_row(f"Kategori    : {kategori}"),
            self._format_card_row(f"Brand       : {self.__brand}"),
            self._format_card_row(f"Harga       : {self.format_rupiah(self.__harga)}"),
            self._format_card_row(f"Stok        : {self.__stok} unit"),
            self._format_card_row(f"Spesifikasi : {spek1}"),
            self._format_card_row(f"              {spek2}"),
            sep
        ]

    # Method polimorfik murni untuk menghasilkan baris-baris kartu produk
    def get_card_lines(self, nomor_urut):
        raise NotImplementedError("Subclass wajib mengimplementasikan method get_card_lines()")

    # Method display_info yang dioverride oleh kelas-kelas turunan (Polimorfisme)
    def display_info(self):
        for line in self.get_card_lines(1):
            print(line)

