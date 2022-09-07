/*
SPDX-FileCopyrightText: 2021 Hamed Masafi <hamed.masfi@gmail.com>

SPDX-License-Identifier: GPL-3.0-or-later
*/

#ifndef FILESTATUS_H
#define FILESTATUS_H

#include <QString>
#include <QObject>

class FileStatus
{
public:
    enum Status {
        Unknown = 0,
        Unmodified = 1,
        Modified = 2,
        Added = 3,
        Removed = 4,
        Renamed = 5,
        Copied = 6,
        UpdatedButInmerged = 7,
        Ignored = 8,
        Untracked = 9,
        NoGit = 10
    };

    FileStatus();
    FileStatus(QString name, Status status);

    const QString &name() const;
    Status status() const;

    void parseStatusLine(const QString &line);
    const QString &fullPath() const;

    void setFullPath(const QString &newFullPath);

    void setStatus(const QString &x, const QString &y = QString());
    void setName(const QString &newName);

private:
    QString _fullPath;
    QString _name;
    QString _newName;
    Status _status;

    friend class Manager;
};
Q_DECLARE_METATYPE(FileStatus)
Q_DECLARE_TYPEINFO(FileStatus, Q_MOVABLE_TYPE);
bool operator==(const FileStatus &f1, const FileStatus &f2);

#endif // FILESTATUS_H
