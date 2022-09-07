/*
SPDX-FileCopyrightText: 2021 Hamed Masafi <hamed.masfi@gmail.com>

SPDX-License-Identifier: GPL-3.0-or-later
*/

#include "mergecloseeventdialog.h"

MergeCloseEventDialog::MergeCloseEventDialog(QWidget *parent) :
      AppDialog(parent)
{
    setupUi(this);
}

void MergeCloseEventDialog::on_commandLinkButtonMarkResolved_clicked()
{
    accept();
}


void MergeCloseEventDialog::on_commandLinkButtonLeaveAsIs_clicked()
{
    reject();
}


void MergeCloseEventDialog::on_commandLinkButtonDontExit_clicked()
{
    done(DontExit);
}

