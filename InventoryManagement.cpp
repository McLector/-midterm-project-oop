//100% CODED BY: MYRE LECTOR MORADA
//C2A

#include <iostream>
#include <limits>
#include <vector>
#include <cctype>
#include <iomanip>
using namespace std;

struct Details
    {
        string category;
        string id;
        string name;
        int qty;
        int price;
    };

void DisplayMenu();
void CatergoryvValidator(string &a, string &t);
bool DuplicateValidator(vector<Details> a, Details b);
bool QuantityValidator(int &a);
bool PriceValidator(int &a);
bool LinearSearchID(vector<Details> a, Details &b, int &c);
bool IntChoiceValidator(int &a);

void SearchItem(vector<Details> a);
void SortItem(vector<Details> a);
void LowStack(vector<Details> a);



class ItemManagement
{
    public:
    virtual void AddItem(vector<Details> &a,string b)=0;
    virtual void UpdateItem(vector<Details> &a)=0;
    virtual void RemoveItem(vector<Details> &a)=0;
};

class ClothingSection : public ItemManagement
{
    private:
    vector<Details> clothD;

    public:

    Details getclothD(int a)
    {
        return clothD[a];
    };

    void AddItem(vector<Details> &a,string b) override{
        Details clothT;
        
        clothT.category=b;

        do
        {
        cout<<"Enter ID: ";
        cin>>clothT.id;
        } while (DuplicateValidator(clothD, clothT)!=true);
        
        cout<<"Enter Name: ";
        cin>>clothT.name;

        do
        {
            cout<<"Enter QTY: ";
            cin>>clothT.qty;
        }while(QuantityValidator(clothT.qty)!=true);
        do
        {
            cout<<"Enter Price: ";
            cin>>clothT.price;
        }while(PriceValidator(clothT.price)!=true);

        clothD.push_back(clothT);
        a.push_back(clothT);

        cout << "\nItem added successfully!\n"
                        << "ID: " << clothT.id << "\n"
                        << "Name: " << clothT.name << "\n"
                        << "Quantity: " << clothT.qty << "\n"
                        << "Price: " << clothT.price << "\n"; 

        system("pause");
        system("cls");

    };
    
    void UpdateItem(vector<Details> &a) override{
        Details clothT;
        int i;
        bool o;

        o=LinearSearchID(clothD, clothT, i);

        if(o==true)
        {
            cout<<"ID: "<<clothD[i].id<<endl;
            cout<<"Name: "<<clothD[i].name<<endl;
            cout<<"QTY: "<<clothD[i].qty<<endl;
            cout<<"Price: "<<clothD[i].price<<endl;

            cout<<"\nUpdate\n";
            do
            {
                cout<<"Enter New QTY: ";
                cin>>clothT.qty;
            }while(QuantityValidator(clothT.qty)!=true);

            do
            {
                cout<<"Enter New Price: ";
                cin>>clothT.price;
            }while(PriceValidator(clothT.price)!=true);

            clothD[i].qty = clothT.qty;
            clothD[i].price = clothT.price;

            for(int j=0;j<a.size(); j++)
            {
                if(clothD[i].category==a[j].category && clothD[i].id == a[j].id)
                {
                    a[j].qty = clothT.qty;
                    a[j].price = clothT.price;
                }
            };

            cout << "\nItem updated successfully!\n"
                        << "ID: " << clothD[i].id << "\n"
                        << "Name: " << clothD[i].name << "\n"
                        << "Quantity: " << clothD[i].qty << "\n"
                        << "Price: " << clothD[i].price << "\n"; 

            

        system("pause");
        system("cls");

        }

    };

