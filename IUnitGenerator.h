#pragma once
#include "Units.h"

/*
    абстрактный генератор кода (интерфейс)
*/

class IUnitGenerator
{
public:

    virtual ~IUnitGenerator() = default;

    //получить языковую констукцию класса
    virtual std::shared_ptr<ClassUnit> getClassUnit(const std::string& name, uint32_t modifier = ClassUnit::NONE) const = 0;

    //получить языковую констукцию метода
    virtual std::shared_ptr<MethodUnit> getMethodUnit(const std::string& name, const std::string& returnType, uint32_t flags = MethodUnit::NONE) const = 0;

    //получить языковую констукцию оператора вывода
    virtual  std::shared_ptr<PrintUnit> getPrintUnit(const std::string& text) const = 0;
};

