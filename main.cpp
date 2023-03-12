#include <iostream>
#include <list>

using namespace std;

const int m = 10; // max pomiar


void dodajmacierz(int mat[][m], int wiersz, int kolumna) {
    cout << "Podaj elemienty macierzy " << wiersz << "x" << kolumna << ":\n";
    for (int i = 0; i < wiersz; i++) {
        for (int j = 0; j < kolumna; j++) {
            //cin >> mat[i][j];
            omt:
            string s1;
            cin >> s1;
            for (int i = 0; i < s1.length(); i++){
                if (((int(s1[i]) > 57) || (int(s1[i]) < 48)) && (int(s1[i]) != 45)){
                    cout << "Podane bledne dane!" << endl;
                    goto omt;
                }
            }
            mat[i][j] = stoi(s1);
        }
    }
}

void wypiszmacirz(int mat[][m], int wiersz, int kolumna) {
    cout << "Macierz "<< wiersz << "x" << kolumna << ":\n";
    for (int i = 0; i < wiersz; i++) {
        for (int j = 0; j < kolumna; j++) {
            cout <<"["<< mat[i][j] <<"]"<< "\t";
        }
        cout << endl;
    }
    //wypisz_macierz_z_listy(macierz_to_list(mat[][m], wiersz, kolumna),wiersz,kolumna);
}

void wypisz_macierz_z_listy(list <int> list_mat, int wiersz, int kolumna){
    cout << "Macierz "<< wiersz << "x" << kolumna << ":\n";
    for (int i = 0; i < wiersz; i++) {
        for (int j = 0; j < kolumna; j++) {
            cout <<"["<< list_mat.front() <<"]"<< "\t";
            list_mat.pop_front();
        }
        cout << endl;
    }
}

list <int> macierz_to_list(int mat[][m], int wiersz, int kolumna){
    list <int> list_mat;
    for (int i = 0; i < wiersz; i++) {
        for (int j = 0; j < kolumna; j++) {
            list_mat.push_back(mat[i][j]);
        }
    }
    return list_mat;
}

