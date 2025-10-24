#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name;
    double price;
    string description;
    bool available;



    Product(string n,double p,string d,bool a) {
        name=n;
        price=p;
        description=d;
        available=a;
    }
};

int partition(Product arr[], int low, int high) {
    double pivot=arr[high].price;
    int i=low-1;

    for (int j=low; j<=high-1; j++) {
        if (arr[j].price<=pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}

void quickSort(Product arr[], int low, int high) {
    if (low<high) {
        int pi=partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1,high);
    }
}

void printProducts(Product arr[], int size) {
  
    for (int i = 0; i < size; i++) {
        cout<<"Name: "<< arr[i].name<< endl;
        cout<<"Price: "<< arr[i].price<< endl;
        cout<<"Description: "<<arr[i].description << endl;
        if (arr[i].available) {
            cout<<"Availability:In Stock"<<endl;
        } else {
            cout<<"Availability: Out of Stock"<<endl;
        }
        
    }
}

int main() {
    const int n=3;
    Product products[n];

    cout << "Enter details for 3 products:\n";
    for (int i = 0; i < n; i++) {
        string name, desc;
        double price;
        char avail;
        bool available;

        cout << "\nProduct " << i + 1 << ":\n";
        cout << "Name: ";
        getline(cin, name);
        cin.ignore();

        cout << "Price: ";
        cin >> price;

        cout << "Description: ";
       cin.ignore();
        getline(cin, desc);

        cout<<"Available (Y/N): ";
        cin>>avail;
        available=(avail=='Y'||avail=='y');

        products[i]=Product(name, price, desc, available);
    }

    quickSort(products,0,n-1);
    printProducts(products, n);

    return 0;
}

