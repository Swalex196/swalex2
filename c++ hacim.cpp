class Kutu {
public:
    double uzunluk; // Kutunun uzunluğu
    double genislik; // Kutunun genişliği
    double yukseklik; // Kutunun yüksekliği
    double getHacim(void);
    void uzunluguAyarla(double uz);
    void genisliginiAyarla(double gen);
    void yuksekliginiAyarla(double yuk);
};

void Kutu::uzunluguAyarla(double uz) {
    uzunluk = uz;
}

void Kutu::genisliginiAyarla(double gen) {
    genislik = gen;
}

void Kutu::yuksekliginiAyarla(double yuk) {
    yukseklik = yuk;
}

double Kutu::getHacim(void) {
    return uzunluk * genislik * yukseklik;
}

int main() {
    Kutu kutu1;
    Kutu kutu2;
    double hacim, hacim1;
    
    // Kutu 1 Özellikleri Girilme Yeri
    kutu1.yuksekliginiAyarla(5.0);
    kutu1.genisliginiAyarla(7.0);
    kutu1.uzunluguAyarla(6.0);
    
    // Kutu 2 Özellikleri Girilme Yeri
    kutu2.yuksekliginiAyarla(12.0);
    kutu2.genisliginiAyarla(13.0);
    kutu2.uzunluguAyarla(10.0);
    
    // Kutu1 için hacim bul
    hacim = kutu1.getHacim();
    cout << "Kutu1'in Hacmi = " << hacim << endl;
    
    // Kutu2 için hacim bul
    hacim1 = kutu2.getHacim();
    cout << "Kutu2'nin Hacmi = " << hacim1 << endl;
    
    return 0;
}
