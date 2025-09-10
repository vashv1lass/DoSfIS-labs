/**
 * @file set.cpp Файл с реализацией всех методов из set.hpp
 * @author Вашкевич Максим Викторович, гр. 421702
 */

#include "set.hpp"

#include <cstring>
#include <stdexcept>

void set::m_expand_if_necessary() {
	if (this->m_size >= this->m_capacity) {
		this->m_capacity = this->m_capacity * 2;
		auto *new_data = new std::variant<char *, set>[this->m_capacity];
		for (size_t i = 0; i < this->m_size; i++) {
			if (std::holds_alternative<char *>(this->m_data[i])) {
				char *old_str = std::get<char *>(this->m_data[i]);
				const size_t LEN = std::strlen(old_str);
				
				char *new_str = new char[LEN + 1];
				std::strcpy(new_str, old_str);
				
				new_data[i] = new_str;
			} else {
				new_data[i] = std::move(std::get<set>(this->m_data[i]));
			}
		}
		
		delete[] this->m_data;
		this->m_data = new_data;
	}
}

size_t set::m_find_pos(const std::variant<char *, set> &elem) const noexcept {
	if (std::holds_alternative<char *>(elem)) {
		char *elem_atom = std::get<char *>(elem);
		
		for (size_t i = 0; i < this->m_size; i++) {
			if (std::holds_alternative<char *>(this->m_data[i])) {
				char *current_atom = std::get<char *>(this->m_data[i]);
				
				if (strcmp(elem_atom, current_atom) == 0) {
					return i;
				}
			}
		}
	} else {
		set elem_set = std::get<set>(elem);
		
		for (size_t i = 0; i < this->m_size; i++) {
			if (std::holds_alternative<set>(this->m_data[i])) {
				set current_set = std::get<set>(this->m_data[i]);
				
				if (elem_set == current_set) {
					return i;
				}
			}
		}
	}
	
	return static_cast<size_t>(-1);
}

set::set() : m_data(nullptr), m_capacity(0), m_size(0) {}

set::set(const std::string &set_str) : set(set_str.c_str()) {}

static bool needs_quotes(const char *str, const size_t len) {
	for (size_t i = 0; i < len; i++) {
		if (str[i] == ' ' || str[i] == ',' || str[i] == '\"') {
			return true;
		}
	}
	return false;
}

static bool set_string_is_valid(const char *set_str) {
	if (*set_str == '\0') {
		return false;
	}
	
	while (*set_str == ' ') {
		++set_str;
	}
	if (*set_str != '{') {
		return false;
	}
	
	const char *end = set_str + std::strlen(set_str) - 1;
	while (end > set_str && *end == ' ') {
		--end;
	}
	if (*end != '}') {
		return false;
	}
	
	const char *start = set_str + 1;
	--end;
	
	while (start < end && *start == ' ') {
		++start;
	}
	while (end > start && *end == ' ') {
		--end;
	}
	
	if (start == end) {
		return true;
	}
	
	const char *current = start;
	int depth = 0;
	bool in_quotes = false;
	bool at_element = false;
	const char *element_start = nullptr;
	size_t element_len = 0;
	
	while (current <= end) {
		if (in_quotes) {
			if (*current == '\"') {
				in_quotes = false;
				element_len = current - element_start + 1;
			}
		} else if (depth > 0) {
			if (*current == '{') {
				depth++;
			} else if (*current == '}') {
				depth--;
				
				if (depth == 0) {
					element_len = current - element_start + 1;
					
					char *inner_set = new char[element_len + 1];
					std::strncpy(inner_set, element_start, element_len);
					inner_set[element_len] = '\0';
					if (!set_string_is_valid(inner_set)) {
						return false;
					}
					delete[] inner_set;
				}
			}
		} else {
			if (*current == '\"') {
				in_quotes = true;
				at_element = true;
				element_start = current;
			} else if (*current == '{') {
				depth++;
				if (!at_element) {
					at_element = true;
					element_start = current;
				}
			} else if (*current == '}') {
				return false;
			} else if (*current == ',') {
				if (!at_element || element_len == 0) {
					return false;
				}
				
				if (*element_start != '\"' && *element_start != '{') {
					if (needs_quotes(element_start, element_len)) {
						return false;
					}
				}
				
				at_element = false;
				element_len = 0;
			} else if (*current != ' ') {
				if (!at_element) {
					at_element = true;
					element_start = current;
				}
				element_len++;
			}
		}
		
		++current;
	}
	
	if (at_element) {
		if (in_quotes || depth > 0) {
			return false;
		}
		
		if (*element_start != '\"' && *element_start != '{') {
			if (needs_quotes(element_start, element_len)) {
				return false;
			}
		}
	}
	
	return true;
}

