#pragma once
#include "Units.h"

class CppClassUnit : public ClassUnit
{
public:

    explicit CppClassUnit(const std::string& name, Flags modifier = ClassUnit::NONE);
    ~CppClassUnit();

    std::string compile(unsigned int level = 0) const;
};

class CppMethodUnit : public MethodUnit
{
public:

    explicit CppMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    ~CppMethodUnit();

    std::string compile(unsigned int level = 0) const;
};

class CppPrintUnit : public PrintUnit
{
public:

    explicit CppPrintUnit(const std::string& text);
    ~CppPrintUnit();

    std::string compile(unsigned int level = 0) const;
};
