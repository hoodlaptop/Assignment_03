#pragma once
#include <iostream>
#include <algorithm>

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

template <typename T>
Inventory<T>::Inventory(int capacity)
{
    if (capacity <= 0)
    {
        capacity = 1;
    }

    capacity_ = capacity;
    size_ = 0;
    pItems_ = new T[capacity_];
}

template <typename T>
Inventory<T>::Inventory(const Inventory<T>& other)
{
    capacity_ = other.capacity_;
    size_ = other.size_;
    pItems_ = new T[capacity_];
    for (int i = 0; i < size_; ++i)
    {
        pItems_[i] = other.pItems_[i];
    }
    std::cout << "인벤토리 복사 완료" << std::endl;
}

template <typename T>
Inventory<T>::~Inventory()
{
    delete[] pItems_;
    pItems_ = nullptr;
}

template <typename T>
void Inventory<T>::AddItem(const T& item)
{
    if (size_ >= capacity_)
    {
        Resize(capacity_ * 2);
    }

    pItems_[size_] = item;
    size_++;
}

template <typename T>
void Inventory<T>::RemoveLastItem()
{
    if (size_ <= 0)
    {
        std::cout << "인벤토리가 비어있습니다." << std::endl;
        return;
    }

    size_--;
}

template <typename T>
int Inventory<T>::GetSize() const
{
    return size_;
}

template <typename T>
int Inventory<T>::GetCapacity() const
{
    return capacity_;
}

template <typename T>
void Inventory<T>::PrintInfo() const
{
    for (int i = 0; i < size_; i++)
    {
        pItems_[i].PrintInfo();
    }
}

template <typename T>
void Inventory<T>::Assign(const Inventory<T>& other)
{
    if (this == &other) return;
    
    delete[] pItems_;
    
    capacity_ = other.capacity_;
    size_ = other.size_;
    pItems_ = new T[capacity_];
    for (int i = 0; i < size_; i++)
    {
        pItems_[i] = other.pItems_[i];
    }
}

template <typename T>
void Inventory<T>::Resize(int newCapacity)
{
    if (newCapacity <= 0)
    {
        newCapacity = 1;
    }

    T* newItems = new T[newCapacity];

    int copyCount = (size_ < newCapacity) ? size_ : newCapacity;
    for (int i = 0; i < copyCount; i++)
    {
        newItems[i] = pItems_[i];
    }

    delete[] pItems_;

    pItems_ = newItems;
    capacity_ = newCapacity;
    size_ = copyCount;
}

template <typename T>
template <typename Compare>
void Inventory<T>::SortItems(Compare comp)
{
    std::sort(pItems_, pItems_ + size_, comp);
}
