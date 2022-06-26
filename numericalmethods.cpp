#include "numericalmethods.h"
namespace NumericalMethods {

TrapezoidalRule::TrapezoidalRule(): m_lastSample(0.0), m_lastInterval(0.0), m_integral(0.0)
{

}

double TrapezoidalRule::result() const { return m_integral; }

void TrapezoidalRule::clean()
{
    m_lastSample    = 0.0;
    m_lastInterval = 0.0;
    m_integral     = 0.0;
}

void TrapezoidalRule::integrate(const T newSample, const T newInterval)
{
    double area = ( (newInterval - m_lastInterval) * (m_lastSample + newSample) ) / 2;

    m_integral    += area;
    m_lastInterval = newInterval;
    m_lastSample    = newSample;
}



}
