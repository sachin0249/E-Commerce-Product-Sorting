#include <iostream>
#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    float price;
    float rating;
    int reviews;
};

void insertionSort(Product p[], int n) {
    for(int i = 1; i < n; i++) {
        Product key = p[i];
        int j = i - 1;

        while(j >= 0 && p[j].rating < key.rating) {
            p[j + 1] = p[j];
            j--;
        }
        p[j + 1] = key;
    }
}

void selectionSort(Product p[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min = i;

        for(int j = i + 1; j < n; j++) {
            if(p[j].price < p[min].price)
                min = j;
        }

        Product temp = p[i];
        p[i] = p[min];
        p[min] = temp;
    }
}

void display(Product p[], int n) {
    cout << "\nProducts List:\n";
    for(int i = 0; i < n; i++) {
        cout << p[i].id << " "
             << p[i].name << " "
             << p[i].price << " "
             << p[i].rating << " "
             << p[i].reviews << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;

    Product p[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter ID Name Price Rating Reviews: ";
        cin >> p[i].id >> p[i].name >> p[i].price >> p[i].rating >> p[i].reviews;
    }

    insertionSort(p, n);
    selectionSort(p, n);

    display(p, n);

    return 0;
}
