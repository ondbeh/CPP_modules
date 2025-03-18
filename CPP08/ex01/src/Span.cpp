#include "../inc/Span.hpp"

Span::Span(unsigned int n) : _size(n) {}

Span::Span(Span const &src) : _size(src._size), _vector(src._vector) {}

Span &Span::operator=(Span const &src) {
	if (this != &src) {
		_size = src._size;
		_vector = src._vector;
	}
	return *this;
}

void Span::addNumber(const int &n) {
	if (_vector.size() == _size) {
		throw std::runtime_error("Span is full");
	}
	_vector.push_back(n);
}

int Span::shortestSpan() const {
	if (_vector.size() < 2) {
		throw std::runtime_error("Not enough elements");
	}
	std::vector <int> sorted = _vector;
	std::sort(sorted.begin(), sorted.end());
	int min = INT32_MAX;
	for (size_t i = 1; i < sorted.size(); i++) {
		if (sorted[i] - sorted[i - 1] < min) {
			min = sorted[i] - sorted[i - 1];
		}
	}
	return min;
}

int Span::longestSpan() const {
	if (_vector.size() < 2) {
		throw std::runtime_error("Not enough elements");
	}
	int min = *std::min_element(_vector.begin(), _vector.end());
	int max = *std::max_element(_vector.begin(), _vector.end());
	return max - min;
}





