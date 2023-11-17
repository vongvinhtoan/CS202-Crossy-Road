#include <iostream>

template<typename T>
void Extra::putExtra(const std::string& key, const T& value)
{
    m_extra[key] = value;
}

template<typename T>
T Extra::getExtra(const std::string& key)
{
    return std::any_cast<T>(m_extra[key]);
}