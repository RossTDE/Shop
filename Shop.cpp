#include <iostream>
#include <string>
using namespace std;

/*
Создать структуру для хранения информации о товаре.
Название, цена, количество.Создать массив товаров.
Написать функцию, случайно заполняющую этот массив.
Написать функцию печати массива.Написать общую сумму от продажи всех товаров.
*/

struct unit {
    string name;
    int quantity;
    int price;
    unit* pNext;
};

class List
{
    unit* head;
public:
    List()
    {
        head = nullptr;
    }
    ~List();
    void Add_Name(string name);
    void print_lst();
    int count();
    bool add_unit(istream& in);
};

List::~List()
{
    while (head != nullptr)
    {
        unit* temp = head->pNext;
        delete head;
        head = temp;
    }
}

void List::Add_Name(string name)
{
    unit* temp = new unit;
    temp->name = name;
    temp->pNext = head;
    head = temp;
}

bool List::add_unit(istream& in) {
    string name;
    if (!(in >> name)) return false;
    this->Add_Name(name);
    string status;
    in >> head->quantity;
    in >> head->price;
    return true;
}

void List::print_lst()
{
    unit* temp = head;
    while (temp != nullptr)
    {
        cout << temp->name << " ";
        cout << temp->quantity << " pc." << " ";
        cout << temp->price << "$" << " \n";
        temp = temp->pNext;
    } cout << endl;
}

int List::count()
{
    int sum = 0;
    int price, quantity;

    unit* temp = head;
    while (temp != nullptr)
    {
        price = temp->price;
        quantity = temp->quantity;
        sum += price * quantity;
        temp = temp->pNext;
    }
    return sum;
}

int main() {
    List lst;
    string name;

    while (lst.add_unit(cin));
    lst.print_lst();
    cout << "Total income: " << lst.count() << "$";
}
