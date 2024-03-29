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

#ifndef KSCREEN_CONFIG_H
#define KSCREEN_CONFIG_H

#include "screen.h"
#include "output.h"
#include "kscreen_export.h"

#include <QtCore/QHash>
#include <QtCore/QObject>
#include <QtCore/QMetaType>

namespace KScreen {

class KSCREEN_EXPORT Config : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Screen* screen READ screen)
    Q_PROPERTY(OutputList outputs READ outputs)

  public:
    static bool loadBackend();
    static Config* current();
    static bool setConfig(Config* config);
    static bool canBeApplied(Config* config);

    explicit Config(QObject *parent = 0);
    virtual ~Config();

    Config* clone() const;

    Screen* screen() const;
    void setScreen(Screen* screen);

    Output* output(int outputId) const;
    QHash<int, Output*> outputs() const;
    QHash<int, Output*> connectedOutputs() const;
    Output* primaryOutput() const;
    void setOutputs(OutputList outputs);

    bool isValid() const;
    void setValid(bool valid);

  private:
    Q_DISABLE_COPY(Config)

    class Private;
    Private * const d;

    Config(Private *dd);
};

} //KScreen namespace

#endif //KSCREEN_CONFIG_H
