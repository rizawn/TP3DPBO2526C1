#pragma once
#ifndef SPAREPART_PC_CPP
#define SPAREPART_PC_CPP

#include <iostream>
#include <string>
#include "Produk.cpp"

using namespace std;

// Kelas turunan untuk komponen / suku cadang PC Desktop (Hierarchical Inheritance)
class SparepartPc : public Produk {
private:
    int dayaWatt;
    string formFactor;

public:
    // Constructor default
    SparepartPc() : Produk() {
        this->dayaWatt = 0;
        this->formFactor = "";
    }

    // Constructor berparameter
    SparepartPc(string id, string nama, string brand, double harga, int stok, int dayaWatt, string formFactor)
        : Produk(id, nama, brand, harga, stok) {
        this->dayaWatt = dayaWatt;
        this->formFactor = formFactor;
    }

    // Destructor
    virtual ~SparepartPc() {}

    // Getter dan Setter
    void setDayaWatt(int dayaWatt) {
        this->dayaWatt = dayaWatt;
    }

    int getDayaWatt() const {
        return this->dayaWatt;
    }

    void setFormFactor(string formFactor) {
        this->formFactor = formFactor;
    }

    string getFormFactor() const {
        return this->formFactor;
    }

    // Override displayInfo (Polimorfisme)
    void displayInfo() const override {
        cout << "  ID Produk   : " << id << endl;
        cout << "  Kategori    : SparepartPc" << endl;
        cout << "  Nama Produk : " << nama << endl;
        cout << "  Brand       : " << brand << endl;
        cout << "  Harga       : " << formatRupiah(harga) << endl;
        cout << "  Stok        : " << stok << " unit" << endl;
        cout << "  Spesifikasi : Daya: " << dayaWatt << " W | Form Factor: " << formFactor << endl;
    }
};

#endif
