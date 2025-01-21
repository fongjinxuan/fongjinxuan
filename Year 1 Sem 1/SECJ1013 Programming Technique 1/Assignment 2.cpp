/*
FONG JIN XUAN A24CS0074
LAI SHI NI A24CS0298
27 DEC 2024
*/


#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

void getInfo(int&,int&,int&);
double getPrice(int, int, int);
void printInfo(int,int,int,double);
void getLoan(double);
double calculateMonthlyInstallment(double, double, double, int);

int main(){
    char repeat='y';

    do
    {
    double price;
    int model,variant,region;

    getInfo(model,variant,region);
    price=getPrice(model,variant,region);

    printInfo(model,variant,region,price);

    getLoan(price);

    cout<<"\nDo you want to enter other data? [Y @ N]: ";
    cin>>repeat;
    repeat=tolower(repeat);
    }while (repeat!='n');

    cout<<"Thank you!:)"<<endl;
    return 0;
}

void getInfo(int&model,int&variant,int&region){
    cout<<"Proton Car Loan Calculator\n\n";
    do {
    cout<<"Model [1-X50, 2-Exora, 3-Persona]:";
    cin>>model;
    cout<<"Variants [1-1.6L Standard CVT, 2-1.6L Premium CVT]:";
    cin>>variant;
    cout<<"Region [1-Peninsular Malaysia, 2-East Malaysia]:";
    cin>>region;
    if (model<1||model>3||variant<1||variant>2||region<1||region>2) {
        cout<<"Invalid input."<<endl;
    }
    }while(model<1||model>3||variant<1||variant>2||region<1||region>2);
}

double getPrice(int model, int variant, int region){
    double price;
    if (model==1){
        if (variant==1) {
            price=86300;
        } else {
            price=93300;
        }
    } 

    else if (model==2){
        if (variant==1){
            price=62800;
        } else {
            price=69800;
        }
    } 

    else {
        if (variant==1){
            price=53300;
        } else {
            price=54600;
        }
    }

    if (region==2){
        price+=2000;
    }

    return price;
}

void printInfo(int model, int variant, int region, double price) {
    cout<<"Car Info\n";

    switch(model){
        case 1:cout<<"Model: X50\n";break;
        case 2:cout<<"Model: Exora\n";break;
        case 3:cout<<"Model: Persona\n";break;
    }

    switch(variant){
        case 1:cout<<"Variant:1.6L Standard CVT\n";break;
        case 2:cout<<"Variant:1.6L Premium CVT\n";break;
    }

    switch(region){
        case 1:cout<<"Region: Peninsular Malaysia\n";break;
        case 2:cout<<"Region: East Malaysia\n";break;
        }
    
cout<<"Paint Type: Metallic\n";
cout<<"Price (MYR): "<<fixed << setprecision(2)<<price<<endl<<endl;
}

void getLoan (double price){
    double downPay,interestRate, monthlyInstallment;
    int years;

    cout<<"Down Payment (MYR): ";
    cin>>downPay;

    cout<<"Interest Rate (%): ";
    cin>>interestRate;

    cout<<"Repayment period (in years): ";
    cin>>years;

    monthlyInstallment=calculateMonthlyInstallment(downPay, interestRate,price, years);
    cout<<"MONTHLY INSTALLMENT (MYR): "<<fixed << setprecision(2)<<monthlyInstallment;
}

double calculateMonthlyInstallment(double downPayment, double interestRate, double price, int year) {
    double inst;
    
    price-=downPayment;
    interestRate/=100;
    inst=(price+(price*interestRate*year))/(year*12);
    
    return inst;
}