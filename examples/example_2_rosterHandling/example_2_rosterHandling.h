// SPDX-FileCopyrightText: 2012 Manjeet Dahiya <manjeetdahiya@gmail.com>
//
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef XMPPCLIENT_H
#define XMPPCLIENT_H

#include "QXmppClient.h"

class QXmppRosterManager;

class xmppClient : public QXmppClient
{
    Q_OBJECT

public:
    xmppClient(QObject *parent = nullptr);
    ~xmppClient() override;

public slots:
    void clientConnected();
    void rosterReceived();
    void presenceChanged(const QString &bareJid, const QString &resource);

private:
    QXmppRosterManager *m_rosterManager;
};

#endif  // XMPPCLIENT_H
