/*
SPDX-FileCopyrightText: 2021 Hamed Masafi <hamed.masfi@gmail.com>

SPDX-License-Identifier: GPL-3.0-or-later
*/

#ifndef COMPLETIONTEXTEDIT_H
#define COMPLETIONTEXTEDIT_H

#include <QTextEdit>

class QCompleter;
class QStringListModel;
class CompletionTextEdit : public QTextEdit
{
    Q_OBJECT

public:
    CompletionTextEdit(QWidget *parent = nullptr);

    void setCompleter(QCompleter *c);
    QCompleter *completer() const;

    void addWord(const QString &word);
    void addWords(const QStringList &words);

    const QStringList &words() const;
    void setWords(const QStringList &newWords);

    void begin();

protected:
    void keyPressEvent(QKeyEvent *e) override;
    void focusInEvent(QFocusEvent *e) override;

private Q_SLOTS:
    void insertCompletion(const QString &completion);

private:
    QString textUnderCursor() const;

private:
    QStringList _words;
    QStringListModel *const _completionModel;
    QCompleter *const c;
};

#endif // COMPLETIONTEXTEDIT_H
