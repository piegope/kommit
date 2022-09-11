/*
SPDX-FileCopyrightText: 2021 Hamed Masafi <hamed.masfi@gmail.com>

SPDX-License-Identifier: GPL-3.0-or-later
*/

#pragma once

#include "../core/appdialog.h"
#include "ui_mergeopenfilesdialog.h"

class MergeOpenFilesDialog : public AppDialog, private Ui::MergeOpenFilesDialog
{
    Q_OBJECT

public:
    explicit MergeOpenFilesDialog(QWidget *parent = nullptr);

    QString filePathLocal() const;
    void setFilePathLocal(const QString &newFilePathLocal);

    QString filePathRemote() const;
    void setFilePathRemote(const QString &newFilePathRemote);

    QString filePathBase() const;
    void setFilePathBase(const QString &newFilePathBase);

private Q_SLOTS:
    void on_toolButtonSelectLocalFile_clicked();
    void on_toolButtonSelectRemoteFile_clicked();
    void on_toolButtonSelectBaseFile_clicked();
};
