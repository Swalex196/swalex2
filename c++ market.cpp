#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Urun {
private:
    string isim;
    double fiyat;

public:
    Urun(const string &isim, double fiyat) : isim(isim), fiyat(fiyat) {}

    string getIsim() const {
        return isim;
    }

    double getFiyat() const {
        return fiyat;
    }

    void bilgiYazdir() const {
        cout << "Ürün: " << isim << ", Fiyat: " << fiyat << " TL" << endl;
    }
};

class Sepet {
private:
    vector<Urun> urunler;

public:
    void urunEkle(const Urun &urun) {
        urunler.push_back(urun);
    }

    void sepetiGoruntule() const {
        if (urunler.empty()) {
            cout << "Sepetiniz boş." << endl;
            return;
        }

        cout << "Sepetinizdeki Ürünler:" << endl;
        for (const auto &urun : urunler) {
            urun.bilgiYazdir();
        }
    }

    double toplamFiyatHesapla() const {
        double toplam = 0.0;
        for (const auto &urun : urunler) {
            toplam += urun.getFiyat();
        }
        return toplam;
    }
};

int main() {
    Sepet sepet;

    Urun urun1("Elma", 3.5);
    Urun urun2("Ekmek", 2.0);
    Urun urun3("Süt", 4.0);
    Urun urun4("Yumurta", 8.0);

    sepet.urunEkle(urun1);
    sepet.urunEkle(urun2);
    sepet.urunEkle(urun3);
    sepet.urunEkle(urun4);

    sepet.sepetiGoruntule();

    double toplamFiyat = sepet.toplamFiyatHesapla();
    cout << "Toplam Fiyat: " << toplamFiyat << " TL" << endl;

    return 0;
}
