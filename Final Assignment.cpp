
#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

class property;
class admin;
class buyer
{
private:
    string username;
    string phonenumber;
    int member;
    float budget;
    float room_size;
    char status;
public:
    void set_buyer(string a,string b,int c,float d,float e, char f);
    friend class property;

} b;

class admin
{
    string admin_name;
    string password;
    float profit;
    int property_sold;
public:
    admin(string a, string b)
    {
        admin_name = a;
        password = b;
        profit = 0;
        property_sold = 0;
    }
    void calculateProfit(float a);
    void display_admin(void);
    void search_user(string a, string b, admin &d);
} ;

class property
{
private:
    string location;
    float rent;
    float sise;
    char status;
public:
    void set_property(void);
    void display();
    void search_property(buyer &i);
    float rent_property(void);
    float sell_property(void);

} p[10];

void admin :: search_user(string a, string b, admin &d)
{
    int j=0, cnt=0;

    for(j=0; j<1;)
    {
        if (d.admin_name == a)
        {
            if(d.password == b)
            {
                cout << "Login Successful" << endl;
                break;
            }
            else
            {
                cnt ++;
                if(cnt == 5)
                {
                    cout << "Too many wrong attempt" << endl;
                }
                else
                {
                    cout << endl;
                    cout << "Wrong password!!!" << endl;
                    cout << "Please try Again" << endl;
                    cout << endl;
                    cout << "State your name: " << endl;
                    cin >> a;
                    cout << "State your password: " << endl;
                    cin >> b;
                    j=0;
                    continue;
                }
            }
        }

        else if(j == 0)
        {
            cnt ++;
            if(cnt == 5)
            {
                cout << "Too many wrong attempt" << endl;
            }
            else
            {
                cout << endl;
                cout << "Wrong Name!!!" << endl;
                cout << "Please try Again" << endl;
                cout << endl;
                cout << "State your name: " << endl;
                cin >> a;
                cout << "State your password: " << endl;
                cin >> b;
                j=0;
                continue;
            }
        }
    }
}
void admin :: display_admin(void)
{
    cout << "Property Sold or Rented: " << property_sold << endl;
    cout << "Profit: " << profit << endl;
}

void admin :: calculateProfit(float a)
{
    property_sold++;
    profit = a*.15;
}

void property::set_property(void)
{
    fstream f;
    f.open("Property.txt",ios::in);
    int j;
    for(j=0; j<10; j++)
    {
        f >> p[j].location;
        f >> p[j].rent;
        f >> p[j].sise;
        f >> p[j].status;
    }
}
void buyer::set_buyer(string a,string b,int c,float d,float e, char f)
{
    username = a;
    phonenumber = b;
    member = c;
    budget = d;
    room_size = e;
    status = f;
}

void property::search_property(buyer &i)
{

    for(int j=0; j<10; j++)
    {
        if(p[j].rent <= i.budget && p[j].status == b.status)
        {
            if(p[j].sise >= i.room_size)
            {
                p[j].display();
            }
        }
    }
}
void property::display(void)
{
    cout<<"Location: "<<location<<endl;
    cout<<"Size: "<<sise<<endl;
    cout<<"Price: "<<rent<<endl;
    cout<<"Status: "<<status<<endl;
}
float property::rent_property(void)
{
    string t;
    int j;
    char ch;
    cout<<"Which property do you want to rent"<<endl;
    cin>>t;
    for(j=0; j<10; j++)
    {
        if(p[j].location==t)
        {
            p[j].display();
            cout<<"Do you want to buy this property: Y/N"<<endl;
            cin>>ch;
            if(ch=='Y')
            {
                cout<<"You have bought this property"<<endl;
                return p[j].rent;
            }
            else
            {
                cout<<"Your purchase is cancelled"<<endl;
            }
        }
    }

}
float property::sell_property(void)
{
    string t;
    int j;
    char ch;
    cout<<"Which property do you want to buy"<<endl;
    cin>>t;
    for(j=0; j<10; j++)
    {
        if(p[j].location==t)
        {
            p[j].display();
            cout<<"Do you want to buy this property: Y/N"<<endl;
            cin>>ch;
            if(ch=='Y')
            {
                cout<<"You have bought this property"<<endl;
                return p[j].rent;
            }
            else
            {
                cout<<"Your purchase is cancelled"<<endl;
            }
        }
    }

}
int main()
{
    p[0].set_property();
    admin a("Azfar", "2107101");
    int cnt;
    do
    {
        cout<<"---------------------Welcome to KAZI HOLDINGS------------------------------"<<endl;
        cout << "(a)Login as User" << endl;
        cout << "(b)Login as Admin" << endl;
        char t1;
        cin >> t1;

        if(t1 == 'a')
        {
            do
            {
                string name,phone;
                int mem;
                float budge,room;
                char f;
                cout<<"Enter your name:"<<endl;
                cin>>name;
                cout<<"Enter your number:"<<endl;
                cin>>phone;
                cout<<"How many members do you have:"<<endl;
                cin>>mem;
                cout<<"What's your budget"<<endl;
                cin>>budge;
                cout<<"what room size do you prefer"<<endl;
                cin>>room;
                cout<<"What is your choice?"<<endl;
                cin>>f;
                b.set_buyer(name,phone,mem,budge,room,f);
                do
                {
                    cout<<"What do you want to do?"<<endl;
                    cout<<"1.Search property"<<endl;
                    cout<<"2.Buy property"<<endl;
                    cout<<"3.Rent property"<<endl;
                    int a1;
                    cin >> a1;

                    if(a1 == 1)
                    {
                        p[6].search_property(b);
                        cout << "What do you want to do?" << endl;
                        cout << "1. Logout"<< endl;
                        cout << "2. Options Menu" << endl;
                        cout << "3. Main Menu" << endl;
                        cin >> cnt;
                    }
                    else if(a1 == 2)
                    {
                        float tp;
                        tp = p[0].sell_property();
                        a.calculateProfit(tp);
                        cout << "What do you want to do?" << endl;
                        cout << "1. Logout"<< endl;
                        cout << "2. Options Menu" << endl;
                        cout << "3. Main Menu" << endl;
                        cin >> cnt;
                    }
                    else if(a1==3)
                    {
                        float tp;
                        tp = p[0].rent_property();
                        a.calculateProfit(tp);
                        cout << "What do you want to do?" << endl;
                        cout << "1. Logout"<< endl;
                        cout << "2. Options Menu" << endl;
                        cout << "3. Main Menu" << endl;
                        cin >> cnt;
                    }
                }
                while(cnt == 2);


            }
            while(cnt == 1);
        }
        else if(t1 == 'b')
        {
            do
            {
                string s1, s2;
                cout << "Enter Your User name" << endl;
                cin >> s1;
                cout << "Enter Your Password" << endl;
                cin >> s2;
                do
                {
                    a.search_user(s1,s2,a);
                    cout << "1. Display Profit" << endl;
                    cout << "2.Logout" << endl;
                    cout << "3.Main Menu" << endl;
                    cin >> cnt;
                    if(cnt == 1)
                    {
                        a.display_admin();
                        cout << "1.Options Menu" << endl;
                        cout << "2.Logout" << endl;
                        cout << "3.Main Menu" << endl;
                        cin >> cnt;
                    }
                }
                while(cnt == 1);
            }
            while(cnt == 2);
        }

    }
    while(cnt == 3);

}
