#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int i,j,k,a,n;
    bool check;
    int batas=0;
    int nyawa=3;
    char lagi;
    string kata;
    string tebak;
    input:
    cout <<"Silahkan input kata : ";
    cin >> kata;
    cout << "Huruf telah diacak. Kira-kira kata apakah itu???" << endl ;
    srand(static_cast<unsigned int>(time(0))); //acak huruf
    cout << "nyawa anda = " << nyawa << endl;
    n = kata.size(); //jumlah huruf
    int indeks[n];
    for(i=0;i<n;i++)
    {
        if(i == 0)
        {
            j = rand() % n;
            indeks[i] = j;
            batas++;
        }else
        {
            check = true;
            j = rand() % n;
            k = 0;
            while(k<batas)
            {
                if(j==indeks[k])
                {
                    check = false;
                }
                if (check == false)
                {
                    k = 0;
                    j = rand() % n;
                    check = true;
                }else
                {
                    k++;
                }

            }
            indeks[i] =  j;
            batas++;
        }
    }

    for(a=0;a<n;a++)
    {
        cout << kata[indeks[a]] ;
    }

    cout << "\n(hint = "<< kata << ")" << endl;
    tebak:
    cout << "Masukkan tebakan anda: ";
    cin >> tebak;
    if(tebak == kata)
    {
        cout << "\nSelamat! Tebakan kamu benar..." << endl;
        cout << "Apakah anda mau main lagi?(y/n): ";
        cin >> lagi;
        if(lagi == 'y')
        {
            batas = 0;
            nyawa = 3;
            goto input;
        }else if(lagi == 'n')
        {
            cout << "\nTerimakasih sudah bermain!" << endl;
            system("pause");
            exit(0);
        }
    }else
    {
        nyawa--;
        if(nyawa!= 0)
        {
            cout << "\nMaaf tebakan kamu salah!! Coba tebak lagi.." << endl;
            cout << "nyawa anda = " << nyawa << endl;
            goto tebak;
        }
    }
    if(nyawa == 0)
        {
            cout << "\nMaaf, nyawa anda sudah habis." << endl;
            cout << "nyawa anda = " << nyawa << endl;
            cout << "Apakah anda mau main lagi?(y/n): ";
            cin >> lagi;
            if(lagi == 'y')
            {
                nyawa = 3;
                batas = 0;
                goto input;
            }else if(lagi == 'n')
            {
                cout << "\nTerimakasih sudah bermain!" << endl;
                system("pause");
                exit(0);
            }
        }

    return 0;
}
