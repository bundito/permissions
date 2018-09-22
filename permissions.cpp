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

#include <QString>
#include <QStringList>
#include "permissions.h"

Permissions::Permissions(QString p) :
    m_valid(true),
    m_username(QString()),
    m_group(QString()),
    m_value(0)
{
    parsePermissions(p);
}

void Permissions::parsePermissions(QString const &p) {

    QStringList segments = p.split(":");

    if (segments.length() != 3) {
        m_valid = false;
        return;
    }

    if (segments[0].isEmpty() || segments[1].isEmpty()) {
        m_valid = false;
        return;
    }

    bool ok;
    int octal = segments[2].toInt(&ok, 8);
    if (!ok || octal == 0) {
        m_valid = false;
        return;
    } else {
        m_value = segments[2].toInt(&ok, 10);
    }

    // We have exactly three segments and the third is valid octal,
    // so we can declare the string valid and set the user and group names
    m_valid = true;
    m_username = segments[0];
    m_group = segments[1];

    return;

}

bool Permissions::isValid() {
    return m_valid;
}

QString Permissions::username() {
    return m_username;
}

QString Permissions::group() {
    return m_group;
}

int Permissions::value() {
    return m_value;
}



