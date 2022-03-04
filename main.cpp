#include <iostream>
#include "CppUnitGenerator.h"
#include "JavaUnitGenerator.h"
#include "CsUnitGenerator.h"

std::string generateCode(const std::shared_ptr<IUnitGenerator>& generator)
{
	//получить юнит класса с названием "MyClass"
	//модификаторы доустпа у класса: public и final
	auto classUnit = generator->getClassUnit("MyClass", ClassUnit::PUBLIC | ClassUnit::FINAL);

	//если указатель не пустой
	if (classUnit)
	{
		//добавить в класс "MyClass"
		//метода testFunc1, который ничего не возвращает (void)
		auto functionUnit1 = generator->getMethodUnit("testFunc1", "void");
		//добавить этот метод в список публичных юнитов
		classUnit->add(functionUnit1, ClassUnit::PUBLIC);

		//добавить в класс "MyClass"
		//метода testFunc2, который ничего не возвращает (void)
		//модификатор метода - internal
		auto functionUnit2 = generator->getMethodUnit("testFunc2", "void", MethodUnit::INTERNAL);
		//добавить метод в список приватных методов
		classUnit->add(functionUnit2, ClassUnit::PRIVATE);

		//добавить в класс "MyClass"
		//метода testFunc3, который ничего не возвращает (void)
		//модификатор метода - virtual и const
		auto functionUnit3 = generator->getMethodUnit("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST);
		//добавить метод в список публичных методов
		classUnit->add(functionUnit3, ClassUnit::PUBLIC);

		//добавить в класс "MyClass"
		//метода testFunc4, который ничего не возвращает (void)
		//модификатор метода - static
		auto functionUnit4 = generator->getMethodUnit("testFunc4", "void", MethodUnit::STATIC);
		//добавить в тело метода "testFunc4"
		//оператор вывода с текстом "Hello,world!"

		if (functionUnit4)
		{
			auto printUnit = generator->getPrintUnit(R"(Hello, world!\n)");
			functionUnit4->add(printUnit);
		}

		classUnit->add(functionUnit4, ClassUnit::PROTECTED);
	}
	//сгенерировать строку для всего класса и его методов
	return classUnit->compile();
}

int main()
{
	std::cout << generateCode(std::make_shared<CppUnitGenerator>()) << std::endl;
	std::cout << generateCode(std::make_shared<JavaUnitGenerator>()) << std::endl;
	std::cout << generateCode(std::make_shared<CsUnitGenerator>()) << std::endl;

	system("pause");
	return 0;
}
