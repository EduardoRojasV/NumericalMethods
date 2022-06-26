#ifndef NUMERICALMETHODS_H
#define NUMERICALMETHODS_H

/**
 * @author Jose Eduardo Rojas Vera <joseeduardo2511@outlook.es> / GLINTEC
 * @date
 *   This work is licensed under the terms of the GNU GPL, version 2.
*/

namespace NumericalMethods {

// *** Metódos numericos para integración

/* Descripción de la clase
 * La clase TrapezoidalRule ejecuta el metodo numerico del trapezio
 * para integrar funciones.
 *
 * @param sample y interval
 * @return el área valor de la integral
*/

template<typename T>
class TrapezoidalRule
{
    T m_lastSample;
    T m_lastInterval;
    T m_integral;
public:
    TrapezoidalRule();

    T result() const;
    void clean();
    void integrate(const T newSample, const T newInterval);
};

// *** Metódos numericos para derivación

}
#endif // NUMERICALMETHODS_H
