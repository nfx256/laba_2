#include "JavaUnitGenerator.h"

JavaUnitGenerator::JavaUnitGenerator()
{}

JavaUnitGenerator::~JavaUnitGenerator()
{}

std::shared_ptr<ClassUnit> JavaUnitGenerator::getClassUnit(const std::string& name, uint32_t modifier) const
{
    return std::make_shared< JavaClassUnit >(name, modifier);
}

std::shared_ptr<MethodUnit> JavaUnitGenerator::getMethodUnit(const std::string& name, const std::string& returnType, uint32_t flags) const
{
    return std::make_shared< JavaMethodUnit >(name, returnType, flags);
}

std::shared_ptr<PrintUnit> JavaUnitGenerator::getPrintUnit(const std::string& text) const
{
    return std::make_shared< JavaPrintUnit >(text);
}
