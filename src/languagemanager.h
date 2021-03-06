/*
 * Copyright © 2016-2017 Andrew Penkrat
 *
 * This file is part of Liri Text.
 *
 * Liri Text is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Liri Text is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Liri Text.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LANGUAGEMANAGER_H
#define LANGUAGEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QMimeType>
#include "languagedatabasemaintainer.h"

class QThread;
class LanguageManager : public QObject
{
    Q_OBJECT
public:
    static LanguageManager *getInstance();
    QString pathForId(const QString &id);
    QString pathForMimeType(const QMimeType &mimeType, const QString &filename);
private:
    explicit LanguageManager(QObject *parent = 0);
    ~LanguageManager();
    static LanguageManager *m_instance;
    QThread *m_thread;
    const QString m_connId;
};

#endif // LANGUAGEMANAGER_H
