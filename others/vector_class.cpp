#include <iostream>
using namespace std;

template <class T, size_t s>
class Vector
{
    public:
        Vector();
        Vector(const Vector<T, s>&);
        ~Vector();
        size_t size() const;
        void push_back(const T&);
        void pop_back();
        void reserve(size_t);
        void resize(size_t);
        T & operator[](size_t);
    private:
        size_t my_size;
        size_t my_capacity;
        T* buffer;
};

template <class T, size_t s>
Vector<T, s>::Vector()
{
    my_capacity = s;
    my_size = 0;
    buffer = new T[s];
}

template <class T, size_t s>
Vector<T, s>::Vector(const Vector<T, s>& v)
{
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T[my_size];
    for (size_t i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];
}

template <class T, size_t s>
Vector<T, s>::~Vector()
{
    delete[] buffer;
}

template <class T, size_t s>
size_t Vector<T, s>::size() const
{
    return my_size;
}

template <class T, size_t s>
void Vector<T, s>::push_back(const T& v)
{
    if (my_size >= my_capacity)
        reserve(my_capacity * 2);
    buffer[my_size++] = v;
}

template <class T, size_t s>
void Vector<T, s>::reserve(size_t new_capacity)
{
    if (buffer == nullptr)
    {
        my_size = 0;
        my_capacity = 0;
    }

    T* new_buffer = new T[new_capacity];
    size_t loading_size = new_capacity < my_size ? new_capacity : my_size;

    for (size_t i = 0; i < loading_size; i++)
        new_buffer[i] = buffer[i];
    
    my_capacity = new_capacity;
    delete[] buffer;
    buffer = new_buffer;
}

template <class T, size_t s>
void Vector<T, s>::resize(size_t new_size)
{
    reserve(new_size);
    my_size = new_size;
}

template <class T, size_t s>
void Vector<T, s>::pop_back()
{
    my_size--;
    buffer[my_size]->~T();
}

template<class T, size_t s>
T& Vector<T, s>::operator[](size_t index)
{
    return buffer[index];
}

int main()
{

}