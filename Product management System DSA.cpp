#include<bits/stdc++.h>
using namespace std;
void Product_create( );
void addfun();
void add_product();
void wallpaper();
void theme();
void sorting();
void buying();
void swap_digit(long int *,long int *);
void word_swap(char *, char *);
void swap_Float(float *x, float *y);
void display();
void Forcounting();
void product_search();

void delete_item();
void delete_first();


class product
{
public:
    long int sri;
    char pname[30];
    float price;
    int quantity;
    product *next;
};
product *start,*last,*current;

int main()
{
    system("color 09");
    int opption;
    wallpaper();
    while(1)
    {
        cout<<(" 1. Stock In\n");
        cout<<(" 2. Show the All Product\n");
        cout<<(" 3. Available Product Numbers\n");
        cout<<(" 4. Searching Product\n");
        cout<<(" 5. Buying Product\n");
        cout<<(" 6. Stock Out\n");
        cout<<(" 0. Exit\n");
        cout<<("\nChoose Your Option\n");
        cin>>opption;
        switch(opption)
        {
        case 1:
            addfun();
            break;
        case 2:
            display();
            break;
        case 3:
            Forcounting();
            break;
        case 4:
            product_search();
            break;
        case 5:
            buying();
            break;
        case 6:
            delete_item();
            break;
        case 0:
            exit(0);
            break;
        default:
            cout<<("\nWrong option: ");
        }
    }
}


void buying()
{
    display();
    long int code;
    int qua;
    cout<<("Enter Product code to buy\n");
    cin>>code;
    cout<<("Enter Quantity\n");
    cin>>qua;
system("cls");
    int flag=0;
    current = start;
    while(current!=NULL)
    {
        if(current->sri==code)
        {
            if(qua<0){
                cout<<"Please enter valid input"<<endl;
            }
          else if(qua<=current->quantity)
            {
                theme();
                flag=1;
                cout << " "<<current->sri << " \t\t\t\t"
                     << current->pname << "\t\t\t\t"
                     << current->price*qua << "\t\t\t\t"
                     << qua << endl;
            }
            else{
                cout<<"Number of "<<qua<<"Product is not available in stock"<<endl;
            }
        }
        current=current->next;
    }
    if(flag==0)
        cout<<("\nPlease enter valid product code!\n");

}


void addfun( )
{
    int x=1;
    cout<<("1. At First create. \n2. After Creating")<<endl;
    cin>>x;
    if(x==1)
        Product_create();
    else if(x==2)
        add_product();
    else
        cout<<("\nWrong Click\n")<<endl;

}

void Product_create( )
{
    system("cls");
    product *newproduct;
    start=0;
    int i,N;
    cout<<("\nHow Many product you want to added? ");
    cin>>N;

    for(i=1; i<=N; i++)
    {
        newproduct = new product();

        cout<<("Enter Code no: ");
        cin>>newproduct->sri;
        fflush(stdin);

        cout<<("Enter Name : ");
        cin.get(newproduct->pname, 100);

        cout<<("Enter Price : ");
        cin>>newproduct->price;

        cout<<("Enter Quantity: ");
        cin>>newproduct->quantity;

        newproduct->next = 0;
        if(start==0)
        {
            start = last = current = newproduct;
        }
        else
        {
            current->next = newproduct;
            current = newproduct;
            last=last->next;
        }
        system("cls");
    }
    cout<<("\nAdded Successfully\n")<<endl;
}

void add_product()
{
    system("cls");
    product *newproduct;
    newproduct = new product();

    cout<<("Enter Code no: ");
    cin>>newproduct->sri;
    fflush(stdin);

    cout<<("Enter product Name : ");
    cin.get(newproduct->pname, 100);

    cout<<("Enter price : ");
    cin>>newproduct->price;

    cout<<("Enter Quantity: ");
    cin>>newproduct->quantity;

    newproduct->next=0;
    last->next = newproduct;
    last = newproduct;
    system("cls");
    cout<<("\n Added Successfully\n");
}