    void RemoveItem(vector<Details> &a) override{
        Details clothT;
        string temp;
        int i;
        bool o;
        char choice;

        o=LinearSearchID(clothD, clothT, i);

        if(o==true)
        {
            cout<<"ID: "<<clothD[i].id<<endl;
            cout<<"Name: "<<clothD[i].name<<endl;
            cout<<"QTY: "<<clothD[i].qty<<endl;
            cout<<"Price: "<<clothD[i].price<<endl;
            temp=clothD[i].name;

            cout<<"Are you sure to delete[Y/N]: ";
            cin>>choice;

            if(choice=='Y' || choice || 'y')
            {
                
                for(int j=0;j<a.size(); j++)
                {
                    if(clothD[i].category==a[j].category && clothD[i].id == a[j].id)
                    {
                        a.erase(a.begin()+j);
                        clothD.erase(clothD.begin()+i);
                    }
                };
                cout<<"\nItem "<<"'"<<temp<<"'"<<" has been removed from the inventory.\n";
            }
            else
            {
                return;
            }
            

        system("pause");
        system("cls");

        }
    };

    void displayclothD()
    {
        system("cls");
        cout << "\n    Clothing Section Item List\n";

        cout<<setw(3)<<"ID"<<setw(15)<<"NAME"<<setw(15)<<"QTY"<<setw(17)<<"PRICE"<<endl;
        for(int i=0; i<clothD.size(); i++)
        {
        cout<<setw(2)<<clothD[i].id<<setw(15)<<clothD[i].name<<setw(16)<<clothD[i].qty<<setw(16)<<clothD[i].price<<endl; 
        }
        system("pause");
    }
};

class ElectronicsSection : public ItemManagement
{
    private:
        vector<Details> electroD;

    public:

        Details getelectroD(int a)
        {
            return electroD[a];
        }

        void AddItem(vector<Details> &a,string b) override{
        Details electroT;

        electroT.category=b;

        do
        {
        cout<<"Enter ID: ";
        cin>>electroT.id;
        } while (DuplicateValidator(electroD, electroT)!=true);
        
        cout<<"Enter Name: ";
        cin>>electroT.name;

        do
        {
            cout<<"Enter QTY: ";
            cin>>electroT.qty;
        }while(QuantityValidator(electroT.qty)!=true);
        do
        {
            cout<<"Enter Price: ";
            cin>>electroT.price;
        }while(PriceValidator(electroT.price)!=true);

        electroD.push_back(electroT);
        a.push_back(electroT);

        cout << "\nItem added successfully!\n"
                        << "ID: " << electroT.id << "\n"
                        << "Name: " << electroT.name << "\n"
                        << "Quantity: " << electroT.qty << "\n"
                        << "Price: " << electroT.price << "\n"; 

        system("pause");
        system("cls");

    };

        void UpdateItem(vector<Details> &a) override{
        Details electroT;
        int i;
        bool o;

        o=LinearSearchID(electroD, electroT, i);

        if(o==true)
        {
            cout<<"ID: "<<electroD[i].id<<endl;
            cout<<"Name: "<<electroD[i].name<<endl;
            cout<<"QTY: "<<electroD[i].qty<<endl;
            cout<<"Price: "<<electroD[i].price<<endl;

            cout<<"\nUpdate\n";
            do
            {
                cout<<"Enter New QTY: ";
                cin>>electroT.qty;
            }while(QuantityValidator(electroT.qty)!=true);

            do
            {
                cout<<"Enter New Price: ";
                cin>>electroT.price;
            }while(PriceValidator(electroT.price)!=true);

            electroD[i].qty = electroT.qty;
            electroD[i].price = electroT.price;

            for(int j=0;j<a.size(); j++)
            {
                if(electroD[i].category==a[j].category && electroD[i].id == a[j].id)
                {
                    a[j].qty = electroT.qty;
                    a[j].price = electroT.price;
                }
            };


            cout << "\nItem updated successfully!\n"
                        << "ID: " << electroD[i].id << "\n"
                        << "Name: " << electroD[i].name << "\n"
                        << "Quantity: " << electroD[i].qty << "\n"
                        << "Price: " << electroD[i].price << "\n"; 

            

        system("pause");
        system("cls");

        }

    };

