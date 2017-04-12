#include<iostream>
#include<fstream>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<stdio.h>


using namespace std;
class Product
{
public:

           char pname[30],type[30];
           int price,quantity,pid;

public:

       void SetProduct()
        {
            cout<<"\nEnter the ID of the Product:: ";
            cin>>pid;
            cin.ignore();
            cout<<"\nEnter the Type of Product :: ";
            cin.getline(type,15);
            cin.ignore();
            cout<<"\nProduct-Name ::";
            cin>>pname;
            cin.ignore();
            cout<<"\nProduct-Price ::";
            cin>>price;
            cin.ignore();
            cout<<"\nProduct-Quantity :: ";
            cin>>quantity;
            cin.ignore();

        }

        void Display()
       {
           cout<<"\nThe ID of the Product = "<<pid;
           cout<<"\nThe Type of Product:: "<<type;
           cout<<"\nThe Product-Name is = " <<pname;
           cout<<"\nProduct-Price is = "<<price;
           cout<<"\nProduct-Quantity is = "<<quantity;

           cout<<endl;
       }

      string GetProductType()
        {
            return type;
        }

       int GetQuantity()
       {
           return quantity;
       }
       string GetProductName()
       {
           return pname;
       }

       int GetProductPrice()
       {
           return price;
       }

       int GetProductID()
       {
           return pid;
       }
};

class Customer
{
public:
        char pass[10],name[30];
        int cusid,balance;
public:

       void New_Cust()
       {
           cout<<"\nEnter the ID :: ";
           cin>>cusid;
           cin.ignore();
           cout<<"\nEnter the Name :: ";
           cin.getline(name,30);
           cin.ignore();
           cout<<"\nEnter the Password :: \n";
           cin.getline(pass,8);
           cin.ignore();
           cout<<"\nEnter You Initial Balance :: ";
           cin>>balance;
           cin.ignore();
       }
       void Display()
       {
           cout<<"\nYou User Name is = "<<name;
           cout<<"\nThe Password is = "<< pass;
           cout<<"\nThe Customer ID = "<<cusid;
       }
       string GetName()
       {
           return name;
       }
       string GetPassword()
       {
           return pass;
       }

       int GetCustomerID()
       {
           return cusid;
           cout<<"\nYour Customer ID is :: "<<cusid;
       }

       int GetCustomerBalance()
       {
           return balance;
       }

       void AddBalance()
       {
           int addb;
           cout<<"\nEnter the Amount to Add into the Balance :: ";
           cin>>addb;
           addb=balance + addb;
           cout<<"\nYour Total Balance is :: \n"<<addb;
       }



};
class CreateAccount
{
public:
        int i;

public:

    void CreateAcc()
    {
          Customer cs[3];       //Creating Customer Objects
n:
          fstream file;
          int i;

               file.open("customer.txt",ios::out | ios::app);

                for(i=0;i<1;i++)
                  {
                    cs[i].New_Cust();
                    file.write((char*)&cs[i],sizeof(cs[i]));
                  }
           file.close();

           char ch4;

           cout<<"\nWant to Enter the another Account Press y or To exit n \n";
           cin>>ch4;

                    if(ch4=='y' || ch4=='Y')
                      {
                         goto n;
                      }

                     else if(ch4=='n' || ch4=='N')
                        {
                           exit(0);
                        }
                         else
                           {
                                cout<<"\nPlease Enter the Correct Choice !!\n";
                           }
       }

};
class ViewProducts
{
public:

        int i;
        char choice;
public:

      Product ps;

        void Show_Products()
              {
                  int i;
                    char choice;
                    Product ps;
                    fstream f;

                  cout<<"\n_________________________________________________________________________\n";
                  cout<<"\n************ The Following Products are available to Sell ***************\n";
                  cout<<"\n_________________________________________________________________________\n";


                   		f.open("product.txt",ios::binary|ios::in);
		                   f.read((char*)&ps,sizeof(ps));

		                   while(!f.eof())
		                      {

		                          ps.Display();
		                             f.read((char*)&ps,sizeof(ps));

	 	                             if(f.eof())
		                              {
		                                cout<<"\n\n   End of the file reached\n\n";
                                      }
		                      }
		                          f.close();


              }

};


class Login
{
public:
        char tempcname[10],temppass[8];

public:

           ViewProducts vp;

           void loginCust()
            {
                Customer ct;

            int rn;
             char found='n',tempn[10],tempp[10];

                ifstream f3("customer.txt",ios::in );

		            cout<<"\nEnter Your Name ::\t";
		             cin>>tempn;

		            cout<<"\nEnter Your Password :: ";
		             cin>>tempp;

		                while(!f3.eof())
		                  {
		                      f3.read((char*)&ct,sizeof(ct));

		                      if(ct.GetName()==tempn && ct.GetPassword()==tempp)
		                           {
                                      f3.read((char*)&ct,sizeof(ct));

         		                             ct.Display();

		                              found='y';

		                        break;

		                            }
		                  }
		                         if(found=='n')
		                            cout<<"\n\n\tRECORD NOT FOUND!!!!!!!!!!!!!\n"<<endl;

		                 f3.close();
        }

};

class SetProduct
{
public:
          int i;
          char choice;
public:

           Product pr;

         void SetPro()
         {
            fstream outfile;

admin:
                system("cls");

                cout<<"\nWel Come to the Section of Set Products\n";

g:

                   pr.SetProduct();

          while(!outfile.eof())
                 {
                     ofstream outfile("product.txt",ios::app|ios::binary|ios::out);
                       outfile.write(reinterpret_cast<char*>(&pr),sizeof(pr));
//

                   cout<<"\nwant to enter more details if yes enter y or to goto Main menu  Enter n :: ";
                   cin>>choice;

                    if(choice=='y' || choice=='Y')
                      {
                         cin.ignore();
                         goto g;
                      }

                     else if(choice=='n' || choice=='N')
                        {
                            char o;
                            outfile.close();
                            system("cls");
                            cout<<"\nEnter S for Set Product and d for View Products :: ";
                            cin>>o;

                            if(o=='s' || o=='S')
                             {
                                  goto g;
                             }
                             else if(o=='d' || 0=='D')
                               {

                                    int i;
                                    char choice;
                                    Product ps;
                                    fstream f;
                                    f.open("product.txt",ios::in | ios::binary);

		                    f.read(reinterpret_cast<char*>(&ps),sizeof(ps));

		                   while(f)
		                      {

                                    ps.Display();
                                    f.read(reinterpret_cast<char*>(&ps),sizeof(ps));

	 	                             if(f.eof())
		                              {
		                                cout<<"\n\n   End of the file reached\n\n";
                                      }
		                      }
		                          f.close();

                                }
                        }
                         else
                           {
                                goto g;
                                cout<<"\nPlease Enter the Correct Choice !!\n";
                           }

                        outfile.close();

                     }
         }


};


class PurchaseProduct
{
public:

       char Pname[10];
public:


            void SearchProduct()
		       {
		             Product pr;
		             Customer cs;

	 	            int rn;
		            char found='n';

		            ifstream f1("product.txt",ios::in );

		            cout<<"\n\n Enter The Product ID to buy the Product :\t";
		            cin>>rn;


		                while(!f1.eof())
		                  {
		                      f1.read((char*)&pr,sizeof(pr));

		                      if(pr.GetProductID()==rn )
		                           {
		                              pr.Display();

		                              found='y';

		                        break;

		                            }
		                  }
		                         if(found=='n')
		                            cout<<"\n\n\tRECORD NOT FOUND!!!!!!!!!!!!!\n"<<endl;

		                 f1.close();


		       int cid;

		            ifstream f2("customer.txt",ios::in );

		            cout<<"\n\n Enter The Customer ID to buy the Product :\t";
		            cin>>cid;

		                while(!f2.eof())
		                  {
		                      f2.read((char*)&cs,sizeof(cs));

		                      if(cs.GetCustomerID()==cid)
		                           {
		                              cs.Display();

		                              found='y';

		                        break;

		                            }
		                  }
		                         if(found=='n')
		                            cout<<"\n\n\tRECORD NOT FOUND!!!!!!!!!!!!!\n"<<endl;

		                 f2.close();

		                  int totalb;

                                        totalb=cs.GetCustomerBalance()-pr.GetProductPrice();

		                                     cout<<"\n\n\n Your Total Bill is :: \n"<<totalb;
		                                     cout<<endl<<endl<<endl;

		       }
};