static void remove_extraneous_spaces(char *dest_set_str, const char *src_set_str) {
	bool in_quotes = false;
	while (*src_set_str != '\0') {
		if (!in_quotes) {
			if (*src_set_str == '\"') {
				in_quotes = true;
			}
			
			if (*src_set_str != ' ') {
				*dest_set_str++ = *src_set_str;
			}
		} else {
			if (*src_set_str == '\"') {
				in_quotes = false;
			}
			
			*dest_set_str++ = *src_set_str;
		}
		
		++src_set_str;
	}
}

#define GET_SUBSTRING(name, start, end) \
    const size_t STR_LEN = end - start; \
	char *name = new char[STR_LEN + 1]; \
	std::strncpy(name, start, STR_LEN); \
	name[STR_LEN] = '\0'

set::set(const char *set_str) : set() {
	if (!set_string_is_valid(set_str)) {
		throw std::invalid_argument("Invalid set string");
	}
	
	char *normalized_set_str = new char[std::strlen(set_str)];
	remove_extraneous_spaces(normalized_set_str, set_str);
	
	const size_t LEN = std::strlen(normalized_set_str);
	if (LEN < 2) {
		delete[] normalized_set_str;
		return;
	}
	
	const char *start = normalized_set_str + 1;
	const char *end = normalized_set_str + LEN - 1;
	
	if (start < end) {
		this->m_capacity = 1;
		this->m_data = new std::variant<char *, set>[this->m_capacity];
		
		const char *cur = start;
		while (cur < end) {
			if (*cur == '{') {
				const char *inner_start = cur;
				int depth = 1;
				++cur;
				
				while (cur < end && depth > 0) {
					if (*cur == '{') {
						depth++;
					} else if (*cur == '}') {
						depth--;
					}
					++cur;
				}
				
				GET_SUBSTRING(inner_str, inner_start, cur);
				
				set inner_set(inner_str);
				if (this->m_find_pos(inner_set) == static_cast<size_t>(-1)) {
					this->m_expand_if_necessary();
					this->m_data[this->m_size++] = inner_set;
				}
				
				delete[] inner_str;
				
				++cur;
			} else if (*cur == '\"') {
				const char *str_start = ++cur;
				
				while (cur < end && *cur != '\"') {
					++cur;
				}
				
				GET_SUBSTRING(str, str_start, cur);
				if (this->m_find_pos(str) == static_cast<size_t>(-1)) {
					this->m_expand_if_necessary();
					this->m_data[this->m_size++] = str;
				} else {
					delete[] str;
				}
				
				cur += 2;
			} else {
				const char *str_start = cur;
				while (cur < end && *cur != ',' && *cur != '{' && *cur != '}') {
					++cur;
				}
				
				GET_SUBSTRING(str, str_start, cur);
				if (this->m_find_pos(str) == static_cast<size_t>(-1)) {
					this->m_expand_if_necessary();
					this->m_data[this->m_size++] = str;
				} else {
					delete[] str;
				}
				
				++cur;
			}
		}
	}
	
	delete[] normalized_set_str;
}

#undef GET_SUBSTRING

set::set(const set &other) : set() {
	for (size_t i = 0; i < other.m_size; ++i) {
		this->insert(other.m_data[i]);
	}
}

set& set::operator=(const set& other) {
	if (this != &other) {
		set temp(other);
		swap(*this, temp);
	}
	return *this;
}

set::set(set &&other) noexcept : m_data(other.m_data), m_capacity(other.m_capacity), m_size(other.m_size) {
	other.m_data = nullptr;
	other.m_capacity = 0;
	other.m_size = 0;
}

set& set::operator=(set&& other) noexcept {
	if (this != &other) {
		set copy(std::move(*this));
		swap(*this, other);
	}
	return *this;
}

set::~set() {
	if (this->m_data == nullptr) {
		for (size_t i = 0; i < this->m_size; i++) {
			if (std::holds_alternative<char *>(this->m_data[i])) {
				delete[] std::get<char *>(this->m_data[i]);
			}
		}
		delete[] this->m_data;
		
		this->m_data = nullptr;
		this->m_capacity = 0;
		this->m_size = 0;
	} else {
		this->m_capacity = 0;
		this->m_size = 0;
	}
}

void swap(set &a, set &b) noexcept {
	std::swap(a.m_data, b.m_data);
	std::swap(a.m_capacity, b.m_capacity);
	std::swap(a.m_size, b.m_size);
}

bool set::operator==(const set &other) const noexcept {
	if (this->m_size != other.m_size) {
		return false;
	}
	
	for (size_t i = 0; i < this->m_size; i++) {
		if (!other[this->m_data[i]]) {
			return false;
		}
	}
	
	for (size_t i = 0; i < other.m_size; i++) {
		if (!(*this)[other.m_data[i]]) {
			return false;
		}
	}
	
	return true;
}

