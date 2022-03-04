#include "CppUnits.h"

CppClassUnit::CppClassUnit(const std::string& name, Flags modifier) :
    ClassUnit(name, modifier)
{}

CppClassUnit::~CppClassUnit()
{}

std::string CppClassUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level) + "class " + m_name + " ";

    //если установлен бит "final"
    if(m_modifier & FINAL)
    {
        result += "final ";
    }

    result += "{\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
    {
        if (m_fields[i].empty())
            continue;

        result += ACCESS_MODIFIERS[i] + ":\n";

        //генерируем строку для всех полей класса
        for (const auto& f : m_fields[i])
        {
            if (f)
                result += f->compile(level + 1);
        }
        result += "\n";
    }

    result += generateShift(level) + "};\n";

    return result;
}

CppMethodUnit::CppMethodUnit(const std::string& name,
    const std::string& returnType, Flags flags) :
    MethodUnit(name, returnType, flags)
{}

CppMethodUnit::~CppMethodUnit()
{}

std::string CppMethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    //если установлен бит "static"
    if (m_flags & STATIC)
    {
        result += "static ";
    }
    //если установлен бит "virtual"
    else if (m_flags & VIRTUAL)
    {
        result += "virtual ";
    }
    //одновременно не может быть и static и virtual

    result += m_returnType + " ";
    result += m_name + "()";

    if(m_flags & FINAL)
    {
        result += "final ";
    }

    if (m_flags & CONST)
    {
        result += " const";
    }

    result += " {\n";

    for (const auto& b : m_body)
    {
        if (b)
            result += b->compile(level + 1);
    }

    result += generateShift(level) + "}\n";

    return result;
}

CppPrintUnit::CppPrintUnit(const std::string& text) :
    PrintUnit(text)
{}

CppPrintUnit::~CppPrintUnit()
{}

std::string CppPrintUnit::compile(unsigned int level) const
{
    return generateShift(level) + "printf( \"" + m_text + "\" );\n";
}