int main()
{

             cout<<"\n_________________________________________________________________________________\n";
             cout<<"\n^^^^^^^^^^^^^^^^^^^^^ Wel-Come to Digital Marketing ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
             cout<<"\n_________________________________________________________________________________\n";

             cout<<endl<<endl;
        abc:
       //     system("cls");
             char ch1;
             cout<<"\nEnter a For Administration :\n";
             cout<<"\nEnter u For Users :  \n";
             cin>>ch1;

             if(ch1=='u' || ch1=='U')
             {
                  char ch2;
 option:
                  cout<<"Enter N for Create a New Account : ";
                  cout<<"Enter L for Login : ";
                  cin>>ch2;

                         if(ch2=='n' || ch2=='N')
                           {
                              CreateAccount ca;
                              ca.CreateAcc();
                           }
                    else if(ch2=='l' || ch2=='L')
                           {

                            system("cls");

                                cout<<"\n____________________________________________________________________________\n";
                                cout<<"\n$$$$$$$$$$$$$$$$$$$$$$$ Wel-Come to Digital Marketing $$$$$$$$$$$$$$$$$$$$$$ \n";
                                cout<<"\n____________________________________________________________________________\n";

                                Login l;
                                l.loginCust();

                                    ViewProducts vp;
                                    vp.Show_Products();

                                  cout<<"\n____________________________________________________________________________\n";

                                     PurchaseProduct pp;
                                     pp.SearchProduct();


                                 }
                                     else
                                      {
                                         cout<<"\nPlease Enter the Correct Choice !!\n";
                                         goto option;
                                      }

                             }




        else if(ch1=='a' || ch1=='A')
             {
                 system("cls");
                 char str[10];
                 int k;
    password:;
             	cout<<"\n\n\tPLEASE BE CAREFUL ENTER THE PASSWORD IN SMALL LETTERS\n";
	            cout<<"\n\t\tPASSWORD DOES NOT CONTAINS ANY NUMBER\n\n\n";
	            cout<<"\n\n\t\t\tEnter your Password\t";

	               str[0]=getch();
	               cout<<"*";

	                 str[1]=getch();
                   	 cout<<"*";

	                   str[2]=getch();
	                   cout<<"*";

	                    str[3]=getch();
	                    cout<<"*";

	                      str[4]=getch();
                          cout<<"*";

	                       str[5]=getch();
	                       cout<<"*";

	                         str[6]=getch();
                             cout<<"*";

	                          str[7]='\0';
	                          cout<<"*";

	                             if(strcmp(str,"asthapa")==0)
	                               {
	                                     system("cls");

                    cout<<"\n_____________________________________________________________________________ \n";
                    cout<<"\n***************** Wel come to the Section of Administration *****************\n";
                    cout<<"\n_____________________________________________________________________________ \n";

                              char ch3;
                do
                {


                  cout<<"\n____________________________________________________________________________\n";
                  cout<<"\nEnter S for Set the Products\n";
                  cout<<"\nEnter D for View the Product DataBase\n";
                  cout<<"\nEnter e to exit";
                  cout<<"\n____________________________________________________________________________\n";
                  cin>>ch3;

                         if(ch3=='S' || ch3=='s')
                            {
                                SetProduct sp;
                                sp.SetPro();
                            }
                              else if(ch3=='D' || ch3=='d')
                                 {
                                     ViewProducts v;
                                     v.Show_Products();
                                 }
                                 else if(ch3=='e' || ch3=='E')
                                 {
                                    goto abc;
                                    system("cls");
                                 }
                                  else
                                    {
                                      cout<<"\nPlease Enter the Correct Choice !!\n";
                                      cout<<endl<<endl;
                                    }
}
while(ch3!='e');
    }
    else
	{
	   cout<<"\n\n\t\t\t$$$$$$ Ooop's wrong password $$$$$$\n";
	     cout<<"\n\n\t\t\t%%%%%% Please re-enter the password%%%%%%\n";

          	getch();
	           k++;

	if(k==3)
	{
	cout<<"\nExiting from the project!!!!! \n";
	getch();
	exit(0);
	}
	   goto password;
}



       }
              else
                {
                   cout<<"\nPlease Enter the Correct Choice !!\n";
                   cout<<endl<<endl;
                }
}





