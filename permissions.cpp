/*
 *  Copyright (C) 2018 Scott Harvey <scott@spharvey.me>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301, USA.
 */

#include <QString>
#include <QStringList>
#include <QDebug>
#include "permissions.h"

Permissions::Permissions(QString p) :
    m_valid(true),
    m_username(QString()),
    m_group(QString()),
    m_value(0)
{
    qDebug() << p;
    parsePermissions(p);
}

void Permissions::parsePermissions(QString const &p) {

    QStringList segments = p.split(":");

    if (segments.length() != 3) {
        m_valid = false;
        return;
    }

    bool ok;
    int octal = segments[2].toInt(&ok, 8);
    if (!ok) {
        m_valid = false;
    } else {
        m_value = octal;
    }

    // We have exactly three segments and the third one is valid octal,
    // so we can declare the string valid and set the user and group names
    m_username = segments[0];
    m_group = segments[1];

    return;

}

bool Permissions::isValid() {
        return m_valid;
        }

QString Permissions::username() {
    if (m_valid) {
        return m_username;
    } else {
        invalidAccess();
    }
}

QString Permissions::group() {
    if (m_valid) {
        return m_group;
    } else {
        invalidAccess();
    }
}

int Permissions::value() {
    if (m_valid) {
        return m_value;
    } else {
        invalidAccess();
    }
}

void Permissions::invalidAccess() {
    printf("Error: Not a valid permission string");
    exit(1);
}

