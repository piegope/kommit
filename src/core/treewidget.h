/*
SPDX-FileCopyrightText: 2021 Hamed Masafi <hamed.masfi@gmail.com>

SPDX-License-Identifier: GPL-3.0-or-later
*/

#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QTreeWidget>

class TreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit TreeWidget(QWidget *parent = nullptr);


protected slots:
    void currentChanged(const QModelIndex &current, const QModelIndex &previous) override;

signals:
    void itemActivated(const QModelIndex &index);
};

#endif // TREEWIDGET_H
