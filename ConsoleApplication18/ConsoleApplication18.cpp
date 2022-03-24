// ConsoleApplication18.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Ocean.h"
int main()
{
    Ocean* myOcean = new Ocean;
    myOcean->Initialize();
    myOcean->Run();
    
    delete myOcean;
}
