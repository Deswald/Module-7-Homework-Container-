#include "IntArray.h"

// Exception classes
const char* bad_length::what() const noexcept
{ 
    return "ERROR: Bad length."; 
}
const char* bad_range::what() const noexcept
{
    return "ERROR: Bad range.";
}
const char* bad_value::what() const noexcept
{
    return "ERROR: Bad value.";
}

// Constructors and destructor
IntArray::IntArray(int m_length) : _m_length(m_length)
{
    if (m_length <= 0)
    {
        throw bad_length();
    }
    _m_data = new int[m_length] {};
}
IntArray::IntArray(const IntArray& a)
{
    reallocate(a.getLength());

    for (int index{ 0 }; index < _m_length; ++index)
        _m_data[index] = a._m_data[index];
}
IntArray::~IntArray()
{
    delete[] _m_data;
}

// Operator overloads
int& IntArray::operator[](int index)
{
    if (index < 0 || index >= _m_length)
    {
        throw bad_range();
    }
    return _m_data[index];
}
IntArray& IntArray::operator=(const IntArray& a)
{
    if (&a == this)
        return *this;

    reallocate(a.getLength());

    for (int index{ 0 }; index < _m_length; ++index)
        _m_data[index] = a._m_data[index];

    return *this;
}

// Functions
void IntArray::erase()
{
    delete[] _m_data;
    _m_data = nullptr;
    _m_length = 0;
}
void IntArray::reallocate(int newLength)
{
    erase();

    if (newLength <= 0)
        return;

    _m_data = new int[newLength];
    _m_length = newLength;
}
void IntArray::resize(int newLength)
{
    if (newLength == _m_length)
        return;

    if (newLength <= 0)
    {
        erase();
        return;
    }

    int* data{ new int[newLength] };

    if (_m_length > 0)
    {
        int elementsToCopy{ (newLength > _m_length) ? _m_length : newLength };

        for (int index{ 0 }; index < elementsToCopy; ++index)
            data[index] = _m_data[index];
    }

    delete[] _m_data;

    _m_data = data;
    _m_length = newLength;
}
void IntArray::insertBefore(int value, int index)
{
    if (index < 0 || index > _m_length)
    {
        throw bad_length();
    }

    int* data{ new int[_m_length + 1] };

    for (int before{ 0 }; before < index; ++before)
        data[before] = _m_data[before];

    data[index] = value;

    for (int after{ index }; after < _m_length; ++after)
        data[after + 1] = _m_data[after];

    delete[] _m_data;
    _m_data = data;
    ++_m_length;
}
void IntArray::remove(int index)
{
    if (index < 0 || index >= _m_length)
    {
        throw bad_length();
    }

    if (_m_length == 1)
    {
        erase();
        return;
    }

    int* data{ new int[_m_length - 1] };

    for (int before{ 0 }; before < index; ++before)
        data[before] = _m_data[before];

    for (int after{ index + 1 }; after < _m_length; ++after)
        data[after - 1] = _m_data[after];

    delete[] _m_data;
    _m_data = data;
    --_m_length;
}
void IntArray::insertAtBeginning(int value)
{
    insertBefore(value, 0);
}
void IntArray::insertAtEnd(int value)
{
    insertBefore(value, _m_length);
}
int IntArray::getLength() const
{
    return _m_length;
}
int IntArray::GetElementByIndex(int index)
{
    if (index < 0 || index >= _m_length)
    {
        throw bad_range();
    }
    cout << "Element " << index << " has value: ";
    return _m_data[index];
}
int IntArray::GetElementByValue(int value)
{
    for (int i = 0; i <= _m_length; ++i)
    {
        if (_m_data[i] == value)
        {
            cout << "Value " << value << " has index: ";
            return i;
        }
        if (i == _m_length)
        {
            throw bad_value();
        }
    }
}