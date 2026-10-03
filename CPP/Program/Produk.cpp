#ifndef PRODUK_CPP
#define PRODUK_CPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Kelas induk (Superclass) yang merepresentasikan produk secara umum
class Produk {
protected:
    string id;
    string nama;
    string brand;
    double harga;
    int stok;

    // Helper untuk memformat angka harga ke format Rupiah (contoh: Rp 8.499.000)
    string formatRupiah(double nilai) const {
        long long nominal = static_cast<long long>(nilai);
        string s = to_string(nominal);
        int n = s.length();
        string hasil = "";
        int hitung = 0;

        for (int i = n - 1; i >= 0; i--) {
            hasil = s[i] + hasil;
            hitung++;
            if (hitung % 3 == 0 && i != 0) {
                hasil = "." + hasil;
            }
        }
        return "Rp " + hasil;
    }

    // Helper untuk memotong atau melengkapi string ke panjang tepat N karakter
    string padTrunc(const string& text, size_t targetLen) const {
        if (text.length() > targetLen) {
            if (targetLen > 3) {
                return text.substr(0, targetLen - 3) + "...";
            }
            return text.substr(0, targetLen);
        }
        return text + string(targetLen - text.length(), ' ');
    }

    // Helper membuat satu baris kartu dengan border vertikal
    string formatCardRow(const string& text) const {
        return "| " + padTrunc(text, 35) + " |";
    }

    // Helper pembentuk kumpulan baris kartu 39-karakter
    vector<string> formatCardLines(int nomorUrut, const string& kategori, const string& spek1, const string& spek2) const {
        string sep = "+" + string(37, '-') + "+";
        vector<string> lines;
        lines.push_back(sep);
        lines.push_back(formatCardRow("[" + to_string(nomorUrut) + "] " + nama));
        lines.push_back(sep);
        lines.push_back(formatCardRow("ID Produk   : " + id));
        lines.push_back(formatCardRow("Kategori    : " + kategori));
        lines.push_back(formatCardRow("Brand       : " + brand));
        lines.push_back(formatCardRow("Harga       : " + formatRupiah(harga)));
        lines.push_back(formatCardRow("Stok        : " + to_string(stok) + " unit"));
        lines.push_back(formatCardRow("Spesifikasi : " + spek1));
        lines.push_back(formatCardRow("              " + spek2));
        lines.push_back(sep);
        return lines;
    }

public:
    // Constructor default
    Produk() {
        this->id = "";
        this->nama = "";
        this->brand = "";
        this->harga = 0.0;
        this->stok = 0;
    }

    // Constructor berparameter
    Produk(string id, string nama, string brand, double harga, int stok) {
        this->id = id;
        this->nama = nama;
        this->brand = brand;
        this->harga = harga;
        this->stok = stok;
    }

    // Destructor virtual
    virtual ~Produk() {}

    // Getter dan Setter
    void setId(string id) {
        this->id = id;
    }

    string getId() const {
        return this->id;
    }

    void setNama(string nama) {
        this->nama = nama;
    }

    string getNama() const {
        return this->nama;
    }

    void setBrand(string brand) {
        this->brand = brand;
    }

    string getBrand() const {
        return this->brand;
    }

    void setHarga(double harga) {
        this->harga = harga;
    }

    double getHarga() const {
        return this->harga;
    }

    void setStok(int stok) {
        this->stok = stok;
    }

    int getStok() const {
        return this->stok;
    }

    // Method polimorfik murni untuk menghasilkan baris-baris kartu produk
    virtual vector<string> getCardLines(int nomorUrut) const = 0;

    // Method displayInfo yang dioverride oleh semua kelas turunan (Polimorfisme murni)
    virtual void displayInfo() const = 0;
};

#endif
