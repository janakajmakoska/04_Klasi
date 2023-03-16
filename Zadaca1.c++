#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Datum {
private:
    int den, mesec, godina;

public:
    Datum(int d, int m, int g) : den(d), mesec(m), godina(g) {}

    void prikazi_datum() {
        cout << den << "." << mesec << "." << godina << endl;
    }
};

class Zivotno {
private:
    Datum datum_na_ragjanje, datum_na_donesuvawe_vo_zoo, datum_na_posledna_vakcinacija;
    char tip, pol;
    string ime;

public:
    Zivotno(Datum datum_ragjanje, Datum datum_donesuvanje, char tip_zivotno, char pol_zivotno, string ime_zivotno)
        : datum_na_ragjanje(datum_ragjanje), datum_na_donesuvawe_vo_zoo(datum_donesuvanje), tip(tip_zivotno), pol(pol_zivotno), ime(ime_zivotno) {}

    void prikazi_podatoci() {
        cout << "Tip: " << tip << endl;
        cout << "Pol: " << pol << endl;
        cout << "Ime: " << ime << endl;
        cout << "Datum na ragjanje: ";
        datum_na_ragjanje.prikazi_datum();
        cout << "Datum na donesuvanje vo zoo: ";
        datum_na_donesuvawe_vo_zoo.prikazi_datum();
        if (datum_na_posledna_vakcinacija) {
            cout << "Datum na posledna vakcinacija: ";
            datum_na_posledna_vakcinacija.prikazi_datum();
        }
    }

    bool treba_da_se_vakcinira() {
        time_t now = time(nullptr);
        tm* time_now = localtime(&now);

        int meseci_posledna_vakcinacija = (time_now->tm_year - datum_na_posledna_vakcinacija.godina) * 12 + (time_now->tm_mon - datum_na_posledna_vakcinacija.mesec);
        if (tip == 'c' && meseci_posledna_vakcinacija >= 12) {
            return true;
        }
        else if (tip == 'p' && meseci_posledna_vakcinacija >= 6) {
            return true;
        }
        else if (tip == 'v' && meseci_posledna_vakcinacija >= 8) {
            return true;
        }
        return false;
    }

    void vakciniraj() {
        time_t now = time(nullptr);
        tm* time_now = localtime(&now);
        datum_na_posledna_vakcinacija = Datum(time_now->tm_mday, time_now->tm_mon + 1, time_now->tm_year + 1900);
    }

    char get_tip() {
        return tip;
    }
};

vector<Zivotno> zivotni;

void dodadi_z
