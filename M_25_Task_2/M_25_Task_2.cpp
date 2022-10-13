/*Задание 2. Проект симулятора работы компьютера
* 
Что нужно сделать
Реализуйте простую модель работы персонального компьютера в качестве
многомодульного проекта. В компьютере несколько основных, условных
компонент.
Центральный процессор (cpu) — должен иметь функцию compute, которая
складывает 8 чисел из буфера оперативной памяти (см. далее) и выводит
результат в консоль.
Оперативная память (ram) — содержит буфер на 8 целых чисел, которые
можно заполнить функцией write и считать функцией read.
Жёсткий диск (disk) — имеет в себе две функции, save и load. Функция
save должна сохранить состояние 8 чисел из оперативной памяти на
постоянный носитель в файл data.txt. Функция load — загрузить их с
носителя в оперативную память.
Графическая карта (gpu) — выводит в консоль 8 чисел из оперативной
памяти.
Клавиатура (kbd) — позволяет ввести 8 чисел и разместить их в
оперативной памяти.
Каждая компонента должна располагаться в отдельном модуле, с отдельным
заголовочным файлом. Основной модуль программы (main.cpp) должен считывать
пользовательский ввод команды, которая соответствует отдельным функциям
устройств: sum (вычисление суммы), save (сохранить в файл), load (загрузить из файла),
input (ввести с клавиатуры), display (вывести на экран). Команда exit
— выходит из программы.*/

#include <iostream>
#include <string>
#include <vector>
#include "Ram.h"

int main()
{
    const int SIZE_BUF = 8;
    int buf[SIZE_BUF]{}; 
    const char* PATH{ "buf.bin" };

    std::string comand;
    std::vector<std::string> pattern{ "sum","save","load","input","display" };

    while (true)
    {
        std::cout << "Input comand: ";
        std::getline(std::cin, comand);

        int int_com{ -1 };
        for (int i = 0; i < pattern.size(); i++) {
            if (comand == pattern[i]) {
                int_com = i;
                break;
            }
        }
        switch (int_com)
        {
        case 0:
            sum(buf, SIZE_BUF);
            break;
        case 1:
            if (!save(buf, SIZE_BUF, PATH))
                std::cout << "File opening error!";
            break;
        case 2:
            if (!load(buf, PATH))
                std::cout << "File opening error!";
            break;
        case 3:
            input(buf, SIZE_BUF);
            break;
        case 4:
            display(sum(buf, SIZE_BUF));
            break;
        default:
            break;
        }
    }

    
}

