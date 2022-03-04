#include "JavaUnits.h"

JavaClassUnit::JavaClassUnit(const std::string& name, Flags modifier) :
    ClassUnit(name, modifier)
{}

JavaClassUnit::~JavaClassUnit()
{}

std::string JavaClassUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_modifier & ClassUnit::PRIVATE)
        result += "private ";
    else if (m_modifier & ClassUnit::PROTECTED)
        result += "protected ";
    else
        result += "public ";

    result += "class " + m_name + " ";

    if(m_modifier & ClassUnit::FINAL)
        result += "final ";
    else if(m_modifier & ClassUnit::ABSTRACT)
        result += "abstract ";

    result += "{\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
    {
        if (m_fields[i].empty())
            continue;

        for (const auto& f : m_fields[i])
        {
            if (f)
                result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + f->compile(0);
        }
        result += "\n";
    }

    result += generateShift(level) + "};\n";

    return result;
}

JavaMethodUnit::JavaMethodUnit(const std::string& name,
    const std::string& returnType,
    Flags flags) :
    MethodUnit(name, returnType, flags)
{}

JavaMethodUnit::~JavaMethodUnit()
{}

std::string JavaMethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & JavaMethodUnit::STATIC)
        result += "static ";
    else if (m_flags & JavaMethodUnit::FINAL)
        result += "final ";
    else if (m_flags & JavaMethodUnit::ABSTRACT)
        result += "abstract ";

    result += m_returnType + " ";
    result += m_name + "()";
    result += " {\n";

    for (const auto& b : m_body)
    {
        if (b)
            result += b->compile(level + 2);
    }

    result += generateShift(level + 1) + "}\n";

    return result;
}

JavaPrintUnit::JavaPrintUnit(const std::string& text) :
    PrintUnit(text)
{}

JavaPrintUnit::~JavaPrintUnit()
{}

std::string JavaPrintUnit::compile(unsigned int level) const
{
    return generateShift(level) + "System.out.println( \"" + m_text + "\" );\n";
}
