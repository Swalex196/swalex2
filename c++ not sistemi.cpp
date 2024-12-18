#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Ogrenci {
private:
    string isim;
    int numara;
    vector<int> notlar;

public:
    Ogrenci(const string &isim, int numara) : isim(isim), numara(numara) {}

    void notEkle(int notDegeri) {
        notlar.push_back(notDegeri);
    }

    double ortalamaHesapla() const {
        if (notlar.empty()) {
            return 0.0;
        }
        int toplam = 0;
        for (int notDegeri : notlar) {
            toplam += notDegeri;
        }
        return static_cast<double>(toplam) / notlar.size();
    }

    void bilgiYazdir() const {
        cout << "İsim: " << isim << "\n";
        cout << "Numara: " << numara << "\n";
        cout << "Ortalama Not: " << ortalamaHesapla() << "\n";
    }
};

class OgrenciKayitSistemi {
private:
    vector<Ogrenci*> ogrenciler;

public:
    void ogrenciEkle(Ogrenci* ogrenci) {
        ogrenciler.push_back(ogrenci);
    }

    void tumOgrencileriYazdir() const {
        for (const auto& ogrenci : ogrenciler) {
            ogrenci->bilgiYazdir();
            cout << "------------------\n";
        }
    }

    void temizle() {
        for (auto& ogrenci : ogrenciler) {
            delete ogrenci;
        }
        ogrenciler.clear();
    }

    ~OgrenciKayitSistemi() {
        temizle();
    }
};

int main() {
    OgrenciKayitSistemi kayitSistemi;

    Ogrenci* ogrenci1 = new Ogrenci("Ahmet Yılmaz", 1001);
    Ogrenci* ogrenci2 = new Ogrenci("Ayşe Kaya", 1002);
    Ogrenci* ogrenci3 = new Ogrenci("Mehmet Demir", 1003);

    ogrenci1->notEkle(85);
    ogrenci1->notEkle(90);
    ogrenci1->notEkle(78);

    ogrenci2->notEkle(88);
    ogrenci2->notEkle(92);

    ogrenci3->notEkle(75);
    ogrenci3->notEkle(80);
    ogrenci3->notEkle(83);
    ogrenci3->notEkle(79);

    kayitSistemi.ogrenciEkle(ogrenci1);
    kayitSistemi.ogrenciEkle(ogrenci2);
    kayitSistemi.ogrenciEkle(ogrenci3);

    kayitSistemi.tumOgrencileriYazdir();

    return 0;
}