        void RemoveItem(vector<Details> &a) override{
        Details electroT;
        string temp;
        int i;
        bool o;
        char choice;

        o=LinearSearchID(electroD, electroT, i);

        if(o==true)
        {
            cout<<"ID: "<<electroD[i].id<<endl;
            cout<<"Name: "<<electroD[i].name<<endl;
            cout<<"QTY: "<<electroD[i].qty<<endl;
            cout<<"Price: "<<electroD[i].price<<endl;
            temp=electroD[i].name;

            cout<<"Are you sure to delete[Y/N]: ";
            cin>>choice;

            if(choice=='Y' || choice || 'y')
            {
                for(int j=0;j<a.size(); j++)
                {
                    if(electroD[i].category==a[j].category && electroD[i].id == a[j].id)
                    {
                        a.erase(a.begin()+j);
                        electroD.erase(electroD.begin()+i);
                        break;
                    }
                };
                cout<<"\nItem "<<"'"<<temp<<"'"<<" has been removed from the inventory.\n";
            }
            else
            {
                return;
            }
            

        system("pause");
        system("cls");

        }
    };

        void displayelectroD()
    {
        system("cls");
        cout << "\n    Electronics Section Item List\n";
        cout<<setw(3)<<"ID"<<setw(15)<<"NAME"<<setw(15)<<"QTY"<<setw(17)<<"PRICE"<<endl;
        for(int i=0; i<electroD.size(); i++)
        {
        cout<<setw(2)<<electroD[i].id<<setw(15)<<electroD[i].name<<setw(16)<<electroD[i].qty<<setw(16)<<electroD[i].price<<endl; 
        }
        system("pause");
    }
};

class EntertainmentSection : public ItemManagement
{
    private:
        vector<Details> entertainD;

    public:

        Details getelectroD(int a)
        {
            return entertainD[a];
        }

        void AddItem(vector<Details> &a,string b) override{
        Details entertainT;

        entertainT.category=b;

        do
        {
        cout<<"Enter ID: ";
        cin>>entertainT.id;
        } while (DuplicateValidator(entertainD, entertainT)!=true);
        
        cout<<"Enter Name: ";
        cin>>entertainT.name;

        do
        {
            cout<<"Enter QTY: ";
            cin>>entertainT.qty;
        }while(QuantityValidator(entertainT.qty)!=true);
        do
        {
            cout<<"Enter Price: ";
            cin>>entertainT.price;
        }while(PriceValidator(entertainT.price)!=true);

        entertainD.push_back(entertainT);
        a.push_back(entertainT);

        cout << "\nItem added successfully!\n"
                        << "ID: " << entertainT.id << "\n"
                        << "Name: " << entertainT.name << "\n"
                        << "Quantity: " << entertainT.qty << "\n"
                        << "Price: " << entertainT.price << "\n"; 

        system("pause");
        system("cls");

    };

        void UpdateItem(vector<Details> &a) override{
        Details entertainT;
        int i;
        bool o;

        o=LinearSearchID(entertainD, entertainT, i);

        if(o==true)
        {
            cout<<"ID: "<<entertainD[i].id<<endl;
            cout<<"Name: "<<entertainD[i].name<<endl;
            cout<<"QTY: "<<entertainD[i].qty<<endl;
            cout<<"Price: "<<entertainD[i].price<<endl;

            cout<<"\nUpdate\n";
            do
            {
                cout<<"Enter New QTY: ";
                cin>>entertainT.qty;
            }while(QuantityValidator(entertainT.qty)!=true);

            do
            {
                cout<<"Enter New Price: ";
                cin>>entertainT.price;
            }while(PriceValidator(entertainT.price)!=true);

            entertainD[i].qty = entertainT.qty;
            entertainD[i].price = entertainT.price;

            for(int j=0;j<a.size(); j++)
            {
                if(entertainD[i].category==a[j].category && entertainD[i].id == a[j].id)
                {
                    a[j].qty = entertainT.qty;
                    a[j].price = entertainT.price;
                }
            };


            cout << "\nItem updated successfully!\n"
                        << "ID: " << entertainD[i].id << "\n"
                        << "Name: " << entertainD[i].name << "\n"
                        << "Quantity: " << entertainD[i].qty << "\n"
                        << "Price: " << entertainD[i].price << "\n"; 

            

        system("pause");
        system("cls");

        }

    };

