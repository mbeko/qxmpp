// SPDX-FileCopyrightText: 2022 Melvin Keskin <melvo@olomono.de>
//
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef QXMPPMESSAGEREACTION_H
#define QXMPPMESSAGEREACTION_H

#include "QXmppGlobal.h"

#include <QDomElement>
#include <QSharedDataPointer>
#include <QXmlStreamWriter>

class QXmppMessageReactionPrivate;

class QXMPP_EXPORT QXmppMessageReaction
{
public:
    QXmppMessageReaction();
    QXMPP_PRIVATE_DECLARE_RULE_OF_SIX(QXmppMessageReaction)

    QString id() const;
    void setId(const QString &id);

    QVector<QString> reactions() const;
    void setReactions(const QVector<QString> &reactions);

    /// \cond
    void parse(const QDomElement &element);
    void toXml(QXmlStreamWriter *writer) const;
    /// \endcond

    static bool isMessageReaction(const QDomElement &element);

private:
    QSharedDataPointer<QXmppMessageReactionPrivate> d;
};

#endif  // QXMPPMESSAGEREACTION_H
