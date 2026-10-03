#ifndef GAMING_FURNITURE_CPP
#define GAMING_FURNITURE_CPP

#include <iostream>
#include <string>
#include "Produk.cpp"

using namespace std;

// Kelas turunan untuk meja dan kursi gaming (Hierarchical Inheritance)
class GamingFurniture : public Produk {
private:
    string material;
    double bebanMaksKg;

public:
    // Constructor default
    GamingFurniture() : Produk() {
        this->material = "";
        this->bebanMaksKg = 0.0;
    }

    // Constructor berparameter
    GamingFurniture(string id, string nama, string brand, double harga, int stok, string material, double bebanMaksKg)
        : Produk(id, nama, brand, harga, stok) {
        this->material = material;
        this->bebanMaksKg = bebanMaksKg;
    }

    // Destructor
    virtual ~GamingFurniture() {}

    // Getter dan Setter
    void setMaterial(string material) {
        this->material = material;
    }

    string getMaterial() const {
        return this->material;
    }

    void setBebanMaksKg(double bebanMaksKg) {
        this->bebanMaksKg = bebanMaksKg;
    }

    double getBebanMaksKg() const {
        return this->bebanMaksKg;
    }

    // Override getCardLines (Polimorfisme murni untuk kartu 2 kolom)
    vector<string> getCardLines(int nomorUrut) const override {
        return formatCardLines(nomorUrut, "GamingFurniture", "Bahan: " + material, "Beban Maks: " + to_string(static_cast<long long>(bebanMaksKg)) + " kg");
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
