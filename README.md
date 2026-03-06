# Inventory<T> - 템플릿 기반 동적 인벤토리 시스템

C++ 템플릿을 활용하여 구현한 범용 인벤토리 클래스입니다.
`std::vector`의 핵심 동작 원리를 직접 구현하며 동적 메모리 관리와 제네릭 프로그래밍을 학습했습니다.

## 주요 기능

### 기본 기능
- **동적 메모리 관리**: `new`/`delete`를 활용한 힙 메모리 할당 및 해제
- **아이템 추가/제거**: `AddItem()`, `RemoveLastItem()`
- **정보 조회**: `GetSize()`, `GetCapacity()`, `PrintInfo()`

### 확장 기능
- **깊은 복사**: 복사 생성자 및 `Assign()` 함수로 안전한 객체 복사
- **자동 확장**: 용량 초과 시 `Resize()`를 통해 2배로 자동 확장
- **정렬**: `std::sort`와 비교 함수를 활용한 `SortItems()` 구현

## 클래스 구조

```cpp
template <typename T>
class Inventory
{
public:
    Inventory(int capacity = 10);
    Inventory(const Inventory<T>& other);
    ~Inventory();

    void AddItem(const T& item);
    void RemoveLastItem();
    int GetSize() const;
    int GetCapacity() const;
    void PrintInfo() const;
    void Assign(const Inventory<T>& other);
    void Resize(int newCapacity);

    template <typename Compare>
    void SortItems(Compare comp);

private:
    T* pItems_;
    int capacity_;
    int size_;
};
```

## 사용 예시

```cpp
// Item 클래스 정의
class Item {
public:
    Item(const string& name, int price);
    void PrintInfo() const;
    int GetPrice() const;
private:
    string name_;
    int price_;
};

// 비교 함수
bool compareItemsByPrice(const Item& a, const Item& b) {
    return a.GetPrice() < b.GetPrice();
}

int main() {
    Inventory<Item> inventory(5);

    // 아이템 추가
    inventory.AddItem(Item("장검", 100));
    inventory.AddItem(Item("포션", 30));
    inventory.AddItem(Item("갑옷", 200));

    // 가격순 정렬
    inventory.SortItems(compareItemsByPrice);

    // 출력
    inventory.PrintInfo();

    return 0;
}
```

## 학습 내용

- **템플릿**: 타입에 독립적인 코드 작성
- **동적 메모리**: `new[]`/`delete[]`를 통한 메모리 관리
- **깊은 복사 vs 얕은 복사**: 포인터 멤버 변수가 있을 때의 복사 문제 해결
- **STL 알고리즘**: `std::sort`와 사용자 정의 비교 함수 활용
