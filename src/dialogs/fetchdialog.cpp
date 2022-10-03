/*
SPDX-FileCopyrightText: 2021 Hamed Masafi <hamed.masfi@gmail.com>

SPDX-License-Identifier: GPL-3.0-or-later
*/

#include "fetchdialog.h"

#include "commands/commandfetch.h"
#include "gitmanager.h"
#include "runnerdialog.h"

FetchDialog::FetchDialog(Git::Manager *git, QWidget *parent)
    : AppDialog(parent)
{
    setupUi(this);

    auto g = git;
    if (!g)
        g = Git::Manager::instance();
    comboBoxRemote->addItems(g->remotes());
    comboBoxBranch->addItems(g->branches());

    comboBoxRemote->setCurrentText(g->currentBranch());
}

void FetchDialog::setBranch(const QString &branch)
{
    comboBoxBranch->setCurrentText(branch);
}

void FetchDialog::on_buttonBox_accepted()
{
    Git::CommandFetch cmd;

    cmd.setRemote(comboBoxRemote->currentText());

    if (!checkBoxAllBranches->isChecked())
        cmd.setBranch(comboBoxBranch->currentText());
    cmd.setNoFf(checkBoxNoFastForward->isChecked());
    cmd.setFfOnly(checkBoxFastForwardOnly->isChecked());
    cmd.setNoCommit(checkBoxNoCommit->isChecked());
    cmd.setPrune(checkBoxPrune->isChecked());
    cmd.setTags(checkBoxTags->isChecked());

    RunnerDialog d(this);
    d.run(&cmd);
    d.exec();

    accept();
}
