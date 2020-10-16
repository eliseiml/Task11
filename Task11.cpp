#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

const int N = 52, N1 = 13;

struct card {
    string type;
    int num;
};

struct card set[N], set1[N1], set2[N1], set3[N1], set4[N1];

string types[4] = { "clubs","diamonds","hearts","spades" };

void fill_set() {
    int counter = 0;
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 13; k++) {
            set[counter].type = types[i];
            set[counter].num = k + 1;
            counter++;
        }
    }
}

void flush_set() {
    for (int i = 0; i < N; i++) {
        swap(set[i], set[rand() % N]);
    }
    for (int i = 0; i < N; i++) {
        if (i < 13) { set1[i] = set[i]; }
        if (i >= 13 && i < 26) { set2[i - 13] = set[i]; }
        if (i >= 26 && i < 39) { set3[i - 26] = set[i]; }
        if (i >= 39) { set4[i - 39] = set[i]; }
    }
}

void print_set(card* tmp, int n) {
    for (int i = 0; i < n; i++) {
        cout << tmp[i].type << " " << tmp[i].num << endl;
    }
}


int main()
{
    srand(time(0));

    fill_set();

    flush_set();
    cout << "\n";

    cout << "\nPLAYER 1\n\n";
    print_set(set1, N1);
    cout << "\nPLAYER 2\n\n";
    print_set(set2, N1);
    cout << "\nPLAYER 3\n\n";
    print_set(set3, N1);
    cout << "\nPLAYER 4\n\n";
    print_set(set4, N1);
}


