/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:56:43 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/06 10:56:43 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this == &other)
        return (*this);
    _value = other.getRawBits();
    return (*this);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (_value > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
    return (_value < other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
    return (_value == other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (*this > other || *this == other);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (*this < other || *this == other);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return !(*this == other);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(_value + other.getRawBits());
    return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(_value - other.getRawBits());
    return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((_value * other.getRawBits()) >> _fractionalBits);
    return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((_value << _fractionalBits) / other.getRawBits());
    return (result);
}

Fixed &Fixed::operator++(void)
{
    _value++;
    return (*this);
}

Fixed &Fixed::operator--(void)
{
    _value--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++(*this);
    return (temp);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --(*this);
    return (temp);
}

int Fixed::getRawBits(void) const
{
    return (_value);
}

void Fixed::setRawBits(int const new_value)
{
    _value = new_value;
}

int Fixed::toInt(void) const
{
    return (_value >> _fractionalBits);
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(_value) / static_cast<float>(1 << _fractionalBits));
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}