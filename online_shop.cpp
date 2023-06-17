#include <bits/stdc++.h>
using namespace std;
class item;
class cart;
class Product
{
    int price;
    string name;
    int serial;

public:
    Product() {}
    Product(int id, string name, float price)
    {
        serial = id;
        this->name = name;
        this->price = price;
    }
    string getShortName()
    {
        return name.substr(0, 1);
    }
    string getDisplayName()
    {
        return name + " : " + to_string(price) + " Taka\n";
    }
    friend class item;
    friend class cart;
};

class item
{
    Product product;
    int quantity;

public:
    item() {}
    item(Product p, int q) : product(p), quantity(q) {}
    int getitemprice()
    {
        return quantity * product.price;
    }
    string getiteminfo()
    {
        return to_string(quantity) + " x " + product.name + " " + to_string(quantity * product.price) + " taka\n";
    }
    friend class cart;
};
vector<Product> allproduct = {
    Product(1, "apple", 200),
    Product(2, "mango", 150),
    Product(3, "banana", 120),
    Product(4, "peach", 300),
    Product(5, "dragon Fruit", 300),
    Product(6, "strawberry", 200),
    Product(7, "chicken", 500),
    Product(8, "Beef", 650),
    Product(9, "Mutton", 900),
    Product(10, "fogg Master Body Spray", 350),
    Product(11, "wireless keyboared", 2000),

};
Product *choseProduct()
{
    string productList;
    cout << "Available Product: \n";
    for (auto product : allproduct)
    {
        productList.append(product.getDisplayName());
    }
    cout << productList;
    cout << "\nEnter first letter of the product to add in your list\n";
    cout << "For example to add apple simply type 'a'\n";
    cout << "---------------" << endl;
    string choice;
     cout<<">> ";
    cin >> choice;
    for (int i = 0; i < allproduct.size(); i++)
    {
        if (allproduct[i].getShortName() == choice)
        {
            return &allproduct[i];
        }
    }
    cout << "Product Not Found!\n";
    return NULL;
}
class cart
{
    unordered_map<int, item> items;

public:
    void addproduct(Product product)
    {
        if (items.count(product.serial) == 0)
        {
            item newitem(product, 1);
            items[product.serial] = newitem;
        }
        else
        {
            items[product.serial].quantity += 1;
        }
    }
    int getTotal()
    {
        int total = 0;
        for (auto itempair : items)
        {
            auto item = itempair.second;
            total += item.getitemprice();
        }
        return total;
    }
    string viewCart()
    {
        if (items.empty())
        {
            return "Cart is empty";
        }
        string itemList;
        int cartTotal = getTotal();
        for (auto itempair : items)
        {
            auto item = itempair.second;
            itemList.append(item.getiteminfo());
        }
        return itemList + "Total Ammount : " + to_string(cartTotal) + " taka";
    }
    bool isEmpty()
    {
        return items.empty();
    }
};

bool checkout(cart &buylist)
{
    if (buylist.isEmpty())
    {
        return false;
    }
    int total = buylist.getTotal();
    cout<<"Your Total bill is "<<total<<" Taka"<<endl;
    cout << "Type ammount : ";
    int paid;
     cout<<">> ";
    cin >> paid;
    if (paid >= total)
    {
        cout << "Change " << paid - total <<" Taka"<< endl;
        cout << "Payment Successful.\n";
        cout << "Thank you for shoping from FASTBUY!\n";
        return true;
    }
    else
    {
        cout << "Oops!! Not enough money.\n\n";
        return false;
    }
}
int main()
{
    char action;
    cart buylist;
    cout << "Welcome to FASTBUY\n";
    while (1)
    {

        cout << "Select an action:-\n";
        cout << "Type:-\n";
        cout << "'s' for Viewing itemlist.\n";
        cout << "'v' for Viewing Selected item.\n";
        cout << "'c' for payment and checkout.\n";
        cout<<">> ";
        cin >> action;
        if (action == 's')
        {
            Product *product = choseProduct();
            if (product != NULL)
            {
                cout << "Added to Your List -> " << product->getDisplayName() << endl;
                buylist.addproduct(*product);
            }
        }
        else if (action == 'v')
        {
            cout << "---------------" << endl;
            cout << buylist.viewCart() << endl;
            cout << "---------------" << endl;
        }
        else if (action == 'c')
        {
            buylist.viewCart();
            if (checkout(buylist))
            {
                break;
            }
            // else
            // {
            //     cout << "You didn't buy anything.Good bye.\n";
            //     break;
            // }
        }
        else
            cout << "Wrong input.\nTry again..\n";
    }
}
