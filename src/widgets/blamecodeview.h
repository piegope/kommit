/*
SPDX-FileCopyrightText: 2020-2022 Hamed Masafi <hamed.masfi@gmail.com>

SPDX-License-Identifier: GPL-3.0-or-later
*/

#pragma once

#include "blamedata.h"
#include "codeeditor.h"

#include <QMap>

class BlameCodeView : public CodeEditor
{
    Q_OBJECT

public:
    explicit BlameCodeView(QWidget *parent = nullptr);
    const Git::BlameData &blameData() const;
    void setBlameData(const Git::BlameData &newBlameData);

    Git::BlameDataRow blameData(const int &blockNumber) const;
    // CodeEditor interface
private:
    int sidebarWidth() const override;
    void sidebarPaintEvent(QPaintEvent *event) override;
    Git::BlameData mBlameData;
    QMap<int, Git::BlameDataRow> mBlames;
};
