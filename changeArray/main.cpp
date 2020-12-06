#include <iostream>
#include <cstdlib>

#include "change_array.hpp"

int main()
{
    srand(time(0));
    const int A_SIZE = 7 + rand() % 11;
    std::cout << "Функция преобразует массив, перенося все его элементы между индексами Start и Stop"
              << " включительно в конец массива."
              << "\n\n";

    std::cout << "Преобразование статического массива." << '\n' << '\n';
    try
    {
        changeStaticArray(A_SIZE);
    }
    catch (const std::string &error)
    {
        std::cerr << "Ошибка при изменении статического массива: " << error << std::endl;
    }
    std::cout << std::endl << "Преобразование динамического массива, размер которого задан пользователем." << '\n' << '\n';
    try
    {
        changeUsersArray();
    }
    catch (const std::string &error)
    {
        std::cerr << "Ошибка при изменении массива пользователя: " << error << std::endl;
    }
    std::cout << std::endl << "Преобразование динамического массива, прочитанного из файла." << '\n' << '\n';
    try
    {
        changeFileArray();
    }
    catch (const std::string &error)
    {
        std::cerr << "Ошибка при изменении массива из файла: " << error << std::endl;
    }

    return 0;
}
