#pragma once
#ifndef PERIFERAL_CPP
#define PERIFERAL_CPP

#include <iostream>
#include <string>
#include "Produk.cpp"

using namespace std;

// Kelas turunan untuk periferal desktop (Hierarchical Inheritance)
class Periferal : public Produk {
private:
    string koneksi;
    string tipeFitur;

public:
    // Constructor default
    Periferal() : Produk() {
        this->koneksi = "";
        this->tipeFitur = "";
    }

    // Constructor berparameter
    Periferal(string id, string nama, string brand, double harga, int stok, string koneksi, string tipeFitur)
        : Produk(id, nama, brand, harga, stok) {
        this->koneksi = koneksi;
        this->tipeFitur = tipeFitur;
    }

    // Destructor
    virtual ~Periferal() {}

    // Getter dan Setter
    void setKoneksi(string koneksi) {
        this->koneksi = koneksi;
    }

    string getKoneksi() const {
        return this->koneksi;
    }

    void setTipeFitur(string tipeFitur) {
        this->tipeFitur = tipeFitur;
    }

    string getTipeFitur() const {
        return this->tipeFitur;
    }

    // Override displayInfo (Polimorfisme)
    void displayInfo() const override {
        cout << "  ID Produk   : " << id << endl;
        cout << "  Kategori    : Periferal" << endl;
        cout << "  Nama Produk : " << nama << endl;
        cout << "  Brand       : " << brand << endl;
        cout << "  Harga       : " << formatRupiah(harga) << endl;
        cout << "  Stok        : " << stok << " unit" << endl;
        cout << "  Spesifikasi : Koneksi: " << koneksi << " | Fitur: " << tipeFitur << endl;
    }
};

#endif