        void RemoveItem(vector<Details> &a) override{
        Details entertainT;
        string temp;
        int i;
        bool o;
        char choice;

        o=LinearSearchID(entertainD, entertainT, i);

        if(o==true)
        {
            cout<<"ID: "<<entertainD[i].id<<endl;
            cout<<"Name: "<<entertainD[i].name<<endl;
            cout<<"QTY: "<<entertainD[i].qty<<endl;
            cout<<"Price: "<<entertainD[i].price<<endl;
            temp=entertainD[i].name;

            cout<<"Are you sure to delete[Y/N]: ";
            cin>>choice;

            if(choice=='Y' || choice || 'y')
            {
                for(int j=0;j<a.size(); j++)
                {
                    if(entertainD[i].category==a[j].category && entertainD[i].id == a[j].id)
                    {
                        a.erase(a.begin()+j);
                        entertainD.erase(entertainD.begin()+i);
                        break;
                    }
                };
                cout<<"\nItem "<<"'"<<temp<<"'"<<" has been removed from the inventory.\n";
            }
            else
            {
                return;
            }
            

        system("pause");
        system("cls");

        }
    };

        void displayelectroD()
    {
        system("cls");
        cout << "\n    Entertainment Section Item List\n";
        cout<<setw(3)<<"ID"<<setw(15)<<"NAME"<<setw(15)<<"QTY"<<setw(17)<<"PRICE"<<endl;
        for(int i=0; i<entertainD.size(); i++)
        {
        cout<<setw(2)<<entertainD[i].id<<setw(15)<<entertainD[i].name<<setw(16)<<entertainD[i].qty<<setw(16)<<entertainD[i].price<<endl; 
        }
        system("pause");
    }
};

