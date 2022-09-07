/*
SPDX-FileCopyrightText: 2021 Hamed Masafi <hamed.masfi@gmail.com>

SPDX-License-Identifier: GPL-3.0-or-later
*/

#include "submodulesmodel.h"
#include <KLocalizedString>
#include "../gitsubmodule.h"
#include "../gitmanager.h"

namespace Git {

SubmodulesModel::SubmodulesModel(Git::Manager *git, QObject *parent)
    : AbstractGitItemsModel{git, parent}
{

}

int SubmodulesModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return _data.size();
}

int SubmodulesModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 2;
}

QVariant SubmodulesModel::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole || !index.isValid() || index.row() < 0
        || index.row() >= _data.size())
        return QVariant();

    auto submodule = _data.at(index.row());

    switch (index.column()) {
    case 0:
        return submodule->path();
    case 1:
        return submodule->refName();
    }
    return QVariant();
}

QVariant SubmodulesModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
        return QVariant();

    switch (section) {
    case 0:
        return i18n("Path");
    case 1:
        return i18n("Head");
    case 2:
        return i18n("Status");
    }

    return QVariant();
}

bool SubmodulesModel::append(Submodule *module)
{
    beginInsertRows(QModelIndex(), _data.size(), _data.size());
    _data.append(module);
    endInsertRows();
    return true;
}

Submodule *SubmodulesModel::fromIndex(const QModelIndex &index)
{
    if (!index.isValid() || index.row() < 0 || index.row() >= _data.size())
        return nullptr;

    return _data.at(index.row());
}

void SubmodulesModel::fill()
{
    qDeleteAll(_data);
    _data.clear();
    const auto modulesList = _git->readAllNonEmptyOutput({"submodule", "status"});
    for (const auto &line : modulesList) {
        auto m = new Submodule;
        m->setCommitHash(line.mid(0, 40));
        auto n = line.lastIndexOf(" ");
        if (line.count(" ") == 1)
            n = line.size() ;
        m->setPath(line.mid(41, n - 41));

        if (line.count(' ') == 2)
            m->setRefName(line.mid(n));
        _data.append(m);
    }
}

} // namespace Git
