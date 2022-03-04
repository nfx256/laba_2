#include "CsUnitGenerator.h"

CsUnitGenerator::CsUnitGenerator()
{}

CsUnitGenerator::~CsUnitGenerator()
{}

std::shared_ptr<ClassUnit> CsUnitGenerator::getClassUnit(const std::string &name, uint32_t modifier) const
{
	return std::make_shared<CsClassUnit>(name, modifier);
}

std::shared_ptr<MethodUnit> CsUnitGenerator::getMethodUnit(const std::string &name, const std::string &returnType, uint32_t flags) const
{
    return std::make_shared<CsMethodUnit>(name, returnType, flags);
}

std::shared_ptr<PrintUnit> CsUnitGenerator::getPrintUnit(const std::string &text) const
{
	return std::make_shared<CsPrintUnit>(text);
}