void delete_item()
{
    system("cls");
    if(start==0)
    {
        cout<<("\nThere is No item!\n");
    }
    else
    {
        int Sri,N=0;
        cout<<("\nEnter Product Code no. for Delete :\n ");
        cin>>Sri;
        if(Sri==start->sri)
        {
            delete_first();
        }
        else
        {
            product *preProduct;
            current = start;
            while(current!=NULL)
            {
                preProduct = current;
                current=current->next;
                if(Sri==current->sri)
                {
                    N=1;
                    preProduct->next = current->next;
                    cout<<("\n Remove Successfully\n");
                    break;
                }
            }
        }
        if(N==0)
            cout<<("\nProduct Not Found!\n");
    }
}


void delete_first()
{
    system("cls");
    if(start==0)
        cout<<("\nThere is No item!\n")<<endl;
    else
    {
        current = start;
        start = start->next;
        free(current); // free the deleted product
        cout<<("\n Deleted Successfully\n");
    }
}

void sorting()
{
    system("cls");
    product *resProduct,*nextProduct;
    resProduct = start;
    while(resProduct!=0)
    {
        nextProduct = resProduct->next;

        while(nextProduct!=0)
        {
            if(resProduct->sri>nextProduct->sri)
            {
                swap_digit(&resProduct->sri, &nextProduct->sri);
                word_swap(resProduct->pname, nextProduct->pname);
                swap_Float(&resProduct->price, &nextProduct->price);
            }
            nextProduct = nextProduct->next;
        }
        resProduct = resProduct->next;
    }
    cout<<("\nProduct is Now Sorted\n");
}

void theme()
{
    cout<<("\n********************** Product  List ************************\n");
    cout<<("\n    Serial no\t\tProduct Name\t\t\t   Price\t\t\t  Quantity\n");
    cout<<("--------------------------------------------------------------------------------------------------\n");
}

void display()
{
    //system("color 05");
    system("cls");
    sorting();
    if(start==0)
    {
        cout<<("There are no Records!\n");
    }
    else
    {
        theme();


        current = start;
        while(current!=NULL)
        {
            cout << " "<<current->sri << " \t\t \t"
                 << current->pname <<  "\t\t\t\t"
                 << current->price <<"\t\t\t\t"
                 <<current->quantity<<endl;
            current = current->next;
        }

        cout<<("\n");
    }
}

void Forcounting()
{
    system("cls");
    current = start;
    int count_all_records=0;
    while(current!=NULL)
    {
        count_all_records++;
        current = current->next;
    }
    cout<<"\nTotal Number of Product:-   "<<count_all_records<<endl;
}


void product_search()
{
    system("cls");
    int Sri,flag=0;
    cout<<("\nEnter Product Code no. for Search: ");
    cin>>Sri;
    current = start;
    while(current!=NULL)
    {
        if(Sri==current->sri)
        {
            theme();
            flag=1;
            cout << " "<<current->sri << " \t\t\t\t"
                 << current->pname << "\t\t\t\t"
                 << current->price << "\t\t\t\t"
                 <<current->quantity<< endl;
            break;
        }
        current=current->next;
    }
    if(flag==0)
        cout<<("\nProduct Not Found!\n");
}

void swap_digit(long int *a,long int *b)
{
    int current;
    current  = *a;
    *a = *b;
    *b = current;
}


void word_swap(char *str1, char *str2)
{
    char *current = (char *)malloc((strlen(str1) + 1) * sizeof(char));
    strcpy(current, str1);
    strcpy(str1, str2);
    strcpy(str2, current);
    free(current);
}

void swap_Float(float *x, float *y)
{
    float current;
    current  = *x;
    *x = *y;
    *y = current;
}

void wallpaper()
{
    cout<<("---------------------------------------------------------------------------------------------------------\n");
    cout<<("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    cout<<("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    cout<<("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    cout<<("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    cout<<("|\t\t\t\t==================================\t\t\t\t\t\t|\n");
    cout<<("|\t\t\t\t|\t     WELCOME TO \t |\t\t\t\t\t\t|\n");
    cout<<("|\t\t\t\t|\t   MY PRESENTION  \t |\t\t\t\t\t\t|\n");
    cout<<("|\t\t\t\t|\tPRODUCT MANAGEMENT SYSTEM|\t\t\t\t\t\t|\n");
    cout<<("|\t\t\t\t==================================\t\t\t\t\t\t|\n");
    cout<<("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    cout<<("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    cout<<("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    cout<<("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    cout<<("---------------------------------------------------------------------------------------------------------\n");

}


