#pragma once
#include "IUnitGenerator.h"
#include "CsUnits.h"

class CsUnitGenerator : public IUnitGenerator
{
public:

    explicit CsUnitGenerator();
    ~CsUnitGenerator();

    std::shared_ptr<ClassUnit> getClassUnit(const std::string& name, uint32_t modifier = ClassUnit::NONE) const override;

    std::shared_ptr<MethodUnit> getMethodUnit(const std::string& name, const std::string& returnType, uint32_t flags = MethodUnit::NONE) const override;

    std::shared_ptr<PrintUnit> getPrintUnit(const std::string& text) const override;
};
