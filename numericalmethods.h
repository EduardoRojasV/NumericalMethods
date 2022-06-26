#ifndef NUMERICALMETHODS_H
#define NUMERICALMETHODS_H

// Authors:
//  Jose Eduardo Rojas Vera <joseeduardo2511@outlook.es> / GLINTEC
//
// This work is licensed under the terms of the GNU GPL, version 2.

namespace NumericalMethods {

// *** Metódos numericos para integración

/* Descripción de la clase
 * La clase TrapezoidalRule ejecuta el metodo numerico del trapezio
 * para integrar funciones.
 *
 * @param sample y interval
 * @return el área valor de la integral
*/

class TrapezoidalRule
{
    double m_lastSample;
    double m_lastInterval;
    double m_integral;
public:
    TrapezoidalRule();
    double result() const;
    void clean();
    void integrate(const double newSample, const double newInterval);
};

// *** Metódos numericos para derivación

}
#endif // NUMERICALMETHODS_H
