#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

template <bool>
struct enable_if{
};

template <>
struct enable_if<true>{
    typedef void    type;
};

#endif /* ENABLE_IF_HPP */
