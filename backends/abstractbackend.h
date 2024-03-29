/*************************************************************************************
 *  Copyright (C) 2012 by Alejandro Fiestas Olivares <afiestas@kde.org>              *
 *                                                                                   *
 *  This library is free software; you can redistribute it and/or                    *
 *  modify it under the terms of the GNU Lesser General Public                       *
 *  License as published by the Free Software Foundation; either                     *
 *  version 2.1 of the License, or (at your option) any later version.               *
 *                                                                                   *
 *  This library is distributed in the hope that it will be useful,                  *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of                   *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU                *
 *  Lesser General Public License for more details.                                  *
 *                                                                                   *
 *  You should have received a copy of the GNU Lesser General Public                 *
 *  License along with this library; if not, write to the Free Software              *
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA       *
 *************************************************************************************/

#ifndef ABSTRACT_BACKEND_H
#define ABSTRACT_BACKEND_H

#include <QtCore/QString>
#include <QtCore/QObject>

namespace KScreen {
    class Config;
    class Edid;
}

class AbstractBackend
{
    public:
        virtual ~AbstractBackend() {}
        virtual QString name() const = 0;
        virtual KScreen::Config* config() const = 0;
        virtual void setConfig(KScreen::Config* config) const = 0;
        virtual bool isValid() const = 0;
        virtual KScreen::Edid* edid(int outputId) const = 0;
        virtual void updateConfig(KScreen::Config* config) const = 0;
};

Q_DECLARE_INTERFACE(AbstractBackend, "org.kde.libkscreen")
#endif //ABSTRACT_BACKEND_H
