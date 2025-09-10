#ifndef SET_HPP
#define SET_HPP

#include <variant>
#include <cstdlib>
#include <string>
#include <iostream>

class set {
private:
	std::variant<char *, set> *m_data;
	size_t m_capacity;
	
	size_t m_size;
	
	void m_expand_if_necessary();
	[[nodiscard]] size_t m_find_pos(const std::variant<char *, set> &) const noexcept;
public:
	set();
	explicit set(const std::string &);
	explicit set(const char *);
	
	set(const set &);
	set &operator=(const set &);
	
	set(set &&) noexcept;
	set &operator=(set &&) noexcept;
	
	~set();
	
	bool operator==(const set &other) const noexcept;
	bool operator!=(const set &other) const noexcept;
	
	friend std::istream &operator>>(std::istream &, set &);
	friend std::ostream &operator<<(std::ostream &, const set &);
	
	bool operator[](const std::variant<char *, set> &) const noexcept;
	bool operator[](const char *) const noexcept;
	
	[[nodiscard]] size_t cardinality() const noexcept;
	[[nodiscard]] bool empty() const noexcept;
	
	void insert(const std::variant<char *, set> &);
	void insert(const char *);
	
	void remove(const std::variant<char *, set> &);
	void remove(const char *);
	
	set &operator+=(const set &);
	set operator+(const set &) const;
	
	set &operator*=(const set &);
	set operator*(const set &) const;
	
	set &operator-=(const set &);
	set operator-(const set &) const;
	
	[[nodiscard]] set powerset() const;
};

#endif // SET_HPP