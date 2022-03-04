#pragma once
#include <string>
#include <memory>
#include <vector>

/*
    Описание всех возможных блоков кода

    Unit:
        Самый базовый абстрактный класс - языковая контрукция


    ClassUnit:

        Абстрактный класс конструкции Класс

        string m_name - имя класса
        vector< Fields > m_fields - блоки кода, которые должны быть внутри этого блока
        пример: методы, член-данные внутри класса
        у m_fields всего 3 поля для добавления в него блоков: public, private, protected

    MethodUnit:

        Абстрактный класс блока метода класса


        string m_name - имя метода
        string m_returnType - возвращаемый тип
        Flags m_flags - модификаторы метода (virtual, const, static)
        vector< shared_ptr< Unit > > m_body - аналогично m_fields  у ClassUnit

    PrintUnit:

        Абстрактый класс потока вывода

        m_text - текст
*/


class Unit
{
public:
    using Flags = unsigned int; //для модификаторов блока
public:

    virtual ~Unit() = default;

    //добавить дочернюю языковую конструкцию
    virtual void add(const std::shared_ptr< Unit >&, Flags);
    //получить строку с кодом, описывающим данную конструкцию
    virtual std::string compile(unsigned int level = 0) const = 0;

protected:

    //сформировать отступ вложенности
    virtual std::string generateShift(unsigned int level) const;
};


class ClassUnit : public Unit
{
public:

    //модификаторы доступа
    enum AccessModifier
    {
        PUBLIC = 0, //с++, java, c#
        PROTECTED = 1, //с++, java, c#
        PRIVATE = 1 << 1, //с++, java, c#
        ABSTRACT = 1 << 2, //java
        FINAL = 1 << 3, //с++, java, c#
        INTERNAL = 1 << 4, //c#
        NONE
    };

    explicit ClassUnit(const std::string& name, Flags modifier = AccessModifier::NONE);
    virtual ~ClassUnit() = default;

    //добавить дочернюю языковую конструкцию
    void add(const std::shared_ptr< Unit >& unit, Flags flags) override;

protected:
    using Fields = std::vector< std::shared_ptr<Unit> >;

    //имя класса
    std::string                             m_name;
    //модификаторы доступа для класса
    Flags                                   m_modifier;
    //список методов класса
    std::vector< Fields >                   m_fields;
    //список полей для модификатор доступа public, private, protected
    static const std::vector< std::string > ACCESS_MODIFIERS;
};

class MethodUnit : public Unit
{
public:
    // модификаторы доступа для методов
    enum AccessModifier
    {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        ABSTRACT = 1 << 3,
        FINAL = 1 << 4,
        INTERNAL = 1 << 5,
        NONE = 0 //нет модификаторов
    };

    MethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    virtual ~MethodUnit() = default;

    //добавить дочернюю языковую конструкцию
    void add(const std::shared_ptr< Unit >& unit, Flags = AccessModifier::NONE) override;

protected:

    std::string                             m_name;
    std::string                             m_returnType;
    Flags                                   m_flags;
    std::vector< std::shared_ptr< Unit > >  m_body;
};

class PrintUnit : public Unit
{
public:

    explicit PrintUnit(const std::string& Text);
    virtual ~PrintUnit() = default;

protected:

    //текст для вывода
    std::string m_text;
};
