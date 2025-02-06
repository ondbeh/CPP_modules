/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:51:49 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/06 10:51:49 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _value;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &other);

    ~Fixed();

    Fixed &operator=(const Fixed &other);

    int getRawBits(void) const;
    void setRawBits(const int raw);

    int toInt(void) const;
    float toFloat(void) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif