#pragma once

#include <algorithm>
#include <iterator>

template <typename T>
	auto easyfind(T &container, int value) {
		auto iter = std::find(std::begin(container), std::end(container), value);
		if (iter == container.end()) {
			throw std::runtime_error("Value not found");
		}
		return (iter);
	}