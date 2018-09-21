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

#ifndef PERMISSIONS_H
#define PERMISSIONS_H

#include <QObject>

/**
 * @brief The Permissions class takes a QString @p in the form of <user>:<group>:<permissions>, checks
 * it for validity, and makes the three components available indivdually.
 */

class Permissions : public QObject
{
    Q_OBJECT

public:

/** Constructor
 * Splits the string @p at the colon (":") into separate elements for <user>, <group>, and <value> (permissions), where
 * <value> is returned as an **octal** number.
 */
    Permissions();
    Permissions(QString p);


    bool m_valid;
    QString m_username;
    QString m_group;
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
