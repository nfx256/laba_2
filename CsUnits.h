#pragma once
#include "Units.h"

class CsClassUnit : public ClassUnit
{
public:

    explicit CsClassUnit(const std::string& name, Flags modifier = ClassUnit::PUBLIC);
    ~CsClassUnit();

    std::string compile(unsigned int level = 0) const;
};

class CsMethodUnit : public MethodUnit
{
public:

    explicit CsMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    ~CsMethodUnit();

    std::string compile(unsigned int level = 0) const;
};

class CsPrintUnit : public PrintUnit
{
public:

    explicit CsPrintUnit(const std::string& text);
    ~CsPrintUnit();

    std::string compile(unsigned int level = 0) const;
};

