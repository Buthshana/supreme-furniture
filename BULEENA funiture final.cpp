#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream>
#include <stdlib.h>
void creat_product();
void show_product();
void write_product();
void display_all_product();
void modify_product();
void menu();
void admin_menu();
void admin_login();
void help();
void intro();
void first();

using namespace std;
string adminUsername = "user";
string adminPassword = "1234";
int isLogged = 0;

/*
  Create Product
*/

    class product
    {
        int pno;
        char name[100];
        float price, qty, tax, dis;
        public:
            void create_product()
            {
                cout << "Please Enter The Product ID ";
                cin >> pno;
                cout << "Please Enter The Product Name ";
                cin>>gets(name);
                cout << "Please Enter The Product Price ";
                cin >> price;
                cout << "Please Enter The Discount (%) ";
                cin >> dis;
            }

        void show_product()
        {
            cout << "The Product No. of The Product : " << pno;
            cout << "The Name of The Product : ";
            puts(name);
            cout << "\nThe Price of The Product : " << price;
            cout << "\nDiscount : " << dis;
        }

        int retpno()
        {
            return pno;
        }

        float retprice()
        {
            return price;
        }

        char * retname()
        {
            return name;
        }

        int retdis()
        {
            return dis;
        }

    }; //class ends here
    
	fstream fp;
    product pr;
   
   //write product 
    void write_product()
{
    fp.open("Shop.dat", ios::out | ios::app);
    pr.create_product();
    fp.write((char * ) & pr, sizeof(product));
    fp.close();
    cout << "\n\nThe Product Has Been Created ";
    getch();
    
}
    // view all product
    void display_all_products()
{

    cout << "\n\n\n\t\tDISPLAY ALL PRODUCTS !!!\n\n";
    fp.open("Shop.dat", ios:: in );
    while (fp.read((char * ) & pr, sizeof(product)))
    {
        pr.show_product();
        cout << "\n\n====================================\n";
        getch();
        
    }
    fp.close();
    getch();
    system("cls");
}

//Update Products

void modify_product()
{
    int no, found = 0;

    cout << "\n\n\tTo Update ";
    cout << "\n\n\tPlease Enter The Product ID";
    cin >> no;
    fp.open("Shop.dat", ios:: in | ios::out);
    while (fp.read((char * ) & pr, sizeof(product)) && found == 0)
    {
        if (pr.retpno() == no)
        {
            pr.show_product();
            cout << "\nPlease Enter The New Details of Product" << endl;
            pr.create_product();
            int pos = -1 * sizeof(pr);
            fp.seekp(pos, ios::cur);
            fp.write((char * ) & pr, sizeof(product));
            cout << "\n\n\t Product Updated";
            found = 1;
        }
    }
    fp.close();
    if (found == 0)
        cout << "\n\n Product Not Found ";
    getch();
    system("cls");
}
void menu()
{

    fp.open("Shop.dat", ios:: in );
    if (!fp)
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File ";

        cout << "\n\n\n Program is closing ....";
        getch();
        system("cls");

    }

    cout << "\n\n\t\tPRODUCT MENU\n\n";
    cout << "====================================================\n";
    cout << "P.NO.\t\tNAME\t\tPRICE\n";
    cout << "====================================================\n";

    while (fp.read((char * ) & pr, sizeof(product)))
    {
        cout << pr.retpno() << "\t\t" << pr.retname() << "\t\t" << pr.retprice() << endl;
    }
    fp.close();
}

