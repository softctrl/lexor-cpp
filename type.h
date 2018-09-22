/*
 *
 * Author:
 *  Carlos Timoshenko
 *  carlostimoshenkorodrigueslopes@gmail.com
 *
 *  https://github.com/softctrl
 *
 * This project is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 */
#ifndef TYPE_H
#define TYPE_H

/**
 * @brief The Type class define all types that a lexeme can be.
 */
class Type {

    public:
        static const Type* END_OF_FILE; // Represents a End -Of-File lexeme.
        static const Type* KEY_WORD; // Represents a Keyword lexeme.
        Type(char* value, bool isCode);

        /**
         * @brief value return a string representation of this type.
         * @return
         */
        char* value() const;

        /**
         * @brief isCode idenfity if that ir a type of code.
         * @return
         */
        bool isCode() const;

    private:
        char* _value;
        bool _is_code;

};

#endif // TYPE_H
