#pragma once
#include "Units.h"

class JavaClassUnit : public ClassUnit
{
public:

    explicit JavaClassUnit(const std::string& name, Flags modifier = ClassUnit::PUBLIC);
    ~JavaClassUnit();

    std::string compile(unsigned int level = 0) const;
};

class JavaMethodUnit : public MethodUnit
{
public:

    explicit JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    ~JavaMethodUnit();

    std::string compile(unsigned int level = 0) const;
};

class JavaPrintUnit : public PrintUnit
{
public:

    explicit JavaPrintUnit(const std::string& text);
    ~JavaPrintUnit();

    std::string compile(unsigned int level = 0) const;
};

