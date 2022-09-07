/*
SPDX-FileCopyrightText: 2021 Hamed Masafi <hamed.masfi@gmail.com>

SPDX-License-Identifier: GPL-3.0-or-later
*/

#include "commandpush.h"

namespace Git {

CommandPush::CommandPush() : AbstractCommand() {}

const QString &CommandPush::remote() const
{
    return _remote;
}

void CommandPush::setRemote(const QString &newRemote)
{
    _remote = newRemote;
}

const QString &CommandPush::localBranch() const
{
    return _localBranch;
}

void CommandPush::setLocalBranch(const QString &newBranch)
{
    _localBranch = newBranch;
}

const QString &CommandPush::remoteBranch() const
{
    return _remoteBranch;
}

void CommandPush::setRemoteBranch(const QString &newRemoteBranch)
{
    _remoteBranch = newRemoteBranch;
}

bool CommandPush::force() const
{
    return _force;
}

void CommandPush::setForce(bool newForce)
{
    _force = newForce;
}

QStringList CommandPush::generateArgs() const
{
    QStringList args{QStringLiteral("push"), _remote};

    if (_remoteBranch.isEmpty())
        args.append(_localBranch);
    else
        args.append(_localBranch + ":" + _remoteBranch);

    if (_force)
        args.append(QStringLiteral("--force"));

    return args;
}

} // namespace Git
