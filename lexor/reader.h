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
#ifndef READER_H
#define READER_H

/**
 * @brief The Reader class define all reader that a llexical machine support.
 */
class Reader {

    public:
        static const int _EOF_; // End Of File.
        static const char _TAB_; // Tab character.
        static const char _NL_; // New Line character.

        /**
         * @brief Reader
         */
        Reader();

        /**
         * @brief next
         * @return
         */
        virtual int next() { return Reader::_EOF_; }

        /**
         * @brief prior
         */
        virtual void prior() {}

        /**
         * @brief current
         * @return
         */
        virtual int current() = 0;

        /**
         * @brief row
         * @return
         */
        virtual long row() { return Reader::_EOF_; }

        /**
         * @brief col
         * @return
         */
        virtual long col() { return Reader::_EOF_; }

        /**
         * @brief close
         */
        virtual void close() = 0;
};

#endif // READER_H
