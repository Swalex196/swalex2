#include <iostream>
using namespace std;

class Kutu {
public:
    double uzunluk;
    void genislikAyarla(double gen);
    double genislikGetir();
private:
    double genislik;
};

void Kutu::genislikAyarla(double gen) {
    genislik = gen;
}

double Kutu::genislikGetir() {
    return genislik;
}

int main() {
    Kutu kutu;
    kutu.uzunluk = 10.0;
    cout << "Kutunun Uzunlugu: " << kutu.uzunluk << endl;
    kutu.genislikAyarla(15.0);
    cout << "Kutunun Genisligi: " << kutu.genislikGetir() << endl;
    return 0;
}
