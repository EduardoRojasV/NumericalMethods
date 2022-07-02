#include "numericalmethods.h"

namespace NumericalMethods {

// *** Metódos de Integración

template<typename T>
TrapezoidalRule<T>::TrapezoidalRule(): m_lastSample(Sample<T>()), m_integral(T())
{

}

template<typename T>
T TrapezoidalRule<T>::result() const { return m_integral; }

template<typename T>
void TrapezoidalRule<T>::resetValues()
{
    m_lastSample.clean();
    m_integral = static_cast<T>(0);
}

template<typename T>
void TrapezoidalRule<T>::integrate(const T newSample, const T newInterval)
{
    T area = (newInterval - m_lastSample.interval) * (m_lastSample.sample + newSample);
    area /= static_cast<T>(2);
    m_integral += area;
    m_lastSample.sample   = newSample;
    m_lastSample.interval = newInterval;
}

}
