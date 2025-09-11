/**
 * @file polynomial.hpp содержит объявления всех методов для класса polynomial.
 * @author Вашкевич Максим Викторович, гр. 421702
 */

#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <cstdlib>
#include <iostream>

/**
 * @class polynomial
 * @brief Класс для представления многочлена с вещественными коэффициентами.
 * @details Полином представлен в виде массива коэффициентов, где индекс элемента соответствует степени переменной.
 * Поддерживаются основные операции над многочленами: сложение, вычитание, умножение, деление и вычисление значения.
 */
class polynomial {
private:
	/// @brief Массив коэффициентов многочлена
	double *m_coefficients;
	/// @brief Размер массива коэффициентов (степень многочлена + 1)
	size_t m_size;
	
	/**
	 * @brief Вспомогательный метод для получения степени многочлена.
	 * @return Степень многочлена (наивысшая степень с ненулевым коэффициентом)
	 */
	[[nodiscard]] size_t m_degree() const noexcept;
	
	/**
	 * @brief Вспомогательный метод для получения старшего коэффициента.
	 * @return Старший коэффициент многочлена (коэффициент при наивысшей степени)
	 */
	[[nodiscard]] double m_leading_coefficient() const noexcept;
	
	/**
	 * @brief Вспомогательный метод для проверки нулевого многочлена.
	 * @return true если многочлен нулевой, false в противном случае
	 */
	[[nodiscard]] bool m_is_zero() const noexcept;

public:
	/**
	 * @brief Конструктор многочлена.
	 * @param degree Степень многочлена
	 * @param coefficients Массив коэффициентов (начиная со старшей степени)
	 */
	explicit polynomial(size_t degree = static_cast<size_t>(-1), const double *coefficients = nullptr);
	
	/**
	 * @brief Конструктор копирования.
	 * @param other Полином для копирования
	 */
	polynomial(const polynomial &);
	
	/**
	 * @brief Оператор присваивания.
	 * @param other Полином для присваивания
	 * @return Ссылку на текущий многочлен
	 */
	polynomial &operator=(const polynomial &);
	
	/**
	 * @brief Конструктор перемещения.
	 * @param other Полином для перемещения
	 */
	polynomial(polynomial &&) noexcept;
	
	/**
	 * @brief Оператор перемещающего присваивания.
	 * @param other Полином для перемещения
	 * @return Ссылку на текущий многочлен
	 */
	polynomial &operator=(polynomial &&) noexcept;
	
	/**
	 * @brief Деструктор многочлена.
	 */
	~polynomial();
	
	/**
	 * @brief Обмен значениями двух многочленов.
	 * @param first Первый многочлен
	 * @param second Второй многочлен
	 */
	friend void swap(polynomial &, polynomial &) noexcept;
	
	/**
	 * @brief Оператор сравнения на равенство.
	 * @param other Полином для сравнения
	 * @return true если многочлены равны, false в противном случае
	 */
	bool operator==(const polynomial &) const noexcept;
	
	/**
	 * @brief Оператор сравнения на неравенство.
	 * @param other Полином для сравнения
	 * @return true если многочлены не равны, false в противном случае
	 */
	bool operator!=(const polynomial &) const noexcept;
	
	/**
	 * @brief Оператор ввода многочлена.
	 * @param is Поток ввода
	 * @param p Полином для ввода
	 * @return Модифицированный поток ввода
	 */
	friend std::istream &operator>>(std::istream &, polynomial &);
	
	/**
	 * @brief Оператор вывода многочлена.
	 * @param os Поток вывода
	 * @param p Полином для вывода
	 * @return Модифицированный поток вывода
	 */
	friend std::ostream &operator<<(std::ostream &, const polynomial &);
	
	/**
	 * @brief Оператор доступа к коэффициенту по степени.
	 * @param degree Степень переменной
	 * @return Коэффициент при указанной степени
	 */
	double operator[](size_t) const noexcept;
	
	/**
	 * @brief Оператор вычисления значения многочлена.
	 * @param x Значение переменной
	 * @return Значение многочлена в точке x
	 */
	double operator()(double) const noexcept;
	
	/**
	 * @brief Оператор сложения с присваиванием.
	 * @param other Полином-слагаемое
	 * @return Ссылку на текущий многочлен после сложения
	 */
	polynomial &operator+=(const polynomial &);
	
	/**
	 * @brief Оператор сложения многочленов.
	 * @param other Полином-слагаемое
	 * @return Новый многочлен - результат сложения
	 */
	polynomial operator+(const polynomial &) const;
	
	/**
	 * @brief Оператор вычитания с присваиванием.
	 * @param other Вычитаемый многочлен
	 * @return Ссылку на текущий многочлен после вычитания
	 */
	polynomial &operator-=(const polynomial &);
	
	/**
	 * @brief Оператор вычитания многочленов.
	 * @param other Вычитаемый многочлен
	 * @return Новый многочлен - результат вычитания
	 */
	polynomial operator-(const polynomial &) const;
	
	/**
	 * @brief Оператор умножения с присваиванием.
	 * @param other Полином-множитель
	 * @return Ссылку на текущий многочлен после умножения
	 */
	polynomial &operator*=(const polynomial &);
	
	/**
	 * @brief Оператор умножения многочленов.
	 * @param other Полином-множитель
	 * @return Новый многочлен - результат умножения
	 */
	polynomial operator*(const polynomial &) const;
	
	/**
	 * @brief Оператор деления с присваиванием.
	 * @param other Делитель-многочлен
	 * @return Ссылку на текущий многочлен после деления
	 */
	polynomial &operator/=(const polynomial &);
	
	/**
	 * @brief Оператор деления многочленов.
	 * @param other Делитель-многочлен
	 * @return Новый многочлен - результат деления
	 */
	polynomial operator/(const polynomial &) const;
};

#endif // POLYNOMIAL_HPP