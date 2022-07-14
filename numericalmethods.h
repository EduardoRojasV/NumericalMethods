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

#include <iostream>
#include <array>

#define DEBUG

namespace NumericalMethods {

  template <typename T>
  struct Sample
  {
    T value;
    T interval;

    Sample(): value(T()), interval(T()) { }
    Sample(const T s, const T i): value(s), interval(i) { }
    Sample(const Sample<T> &s): value(s.value), interval(s.interval) { }

    void resetValue()
    {
      value    = static_cast<T>(0);
      interval = static_cast<T>(0);
    }
  };

  // *** Integración de señales digitales con los métodos numéricos de Newton-Cotes

  /** Descripción de la clase TrapezoidalRule
 *
 * La clase TrapezoidalRule implenta el método numérico regla del trapezio,
 * para integra funciones que son construidas tomado muestras en intervalos
 * (regulares y no reglares) o con tabulación de datos en. El intervalo de
 * intregación será definido por el consumidor de esta clase.
 *
 * Nota: Es importante recalcar que las disminución del erro en el calculo
 * esta relacinado con la cantidad de muestras y el intervalo entre cada
 * muestra, a mayor cantidad de muestras con intervalos pequeños entre cada
 * una se tiene una mejor aproximacion y por consiguiente una disminucion
 * del erro.
*/

  template<typename T>
  class TrapezoidalRule
  {
    Sample<T> m_lastSample;
    T m_integral;

  public:
    TrapezoidalRule(): m_lastSample(Sample<T>()), m_integral(T()) {  }

    T result() const { return m_integral; }

    void resetValues()
    {
      m_lastSample.resetValue();
      m_integral = static_cast<T>(0);
    }
    void integrate(const T newSample, const T newInterval)
    {
      T area = (newInterval - m_lastSample.interval) * (m_lastSample.value + newSample);
      area /= static_cast<T>(2);
      m_integral += area;
      m_lastSample.value    = newSample;
      m_lastSample.interval = newInterval;
    }
  };

  template<typename T>
  class Simpson_1_3
  {
    Sample<T> m_firstSample;
    Sample<T> m_secondSample;
    Sample<T> m_thirdSample;
    T m_integral;

  public:
    Simpson_1_3() : m_firstSample(Sample<T>()),
      m_secondSample(Sample<T>()),
      m_thirdSample(Sample<T>()),
      m_integral(T()) {  }

    T result() const { return m_integral; }

    void resetValues()
    {
      m_firstSample.resetValue();
      m_secondSample.resetValue();
      m_thirdSample.resetValue();
      m_integral = static_cast<T>(0);
    }
    void setFirstSample(const T newValue, const T newInterval)
    {
      m_firstSample.value    = newValue;
      m_firstSample.interval = newInterval;
    }
    void setSecondSample(const T newValue, const T newInterval)
    {
      m_secondSample.value    = newValue;
      m_secondSample.interval = newInterval;
    }
    void setThirdSample(const T newValue, const T newInterval)
    {
      m_thirdSample.value    = newValue;
      m_thirdSample.interval = newInterval;
    }

    void integrate()
    {
      T width { m_thirdSample.interval - m_firstSample.interval };
      T secondSample = (m_secondSample.value * static_cast<T>(4));
      T AverageHeight = (m_firstSample.value + secondSample + m_thirdSample.value) / static_cast<T>(6);

      m_integral = width * AverageHeight;
    }
  };

  // *** Diferenciación numérica

  // Primera diferencia hacia adelante

  template<typename T>
  class FirstDifference
  {
    Sample<T> m_lastSample;
    T m_derivative;

  public:
    FirstDifference(): m_lastSample(Sample<T>()), m_derivative(T()) {}

    T result() const { return m_derivative; }

    void resetValues()
    {
      m_lastSample.resetValue();
      m_derivative = static_cast<T>(0);
    }
    void derive(const T newValue, const T newInterval)
    {
      T denominator = m_lastSample.interval - newInterval;
      T numerator   = m_lastSample.value - newValue;

      m_derivative = denominator != static_cast<T>(0) ? (numerator/denominator) : static_cast<T>(0);

      m_lastSample.interval = newInterval;
      m_lastSample.value    = newValue;
    }
  };

  // *** Transformadas

  template <typename T, uint8_t S>
  class CircularSamples
  {
    std::array<Sample<T>, S> m_samples;
    Sample<T> *m_sampleCurrent;
    uint8_t m_size = S;

    void nextSample()
    {
      ++m_sampleCurrent;
      if(m_sampleCurrent == m_samples.end())
        m_sampleCurrent = m_samples.begin();
    }

  public:

    CircularSamples(): m_size(S)
    {
      m_sampleCurrent = m_samples.begin();
    }

    uint8_t size() const { return m_size; }
    const Sample<T> &sampleCurrent() const { return *m_sampleCurrent; }

    void setNextSample(const Sample<T> &newvalue)
    {
      *m_sampleCurrent = newvalue;
      nextSample();
    }

    void setNextSample(const T newvalue, const T interval)
    {
      m_sampleCurrent->value    = newvalue;
      m_sampleCurrent->interval = interval;
      nextSample();
    }
  };

  // *** Estadística

}
#endif // NUMERICALMETHODS_H
