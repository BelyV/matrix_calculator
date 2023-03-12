#include <iostream>
using namespace std;

const int m = 10; // max pomiar

void dodajmacierz(int mat[][m], int wiersz, int kolumna) {
    cout << "Podaj elemienty macierzy " << wiersz << "x" << kolumna << ":\n";
    for (int i = 0; i < wiersz; i++) {
        for (int j = 0; j < kolumna; j++) {
            cin >> mat[i][j];
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
int main() {
    int a[m][m], b[m][m], c[m][m];
    int wierszA, kolumnaA = 0, wierszB, kolumnaB;
    char w;
    string f;
    cout<<"Dla +,-,* nacisnij - 1"<<endl;
    cout<<"Dla transponowania nacisnij - 2"<<endl;
    cin>>f;
    cout<<endl;

    if(f=="1"){

    cout << "Podaj ilosc wierszej i kolumn dla macierzy A: ";
    cin >> wierszA >> kolumnaA;
    dodajmacierz(a, wierszA, kolumnaA);
    wypiszmacirz(a, wierszA, kolumnaA);

    cout << "Podaj ilosc wierszej i kolumn dla macierzy B: ";
    cin >> wierszB >> kolumnaB;
    dodajmacierz(b, wierszB, kolumnaB);
    //if (wierszA != wierszB || kolumnaA != kolumnaB) {
      //  cout << "Macirzy A i B musza byc tego samego rozmiaru dla dodawania i odejmowania.\n";
    //}
     wypiszmacirz(b, wierszB, kolumnaB);

     cout<<"Podaj + - dodawanie,- - odejmowanie,* - mnorzenie "<<endl;
     cin >>w;
     if(w=='+' || w=='-'){
    if (wierszA != wierszB || kolumnaA != kolumnaB) {
        cout << "Macirzy A i B musza byc tego samego rozmiaru dla dodawania i odejmowania.\n";
    } else {
        //cout<<"Podaj + lub - "<<endl;
        //cin >>w;
        if(w=='+'){

        dodawanie(a, b, c, wierszA, kolumnaA);
        wypiszmacirz(c, wierszA, kolumnaA);}
       else if(w=='-'){
        odejmowanie(a, b, c, wierszA, kolumnaA);
        wypiszmacirz(c, wierszA, kolumnaA);}
        else cout <<"Blad danych"<<endl;



    }
     }
     else if (w=='*') {
         if(wierszB==kolumnaA)
         {


    mnorzenie(a, b, c, wierszA, kolumnaA, kolumnaB);
    wypiszmacirz(c, wierszA, kolumnaB);

}
         else  cout <<"Brak danych"<<endl;
     }
     else cout <<"Brak danych"<<endl;
}
else {
        if(f =="2"){
            cout << "Podaj ilosc wierszej i kolumn dla macierzy A: ";
            cin >> wierszA >> kolumnaA;

            if  (wierszA != kolumnaA)
            {
        cout << "Macirz A musi byc symetryczny.\n";
            }
    else  {
                dodajmacierz(a, wierszA, kolumnaA);
                wypiszmacirz(a, wierszA, kolumnaA);

    transponowanie(a,c,wierszA,kolumnaA);
             wypiszmacirz(c, wierszA, kolumnaA);
            }
        }
    }

}
