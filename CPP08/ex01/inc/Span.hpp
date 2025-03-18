#pragma once

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <stdexcept>


class Span {
private:
	unsigned int _size;
	std::vector <int> _vector;

public:
	Span() = delete;
	Span(unsigned int n);
	Span(Span const &src);

	~Span() = default;

	Span &operator=(Span const &src);

	void addNumber(const int &n);

	template <typename InputIterator>
		void addNumbers(const InputIterator &begin, const InputIterator &end) {
			if (_vector.size() + std::distance(begin, end) > _size) {
				throw std::runtime_error("Span is full");
			}
			_vector.insert(_vector.end(), begin, end);
		}

	int shortestSpan() const;
	int longestSpan() const;
};
