// test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "../CommandLineParser/CmdLineParser.h"
#include <iostream>

void PrintArgument(Argument* argument)
{
	if(argument->Prefix != nullptr)
	{
		std::cout << argument->Prefix;
	}
	else
	{
		std::cout << "NO_PREFIX";
	}
	std::cout << " [ ";

	for (size_t idx = 0; idx < argument->ParameterCount; idx++)
	{
		auto const par = argument->Parameters[idx];
		std::cout << " " << par;
	}

	std::cout << " ] (SRC: ' " << argument->Src << " ')" << std::endl;
}

int main(int argc, char* argv[])
{
	TCHAR* combined = Combine(argc, argv);
	ArgumentMap* map = ParseArguments(combined);

	std::cout << "Free parameters:" << std::endl;
	if (map->HasFreeParameters())
		PrintArgument(map->FreeParameters());

	std::cout << "Flags:" << std::endl;
	for (size_t index = 0; index < map->Count(); index++)
	{
		auto const element = map->At(index);

		PrintArgument(element);
	}

	delete map;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
