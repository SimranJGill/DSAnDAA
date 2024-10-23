#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bus_slot=5, car_slot=5, bike_slot=20, auto_slot=15;
int earings=0, bus_count=0, car_count=0, bike_count=0, auto_count=0;
int index1=0, index2=0, index3=0;
struct customer{
    char customername[10][20], date[10][13];
    int vehiclenumber[10];
}c_data;

//function to print the receipt
void print_receipt(int fees){
    printf("\nReceipt\n");
    printf("**********************************\n");
    printf("Name: %s\n", c_data.customername[index2]);
    printf("Vehicle Number: %d\n", c_data.vehiclenumber[index1]);
    printf("Date: %s\n", c_data.date[index3]);
    printf("Your Fee: %d\n", fees);
    printf("**********************************\n");
}

//function to handle bus parkings
void bus_park(){
    int fees;
    printf("Enter your name: ");
    fflush(stdin);
    gets(c_data.customername[index2]);
    printf("Enter vehicle number: ");
    scanf("%d", &c_data.vehiclenumber[index1]);
    printf("Enter today's date: ");
    fflush(stdin);
    gets(c_data.date[index3]);
repeat:
    printf("Please enter your fees: ");
    scanf("%d", &fees);
    if( fees<200 || fees>200){
        printf("please enter valid amount");
        goto repeat;
    }
    else{
        earings=earings+fees;
        printf("Your paymnet is succesfully done!\n");
    }
    print_receipt(fees);
    index1++;
    index2++;
    index3++;
    bus_count++;
}

//function to handle car parking operations
void car_park(){
    int fees;
    printf("Enter your name: ");
    fflush(stdin);
    gets(c_data.customername[index2]);
    printf("Enter vehicle number: ");
    scanf("%d", &c_data.vehiclenumber[index1]);
    printf("Enter today's date: ");
    fflush(stdin);
    gets(c_data.date[index3]);
repeat:
    printf("Enter the parking fee: ");
    scanf("%d", &fees);
    if( fees<150 || fees>150){
        printf("Enter valid amount\n");
        goto repeat;
    }
    else{
        earings=earings+fees;
        printf("Your payment is successfully done\n");
    }
    print_receipt(fees);
    index1++;
    index2++;
    index3++;
    car_count++;
}

//function to handle bike parking operations
void bike_park(){
    int fees;
    printf("Enter your name: ");
    fflush(stdin);
    gets(c_data.customername[index2]);
    printf("Enter vehicle number: ");
    scanf("%d", &c_data.vehiclenumber[index1]);
    printf("Enter today's date: ");
    fflush(stdin);
    gets(c_data.date[index3]);
repeat:
    printf("Enter parking fees: ");
    scanf("%d",&fees);
    if( fees<50 || fees>50 ){
        printf("Please enet valid amount\n");
        goto repeat;
    }
    else{
        earings=earings+fees;
        printf("Your payment is successfully done");
    }
    print_receipt(fees);
    index1++;
    index2++;
    index3++;
    bike_count++;
}

//function to handle auto parking operations
void auto_park(){
    int fees;
    printf("Enter your name: ");
    fflush(stdin);
    gets(c_data.customername[index2]);
    printf("Enter vehicle number: ");
    scanf("%d", &c_data.vehiclenumber[index1]);
    printf("Enter today's date: ");
    fflush(stdin);
    gets(c_data.date[index3]);
repeat:
    printf("Enter parking fees: ");
    scanf("%d", &fees);
    if( fees<100 || fees>100 ){
        printf("please enter valid amount");
        goto repeat;
    }
    else{
        earings=earings+fees;
        printf("Your payment is successfully done");
    }
    print_receipt(fees);
    index1++;
    index2++;
    index3++;
    auto_count++;
}

//function to handle parking operations
void park_vehicle(){
    int choose;
again:
    printf("\n1. Bus\n2. Car\n3. Bike\n4. Auto\n");
    printf("Which vehicle would you want to park? ");
    scanf("%d", &choose);
    switch(choose){
        case 1:
            if(bus_slot == 0){
                printf("\nSorry! Bus parking slot is not available\n");
            }
            else{
                bus_park();
                bus_slot--;
            }
            break;
        case 2:
            if(car_slot == 0){
                printf("\nSorry! Car parking slot is not available\n");
            }
            else{
                car_park();
                car_slot--;
            }
            break;
        case 3:
            if(bike_slot == 0){
                printf("\nSorry! Bike parking slot is not available\n");
            }
            else{
                bike_park();
                bike_slot--;
            }
            break;
        case 4:
            if(auto_slot == 0){
                printf("\nSorry! Auto parking slot is not available\n");
            }
            else{
                auto_park();
                auto_slot--;
            }
            break;
        default:
            printf("Invalid number, try again\n");
            goto again;
    }
}

//function to check your vehicle is available or not
void check_vehicle(){
    char customername1[20], date1[13];
    int vehiclenumber;
    int i=0, check1, check2, check3;
    printf("\nPlease enter the details\n");
    printf("Enter customer name: ");
    fflush(stdin);
    gets(customername1);
    printf("Enter vehicle number: ");
    scanf("%d", &vehiclenumber);
    printf("Enter date: ");
    fflush(stdin);
    gets(date1);
    while(1){
        check1=strcmp(customername1, c_data.customername[i]);
        check3=strcmp(date1, c_data.date[i]);
        if(vehiclenumber == c_data.vehiclenumber[i]){
            check2 = 0;
        }
        if(check1 == 0 && check2 == 0 && check3 == 0){
            printf("\nYour vehicle is available\n");
            break;
        }
        else{
            if(index1 == 9){
                printf("\nSorry, your vehicle is not available here\n");
                break;
            }
        }
        i++;
    }
}

//function to check parking insight
void check_insight(){
    printf("\n************** Today's Insight **************\n");
    printf("TOtal earnings: %d\n",earings);
    printf("Total Buses parked: %d\n", bus_count);
    printf("Total Cars parked: %d\n", car_count);
    printf("Total Bikes parked: %d\n", bike_count);
    printf("Total Autos parked: %d\n", auto_count);
}

//main function
void main(){
    int choose;
    do{
        printf("\n************** Welcome to Parking Management System **************\n");
        printf("The vehicle fees chart is as follows\n");
        printf("Bus fess = 200\nCar fees = 150\nBike fees = 50\nAuto fees = 100\n");
        printf("\nEnter 1 for park your vehicle\n");
        printf("Enter 2 to check availaibility of your vehicle\n");
        printf("Enter 3 to check Today's Insight\n");
        printf("Enter 4 to Exit\n");
    again:
        printf("Please choose any option: ");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                park_vehicle();
                break;
            case 2:
                check_vehicle();
                break;
            case 3:
                check_insight();
                break;
            case 4:
                printf("Thank You\nYoun have successfully exited\nHave a Nice Day :)\n");
                exit(0);
                break;
            default:
                printf("Invalid number\nTry again\n");
                goto again;
                break;
        }
    } while(choose != 4);
}