bool set::operator!=(const set &other) const noexcept {
	return !(*this == other);
}

std::istream &operator>>(std::istream &is, set &s) {
	std::string set_str;
	getline(is, set_str);
	
	s.~set();
	s = set(set_str);
	
	return is;
}

std::ostream &operator<<(std::ostream &os, const set &s) {
	os << "{";
	for (size_t i = 0; i < s.m_size; i++) {
		if (i > 0) {
			os << ", ";
		}
		
		if (std::holds_alternative<char *>(s.m_data[i])) {
			char *str = std::get<char *>(s.m_data[i]);
			
			bool needs_quotes = str[0] == '\0';
			for (size_t j = 0; str[j] != '\0'; j++) {
				if (str[j] == ' ' || str[j] == ',') {
					needs_quotes = true;
					break;
				}
			}
			
			if (needs_quotes) {
				os << "\"" << str << "\"";
			} else {
				os << str;
			}
		} else {
			os << std::get<set>(s.m_data[i]);
		}
	}
	os << "}";
	
	return os;
}

bool set::operator[](const std::variant<char *, set> &elem) const noexcept {
	return this->m_find_pos(elem) != static_cast<size_t>(-1);
}

bool set::operator[](const char *atom) const noexcept {
	char *atom_copy = new char[std::strlen(atom) + 1];
	std::strcpy(atom_copy, atom);
	
	bool result = (*this)[std::variant<char *, set>(atom_copy)];
	
	delete[] atom_copy;
	
	return result;
}

size_t set::cardinality() const noexcept {
	return this->m_size;
}

bool set::empty() const noexcept {
	return this->m_size == 0;
}

void set::insert(const std::variant<char *, set> &elem) {
	if (this->m_find_pos(elem) == static_cast<size_t>(-1)) {
		std::variant<char *, set> copy_elem;
		if (std::holds_alternative<char*>(elem)) {
			const char* str = std::get<char*>(elem);
			size_t len = std::strlen(str);
			char* new_str = new char[len + 1];
			std::strcpy(new_str, str);
			copy_elem = new_str;
		} else {
			copy_elem = std::get<set>(elem);
		}
		
		if (this->m_data == nullptr) {
			this->m_capacity = this->m_size = 1;
			this->m_data = new std::variant<char *, set>[this->m_capacity];
			this->m_data[0] = copy_elem;
		} else {
			this->m_expand_if_necessary();
			this->m_data[this->m_size++] = copy_elem;
		}
	}
}

void set::insert(const char *atom) {
	char* atom_copy = new char[std::strlen(atom) + 1];
	std::strcpy(atom_copy, atom);
	
	insert(std::variant<char*, set>(atom_copy));
}

void set::remove(const std::variant<char *, set> &elem) {
	if (this->m_size != 0) {
		size_t elem_pos = this->m_find_pos(elem);
		if (elem_pos != static_cast<size_t>(-1)) {
			std::swap(this->m_data[elem_pos], this->m_data[--this->m_size]);
		}
	}
}

void set::remove(const char *atom) {
	char* atom_copy = new char[std::strlen(atom) + 1];
	std::strcpy(atom_copy, atom);
	
	remove(std::variant<char*, set>(atom_copy));
	
	delete[] atom_copy;
}

set &set::operator+=(const set &other) {
	for (size_t i = 0; i < other.m_size; i++) {
		this->insert(other.m_data[i]);
	}
	
	return *this;
}

set set::operator+(const set &other) const {
	set copy(*this);
	return copy += other;
}

set &set::operator*=(const set &other) {
	size_t i = 0;
	while (i < this->m_size) {
		if (!other[this->m_data[i]]) {
			this->remove(this->m_data[i]);
		} else {
			i++;
		}
	}
	
	return *this;
}

set set::operator*(const set &other) const {
	set copy(*this);
	return copy *= other;
}

set &set::operator-=(const set &other) {
	for (size_t i = 0; i < this->m_size; i++) {
		if (other[this->m_data[i]]) {
			this->remove(this->m_data[i]);
		}
	}
	
	return *this;
}

set set::operator-(const set &other) const {
	set copy(*this);
	return copy -= other;
}

set set::powerset() const {
	set result;
	result.insert(set());

	for (size_t i = 0; i < this->m_size; i++) {
		set temp = result;
		for (size_t j = 0; j < temp.m_size; j++) {
			set s = std::get<set>(temp.m_data[j]);
			s.insert(this->m_data[i]);
			result.insert(s);
		}
	}

	return result;
}