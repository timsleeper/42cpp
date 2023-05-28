#include <iostream>
#include "Array.h"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    //SCOPE
    {
        std::cout << "------------Test Suite------------" << std::endl;
        std::cout << "Test 1: Empty array" << std::endl;
        // Test creating an empty array
        Array<int> emptyArray;

        if (emptyArray.size() != 0) {
            std::cerr << "Error: Empty array size is not 0!" << std::endl;
            return 1;
        }

        std::cout << "Test 2: Accessing out-of-bounds index" << std::endl;
        // Test accessing an element out of bounds
        try {
            int val = emptyArray[0];
            std::cerr << "Error: Accessing out-of-bounds index did not throw exception!" << std::endl;
            val = static_cast<int>(val); // To silence unused variable warning
            return 1;
        }
        catch(const std::out_of_range& e) {
            std::cout << "Caught expected out_of_range exception: " << e.what() << std::endl;
        }

        std::cout << "Test 3: Creating array with elements" << std::endl;
        // Test creating an array with elements
        Array<int> numbers(10);

        if (numbers.size() != 10) {
            std::cerr << "Error: Array size is not correct!" << std::endl;
            return 1;
        }

        std::cout << "Test 4: Writing to and reading from the array" << std::endl;
        // Test writing to and reading from the array
        for (int i = 0; i < numbers.size(); ++i) {
            numbers[i] = i;
        }

        for (int i = 0; i < numbers.size(); ++i) {
            if (numbers[i] != i) {
                std::cerr << "Error: Array elements do not match the assigned values!" << std::endl;
                return 1;
            }
        }

        std::cout << "All tests passed!" << std::endl;
    }



    delete [] mirror;//
    return 0;
}