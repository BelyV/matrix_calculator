#include <iostream>
#include <list>

using namespace std;

const int m = 10; // max pomiar


struct Node {
  int val;
  Node* next;

  Node(int _val) : val(_val), next(nullptr){}
  };


struct list_mac {
    Node* first;
    Node* last;

    list_mac() : first(nullptr), last(nullptr) {}

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

    void print() {
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    void remove_first() {
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

};

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
    cout<<"Dla obliczenia wyznacznika nacisnij - 3"<<endl;
    cout<<"e - wyjsc z programu"<<endl;

    cin>>f1;


    if ((f1 != "1") and (f1 != "2") and (f1!="3") and (f1 !="e")) {
        cout << "Podales niepoprawne dane!!!" << endl;
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
    string wierA, kolA, wierB, kolB;
    int wierszA, kolumnaA, wierszB, kolumnaB;
    char w;
    string f;

    r:
    f = podaj_numer();
  if ((f == "1") || (f == "2") || (f =="3")) {
    if(f=="1") {
        fun1:
        cout<<"Podaj + - dodawanie,- - odejmowanie,* - mnorzenie, m-menu "<<endl;
        cin >>w;
        if (w=='m') {
            cout<<endl;
            cout<<endl;
            cout<<endl;
            goto r;
        }

        if(w=='+' || w=='-') {
               oma:
            cout << "Podaj ilosc wierszej dla macierzy A: ";

            cin >> wierA;
            for (int i = 0; i < wierA.length(); i++){
                if (((int(wierA[i]) > 57) || (int(wierA[i]) < 48))){
                    cout << "Podane bledne dane!" << endl;
                    goto oma;
                }
            }
            wierszA=stoi(wierA);
            oma1:
              cout << "Podaj ilosc kolumn dla macierzy A: ";
            cin >> kolA;
            for (int i = 0; i < kolA.length(); i++){
                if (((int(kolA[i]) > 57) || (int(kolA[i]) < 48))){
                    cout << "Podane bledne dane!" << endl;
                    goto oma1;
                }
            }
            kolumnaA=stoi(kolA);
            dodajmacierz(a, wierszA, kolumnaA);
            //wypiszmacirz(a, wierszA, kolumnaA);
            wypisz_macierz_z_listy(macierz_to_list(a, wierszA, kolumnaA),wierszA,kolumnaA);

            omb:
              cout << "Podaj ilosc wierszej dla macierzy B: ";
            cin >> wierB;
            for (int i = 0; i < wierB.length(); i++){
                if (((int(wierB[i]) > 57) || (int(wierB[i]) < 48))){
                    cout << "Podane bledne dane!" << endl;
                    goto omb;
                }
            }
            wierszB=stoi(wierB);
            omb1:
              cout << "Podaj ilosc kolumn dla macierzy B: ";
            cin >> kolB;
            for (int i = 0; i < kolB.length(); i++){
                if (((int(kolB[i]) > 57) || (int(kolB[i]) < 48))){
                    cout << "Podane bledne dane!" << endl;
                    goto omb1;
                }
            }
            kolumnaB=stoi(kolB);
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
oma7:
cout << "Podaj ilosc wierszej dla macierzy A: ";

cin >> wierA;
for (int i = 0; i < wierA.length(); i++){
 if (((int(wierA[i]) > 57) || (int(wierA[i]) < 48))){
     cout << "Podane bledne dane!" << endl;
     goto oma7;
 }
}
wierszA=stoi(wierA);
oma6:
cout << "Podaj ilosc kolumn dla macierzy A: ";
cin >> kolA;
for (int i = 0; i < kolA.length(); i++){
 if (((int(kolA[i]) > 57) || (int(kolA[i]) < 48))){
     cout << "Podane bledne dane!" << endl;
     goto oma6;
 }
}
kolumnaA=stoi(kolA);
dodajmacierz(a, wierszA, kolumnaA);
//wypiszmacirz(a, wierszA, kolumnaA);
wypisz_macierz_z_listy(macierz_to_list(a, wierszA, kolumnaA),wierszA,kolumnaA);

omb3:
cout << "Podaj ilosc wierszej dla macierzy B: ";
cin >> wierB;
for (int i = 0; i < wierB.length(); i++){
 if (((int(wierB[i]) > 57) || (int(wierB[i]) < 48))){
     cout << "Podane bledne dane!" << endl;
     goto omb3;
 }
}
wierszB=stoi(wierB);
omb2:
cout << "Podaj ilosc kolumn dla macierzy B: ";
cin >> kolB;
for (int i = 0; i < kolB.length(); i++){
 if (((int(kolB[i]) > 57) || (int(kolB[i]) < 48))){
     cout << "Podane bledne dane!" << endl;
     goto omb2;
 }
}
kolumnaB=stoi(kolB);
dodajmacierz(b, wierszB, kolumnaB);
//wypiszmacirz(b, wierszB, kolumnaB);
wypisz_macierz_z_listy(macierz_to_list(b, wierszB, kolumnaB),wierszB,kolumnaB);

                if(wierszB==kolumnaA) {
                    mnorzenie(a, b, c, wierszA, kolumnaA, kolumnaB);
                    //wypiszmacirz(c, wierszA, kolumnaB);
                    wypisz_macierz_z_listy(macierz_to_list(c, wierszA, kolumnaB),wierszA,kolumnaB);

                }
                else  cout <<"Brak mozliwosci mnorzenia"<<endl;
            }
            else cout <<"Brak danych"<<endl;
        goto fun1;
    }


        if(f == "2"){ {
            tr:

oma2:
                  cout << "Podaj ilosc wierszej dla macierzy A: ";
cin >> wierA;
for (int i = 0; i < wierA.length(); i++){
    if (((int(wierA[i]) > 57) || (int(wierA[i]) < 48))){
        cout << "Podane bledne dane!" << endl;
        goto oma2;
    }
}
wierszA=stoi(wierA);
oma3:
  cout << "Podaj ilosc kolumn dla macierzy A: ";
cin >> kolA;
for (int i = 0; i < kolA.length(); i++){
    if (((int(kolA[i]) > 57) || (int(kolA[i]) < 48))){
        cout << "Podane bledne dane!" << endl;
        goto oma3;
    }
}
kolumnaA=stoi(kolA);
            if  (wierszA != kolumnaA || wierszA>5) {
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

    }


        if(f == "3"){
            wz:

oma4:
              cout << "Podaj ilosc wierszej dla macierzy A: ";
cin >> wierA;
for (int i = 0; i < wierA.length(); i++){
    if (((int(wierA[i]) > 57) || (int(wierA[i]) < 48))){
        cout << "Podane bledne dane!" << endl;
        goto oma4;
    }
}
wierszA=stoi(wierA);
oma5:
  cout << "Podaj ilosc kolumn dla macierzy A: ";
cin >> kolA;
for (int i = 0; i < kolA.length(); i++){
    if (((int(kolA[i]) > 57) || (int(kolA[i]) < 48))){
        cout << "Podane bledne dane!" << endl;
        goto oma5;
    }
}
kolumnaA=stoi(kolA);
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
                }
cout<<endl;
cout<<endl;
cout<<endl;

goto r;
  }
        else{
          if( f == "e") {
             return 0;
         }
  }
return 0;
}
