#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// BankaHesabi sınıfı
class BankaHesabi {
private:
    string hesapNumarasi;
    double bakiye;
    string sahipAdi;

public:
    // Kurucu fonksiyon
    BankaHesabi(string sahip, string hesapNum, double ilkBakiye) {
        hesapNumarasi = hesapNum;
        bakiye = ilkBakiye;
        sahipAdi = sahip;
    }

    // Para yatırma fonksiyonu
    void paraYatir(double miktar) {
        bakiye += miktar;
        cout << "Yatirilan miktar: " << miktar << " TL. Yeni bakiye: " << bakiye << " TL." << endl;
    }

    // Para çekme fonksiyonu
    bool paraCek(double miktar) {
        if (bakiye >= miktar) {
            bakiye -= miktar;
            cout << "Cekilen miktar: " << miktar << " TL. Yeni bakiye: " << bakiye << " TL." << endl;
            return true;
        } else {
            cout << "Yetersiz bakiye. Cekme islemi basarisiz." << endl;
            return false;
        }
    }

    // Hesap bilgilerini gösterme fonksiyonu
    void hesapBilgileriniGoster() const {
        cout << "Sahip: " << sahipAdi << endl;
        cout << "Hesap Numarasi: " << hesapNumarasi << endl;
        cout << "Bakiye: " << bakiye << " TL." << endl;
    }

    // Sahip adı getter fonksiyonu
    string getSahipAdi() const {
        return sahipAdi;
    }

    // Hesap numarası getter fonksiyonu
    string getHesapNumarasi() const {
        return hesapNumarasi;
    }
};

// BankaGorevlisi sınıfı
class BankaGorevlisi {
public:
    // İşlem yapma fonksiyonu
    void islemYap(BankaHesabi& hesap, char islemTuru, double miktar) {
        if (islemTuru == 'y') {
            hesap.paraYatir(miktar);
        } else if (islemTuru == 'c') {
            hesap.paraCek(miktar);
        } else {
            cout << "Gecersiz islem turu." << endl;
        }
    }
};

// Ana fonksiyon
int main() {
    vector<BankaHesabi> hesaplar;
    BankaGorevlisi gorevli;

    char secim;
    do {
        cout << "Yeni bir hesap eklemek istiyor musunuz? (E/H): ";
        cin >> secim;

        if (secim == 'E' || secim == 'e') {
            string ad, soyad;
            cout << "Adinizi girin: ";
            cin >> ad;
            cout << "Soyadinizi girin: ";
            cin >> soyad;

            string tamAd = ad + " " + soyad;
            string hesapNumarasi = "HSP001";

            // Yeni hesap oluşturma
            BankaHesabi yeniHesap(tamAd, hesapNumarasi, 0.0);
            hesaplar.push_back(yeniHesap);

            cout << "Hesap basariyla olusturuldu." << endl;

            continue;
        }

        do {
            cout << "Islem yapmak icin bir hesap secin:" << endl;
            for (int i = 0; i < hesaplar.size(); ++i) {
                cout << i << ". ";
                hesaplar[i].hesapBilgileriniGoster();
            }

            cout << "Islem yapmak istediginiz hesabin endeksini girin: ";
            string girilenEndeks;
            cin >> girilenEndeks;

            int endeks;
            stringstream(girilenEndeks) >> endeks;

            if (endeks < 0 || endeks >= hesaplar.size()) {
                cout << "Gecersiz endeks. Lutfen gecerli bir endeks girin." << endl;
                continue;
            }

            BankaHesabi& hesap = hesaplar[endeks];

            cout << "Islem turunu girin (Y para yatirma, C para cekme): ";
            char islemTuru;
            cin >> islemTuru;
            islemTuru = tolower(islemTuru);

            if (islemTuru != 'y' && islemTuru != 'c') {
                cout << "Gecersiz islem turu." << endl;
                continue;
            }

            double miktar;
            cout << "Miktari girin: ";
            cin >> miktar;
bu 
            // İşlem yapma
            gorevli.islemYap(hesap, islemTuru, miktar);
            hesap.hesapBilgileriniGoster();

            cout << "Baska bir islem yapmak istiyor musunuz? (E/H): ";
            cin >> secim;
        } while (secim == 'E' || secim == 'e');

        cout << "Yeni bir hesap eklemek istiyor musunuz? (E/H): ";
        cin >> secim;
    } while (secim == 'E' || secim == 'e');

    return 0;
}
