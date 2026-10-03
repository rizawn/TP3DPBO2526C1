#ifndef SPAREPART_LAPTOP_CPP
#define SPAREPART_LAPTOP_CPP

#include <iostream>
#include <string>
#include "Produk.cpp"

using namespace std;

// Kelas turunan untuk komponen / suku cadang Laptop (Hierarchical Inheritance)
class SparepartLaptop : public Produk {
private:
    string tipeKompatibel;
    int garansiBulan;

public:
    // Constructor default
    SparepartLaptop() : Produk() {
        this->tipeKompatibel = "";
        this->garansiBulan = 0;
    }

    // Constructor berparameter
    SparepartLaptop(string id, string nama, string brand, double harga, int stok, string tipeKompatibel, int garansiBulan)
        : Produk(id, nama, brand, harga, stok) {
        this->tipeKompatibel = tipeKompatibel;
        this->garansiBulan = garansiBulan;
    }

    // Destructor
    virtual ~SparepartLaptop() {}

    // Getter dan Setter
    void setTipeKompatibel(string tipeKompatibel) {
        this->tipeKompatibel = tipeKompatibel;
    }

    string getTipeKompatibel() const {
        return this->tipeKompatibel;
    }

    void setGaransiBulan(int garansiBulan) {
        this->garansiBulan = garansiBulan;
    }

    int getGaransiBulan() const {
        return this->garansiBulan;
    }

    // Override getCardLines (Polimorfisme murni untuk kartu 2 kolom)
    vector<string> getCardLines(int nomorUrut) const override {
        return formatCardLines(nomorUrut, "SparepartLaptop", "Modul: " + tipeKompatibel, "Garansi: " + to_string(garansiBulan) + " bln");
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
