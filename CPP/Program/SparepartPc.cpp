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

    // Override getCardLines (Polimorfisme murni untuk kartu 2 kolom)
    vector<string> getCardLines(int nomorUrut) const override {
        return formatCardLines(nomorUrut, "SparepartPc", "Daya: " + to_string(dayaWatt) + " W", "Form: " + formFactor);
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
