#pragma once
#include "IUnitGenerator.h"
#include "CppUnits.h"

class CppUnitGenerator : public IUnitGenerator
{
public:

    explicit CppUnitGenerator();
    ~CppUnitGenerator();

    std::shared_ptr<ClassUnit> getClassUnit(const std::string& name, uint32_t modifier = ClassUnit::NONE) const override;

    std::shared_ptr<MethodUnit> getMethodUnit(const std::string& name, const std::string& returnType, uint32_t flags = MethodUnit::NONE) const override;

    std::shared_ptr<PrintUnit> getPrintUnit(const std::string& text) const override;
};
