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
#ifndef SC_STRING_UTILS_H
#define SC_STRING_UTILS_H

#include <cstring>
#include <ctype.h>

namespace SC {

/**
 * @brief The StringUtils class define utilitary methods to handle strings.
 */
class StringUtils {

    public:

        /**
         * @brief StringUtils
         */
        StringUtils();

        /**
         * @brief _strcpy
         * @param __dest
         * @param __src
         */
        inline static void _strcpy(const char * &__dest, const char * &__src) {

            char *_aux = new char[strlen(__src)+1];
            strcpy(_aux, __src);
            _trim(_aux);
            __dest = _aux;

        }

        /**
         * @brief _trim
         * @param _value
         */
        inline static void _trim(char _value[]) {
            const unsigned int len = strlen(_value);

            unsigned int skip, scrape;
            for (skip = 0; skip < len; skip++) if (! isspace(_value[skip])) break;
            for (scrape = len; scrape > skip; scrape--) if (! isspace(_value[scrape - 1] )) break;

            // Cap off at the scrap point
            if (scrape != len) _value[scrape] = 0;

            if (skip) {
                // Copy the chars down
                unsigned int index = 0;
                while (_value[skip]) _value[index++] = _value[skip++];
                _value[index] = 0;
            }

        }

};

}

#endif // SC_STRING_UTILS_H
