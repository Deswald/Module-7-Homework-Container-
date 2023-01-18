#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
    // Checking for invalid length input
    try
    {
        IntArray array1(0);
    }
    catch (const exception& e)
    {
        std::cout << e.what() << endl;
    }

    // Checking for invalid range input
    try
    {
        IntArray array2(10);
        for (int i{ 0 }; i < 11; ++i)
            array2[i] = i + 1;
    }
    catch (const exception& e)
    {
        std::cout << e.what() << endl;
    }

    // Checking for incorrect copying
    try
    {
        IntArray array3(10);
        for (int i{ 0 }; i < 10; ++i)
            array3[i] = i + 1;
        std::cout << "Original: ";
        for (int i{ 0 }; i < array3.getLength(); ++i)
            std::cout << array3[i] << " ";
        std::cout << endl;

        IntArray array4(array3);
        std::cout << "Copy: ";
        for (int i{ 0 }; i < array4.getLength() + 1; ++i)
            std::cout << array4[i] << " ";
        std::cout << endl;
    }
    catch (const exception& e)
    {
        std::cout << e.what() << endl;
    }

    // Checking for getting an array element at an incorrect index
    try
    {
        IntArray array4(10);
        for (int i{ 0 }; i < 10; ++i)
            array4[i] = i + 1;
        std::cout << array4.GetElementByIndex(10) << endl;
    }
    catch (const exception& e)
    {
        std::cout << e.what() << endl;
    }

    // Search for a non-existent value
    try
    {
        IntArray array5(10);
        for (int i{ 0 }; i < 10; ++i)
            array5[i] = i + 1;
        std::cout << array5.GetElementByValue(13) << endl;
    }
    catch (const exception& e)
    {
        std::cout << e.what() << endl;
    }

    cout << endl;

    try
    {
        IntArray array(10);

        for (int i{ 0 }; i < 10; ++i)
            array[i] = i + 1;

        array.resize(8);

        array.insertBefore(20, 5);

        array.remove(3);

        array.insertAtEnd(30);
        array.insertAtBeginning(40);

        {
            IntArray b{ array };
            b = array;
            b = b;
            array = array;
        }

        for (int i{ 0 }; i < array.getLength(); ++i)
            std::cout << array[i] << ' ';

        std::cout << endl;

        // Copying a Container
        IntArray array5(array);
        std::cout << "Copy: ";
        for (int i{ 0 }; i < array5.getLength(); ++i)
            std::cout << array5[i] << " ";
        std::cout << endl;

        // Getting array element by index or value
        std::cout << array.GetElementByIndex(9) << endl;
        std::cout << array.GetElementByValue(5) << endl;




    }
    catch (bad_length& e)
    {
        std::cout << e.what() << endl;
    }
    catch (bad_range& e)
    {
        std::cout << e.what() << endl;
    }
    catch (bad_value& e)
    {
        std::cout << e.what() << endl;
    }

    return 0;
}