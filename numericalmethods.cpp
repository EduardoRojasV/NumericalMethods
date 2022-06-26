#include "numericalmethods.h"
namespace NumericalMethods {

template<typename T>
TrapezoidalRule<T>::TrapezoidalRule(): m_lastSample(T()), m_lastInterval(T()), m_integral(T())
{

}

template<typename T>
T TrapezoidalRule<T>::result() const { return m_integral; }

template<typename T>
void TrapezoidalRule<T>::clean()
{
    m_lastSample   = static_cast<T>(0);
    m_lastInterval = static_cast<T>(0);
    m_integral     = static_cast<T>(0);
}

template<typename T>
void TrapezoidalRule<T>::integrate(const T newSample, const T newInterval)
{
    double area = ( (newInterval - m_lastInterval) * (m_lastSample + newSample) ) / 2;

    m_integral    += area;
    m_lastInterval = newInterval;
    m_lastSample    = newSample;
}

}
