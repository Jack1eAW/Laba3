#pragma once
#ifndef DEQUE_H
#define DEQUE_H

#include <vector>

template <typename T>
class deque
{
    std::vector<T> frontBlock;
    std::vector<T> backBlock;
    int frontSize;
    int backSize;

public:
    deque() : frontSize(0), backSize(0) {}
    void push_back(T value)
    {
        backBlock.push_back(value);
        backSize++;
    }
    void push_front(T value)
    {
        frontBlock.push_back(value);
        frontSize++;
    }
    T& front()
    {
        if (frontSize > 0)
            return frontBlock.back();
        else
            return backBlock.front();
    }
    T& back()
    {
        if (backSize > 0)
            return backBlock.back();
        else
            return frontBlock.front();
    }
    void pop_back()
    {
        if (isEmpty())
            return;
        if (backSize > 0)
        {
            backBlock.pop_back();
            backSize--;
        }
        else
        {
            frontBlock.erase(frontBlock.begin());
            frontSize--;
        }
    }
    void pop_front()
    {
        if (isEmpty())
            return;
        if (frontSize > 0)
        {
            frontBlock.pop_back();
            frontSize--;
        }
        else
        {
            backBlock.erase(backBlock.begin());
            backSize--;
        }
    }
    bool isEmpty() { return getSize() == 0; }
    int getSize() { return frontSize + backSize; }

    class iterator
    {
        friend class deque;
        deque<T>* owner;
        T* ptr;
        bool side;

    public:
        iterator(deque<T>* owner = nullptr, T* ptr = nullptr, bool side = false) : owner(owner), ptr(ptr), side(side) {}
        bool operator!=(const iterator& other) const
        {
            return ptr != other.ptr;
        }
        bool operator==(const iterator& other) const
        {
            return !this->operator!=(other);
        }
        T& operator*()
        {
            return *ptr;
        }
        iterator operator++(int)
        {
            auto temp = *this;
            this->operator++();
            return temp;
        }
        iterator operator--(int)
        {
            auto temp = *this;
            this->operator--();
            return temp;
        }
        iterator& operator++()
        {
            if (side) // back parts
                ptr++;
            else // front part
            {
                ptr--;
                if ((ptr == &(owner->frontBlock.front()) - 1) && (owner->backSize > 0))
                {
                    ptr = &(owner->backBlock.front());
                    side = !side;
                }
            }
            return *this;
        }
        iterator& operator--()
        {
            if (side) // back part
            {
                ptr--;
                if ((ptr == &(owner->backBlock.front()) - 1) && (owner->frontSize > 0))
                {
                    ptr = &(owner->frontBlock.front());
                    side = !side;
                }
            }
            else // front part
                ptr++;
            return *this;
        }
    };
    iterator begin()
    {
        bool side = frontSize == 0;
        return iterator(this, &front(), side);
    }
    iterator end()
    {
        bool side = backSize != 0;
        if (side)
            return iterator(this, &back() + 1, side);
        else
            return iterator(this, &back() - 1, side);
    }
    iterator rbegin()
    {
        bool side = backSize != 0;
        return iterator(this, &back(), side);
    }
    iterator rend()
    {
        bool side = frontSize == 0;
        if (side)
            return iterator(this, &front() - 1, side);
        else
            return iterator(this, &front() + 1, side);
    }
};

#endif // DEQUE_H
