#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

const int m = 3; // max pomiar


struct Node {
  int val;
  Node* next;

  Node(int _val) : val(_val), next(nullptr){}
  };


struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(int _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }


    void remove_first() {
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

};
int pomiarmacwe(char d,int wier) {


 string wiersz;


oma:
cout << "Podaj ilosc wierszy dla macierzy "<<d<< ": ";

cin >> wiersz;
for (int i = 0; i < wiersz.length(); i++){
 if (((int(wiersz[i]) > 57) || (int(wiersz[i]) < 48))){
     cout << "Podane bledne dane!" << endl;
     goto oma;
 }
}
wier= stoi(wiersz);
if(wier!=1 && wier!=2 && wier!=3){
    cout << "Podane bledne dane!" << endl;
    goto oma;
}
return wier;
//cout<<wier*2<<endl;
}

int pomiarmacko(char d, int kol){
    string kolu;

oma1:
cout << "Podaj ilosc kolumn dla macierzy "<<d<< ": ";
cin >> kolu;
for (int i = 0; i < kolu.length(); i++){
 if (((int(kolu[i]) > 57) || (int(kolu[i]) < 48))){
     cout << "Podane bledne dane!" << endl;
     goto oma1;
 }
}
kol= stoi(kolu);
if(kol!=1 && kol!=2 && kol!=3){
    cout << "Podane bledne dane!" << endl;
    goto oma1;
}
return kol;
//cout<<kol*2<<endl;
    }




void dodajmacierz(int mat[][m], int wiersz, int kolumna) {
    cout << "Podaj elemienty macierzy " << wiersz << "x" << kolumna <<" przez enter"<< ":\n";
    for (int i = 0; i < wiersz; i++) {
        for (int j = 0; j < kolumna; j++) {
            //cin >> mat[i][j];
            omt:
            string s1;
            cin >> s1;
            if (s1=="-"){
              cout<<"Podane bledne dane!" << endl;
              goto omt;
            }
           else {
            for (int i = 0; i < s1.length(); i++){
                if (((int(s1[i]) > 57) || (int(s1[i]) < 48)) && (int(s1[i]) != 45)){
                    cout << "Podane bledne dane!" << endl;
                    goto omt;
                }
            } }

            mat[i][j] = stoi(s1);

        }
    }
}

void wypiszmacirz(int mat[][m], int wiersz, int kolumna) {
   // cout << "Macierz "<< wiersz << "x" << kolumna << ":\n";
    for (int i = 0; i < wiersz; i++) {
        for (int j = 0; j < kolumna; j++) {
            cout <<"["<< mat[i][j] <<"]"<< "\t";
        }
        cout << endl;
    }
    //wypisz_macierz_z_listy(macierz_to_list(mat[][m], wiersz, kolumna),wiersz,kolumna);
}

void wypisz_macierz_z_listy(list list_mat, int wiersz, int kolumna){
    //cout << "Macierz "<< wiersz << "x" << kolumna << ":\n";
    for (int i = 0; i < wiersz; i++) {
        for (int j = 0; j < kolumna; j++) {
            cout <<"["<< list_mat.first->val <<"]"<< "\t";
            list_mat.remove_first();
        }
        cout << endl;
    }
}

list macierz_to_list(int mat[][m], int wiersz, int kolumna){
    list list_mat;
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
    cout<<"KALKULATOR DZIALA NA MACIERZACH DO 3x3"<<endl;
    cout<<endl;
    cout<<"________________________________________________________________________________________________________________________"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Dla +,-,* nacisnij - 1"<<endl;
    cout<<"Dla transponowania nacisnij - 2"<<endl;
    cout<<"Dla obliczenia wyznacznika nacisnij - 3"<<endl;
    cout<<"e - wyjsc z programu"<<endl;
    cout<<endl;
    cout<<endl;

    cin>>f1;


    if ((f1 != "1") and (f1 != "2") and (f1!="3") and (f1 !="e")) {
          system("cls");
          cout<<endl;
          cout<<endl;    cout<<endl;
          cout<<endl;
        cout << "Podales niepoprawne dane!!!" << endl;
        cout<<endl;
        cout<<endl;    cout<<endl;
        cout<<endl;
        goto powtorz;
    }
    return f1;
}

