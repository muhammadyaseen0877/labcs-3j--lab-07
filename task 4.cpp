#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string name;
    int id;
    double salary;

    Employee(string n="", int i=0, double s=0.0){
        name=n;
        id=i;
        salary=s;
    }
};

void merge(Employee arr[], int l, int m, int r){
    int i=l;
    int j=m+1;
    int k=l;
    Employee temp[12];  

    while(i<=m && j<=r) {
        if(arr[i].salary>=arr[j].salary){ 
            temp[k]=arr[i];
            i++;
        } 
		else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }

  
    while (i<=m) {
        temp[k]=arr[i];
        i++;
        k++;
    }

    
    while(j<=r) {
        temp[k]=arr[j];
        j++;
        k++;
    }

    for (int i=l; i<=r; i++) {
        arr[i]=temp[i];
    }
}

void mergeSort(Employee arr[], int l, int r) {
    if(l<r){
        int m=(l+r)/2;

       
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void displayTop3(Employee arr[], int size) {
    cout<< "\nTop 3 High salaryy Employeees:\n";

    for(int i=0; i<3 && i<size; i++) {
        cout<<(i+1)<<" Name: "<<arr[i].name<<" ID: "<<arr[i].id<<" Salary: "<<arr[i].salary<<endl;
    }
}

void displayAllEmployees(Employee arr[], int size) {
    cout<<"all emplyees salary detail in assending order: "<<endl;
  
    for (int i=0; i<size; i++) {
        cout<<(i+1)<<" Name: "<<arr[i].name<<" ID: "<<arr[i].id<<" Salary: "<<arr[i].salary<<endl;
    }
    }


int main() {
    const int size=12;
    Employee employees[size];

    cout << "Enter details for 12 employees:\n";
    for (int i=0; i < size; i++){
        cout<<"\nEmployee "<<(i + 1)<<":\n";
        cout<<"Name: ";
        cin.ignore(); 
        getline(cin, employees[i].name);
        cout<<"ID: ";
        cin>>employees[i].id;
        cout<<"Salary:";
        cin>>employees[i].salary;
    }

  
    mergeSort(employees, 0, size-1);


    displayTop3(employees, size);
    displayAllEmployees(employees, size);

    return 0;
}
