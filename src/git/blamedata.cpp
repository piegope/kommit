/*
SPDX-FileCopyrightText: 2021 Hamed Masafi <hamed.masfi@gmail.com>

SPDX-License-Identifier: GPL-3.0-or-later
*/

#include "blamedata.h"

namespace Git
{

BlameData::BlameData() = default;

void BlameData::initCommits(const LogList &logs)
{
    Q_UNUSED(logs)
    //    for (auto &l: *this) {
    //        l.log = logs.findByHash(l.commitHash);
    //        if (!l.log ) {
    //            qDebug() << "No log found";
    //        }
    //    }
}

}
