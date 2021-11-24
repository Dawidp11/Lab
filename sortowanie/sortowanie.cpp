#include <iostream>
#include <Windows.h>
#include <time.h>


using namespace std;

int wiela;
clock_t start, stop;
double sec;


void bubble_sort(int* Autobana, int h)
{

    for (int j = 0, Śleper = 1; j < h - 1 && Śleper != 0; j++)
    {
        Śleper = 0;
        for (int b = 0; b < h - 1; b++)
            if (Autobana[b] > Autobana[b + 1])
            {
                swap(Autobana[b], Autobana[b + 1]);
                Śleper++;
            }
    }
}

void quicksort(int* tab, int lewy, int prawy)
{
    int v = tab[(lewy + prawy) / 2];
    int i, j, x;
    i = lewy;
    j = prawy;
    do
    {
        while (tab[i] < v) i++;
        while (tab[j] > v) j--;
        if (i <= j)
        {
            x = tab[i];
            tab[i] = tab[j];
            tab[j] = x;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > lewy) quicksort(tab, lewy, j);
    if (i < prawy) quicksort(tab, i, prawy);
}





int main()
{
    system("chcp 1250");

    cout << "podej ilosć numerōw do losowania np.:10 -> ";
    cin >> wiela;

    cout << " \n ";

    int* bera;
    bera = new int[wiela];

    int* cajtung;
    cajtung = new int[wiela];


    srand(time(NULL));

    for (int i = 0; i < wiela; i++)
    {

        bera[i] = rand() % 100 + 1;

    }


    for (int i = 0; i < wiela; i++)
    {
        cajtung[i] = bera[i];
    }


    cout << "Przed sortowaniem \n" << endl;
    for (int i = 0; i < wiela; i++)
    {
        cout << cajtung[i] << " ";
    }
    //algorytmy sortujące //
    
    
    cout << "\n" << endl;


    cout << " bubble_sort " << endl;
    start = clock();
    bubble_sort(bera, wiela);
    stop = clock();
    sec = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << " \n" << endl;
    cout << "po sortowane : \n" << endl;
    for (int i = 0; i < wiela; i++)
    {
        cout << bera[i] << " ";

    }
    cout << endl << "Czas sortowania  " << sec << " s" << endl;
    cout << "\n" << endl;


    cout << " quicksort " << endl;
    start = clock();
    quicksort(bera, 0, wiela - 1);
    stop = clock();
    sec = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << " \n " << endl;
    cout << " po sortowane : \n" << endl;
    for (int i = 0; i < wiela; i++)
    {
        cout << bera[i] << " ";
    }
    cout << endl << "Czas sortowania  " << sec << " s" << endl;

    delete[] bera;
    delete[] cajtung;


    return 0;
}
