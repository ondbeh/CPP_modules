#pragma once

#include <stack>

template <typename T>
	class MutantStack: public std::stack <T> {
	public:
		MutantStack() : std::stack <T>() {}

		MutantStack(MutantStack const &src) : std::stack <T>(src) {}

		~MutantStack() = default;

		MutantStack &operator=(MutantStack const &src) {
			if (this != &src) {
				std::stack <T>::operator=(src);
			}
			return *this;
		}

		auto begin() {
			return std::stack <T>::c.begin();
		}

		auto end() {
			return std::stack <T>::c.end();
		}

		auto begin() const {
			return std::stack <T>::c.begin();
		}

		auto end() const {
			return std::stack <T>::c.end();
		}
	};