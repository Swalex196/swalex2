#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Kitap {
public:
    string baslik;
    string yazar;
    int sayfaSayisi;

    Kitap(const string &baslik, const string &yazar, int sayfaSayisi)
        : baslik(baslik), yazar(yazar), sayfaSayisi(sayfaSayisi) {}
    
    void bilgiYazdir() const {
        cout << "Başlık: " << baslik << ", Yazar: " << yazar << ", Sayfa Sayısı: " << sayfaSayisi << "\n";
    }
};


class Kutuphane {
private:
    vector<Kitap*> kitaplar;

public:
   
    Kutuphane() {}

 
    void kitapEkle(Kitap* kitap) {
        kitaplar.push_back(kitap);
    }

  
    void kitaplariYazdir() const {
        for (const auto& kitap : kitaplar) {
            kitap->bilgiYazdir();
            cout << "------------------\n";
        }
    }

    
    void kitaplariTemizle() {
        for (auto& kitap : kitaplar) {
            delete kitap;
        }
        kitaplar.clear();
    }

    // Yıkıcı (destructor)
    ~Kutuphane() {
        kitaplariTemizle();
    }
};

int main() {
    Kutuphane kutuphane;

    Kitap* kitap1 = new Kitap("Savaş ve Barış", "Lev Tolstoy", 1225);
    Kitap* kitap2 = new Kitap("1984", "George Orwell", 328);
    Kitap* kitap3 = new Kitap("Suç ve Ceza", "Fyodor Dostoyevski", 671);

    kutuphane.kitapEkle(kitap1);
    kutuphane.kitapEkle(kitap2);
    kutuphane.kitapEkle(kitap3);

 
    kutuphane.kitaplariYazdir();  


    return 0;
}
