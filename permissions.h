/*
 *  Copyright (C) 2018 Scott Harvey <scott@spharvey.me>
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 *  of the Software, and to permit persons to whom the Software is furnished to do
 *  so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 *  FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef PERMISSIONS_H
#define PERMISSIONS_H

#include <QString>

/**
 * @brief The Permissions class takes a QString @p in the form of <user>:<group>:<permissions>, checks
 * it for validity, and makes the three components available indivdually.
 */

class Permissions
{

public:

/** Constructor
 * Splits the string @p at the colon (":") into separate elements for <user>, <group>, and <value> (permissions), where
 * <value> is returned as an **octal** number.
 */
    Permissions(QString p);

    QString m_username;
    QString m_group;
    bool m_valid;
    int m_value;

    void parsePermissions(QString const &p);
    bool isValid();
    QString username();
    QString group();
    int value();

/** invalidAccess() aborts the program if an attempt is made to access a parameter when the permissions string
 * is not valid
*/
    void invalidAccess();

};

#endif // PERMISSIONS_H
