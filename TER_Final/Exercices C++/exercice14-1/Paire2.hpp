#ifndef PAIRE2_HPP
#define PAIRE2_HPP

#include <iostream>

template<typename T1, typename T2>
class Paire2 {
private:
    T1 m_first;
    T2 m_second;

public:
    Paire2(T1 first, T2 second);
    T1 first() const;
    T2 second() const;
};

template<typename T1, typename T2>
Paire2<T1, T2>::Paire2(T1 first, T2 second)
    : m_first{first}, m_second{second} {}

template<typename T1, typename T2>
T1 Paire2<T1, T2>::first() const { return m_first; }

template<typename T1, typename T2>
T2 Paire2<T1, T2>::second() const { return m_second; }

#endif 
