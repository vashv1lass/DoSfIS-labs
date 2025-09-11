/**
 * @file polynomial.hpp содержит определения всех методов для класса polynomial.
 * @author Вашкевич Максим Викторович, гр. 421702
 */

#include "polynomial.hpp"

#include <cmath>

const double EPSILON = 1e-10;

size_t polynomial::m_degree() const noexcept {
	for (size_t i = this->m_size - 1; i != static_cast<size_t>(-1); i--) {
		if (std::abs(this->m_coefficients[i]) > EPSILON) {
			return i;
		}
	}
	
	return 0;
}

double polynomial::m_leading_coefficient() const noexcept {
	for (size_t i = this->m_size - 1; i != static_cast<size_t>(-1); i--) {
		if (std::abs(this->m_coefficients[i]) > EPSILON) {
			return this->m_coefficients[i];
		}
	}
	
	return 0;
}

bool polynomial::m_is_zero() const noexcept {
	for (size_t i = 0; i < this->m_size; i++) {
		if (std::abs(this->m_coefficients[i]) > EPSILON) {
			return false;
		}
	}
	return true;
}

polynomial::polynomial(size_t degree, const double *coefficients) : m_size(degree + 1) {
	if (this->m_size == 0) {
		this->m_coefficients = new double[1]();
	} else {
		this->m_coefficients = new double[this->m_size]();
		if (coefficients != nullptr) {
			for (size_t i = 0; i < this->m_size; i++) {
				this->m_coefficients[i] = coefficients[i];
			}
		}
	}
}

polynomial::polynomial(const polynomial &other) : polynomial(other.m_size - 1, other.m_coefficients) {}

polynomial &polynomial::operator=(const polynomial &other) {
	if (this != &other) {
		polynomial copy(other);
		swap(*this, copy);
	}
	
	return *this;
}

polynomial::polynomial(polynomial &&other) noexcept
	: m_coefficients(other.m_coefficients), m_size(other.m_size) {
	other.m_coefficients = nullptr;
	other.m_size = 0;
}

polynomial &polynomial::operator=(polynomial &&other) noexcept {
	if (this != &other) {
		polynomial copy(std::move(*this));
		swap(*this, other);
	}
	return *this;
}

polynomial::~polynomial() {
	delete[] this->m_coefficients;
	this->m_size = 0;
}

void swap(polynomial &a, polynomial &b) noexcept {
	std::swap(a.m_size, b.m_size);
	std::swap(a.m_coefficients, b.m_coefficients);
}

