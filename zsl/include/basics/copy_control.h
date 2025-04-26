#ifndef ZSL_BASICS_COPY_CONTROL_H
#define ZSL_BASICS_COPY_CONTROL_H



#define COPYABLE(Cls)                      \
    Cls(const Cls &) = default;            \
    Cls(Cls &&) = default;                 \
    Cls &operator=(const Cls &) = default; \
    Cls &operator=(Cls &&) = default

/// @class value sematics derived
class Copyable {
protected:
    Copyable() = default;
    ~Copyable() = default;

    COPYABLE(Copyable);
};  

#endif