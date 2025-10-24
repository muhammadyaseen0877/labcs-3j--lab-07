int main() {
    int n;
    cout<<"Enter number of orders: ";
    cin>>n;

    order orders[100];

    for(int i=0; i<n; i++) {
        int id;
        string name;
        double price;

        cout<<"\nEnter details for order "<<i+1<<" :"<<endl;
        cout<<"Order ID: ";
        cin>>id;
        cout<<"Customer Name: ";
        cin>>name;
        cout<<"Total Price: ";
        cin>>price;

        orders[i] = order(id, name, price);
    }

    quickSort(orders, 0, n-1);

    printOrders(orders, n);

    return 0;
}

