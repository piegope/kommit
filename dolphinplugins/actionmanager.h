/*
SPDX-FileCopyrightText: 2021 Hamed Masafi <hamed.masfi@gmail.com>

SPDX-License-Identifier: GPL-3.0-or-later
*/

#pragma once

#include "statuscache.h"
#include <KIOCore/kfileitem.h>
#include <KIOWidgets/KAbstractFileItemActionPlugin>

class ActionManager : public KAbstractFileItemActionPlugin
{
    Q_OBJECT
public:
    explicit ActionManager(QObject *parent, const QList<QVariant> &);

    void addMenu(QMenu *menu, const QString &title, const QStringList &args, const QString &icon = QString());
    QList<QAction *> actions(const KFileItemListProperties &fileItemInfos, QWidget *parentWidget) override;

private:
    void initActions();

    QString getCommonPart(const KFileItemList &fileItems);

    void addMenuToNonGitFile(QMenu *menu, const QString &path);
    void addMenuToGitFile(QMenu *menu, const QString &path, bool isFile, const FileStatus::Status &status);

private:
    StatusCache _cache;

    QAction *mPullAction = nullptr;
    QAction *mPushAction = nullptr;
    QAction *mDiffAction = nullptr;
    QAction *mLogAction = nullptr;
    QAction *mOpenAppAction = nullptr;
};