bool polynomial::operator==(const polynomial &other) const noexcept {
	if (this->m_size == other.m_size) {
		for (size_t i = 0; i < this->m_size; i++) {
			if (this->m_coefficients[i] != other.m_coefficients[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool polynomial::operator!=(const polynomial &other) const noexcept {
	return !(*this == other);
}

std::istream &operator>>(std::istream &is, polynomial &p) {
	size_t size;
	is >> size;
	
	p = polynomial(size);
	for (size_t i = 0; i < p.m_size; i++) {
		is >> p.m_coefficients[i];
	}
	
	return is;
}

std::ostream &operator<<(std::ostream &os, const polynomial &p) {
	if (p.m_size > 0) {
		bool first_term = true;
		for (size_t i = p.m_size - 1; i != static_cast<size_t>(-1); i--) {
			if (p.m_coefficients[i] != 0) {
				if (!first_term) {
					if (p.m_coefficients[i] > 0) {
						os << '+';
					} else {
						os << '-';
					}
				} else {
					if (p.m_coefficients[i] < 0) {
						os << '-';
					}
				}
				
				if (std::abs(p.m_coefficients[i]) != 1 || i == 0) {
					os << std::abs(p.m_coefficients[i]);
				}
				
				if (i > 0) {
					os << 'x';
					if (i > 1) {
						os << '^' << i;
					}
				}
				
				first_term = false;
			}
		}
	} else {
		os << 0;
	}
	
	return os;
}

double polynomial::operator[](size_t c_deg) const noexcept {
	if (c_deg >= this->m_size) {
		return 0;
	}
	return this->m_coefficients[c_deg];
}

double polynomial::operator()(double x) const noexcept {
	if (this->m_size == 0) {
		return 0;
	}
	
	double result = 0;
	double current_x_pow = 1;
	for (size_t i = 0; i < this->m_size; i++) {
		result += this->m_coefficients[i] * current_x_pow;
		current_x_pow *= x;
	}
	
	return result;
}

polynomial &polynomial::operator+=(const polynomial &other) {
	if (other.m_is_zero()) {
		return *this;
	}
	
	size_t max_size = std::max(this->m_size, other.m_size);
	if (max_size > this->m_size) {
		auto *new_coefficients = new double[max_size]();
		if (this->m_coefficients != nullptr) {
			for (size_t i = 0; i < this->m_size; i++) {
				new_coefficients[i] = this->m_coefficients[i];
			}
			delete[] this->m_coefficients;
		}
		
		this->m_coefficients = new_coefficients;
		this->m_size = max_size;
	}
	
	for (size_t i = 0; i < other.m_size; i++) {
		this->m_coefficients[i] += other.m_coefficients[i];
	}
	this->m_size = max_size;
	
	return *this;
}

polynomial polynomial::operator+(const polynomial &other) const {
	polynomial copy(*this);
	return copy += other;
}

polynomial &polynomial::operator-=(const polynomial &other) {
	if (other.m_is_zero()) {
		return *this;
	}
	
	size_t max_size = std::max(this->m_size, other.m_size);
	if (max_size > this->m_size) {
		auto *new_coefficients = new double[max_size]();
		if (this->m_coefficients != nullptr) {
			for (size_t i = 0; i < this->m_size; i++) {
				new_coefficients[i] = this->m_coefficients[i];
			}
			delete[] this->m_coefficients;
		}
		
		this->m_coefficients = new_coefficients;
		this->m_size = max_size;
	}
	
	for (size_t i = 0; i < other.m_size; i++) {
		this->m_coefficients[i] -= other.m_coefficients[i];
	}
	this->m_size = max_size;
	
	return *this;
}

polynomial polynomial::operator-(const polynomial &other) const {
	polynomial copy(*this);
	return copy -= other;
}

polynomial &polynomial::operator*=(const polynomial &other) {
	if (this->m_is_zero() || other.m_is_zero()) {
		*this = polynomial(0);
		return *this;
	}
	
	size_t new_size = this->m_size + other.m_size - 1;
	auto *new_coefficients = new double[new_size]();
	
	for (size_t i = 0; i < this->m_size; i++) {
		for (size_t j = 0; j < other.m_size; j++) {
			new_coefficients[i + j] += this->m_coefficients[i] * other.m_coefficients[j];
		}
	}
	
	delete[] this->m_coefficients;
	this->m_coefficients = new_coefficients;
	this->m_size = new_size;
	
	return *this;
}

polynomial polynomial::operator*(const polynomial &other) const {
	polynomial copy(*this);
	return copy *= other;
}

polynomial &polynomial::operator/=(const polynomial &other) {
	if (other.m_is_zero()) {
		throw std::invalid_argument("Division by zero polynomial");
	}
	
	if (this->m_is_zero()) {
		return *this;
	}
	
	size_t deg_dividend = this->m_degree();
	size_t deg_divisor = other.m_degree();
	
	if (deg_dividend < deg_divisor) {
		*this = polynomial(0);
		return *this;
	}
	
	polynomial quotient(deg_dividend - deg_divisor);
	polynomial remainder(*this);
	
	while (!remainder.m_is_zero() && remainder.m_degree() >= deg_divisor) {
		double coefficient = remainder.m_leading_coefficient() / other.m_leading_coefficient();
		size_t deg_diff = remainder.m_degree() - deg_divisor;
		
		quotient.m_coefficients[deg_diff] = coefficient;
		
		polynomial temp(deg_diff);
		temp.m_coefficients[deg_diff] = coefficient;
		
		remainder -= other * temp;
	}
	
	*this = quotient;
	return *this;
}

polynomial polynomial::operator/(const polynomial &other) const {
	polynomial copy(*this);
	return copy /= other;
}