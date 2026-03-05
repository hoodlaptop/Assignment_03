#pragma once
#include <iostream>

template <typename T>
class Inventory
{
public:
    Inventory(int capacity = 10);
    
    ~Inventory();
    
    void AddItem(const T& item);
    void RemoveLastItem();
    int GetSize() const;
    int GetCapacity() const;
    void PrintInfo() const;

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
        std::cout << "인벤토리가 꽉 찼습니다!" << std::endl;
        return;
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
