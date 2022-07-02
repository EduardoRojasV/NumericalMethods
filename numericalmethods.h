/** Descripción:
 *
 * Esta biblioteca está diseñada bajo el paradigma de programación Orientado a Objetos (POO),
 * para ayudar a los desarrolladores en C++ (Versión del estandar: 11) que requieran de métodos
 * numéricos en sus proyectos.
 *
 * @author Jose Eduardo Rojas Vera <joseeduardo2511@outlook.es>
 * @date Junio - 2022
 * @version 1.0.0
 *
 * This work is licensed under the terms of the GNU GPL, version 2.
*/

#ifndef NUMERICALMETHODS_H
#define NUMERICALMETHODS_H

namespace NumericalMethods {

template <typename T>
struct Sample
{
    T sample;
    T interval;

    Sample(): sample(T()), interval(T())
    {

    }
    Sample(const T s, const T i): sample(s), interval(i)
    {

    }

    void clean()
    {
        sample   = static_cast<T>(0);
        interval = static_cast<T>(0);
    }
};

// *** Integración abierta de Newton-Cotes

/** Descripción
 *
 * La clase TrapezoidalRule (Regla del Trapezio) utiliza el método
 * numérico del trapezio para integrar funcines. La implementación de
 * este algoritmo esta echa para integrar funciones construidas atravez
 * de la adquisicion de muestras obtenidas en intervalos (acumulado de
 * muestras).
 *
 * Nota: Es importante recalcar que las disminución del erro en el calculo
 * esta relacinado con la frecuencia de muestreo, a mayor frecuencia de
 * muestreo se tiene una mejor aproximacion y por consiguiente una disminucion
 * del erro.
 *
 * @param new sample and new interval
 *
 * sample: Mestra obtenida.
 *
 * interval: el intervalo en el que se tomó la muestra.
 *
 * @return el valor de la integral actualizado con la
 * con la ultima muestra e intervalo procesada.
*/

template<typename T>
class TrapezoidalRule
{
    Sample<T> m_lastSample;
    T m_integral;

public:
    TrapezoidalRule();

    T result() const;
    void resetValues();
    void integrate(const T newSample, const T newInterval);
};

template<typename T>
class Simpson1_3
{
    Sample<T> m_firstPoint;
    Sample<T> m_secondPoint;
    Sample<T> m_thirdPoint;
    T m_integral;

public:
    Simpson1_3() : m_firstPoint(Sample<T>()),
    m_secondPoint(Sample<T>()),
    m_thirdPoint(Sample<T>()),
    m_integral(T())
    {

    }

    T result() const { return m_integral; }
    void resetValues()
    {
        m_firstPoint.clean();
        m_secondPoint.clean();
        m_thirdPoint.clean();
        m_integral = static_cast<T>(0);
    }
    void setFirstPoint(const T newSample, const T newInterval)
    {
        m_firstPoint.sample   = newSample;
        m_firstPoint.interval = newInterval;
    }
    void setSecondPoint(const T newSample, const T newInterval)
    {
        m_secondPoint.sample   = newSample;
        m_secondPoint.interval = newInterval;
    }
    void setThirdPoint(const T newSample, const T newInterval)
    {
        m_thirdPoint.sample   = newSample;
        m_thirdPoint.interval = newInterval;
    }
    void integrate()
    {
        T Ancho = ( m_thirdPoint.interval - m_firstPoint.interval );
        T AlturaPromedio =
                m_firstPoint.sample + (4 * m_secondPoint.sample) + m_thirdPoint.sample;
        AlturaPromedio /= 6;
        m_integral = AlturaPromedio;
    }
};
// *** Derivación

// *** Transformadas

// *** Estadística

}
#endif // NUMERICALMETHODS_H
