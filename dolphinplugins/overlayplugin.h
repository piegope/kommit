/*
SPDX-FileCopyrightText: 2021 Hamed Masafi <hamed.masfi@gmail.com>

SPDX-License-Identifier: GPL-3.0-or-later
*/

#ifndef KLIENTDOLPHINOVERLAYPLUGIN_H
#define KLIENTDOLPHINOVERLAYPLUGIN_H

#include "../src/git/filestatus.h"
#include "statuscache.h"
#include <KOverlayIconPlugin>
#include <QCache>

class OverlayPlugin : public KOverlayIconPlugin
{
    Q_PLUGIN_METADATA(IID "org.kfe.gitklient.ovarlayiconplugin" FILE "gitklientoverlayplugin.json")
    Q_OBJECT

    StatusCache _cache;

public:

    explicit OverlayPlugin(QObject *parent = nullptr);

    QStringList getOverlays(const QUrl &url) override;

};

#endif // KLIENTDOLPHINOVERLAYPLUGIN_H