int main()
{
    ClothingSection clothes;
    ElectronicsSection electro;
    EntertainmentSection entertain;
    string category,temp;
    bool r=false,sc=false;
    vector<Details> MainList;
    Details stemp;
    //stemp=clothes.getclothD(0); - For private access

    do
    {
        int choice;
        system("cls");
        DisplayMenu();
        cin>>choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch(choice)
            {
                case 1:
                    do
                    {
                    system("cls");
                    cout<<"\nADD ITEM";
                    CatergoryvValidator(category,temp);
                    if(category=="CLOTHING")
                    {
                        clothes.AddItem(MainList,category);
                        r=true;
                    }
                    else if(category=="ELECTRONICS")
                    {
                        electro.AddItem(MainList,category);
                        r=true;
                    }
                    else if(category=="ENTERTAINMENT")
                    {
                        entertain.AddItem(MainList,category);
                        r=true;
                    }
                    else
                    {
                        cout<<"Category "<<"'"<<temp<<"'"<<" does not exist!\n";
                        system("pause");
                    };  
                    } while(r!=true);
                    category=" ";
                    temp=" ";
                    r=false;
                break;
                case 2:
                    if(MainList.size()==0)
                    {
                        cout<<"Inventory is empty. No item to be removed.\n";
                        system("pause");
                        continue;
                    };

                    do
                    {
                    system("cls");
                    cout<<"\nUPDATE ITEM";
                    CatergoryvValidator(category,temp);
                    if(category=="CLOTHING")
                    {
                        clothes.UpdateItem(MainList);
                        r=true;
                    }
                    else if(category=="ELECTRONICS")
                    {
                        electro.UpdateItem(MainList);
                        r=true;
                    }
                    else if(category=="ENTERTAINMENT")
                    {
                        entertain.UpdateItem(MainList);
                        r=true;
                    }
                    else
                    {
                        cout<<"Category "<<"'"<<temp<<"'"<<" does not exist!\n";
                        system("pause");
                    };  
                    } while(r!=true);
                    category=" ";
                    temp=" ";
                    r=false;
                    break;
                case 3:
                    if(MainList.size()==0)
                    {
                        cout<<"Inventory is empty. No item to be removed.\n";
                        system("pause");
                        continue;
                    };
                    do
                    {
                    system("cls");
                    cout<<"\nREMOVE ITEM";
                    CatergoryvValidator(category,temp);
                    if(category=="CLOTHING")
                    {
                        clothes.RemoveItem(MainList);
                        r=true;
                    }
                    else if(category=="ELECTRONICS")
                    {
                        electro.RemoveItem(MainList);
                        r=true;
                    }
                    else if(category=="ENTERTAINMENT")
                    {
                        entertain.RemoveItem(MainList);
                        r=true;
                    }
                    else
                    {
                        cout<<"Category "<<"'"<<temp<<"'"<<" does not exist!\n";
                        system("pause");
                    };  
                    } while(r!=true);
                    category=" ";
                    temp=" ";
                    r=false;
                    break;
                case 4:
                    do
                    {
                    system("cls");
                    cout<<"\nDISPLAY ITEM";
                    CatergoryvValidator(category,temp);
                    if(category=="CLOTHING")
                    {
                        clothes.displayclothD();
                        r=true;
                    }
                    else if(category=="ELECTRONICS")
                    {
                        electro.displayelectroD();
                        r=true;
                    }
                    else if(category=="ENTERTAINMENT")
                    {
                        entertain.displayelectroD();
                        r=true;
                    }
                    else
                    {
                        cout<<"Category "<<"'"<<temp<<"'"<<" does not exist!\n";
                        system("pause");
                    };  
                    } while(r!=true);
                    category=" ";
                    temp=" ";
                    r=false;
                    break;
                case 5:
                    system("cls");
                    cout << "\n    Inventory Item List\n";
                    cout<<setw(3)<<"ID"<<setw(15)<<"NAME"<<setw(15)<<"QTY"<<setw(17)<<"PRICE"<<setw(17)<<"CATEGORY"<<endl;
                    for(int i=0; i<MainList.size(); i++)
                    {
                    cout<<setw(2)<<MainList[i].id<<setw(15)<<MainList[i].name<<setw(16)<<MainList[i].qty<<setw(16)<<MainList[i].price<<setw(18)<<MainList[i].category<<endl; 
                    }
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    SearchItem(MainList);
                    break;
                case 7:
                    system("cls");
                    SortItem(MainList);
                    break;
                case 8:
                    system("cls");
                    LowStack(MainList);
                break;
                case 9:
                    sc=true;
                    break;
                default:
                break;
            }

    } while (sc!=true);

return 0;
};

void DisplayMenu()
{
            cout<<"\n                Item Management Inventory\n"
            <<"\nMENU\n"
            <<"1 - Add Item\n"
            <<"2 - Update Item\n" 
            <<"3 - Remove Item\n"
            <<"4 - Display Items by Category\n"
            <<"5 - Display All Items\n"
            <<"6 - Search Item\n"
            <<"7 - Sort Items\n"
            <<"8 - Display Low Stock Items\n"
            <<"9 - Exit\n";
}

void CatergoryvValidator(string &a,string &t)
{
                cout<<"\nCategories [CLOTHING] - [ELECTRONICS] - [ENTERTAINMENT]\n"   
                    <<"Enter Category: ";
                cin>>a;
                cin.ignore();
                cin.clear();
                t=a;

                for(char &c : a)
                {
                    c= toupper(c);
                };
};

