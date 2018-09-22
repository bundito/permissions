/*
 *  Copyright (C) 2018 Scott Harvey <scott@spharvey.me>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include "permissions.h"



int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    QString testString = argv[1];

    if (testString.isEmpty()) {
        qDebug() << "Usage: permissions <user>:<group>:<permissions>";
        exit(0);
    }

    Permissions test = testString;
    qDebug() << "Valid? " << test.isValid();
    qDebug() << "User: " << test.username();
    qDebug() << "Group: " << test.group();
    qDebug() << "Value: " << test.value();



 }