//Place Order
void place_order()
{
    int order_arr[50], quan[50], c = 0;
    float amt, damt, total = 0;
    char ch = 'Y';
    menu();
    cout << "\n============================";
    cout << "\n PLACE YOUR ORDER";
    cout << "\n============================\n";
    do
    {
        cout << "\n\nEnter The Product ID : ";
        cin >> order_arr[c];
        cout << "\nQuantity in number : ";
        cin >> quan[c];
        c++;
        cout << "\nDo You Want To Order Another Product ? (y/n)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\nThank You For Placing The Order";
    getch();

    cout << "\n\n******************************** INVOICE ************************\n";
    cout << "\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\ n ";

    for (int x = 0; x <= c; x++)
    {
        fp.open("Shop.dat", ios:: in );
        fp.read((char * ) & pr, sizeof(product));
        while (!fp.eof())
        {
            if (pr.retpno() == order_arr[x])
            {
                amt = pr.retprice() * quan[x];
                damt = amt - (amt * pr.retdis() / 100);
                cout << "\n" << order_arr[x] << "\t" << pr.retname() <<
                    "\t" << quan[x] << "\t\t" << pr.retprice() << "\t" << amt << "\t\t" << damt;
                total += damt;
            }
            fp.read((char * ) & pr, sizeof(product));
        }

        fp.close();
    }
    cout << "\n\n\t\t\t\t\tTOTAL = " << total;
    getch();
    system("CLS");
}


//intro
void intro()
{
	
	 system ("color FC");
      cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<<endl;
	 cout<<"\t\t\t\t\t\t\t\t* * * * * * * * * * * * *\t\t\t\t\t\t\t\t"<<endl;
	 cout<<"\t\t\t\t\t\t\t\t* * * * * * * * * * * * *\t\t\t\t\t\t\t\t"<<endl;
	 cout<<"\t\t\t\t\t\t\t\t* * * * * * * * * * * * *\t\t\t\t\t\t\t\t"<<endl;
	 cout<<"\t\t\t\t\t\t\t\t* < SUPRIME FURNITURE > *\t\t\t\t\t\t\t\t"<<endl;
	 cout<<"\t\t\t\t\t\t\t\t* * * * Yakkala * * * *\t\t\t\t\t\t\t\t"<<endl;
	 cout<<"\t\t\t\t\t\t\t\t* * * * * * * * * * * * *\t\t\t\t\t\t\t\t"<<endl;
	  cout<<"\t\t\t\t\t\t\t\t* * * * * * * * * * * * *\t\t\t\t\t\t\t\t"<<endl;
	 cout<<"\t\t\t\t\t\t\t\t* * * * * * * * * * * * *\t\t\t\t\t\t\t\t"<<endl;
	cout<<"\t\t\t\t\t\t\tWelcome to the Suprime Furinture showroom\t\t\t"<<endl;
	cout<<"\n\nCreated by - Suprime IT "<<endl;
     cout<<"press any key to continue........";
     getch();
     system("cls");
	
}
//Admin menu
void admin_menu()
{

    char ch2;
    cout << "\n\n\n\tADMIN MENU";
    cout << "\n\n\t1.ADD PRODUCT";
    cout << "\n\n\t2.DISPLAY ALL FURNITURES";
    cout << "\n\n\t3.UPDATE PRODUCT";
    cout << "\n\n\t4.VIEW UPDATED ITEM";
    cout << "\n\n\t5.LOGOUT";
    cout << "\n\n\tPlease Enter Your Choice (1-5) ";
    ch2 = getche();
    system("cls");
    switch (ch2)
    
    {
    case '1':
        write_product();
        admin_menu();
        break;
    case '2':
        display_all_products();
        admin_menu();
        break;
    case '3':
        modify_product();
        break;
    case '4':
        menu();
        getch();
    case '5':
        isLogged = 0;
        break;
    default:
        admin_menu();
    }
}
void admin_login()
{
    system ("color FC");
    do{
        string useername, password;
        cout << "\n\WELCOME TO THE LOGIN PAGE\n";
        cout << "\tEnter your USERNAME : ";
        cin >> useername;
        cout << "\tEnter your PASSWORD : ";
        cin >> password;
        if(useername == adminUsername && password == adminPassword){
            isLogged = 1;
            system("CLS");
            admin_menu();
        }else{
            isLogged = 0;
            cout << "\tInvalid Login";
             cout << " ";
        }
    }while(isLogged == 1);
	getch();
    system("cls");
}
void Help()
{
	cout<<"Welcome to SUPRIME Showroom"<<endl;
	cout<<"Contact - 0732355515"<<endl;
	cout<<"Email - suprimss@gmail.com"<<endl;
	cout<<"Location - 35A Kandy road,Yakkala"<<endl;
	cout<<"google map-http\\yakkala.suprime.loc"<<endl;
	getch();
	system("cls");
}
// Home page
int main()
{

    char ch;
    intro();
    system ("color FC");
    do
    {
    	
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. Customer";
        cout << "\n\n\t02. LOGIN";
        cout << "\n\n\t03. Company Details";
        cout << "\n\n\t04. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-4) ";
        ch = getche();
        system("cls");
        switch (ch)
        {
        case '1':
            place_order();
            getch();
            break;    
        case '2':
            if(isLogged == 0){
                admin_login();
            }else{
                admin_menu();
            }

            break;
        case '3':
            Help();
            getch();
            break;
        case '4':
        	system("cls");
        default :
            cout<<"";
        }
    } while (ch != '3');
}

