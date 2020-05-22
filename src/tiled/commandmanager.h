/*
 * commandmanager.h
 * Copyright 2017, Ketan Gupta <ketan19972010@gmail.com>
 *
 * This file is part of Tiled.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "command.h"

#include <QObject>

class QAction;
class QMenu;

namespace Tiled {

class CommandDataModel;

class CommandManager : public QObject
{
    Q_OBJECT

    CommandManager();
    ~CommandManager() override;

public:
    static CommandManager *instance();

    const Command *firstEnabledCommand() const;

    QVector<Command> commands() const;

    void registerMenu(QMenu *menu);

    void retranslateUi();

public slots:
    void showDialog();

private:
    Q_DISABLE_COPY(CommandManager)

    void commit();

    void updateActions();

    CommandDataModel *mModel;
    QVector<Command> mCommands;
    QList<QMenu*> mMenus;
    QList<QAction*> mActions;
    QAction *mEditCommandsAction = nullptr;
};

} // namespace Tiled