bool DuplicateValidator(vector<Details> a, Details b)
{
    for(int i=0; i<a.size(); i++)
    {
        if(b.id==a[i].id)
        {
            cout<<"'ID "<<b.id<<"'"<<" Already exist. Please enter a different ID.\n\n";
            return false;
        }
    }
    return true;
};

bool QuantityValidator(int &a)
{
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
        return false;
    } else if (a <= 0) {
        cout << "Quantity must be greater than zero. Please try again.\n";
        return false;
    } else if (cin.peek() != '\n') {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
        return false;
    } else {
        return true;
    }
};

bool PriceValidator(int &a)
{
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
        return false;
    } else if (a <= 0) {
        cout << "Price must be greater than zero. Please try again.\n";
        return false;
    } else if (cin.peek() != '\n') {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
        return false;
    } else {
        return true;
    }
};

bool LinearSearchID(vector<Details> a, Details &b, int &c)
{
    string temp;
    bool f=false;
    cout<<"\nEnter ID: ";
    cin>>b.id;
    temp=b.id;

        for(int i=0; i<a.size(); i++)
        {
            if(b.id==a[i].id)
            {
                f=true;
                cout<<"\nItem Found!\n";
                c=i;
                return true;
            }
        }

    
        if(f==false)
        {
            cout<<"'"<<b.id<<"'"<<" ID not found.\n";
            system("pause");
            return false;
        }
        

};

void SearchItem(vector<Details> a)
{
    string id;
    bool check=false;
    cout<<"\nEnter ID: ";
    cin>>id;

        system("cls");
        cout<<"\nItem/s Found\n";
        for(int i=0; i<a.size(); i++)
        {
            if(id==a[i].id)
            {   
                cout<<"Category: "<<a[i].category<<"\n"
                    <<"ID: "<<a[i].id<<"\n"
                    <<"Name: "<<a[i].name<<"\n"
                    <<"QTY: "<<a[i].qty<<"\n"
                    <<"Price: "<<a[i].price<<"\n";
                check=true;
            }
        }

        if(check!=true)
        {
            system("cls");
            cout<<"\n'"<<id<<"'"<<" item not found!\n";

        }

        system("pause");

};

bool IntChoiceValidator(int &a)
{
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
        return false;
    }else if (cin.peek() != '\n') {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
        return false;
    } else {
        return true;
    }
}