void wyznacznik(int mat[][m], int wiersz, int kolumna) {
    int det = 0;
    int size=wiersz;

    if(wiersz!=kolumna){
        cout<<"Nia ma mozliwosci obliczyc wyznacznik"<<endl;
    }
   else{
    if (size == 1) {
        det=mat[0][0];
    } else if (size == 2) {
        det=mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    } else if (size == 3) {
        det=mat[0][0]*mat[1][1]*mat[2][2]+mat[0][1]*mat[1][2]*mat[2][0]+mat[0][2]*mat[1][0]*mat[2][1]-mat[0][2]*mat[1][1]*mat[2][0]-mat[0][0]*mat[1][2]*mat[2][1]-mat[0][1]*mat[1][0]*mat[2][2];
    }
    cout<<"Wyznacznik macierzy: "<<det<<endl;
        }
}

int main() {
    int a[m][m], b[m][m], c[m][m];
    int wierA=0;
    int kolA=0;
    int wierB=0;
    int kolB=0;
    int wierszA=0;
    int kolumnaA=0;
    int wierszB=0;
    int kolumnaB=0;
    string w;
    char q;
    char p;
    q='A';
    p='B';
    string f;
    string k;


    r:
    cout<<endl;
    cout<<endl;
    f = podaj_numer();
    cout<<endl;
    cout<<endl;
  if ((f == "1") || (f == "2") || (f =="3")) {
    if(f=="1") {
        fun1:
        cout<<"Podaj + - dodawanie,- - odejmowanie,* - mnorzenie, m-menu "<<endl;
        cin >>w;
        if (w=="m" || w=="M") {
            system("cls");
            cout<<endl;
            cout<<endl;
            cout<<endl;
            goto r;
        }

        if(w=="+" || w=="-") {
           // pomiarmac(q, wierA, kolA) ;
            wierszA=pomiarmacwe(q, wierA) ;
            kolumnaA=pomiarmacko(q, kolA) ;
            dodajmacierz(a, wierszA, kolumnaA);
            wypisz_macierz_z_listy(macierz_to_list(a, wierszA, kolumnaA),wierszA,kolumnaA);
            a:
            wierszB=pomiarmacwe(p, wierB) ;
            kolumnaB=pomiarmacko(p, kolB) ;
            if(wierszA != wierszB || kolumnaA != kolumnaB) {
                cout<<endl;
                cout << "Macirzy A i B musza byc tego samego rozmiaru dla dodawania i odejmowania.\n";
                goto a;
            }

            dodajmacierz(b, wierszB, kolumnaB);
            //wypiszmacirz(b, wierszB, kolumnaB);
            wypisz_macierz_z_listy(macierz_to_list(b, wierszB, kolumnaB),wierszB,kolumnaB);

            if (wierszA != wierszB || kolumnaA != kolumnaB) {
                cout << "Macirzy A i B musza byc tego samego rozmiaru dla dodawania i odejmowania.\n";
            }
            else {

                if(w=="+") {
                    dodawanie(a, b, c, wierszA, kolumnaA);
                    //wypiszmacirz(c, wierszA, kolumnaA);
                    cout<<endl;
                    cout<<"Macierz C = "<<endl;
                    wypisz_macierz_z_listy(macierz_to_list(c, wierszA, kolumnaA),wierszA,kolumnaA);
                }
                else
                    if(w=="-") {
                        odejmowanie(a, b, c, wierszA, kolumnaA);
                        //wypiszmacirz(c, wierszA, kolumnaA);
                        cout<<endl;
                        cout<<"Macierz C = "<<endl;
                        wypisz_macierz_z_listy(macierz_to_list(c, wierszA, kolumnaA),wierszA,kolumnaA);
                    }
                    else cout <<"Blad danych"<<endl;
             }
        }
        else
            if (w=="*") {
                wierszA=pomiarmacwe(q, wierA) ;
                kolumnaA=pomiarmacko(q, kolA) ;
                dodajmacierz(a, wierszA, kolumnaA);
                wypisz_macierz_z_listy(macierz_to_list(a, wierszA, kolumnaA),wierszA,kolumnaA);
                u:
                wierszB=pomiarmacwe(p, wierB) ;
                kolumnaB=pomiarmacko(p, kolB) ;

                if(wierszB!=kolumnaA) {
                    cout <<"Brak mozliwosci mnorzenia"<<endl;
                    goto u;
                }

                dodajmacierz(b, wierszB, kolumnaB);

                wypisz_macierz_z_listy(macierz_to_list(b, wierszB, kolumnaB),wierszB,kolumnaB);

                if(wierszB==kolumnaA) {
                    mnorzenie(a, b, c, wierszA, kolumnaA, kolumnaB);
                    //wypiszmacirz(c, wierszA, kolumnaB);
                    cout<<endl;
                    cout<<"Macierz C = "<<endl;
                    wypisz_macierz_z_listy(macierz_to_list(c, wierszA, kolumnaB),wierszA,kolumnaB);

                }
                else  cout <<"Brak mozliwosci mnorzenia"<<endl;
            }
            else cout <<"Brak danych"<<endl;
        goto fun1;
    }


        if(f == "2"){ {
            tr:
                 system("cls");
                 cout<<"Transponowanie"<<endl;
                 cout<<endl;
                 cout<<endl;
                wierszA=pomiarmacwe(q, wierA) ;
                kolumnaA=pomiarmacko(q, kolA) ;


            if  (wierszA != kolumnaA || wierszA>3) {
                cout << "Macirz A musi byc symetryczny i mniej niz 3x3.\n";
                cout<<endl;
                cout<<endl;
                cout<<endl;
                goto tr;
            }
            else {
                dodajmacierz(a, wierszA, kolumnaA);

                wypisz_macierz_z_listy(macierz_to_list(a, wierszA, kolumnaA),wierszA,kolumnaA);
                transponowanie(a,c,wierszA,kolumnaA);
                cout<<"Macierz transponowana:  "<<endl;
                wypisz_macierz_z_listy(macierz_to_list(c, wierszA, kolumnaA),wierszA,kolumnaA);
            }
        }
            q:
            cout<<endl;
            cout<<endl;
            cout<<endl;

            cout<<"P-Jeszcze raz, M-menu"<<endl;
            cin>>k;
            if(k=="P" || k=="p"){
                   system("cls");
                   goto tr;

            }
           else if(k=="M" || k=="m"){
                  system("cls");
                goto r;
            }
            else  goto q;
    }


        if(f == "3"){
            wz:
            system("cls");
            cout<<"Obliczenie wyznacznika"<<endl;
            cout<<endl;
            cout<<endl;
            wierszA=pomiarmacwe(q, wierA) ;
            kolumnaA=pomiarmacko(q, kolA) ;
            if  (wierszA != kolumnaA || wierszA>3) {
                cout << "Macirz A musi byc symetryczny i mniej niz 3x3.\n";
                cout<<endl;
                cout<<endl;
                cout<<endl;
                goto wz;
        }
            else {
                      dodajmacierz(a, wierszA, kolumnaA);
                      wypisz_macierz_z_listy(macierz_to_list(a, wierszA, kolumnaA),wierszA,kolumnaA);
                      wyznacznik(a, wierszA, kolumnaA);


                  }
                       j:
                       cout<<endl;
                       cout<<endl;
                       cout<<endl;

                       cout<<"P-Jeszcze raz, M-menu"<<endl;
                       cin>>k;
                       if(k=="P" || k=="p"){
                        system("cls");
                          goto wz;

                            }
                       else if(k=="M" || k=="m"){
                       system("cls");
                          goto r;
                         }
                       else  goto j;
                }
cout<<endl;
cout<<endl;
cout<<endl;

  }
        else{
          if( f == "e" || f=="E") {
              system("cls");
              z:
              system("cls");
              cout<<"                           Wyjśce?"<<endl;
              cout<<  "                     T-tak   N-nie"<<endl;
              cin>>k;
              cout<<endl;
              if(k=="t" || k=="T"){
                   system("cls");
                  cout<<endl;
                  cout<<endl;
                  cout<<endl;

                  cout<<endl;
                  cout<<endl;
                  cout<<"                                            DO WIDZENIA"<<endl;
                  cout<<endl;

                  return 0;
              }
             else if(k=="n" || k=="N"){
                    system("cls");
                  goto r;
              }
              else  goto z;
         }
  }
return 0;
}
