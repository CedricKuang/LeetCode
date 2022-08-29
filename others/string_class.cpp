#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class String
{
    friend String operator+(const String& s1, const String& s2);
    public:
        String();
        String(char*);
        String(const String&);
        String(String&&);
        ~String();
        size_t size() const;
        char& operator[](size_t);
        String& operator=(const String&);
    private:
        char* buffer;
        size_t my_size;
};

String::String()
{
    buffer = nullptr;
    my_size = 0;
}

String::String(char *val)
{
    if (val == nullptr)
    {
        buffer = nullptr;
        my_size = 0;
    }
    else
    {
        buffer = new char[strlen(val) + 1];
        strcpy(buffer, val);
        buffer[strlen(val)] = '\0';
        my_size = strlen(buffer);
    }
}

String::String(const String& source)
{
    buffer = new char[source.size() + 1];
    strcpy(buffer, source.buffer);
    buffer[source.size()] = '\0';
    my_size = source.size();
}

String::String(String&& source)
{
    buffer = source.buffer;
    my_size = source.size();
    source.buffer = nullptr;
    source.my_size = 0;
}

String::~String()
{
    delete buffer;
}

size_t String::size() const
{
    return my_size;
}

char& String::operator[](size_t index)
{
    return buffer[index];
}

String& String::operator=(const String& source)
{
    if (this == &source)
        return *this;
    buffer = new char[source.size() + 1];
    strcpy(buffer, source.buffer);
    buffer[source.size()] = '\0';
    my_size = source.size();
    return *this;
}

String operator+(const String& s1, const String& s2)
{
    size_t total_size = s1.my_size + s2.my_size;
    char* new_buffer = new char[total_size + 1];

    strcpy(new_buffer, s1.buffer);
    strcpy(new_buffer, s2.buffer);
    new_buffer[total_size] = '\0';

    String temp{ new_buffer };
    delete[] new_buffer;
    return temp;
}


int main()
{

}