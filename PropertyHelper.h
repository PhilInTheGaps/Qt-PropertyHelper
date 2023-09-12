#pragma once

#include <QObject>
#include <QQmlListProperty>

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

#define AUTO_LIST_PROPERTY(TYPE, NAME)                                                                                 \
    Q_PROPERTY(QQmlListProperty<TYPE> NAME READ NAME##Qml NOTIFY NAME##Changed)                                        \
public:                                                                                                                \
    [[nodiscard]] auto NAME() const->QList<TYPE *>                                                                     \
    {                                                                                                                  \
        return a_##NAME;                                                                                               \
    }                                                                                                                  \
    [[nodiscard]] auto NAME##Qml()->QQmlListProperty<TYPE>                                                             \
    {                                                                                                                  \
        return QQmlListProperty(this, &a_##NAME);                                                                      \
    }                                                                                                                  \
    void NAME(const QList<TYPE *> &value)                                                                              \
    {                                                                                                                  \
        if (a_##NAME == value) return;                                                                                 \
        a_##NAME = value;                                                                                              \
        emit NAME##Changed(value);                                                                                     \
    }                                                                                                                  \
    Q_SIGNAL void NAME##Changed(QList<TYPE *> value);                                                                  \
                                                                                                                       \
private:                                                                                                               \
    QList<TYPE *> a_##NAME;

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

#define READ_LIST_PROPERTY(TYPE, NAME)                                                                                 \
    Q_PROPERTY(QQmlListProperty<TYPE> NAME READ NAME##Qml NOTIFY NAME##Changed)                                        \
public:                                                                                                                \
    [[nodiscard]] auto NAME() const->QList<TYPE *>                                                                     \
    {                                                                                                                  \
        return a_##NAME;                                                                                               \
    }                                                                                                                  \
    [[nodiscard]] auto NAME##Qml()->QQmlListProperty<TYPE>                                                             \
    {                                                                                                                  \
        return QQmlListProperty(this, &a_##NAME);                                                                      \
    }                                                                                                                  \
    Q_SIGNAL void NAME##Changed();                                                                                     \
                                                                                                                       \
private:                                                                                                               \
    QList<TYPE *> a_##NAME;
