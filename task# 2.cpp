#include <iostream>
#include <string>
using namespace std;

class Participant{
public:
    string name;
    int time;

    Participant(string n, int t){
    	name=n;
    	time=t;
	}
};

void merge(Participant arr[], int l, int m, int r) {
    int i=l;
	int j=m+1; 
	int k=l;
    Participant temp[10];

    while(i<=m && j<=r) {
        if(arr[i].time<arr[j].time) {
            temp[k]=arr[i];
            i++;
            k++;
        }
		 else{
            temp[k]=arr[j];
            j++;
            k++;
        }
        
    }

    while (i<=m){
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
        arr[i]=temp[k];
    }
}

void mergeSort(Participant arr[], int l, int r) {
    if (l<r) {
        int m=(l+r)/2;

        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}

void displayTop5(Participant arr[], int size) {
    cout<<"Top 5 Fastest Runners:\n";
    for(int i=0; i<5 && i<size; i++) {
        cout<<(i+1)<<": "<<arr[i].name<<" - "<<arr[i].time<<" seconds\n";
    }
}

int main(){
    int size=10;
    Participant participants[size];

    for (int i=0; i<size; i++) {
        cout<<"Enter name of participant: "<<(i+1)<<": ";
        cin>>participants[i].name;
        cout<<"Enter finish time for "<<participants[i].name<<": ";
        cin>>participants[i].time;
    }

    mergeSort(participants,0,size-1);

    displayTop5(participants,size);

    return 0;
}
       
