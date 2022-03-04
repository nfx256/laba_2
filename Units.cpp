#include <stdexcept>
#include "Units.h"

//в базовом классе, данный метод не пригоден для использования
void Unit::add(const std::shared_ptr< Unit >&, Flags)
{
    throw std::runtime_error("Not supported");
}


std::string Unit::generateShift(unsigned int level) const
{
    static const auto DEFAULT_SHIFT = "    ";
    std::string result;

    for (unsigned int i = 0; i < level; ++i)
        result += DEFAULT_SHIFT;

    return result;
}

//во всех трех языках только по 3 модификатор доступа в классе
const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "public", "protected", "private" };

ClassUnit::ClassUnit(const std::string & name, Flags modifier) :
    m_name(name),
    m_modifier(modifier)
{
    m_fields.resize(ACCESS_MODIFIERS.size());
}

//добавить юнит в соответвующий список доступа
//по умолчаниию доступ "private"
void ClassUnit::add(const std::shared_ptr< Unit > & unit, Flags flags)
{
    int accessModifier = PRIVATE;

    if (flags < ACCESS_MODIFIERS.size())
        accessModifier = flags;

    m_fields[accessModifier].push_back(unit);
}


MethodUnit::MethodUnit(const std::string & name,
    const std::string & returnType,
    Flags flags) :
    m_name(name),
    m_returnType(returnType),
    m_flags(flags)
{}

//добавить юнит в тело метода
void MethodUnit::add(const std::shared_ptr< Unit > & unit, Flags)
{
    m_body.push_back(unit);
}

PrintUnit::PrintUnit(const std::string & Text) :
    m_text(Text)
{}