void SortItem(vector<Details> a)
{
    int choice,choice2,s;
    s=a.size();

    do
    {
        cout<<"\n1 - QTY\n"
        <<"2 - Price\n"
        <<"Sort by: ";
        cin>>choice;
    } while (IntChoiceValidator(choice)==false);
    

    switch(choice)
    {
        case 1:
            do
            {
                cout<<"1 - Ascending\n"
                <<"2 - Descending\n"
                <<"Sort by: ";
                 cin>>choice2;
            } while (IntChoiceValidator(choice2)==false);

            if(choice2 == 1)
            {
                cout<<"\nItem list qty sorted in ascending order!\n";

                for(int i=0; i<s-1; i++)
                {
                    for (int j = 0; j<s-i-1; j++)
                    {
                        if(a[j].qty>a[j+1].qty)
                        {
                            swap(a[j], a[j + 1]);
                        }
                    }
                }
                    cout<<setw(3)<<"ID"<<setw(15)<<"NAME"<<setw(15)<<"QTY"<<setw(17)<<"PRICE"<<setw(17)<<"CATEGORY"<<endl;
                    for(int i=0; i<a.size(); i++)
                    {
                    cout<<setw(2)<<a[i].id<<setw(15)<<a[i].name<<setw(16)<<a[i].qty<<setw(16)<<a[i].price<<setw(18)<<a[i].category<<endl; 
                    }
                    system("pause");

                return;
            }
            else if(choice2 == 2)
            {
                cout<<"\nItem list qty sorted in descending order!\n";

                for(int i=0; i<s-1; i++)
                {
                    for (int j = 0; j<s-i-1; j++)
                    {
                        if(a[j].qty<a[j+1].qty)
                        {
                            swap(a[j], a[j + 1]);
                        }
                    }
                }
                    cout<<setw(3)<<"ID"<<setw(15)<<"NAME"<<setw(15)<<"QTY"<<setw(17)<<"PRICE"<<setw(17)<<"CATEGORY"<<endl;
                    for(int i=0; i<a.size(); i++)
                    {
                    cout<<setw(2)<<a[i].id<<setw(15)<<a[i].name<<setw(16)<<a[i].qty<<setw(16)<<a[i].price<<setw(18)<<a[i].category<<endl; 
                    }
                    system("pause");

                return;
            }
            else
            {
                cout<<"\nInvalid Choice.";
                system("pause");
                return;
            }
        break;
        case 2:
            do
            {
                cout<<"1 - Ascending\n"
                <<"2 - Descending\n"
                <<"Sort by: ";
                 cin>>choice2;
            } while (IntChoiceValidator(choice2)==false);

            if(choice2 == 1)
            {
                cout<<"\nItem list price sorted in ascending order!\n";

                for(int i=0; i<s-1; i++)
                {
                    for (int j = 0; j<s-i-1; j++)
                    {
                        if(a[j].price>a[j+1].price)
                        {
                            swap(a[j], a[j + 1]);
                        }
                    }
                }
                    cout<<setw(3)<<"ID"<<setw(15)<<"NAME"<<setw(15)<<"QTY"<<setw(17)<<"PRICE"<<setw(17)<<"CATEGORY"<<endl;
                    for(int i=0; i<a.size(); i++)
                    {
                    cout<<setw(2)<<a[i].id<<setw(15)<<a[i].name<<setw(16)<<a[i].qty<<setw(16)<<a[i].price<<setw(18)<<a[i].category<<endl; 
                    }
                    system("pause");

                return;
            }
            else if(choice2 == 2)
            {
                cout<<"\nItem list price sorted in descending order!\n";

                for(int i=0; i<s-1; i++)
                {
                    for (int j = 0; j<s-i-1; j++)
                    {
                        if(a[j].price<a[j+1].price)
                        {
                            swap(a[j], a[j + 1]);
                        }
                    }
                }
                    cout<<setw(3)<<"ID"<<setw(15)<<"NAME"<<setw(15)<<"QTY"<<setw(17)<<"PRICE"<<setw(17)<<"CATEGORY"<<endl;
                    for(int i=0; i<a.size(); i++)
                    {
                    cout<<setw(2)<<a[i].id<<setw(15)<<a[i].name<<setw(16)<<a[i].qty<<setw(16)<<a[i].price<<setw(18)<<a[i].category<<endl; 
                    }
                    system("pause");

                return;
            }
            else
            {
                cout<<"\nInvalid Choice.";
                system("pause");
                return;
            }

        break;
        default:
        cout<<"\nInvalid Choice.";
        system("pause");
        return;
    };

}

void LowStack(vector<Details> a)
{
    vector<Details> b;

    for(int i=0; i<a.size(); i++)
    {
        if(a[i].qty<=5)
        {
            b.push_back(a[i]);
        }
        
    }

    if(b.size()>0)
    {
        cout<<"\nLow Stock Items\n";
        cout<<setw(3)<<"ID"<<setw(15)<<"NAME"<<setw(15)<<"QTY"<<setw(17)<<"PRICE"<<setw(17)<<"CATEGORY"<<endl;
                    for(int i=0; i<b.size(); i++)
                    {
                    cout<<setw(2)<<b[i].id<<setw(15)<<b[i].name<<setw(16)<<b[i].qty<<setw(16)<<b[i].price<<setw(18)<<b[i].category<<endl; 
                    }
                    system("pause");
    }
    else
    {
        cout<<"\nNo low stock items found.\n";
        system("pause");
    }
}