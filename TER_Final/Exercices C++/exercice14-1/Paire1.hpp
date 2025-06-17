#ifndef PAIRE1_HPP
#define PAIRE1_HPP

#include <iostream>

template<typename T>
class Paire1 {
private:
    T m_first;
    T m_second;

public:
    Paire1(T first, T second);
    T first() const;
    T second() const;
};


template<typename T>
Paire1<T>::Paire1(T first, T second) : m_first{first}, m_second{second} {}

template<typename T>
T Paire1<T>::first() const { return m_first; }

template<typename T>
T Paire1<T>::second() const { return m_second; }

#endif 
