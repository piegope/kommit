/*
SPDX-FileCopyrightText: 2021 Hamed Masafi <hamed.masfi@gmail.com>

SPDX-License-Identifier: GPL-3.0-or-later
*/

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Git {
class Manager;
}

class AppDialog : public QDialog
{
    Q_OBJECT

protected:
    Git::Manager *_git;

public:
    explicit AppDialog(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    explicit AppDialog(Git::Manager *git, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

    bool event(QEvent *event) override;
};

#endif // DIALOG_H
