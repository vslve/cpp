#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>

const std::string POSITION_ERROR = "Некорректный номер элемента.";
const std::string WRONG_NAME = "Неверное имя элемента контейнера.";

template <typename Type>
class Container
{
    public:
        Container();
        Container(Type item);
        Container(const Type &container);
        ~Container();

        void add(Type &item);
        Type &take(int position);
        int getPosition(std::string name);
        void change(int position, Type value);
        int size() const;
        void clear();
        void create(int size);
        bool is_member(Type &item);
        Type *begin() const;
        Type *end() const;

        Container<Type> operator=(const Type &container);


    private:
        int size_;
        int fullness_;
        Type *items_;
};

template <typename Type>
Container<Type>::Container():
        items_(new Type[5]),
        size_(5),
        fullness_(0) {};

template<typename Type>
Container<Type>::Container(const Type &container):
    size_(container.size_),
    fullness_(container.fullness_)
    {
        delete[] items_;
        items_ = new Type[size_];
        for (int i = 0; i < fullness_; ++i)
        {
            *(items_ + i) = *(container.items_ + i);
        }
    }

template <typename Type>
Container<Type>::~Container<Type>()
{
    delete[] items_;
    items_ = nullptr;
}

template <typename Type>
void Container<Type>::add(Type &item)
{
    if (fullness_ == size_)
    {
        size_ += 5;
        Type *newItems = new Type[size_];
        for (int i = 0; i < fullness_; ++i)
        {
            *(newItems + i) = *(items_ + i);
        }
        delete[] items_;
        items_ = newItems;
        newItems = nullptr;
    }
    *(items_ + fullness_) = item;
    ++fullness_;
}

template <typename Type>
Type &Container<Type>::take(int position)
{
    if (position < 1 || position > size_)
    {
        throw POSITION_ERROR;
    }
    return *(items_ + position - 1);
}

template<typename Type>
int Container<Type>::getPosition(std::string name)
{
    for (int i = 0; i < fullness_; ++i)
    {
        if ((*(items_ + i)).getName() == name)
        {
            return i + 1;
        }
    }
    throw WRONG_NAME;
}


template<typename Type>
void Container<Type>::change(int position, Type value)
{
    if (position < 1 || position > size_)
    {
        throw POSITION_ERROR;
    }
    *(items_ + position - 1) = value;
}

template<typename Type>
int Container<Type>::size() const
{
    return fullness_;
}

template <class Type>
void Container<Type>::clear()
{
    delete[] items_;
    items_ = new Type[5];
    fullness_ = 0;
}

template<typename Type>
bool Container<Type>::is_member(Type &item)
{
    for (int i = 0; i < fullness_; ++i)
    {
        if (*(items_ + i) == item)
        {
            return true;
        }
    }
    return false;
}

template<typename Type>
Type *Container<Type>::begin() const
{
    return items_;
}

template<typename Type>
Type *Container<Type>::end() const
{
    return items_ + fullness_;
}

template<typename Type>
Container<Type> Container<Type>::operator=(const Type &container)
{
    if (this == &container)
    {
        return *this;
    }
    delete[] items_;
    size_ = container.size_;
    items_ = new Type[size_];
    fullness_ = container.fullness_;
    for (int i = 0; i < fullness_; ++i)
    {
        *(items_ + i) = *(container.items_ + i);
    }
    return *this;
}

template<typename Type>
void Container<Type>::create(int size)
{
    delete[] items_;
    items_ = new Type[size];
    size_ = size;
    fullness_ = 0;
}
#endif // CONTAINER_H
