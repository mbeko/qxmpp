// SPDX-FileCopyrightText: 2022 Melvin Keskin <melvo@olomono.de>
//
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "QXmppMessageReaction.h"

#include "QXmppConstants_p.h"
#include "QXmppUtils.h"

#include <QSharedData>

class QXmppMessageReactionPrivate : public QSharedData
{
public:
    QString id;
    QVector<QString> reactions;
};

QXmppMessageReaction::QXmppMessageReaction()
    : d(new QXmppMessageReactionPrivate)
{
}

QString QXmppMessageReaction::id() const
{
    return d->id;
}

void QXmppMessageReaction::setId(const QString &id)
{
    d->id = id;
}

QXMPP_PRIVATE_DEFINE_RULE_OF_SIX(QXmppMessageReaction)

QVector<QString> QXmppMessageReaction::reactions() const
{
    return d->reactions;
}

void QXmppMessageReaction::setReactions(const QVector<QString> &reactions)
{
    d->reactions = reactions;
}

/// \cond
void QXmppMessageReaction::parse(const QDomElement &element)
{
    d->id = element.attribute(QStringLiteral("id"));

    for (auto childElement = element.firstChildElement();
        !childElement.isNull();
        childElement = childElement.nextSiblingElement()) {
        d->reactions.append(childElement.text());
    }
}

void QXmppMessageReaction::toXml(QXmlStreamWriter *writer) const
{
    writer->writeStartElement(QStringLiteral("reactions"));
    writer->writeDefaultNamespace(ns_reactions);
    writer->writeAttribute(QStringLiteral("id"), d->id);
    for (const auto &reaction : d->reactions) {
        helperToXmlAddTextElement(writer, QStringLiteral("reaction"), reaction);
    }
    writer->writeEndElement();
}
/// \endcond

///
/// Determines whether the given DOM element is an OMEMO element.
///
/// \param element DOM element being checked
///
/// \return true if element is an OMEMO element, otherwise false
///
bool QXmppMessageReaction::isMessageReaction(const QDomElement &element)
{
    return element.tagName() == QStringLiteral("reactions") &&
        element.namespaceURI() == ns_reactions;
}
