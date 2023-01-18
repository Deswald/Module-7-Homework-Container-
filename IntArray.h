#pragma once
#include <iostream>
#include <exception>

using namespace std;

// Exception classes
class bad_length : public exception
{
public:
    virtual const char* what() const noexcept override;
};
class bad_range : public exception
{
public:
    virtual const char* what() const noexcept override;
};
class bad_value : public exception
{
public:
    virtual const char* what() const noexcept override;
};

class IntArray
{
public:
    // Constructors and destructor
    IntArray() = default;
    IntArray(int length);
    IntArray(const IntArray& a);
    ~IntArray();

    // Operator overloads
    int& operator[](int index);
    IntArray& operator=(const IntArray& a);

    // Functions
    void erase();
    void reallocate(int newLength);
    void resize(int newLength);
    void insertBefore(int value, int index);
    void remove(int index);
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    int getLength() const;
    int GetElementByIndex(int index);
    int GetElementByValue(int value);


private:
    int _m_length{};
    int* _m_data{};

};