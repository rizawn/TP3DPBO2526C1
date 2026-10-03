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

    // Override getCardLines (Polimorfisme murni untuk kartu 2 kolom)
    vector<string> getCardLines(int nomorUrut) const override {
        return formatCardLines(nomorUrut, "Periferal", "Koneksi: " + koneksi, "Fitur: " + tipeFitur);
    }

    // Override displayInfo (Polimorfisme murni)
    void displayInfo() const override {
        vector<string> lines = getCardLines(1);
        for (const string& line : lines) {
            cout << line << endl;
        }
    }
};

#endif