void dodawanie(int a[][m], int b[][m], int c[][m], int wiersz, int kolumna) {
    for (int i = 0; i < wiersz; i++) {
        for (int j = 0; j < kolumna; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void odejmowanie(int a[][m], int b[][m], int c[][m], int wiersz, int kolumna) {
    for (int i = 0; i < wiersz; i++) {
        for (int j = 0; j < kolumna; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void mnorzenie(int a[][m], int b[][m], int c[][m], int wierszA, int kolumnaA, int kolumnaB) {
    for (int i = 0; i < wierszA; i++) {
        for (int j = 0; j < kolumnaB; j++) {
            c[i][j] = 0;
            for (int k = 0; k < kolumnaA; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transponowanie(int a[][m], int c[][m], int wiersz, int kolumna) {
    for (int i = 0; i < wiersz; i++) {
        for (int j = 0; j < kolumna; j++) {
            c[i][j] = a[j][i];
        }
    }
}

string podaj_numer(){
    string f1;
    powtorz:
    cout<<"Dla +,-,* nacisnij - 1"<<endl;
    cout<<"Dla transponowania nacisnij - 2"<<endl;

    cin>>f1;


    if ((f1 != "1") and (f1 != "2")) {
        cout << "Podales niepoprawne dane, wprowadz liczbe w przedziale [1,2]" << endl;
        goto powtorz;
    }
    return f1;
}


int main() {
    int a[m][m], b[m][m], c[m][m];
    int wierszA, kolumnaA = 0, wierszB, kolumnaB;
    char w;
    string f;

    //cout<<"Dla +,-,* nacisnij - 1"<<endl;
    //cout<<"Dla transponowania nacisnij - 2"<<endl;

    //cin>>f;
    f = podaj_numer();

    if(f=="1") {
       //cout << "Podaj ilosc wierszej i kolumn dla macierzy A: ";
       //cin >> wierszA >> kolumnaA;
       //dodajmacierz(a, wierszA, kolumnaA);
       //wypiszmacirz(a, wierszA, kolumnaA);

       //cout << "Podaj ilosc wierszej i kolumn dla macierzy B: ";
       //cin >> wierszB >> kolumnaB;
       //wypiszmacirz(b, wierszB, kolumnaB);
        fun1:
        cout<<"Podaj + - dodawanie,- - odejmowanie,* - mnorzenie, e-wyjsc "<<endl;
        cin >>w;
        if (w=='e') {
            return 0;
        }
        if(w=='+' || w=='-') {
            cout << "Podaj ilosc wierszej i kolumn dla macierzy A: ";
            cin >> wierszA >> kolumnaA;
            dodajmacierz(a, wierszA, kolumnaA);
            //wypiszmacirz(a, wierszA, kolumnaA);
            wypisz_macierz_z_listy(macierz_to_list(a, wierszA, kolumnaA),wierszA,kolumnaA);

            cout << "Podaj ilosc wierszej i kolumn dla macierzy B: ";
            cin >> wierszB >> kolumnaB;
            dodajmacierz(b, wierszB, kolumnaB);
            //wypiszmacirz(b, wierszB, kolumnaB);
            wypisz_macierz_z_listy(macierz_to_list(b, wierszB, kolumnaB),wierszB,kolumnaB);

            if (wierszA != wierszB || kolumnaA != kolumnaB) {
                cout << "Macirzy A i B musza byc tego samego rozmiaru dla dodawania i odejmowania.\n";
            }
            else {
                if(w=='+') {
                    dodawanie(a, b, c, wierszA, kolumnaA);
                    //wypiszmacirz(c, wierszA, kolumnaA);
                    wypisz_macierz_z_listy(macierz_to_list(c, wierszA, kolumnaA),wierszA,kolumnaA);
                }
                else
                    if(w=='-') {
                        odejmowanie(a, b, c, wierszA, kolumnaA);
                        //wypiszmacirz(c, wierszA, kolumnaA);
                        wypisz_macierz_z_listy(macierz_to_list(c, wierszA, kolumnaA),wierszA,kolumnaA);
                    }
                    else cout <<"Blad danych"<<endl;
             }
        }
        else
            if (w=='*') {
                cout << "Podaj ilosc wierszej i kolumn dla macierzy A: ";
                cin >> wierszA >> kolumnaA;
                dodajmacierz(a, wierszA, kolumnaA);
                //wypiszmacirz(a, wierszA, kolumnaA);
                wypisz_macierz_z_listy(macierz_to_list(a, wierszA, kolumnaA),wierszA,kolumnaA);

                cout << "Podaj ilosc wierszej i kolumn dla macierzy B: ";
                cin >> wierszB >> kolumnaB;
                dodajmacierz(b, wierszB, kolumnaB);
                //wypiszmacirz(b, wierszB, kolumnaB);
                wypisz_macierz_z_listy(macierz_to_list(b, wierszB, kolumnaB),wierszB,kolumnaB);

                if(wierszB==kolumnaA) {
                    mnorzenie(a, b, c, wierszA, kolumnaA, kolumnaB);
                    //wypiszmacirz(c, wierszA, kolumnaB);
                    wypisz_macierz_z_listy(macierz_to_list(c, wierszA, kolumnaB),wierszA,kolumnaB);

                }
                else  cout <<"Brak danych"<<endl;
            }
            else cout <<"Brak danych"<<endl;
        goto fun1;
    }
    else {
        if(f == "2") {
            tr:
            cout << "Podaj ilosc wierszej i kolumn dla macierzy A: ";
            cin >> wierszA >> kolumnaA;
            if  (wierszA != kolumnaA || wierszA>5) {
                cout << "Macirz A musi byc symetryczny i mniej niz 5x5.\n";
                goto tr;
            }
            else {
                dodajmacierz(a, wierszA, kolumnaA);
                //wypiszmacirz(a, wierszA, kolumnaA);
                wypisz_macierz_z_listy(macierz_to_list(a, wierszA, kolumnaA),wierszA,kolumnaA);
                transponowanie(a,c,wierszA,kolumnaA);
                //wypiszmacirz(c, wierszA, kolumnaA);
                wypisz_macierz_z_listy(macierz_to_list(c, wierszA, kolumnaA),wierszA,kolumnaA);
            }
        }
    }
return 0;
}
