#pragma once

#include <QObject>

#define AUTO_PROPERTY(TYPE, NAME)                                                                                      \
    Q_PROPERTY(TYPE NAME READ NAME WRITE NAME NOTIFY NAME##Changed)                                                    \
public:                                                                                                                \
    [[nodiscard]] auto NAME() const->TYPE                                                                              \
    {                                                                                                                  \
        return a_##NAME;                                                                                               \
    }                                                                                                                  \
    void NAME(const TYPE &value)                                                                                       \
    {                                                                                                                  \
        if (a_##NAME == value) return;                                                                                 \
        a_##NAME = value;                                                                                              \
        emit NAME##Changed(value);                                                                                     \
    }                                                                                                                  \
    Q_SIGNAL void NAME##Changed(TYPE value);                                                                           \
                                                                                                                       \
private:                                                                                                               \
    TYPE a_##NAME;

#define AUTO_PROPERTY2(TYPE, NAME, DEFAULT)                                                                            \
    Q_PROPERTY(TYPE NAME READ NAME WRITE NAME NOTIFY NAME##Changed)                                                    \
public:                                                                                                                \
    [[nodiscard]] auto NAME() const->TYPE                                                                              \
    {                                                                                                                  \
        return a_##NAME;                                                                                               \
    }                                                                                                                  \
    void NAME(const TYPE &value)                                                                                       \
    {                                                                                                                  \
        if (a_##NAME == value) return;                                                                                 \
        a_##NAME = value;                                                                                              \
        emit NAME##Changed(value);                                                                                     \
    }                                                                                                                  \
    Q_SIGNAL void NAME##Changed(TYPE value);                                                                           \
                                                                                                                       \
private:                                                                                                               \
    TYPE a_##NAME = DEFAULT;

#define AUTO_PROPERTY_VAL(TYPE, NAME)                                                                                  \
    Q_PROPERTY(TYPE NAME READ NAME WRITE NAME NOTIFY NAME##Changed)                                                    \
public:                                                                                                                \
    [[nodiscard]] auto NAME() const->TYPE                                                                              \
    {                                                                                                                  \
        return a_##NAME;                                                                                               \
    }                                                                                                                  \
    void NAME(TYPE value)                                                                                              \
    {                                                                                                                  \
        if (a_##NAME == value) return;                                                                                 \
        a_##NAME = value;                                                                                              \
        emit NAME##Changed(value);                                                                                     \
    }                                                                                                                  \
    Q_SIGNAL void NAME##Changed(TYPE value);                                                                           \
                                                                                                                       \
private:                                                                                                               \
    TYPE a_##NAME;

#define AUTO_PROPERTY_VAL2(TYPE, NAME, DEFAULT)                                                                        \
    Q_PROPERTY(TYPE NAME READ NAME WRITE NAME NOTIFY NAME##Changed)                                                    \
public:                                                                                                                \
    [[nodiscard]] auto NAME() const->TYPE                                                                              \
    {                                                                                                                  \
        return a_##NAME;                                                                                               \
    }                                                                                                                  \
    void NAME(TYPE value)                                                                                              \
    {                                                                                                                  \
        if (a_##NAME == value) return;                                                                                 \
        a_##NAME = value;                                                                                              \
        emit NAME##Changed(value);                                                                                     \
    }                                                                                                                  \
    Q_SIGNAL void NAME##Changed(TYPE value);                                                                           \
                                                                                                                       \
private:                                                                                                               \
    TYPE a_##NAME = DEFAULT;

#define READONLY_PROPERTY(TYPE, NAME)                                                                                  \
    Q_PROPERTY(TYPE NAME READ NAME CONSTANT)                                                                           \
public:                                                                                                                \
    [[nodiscard]] auto NAME() const->TYPE                                                                              \
    {                                                                                                                  \
        return a_##NAME;                                                                                               \
    }                                                                                                                  \
                                                                                                                       \
private:                                                                                                               \
    TYPE a_##NAME;

#define READONLY_PROPERTY2(TYPE, NAME, DEFAULT)                                                                        \
    Q_PROPERTY(TYPE NAME READ NAME CONSTANT)                                                                           \
public:                                                                                                                \
    [[nodiscard]] auto NAME() const->TYPE                                                                              \
    {                                                                                                                  \
        return a_##NAME;                                                                                               \
    }                                                                                                                  \
                                                                                                                       \
private:                                                                                                               \
    TYPE a_##NAME = DEFAULT;

#define READ_PROPERTY(TYPE, NAME)                                                                                      \
    Q_PROPERTY(TYPE NAME READ NAME NOTIFY NAME##Changed)                                                               \
public:                                                                                                                \
    [[nodiscard]] auto NAME() const->TYPE                                                                              \
    {                                                                                                                  \
        return a_##NAME;                                                                                               \
    }                                                                                                                  \
    Q_SIGNAL void NAME##Changed(TYPE value);                                                                           \
                                                                                                                       \
private:                                                                                                               \
    TYPE a_##NAME;

#define READ_PROPERTY2(TYPE, NAME, DEFAULT)                                                                            \
    Q_PROPERTY(TYPE NAME READ NAME NOTIFY NAME##Changed)                                                               \
public:                                                                                                                \
    [[nodiscard]] auto NAME() const->TYPE                                                                              \
    {                                                                                                                  \
        return a_##NAME;                                                                                               \
    }                                                                                                                  \
    Q_SIGNAL void NAME##Changed(TYPE value);                                                                           \
                                                                                                                       \
private:                                                                                                               \
    TYPE a_##NAME = DEFAULT;
