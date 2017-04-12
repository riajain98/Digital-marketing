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

       void ViewProducts()
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

       void SetProduct()
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

