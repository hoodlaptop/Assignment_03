#include <iostream>
#include <string>
#include "Inventory.h"

using namespace std;

class Item
{
public:
    Item() : name_(""), price_(0) {}
    Item(const string& name, int price) : name_(name), price_(price) {}

    void PrintInfo() const
    {
        cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
    }

    int GetPrice() const { return price_; }

private:
    string name_;
    int price_;
};

bool compareItemsByPrice(const Item& a, const Item& b)
{
    return a.GetPrice() < b.GetPrice();
}

int main(int argc, char* argv[])
{
    cout << "=== Inventory 테스트 ===" << endl << endl;
    
    Inventory<Item> inventory(5);

    cout << "최대 용량: " << inventory.GetCapacity() << endl;
    cout << "현재 아이템 수: " << inventory.GetSize() << endl << endl;

    cout << "--- 아이템 추가 ---" << endl;
    inventory.AddItem(Item("장검", 100));
    inventory.AddItem(Item("방패", 80));
    inventory.AddItem(Item("체력 포션", 30));

    cout << "현재 아이템 수: " << inventory.GetSize() << endl << endl;

    cout << "--- 전체 아이템 목록 ---" << endl;
    inventory.PrintInfo();
    cout << endl;

    cout << "--- 마지막 아이템 제거 ---" << endl;
    inventory.RemoveLastItem();
    cout << "현재 아이템 수: " << inventory.GetSize() << endl;
    inventory.PrintInfo();
    cout << endl;
    
    cout << "--- 인벤토리 가득 채우기 테스트 ---" << endl;
    inventory.AddItem(Item("활", 120));
    inventory.AddItem(Item("갑옷", 200));
    inventory.AddItem(Item("투구", 90));
    inventory.AddItem(Item("신발", 60));  // Resize Test

    cout << "현재 아이템 수: " << inventory.GetSize() << endl;
    cout << "현재 용량: " << inventory.GetCapacity() << endl << endl;

    cout << "--- 빈 인벤토리 테스트 ---" << endl;
    Inventory<Item> emptyInventory(3);
    emptyInventory.RemoveLastItem();  // 비어있으므로 경고 메시지

    cout << endl << "--- 0 이하 용량 테스트 ---" << endl;
    Inventory<Item> minInventory(-5);
    cout << "입력 용량: -5, 실제 용량: " << minInventory.GetCapacity() << endl;

    cout << endl << "--- SortItems 테스트 (가격순 정렬) ---" << endl;
    Inventory<Item> sortInventory(5);
    sortInventory.AddItem(Item("장검", 100));
    sortInventory.AddItem(Item("포션", 30));
    sortInventory.AddItem(Item("갑옷", 200));
    sortInventory.AddItem(Item("신발", 60));

    cout << "정렬 전:" << endl;
    sortInventory.PrintInfo();

    sortInventory.SortItems(compareItemsByPrice);

    cout << endl << "정렬 후 (가격 오름차순):" << endl;
    sortInventory.PrintInfo();

    return 0;
}

