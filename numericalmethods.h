#ifndef NUMERICALMETHODS_H
#define NUMERICALMETHODS_H

/** Descripción:
 *
 * Esta biblioteca está diseñada bajo el paradigma de programación Orientado a Objetos (POO),
 * para ayudar a los desarrolladores en C++ (Versión del estandar: 11) que requieran de métodos
 * numéricos en sus proyectos.
 *
 * @author Jose Eduardo Rojas Vera <joseeduardo2511@outlook.es> / GLINTEC
 * @date Junio - 2022
 * @version 1.0.0
 *
 * This work is licensed under the terms of the GNU GPL, version 2.
*/

namespace NumericalMethods {

// *** Integración

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
    T m_lastSample;
    T m_lastInterval;
    T m_integral;

public:
    TrapezoidalRule();

    T result() const;
    void resetValues();
    void integrate(const T newSample, const T newInterval);
};

// *** Derivación

// *** Transformadas

// *** Estadística

}
#endif // NUMERICALMETHODS_H
