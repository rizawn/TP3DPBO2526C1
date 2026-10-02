#ifndef PRODUK_CPP
#define PRODUK_CPP

#include <iostream>
#include <string>

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

    // Method displayInfo yang akan dioverride oleh semua kelas turunan (Polimorfisme murni)
    virtual void displayInfo() const = 0;
};

#endif
