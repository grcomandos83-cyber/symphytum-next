/*
 *  Copyright (c) 2011  Giorgio Wicklein <g.wicklein@giowisys.com>
 */

//-----------------------------------------------------------------------------
// Hearders
//-----------------------------------------------------------------------------

#include "updatemanager.h"
#include "../utils/definitionholder.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtCore/QStringList>
#include <QtCore/QUrlQuery>
#include <QtCore/QDateTime>
#include <QtCore/QDebug>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QApplication>
#include <QtGui/QDesktopServices>


//-----------------------------------------------------------------------------
// Public
//-----------------------------------------------------------------------------

UpdateManager::UpdateManager(QObject *parent) :
    QObject(parent)
{
    m_accessManager = new QNetworkAccessManager(this);

    connect(m_accessManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(updateResponseSlot(QNetworkReply*)));
}

UpdateManager::~UpdateManager()
{
}

void UpdateManager::checkForUpdates()
{
    QUrl url(DefinitionHolder::UPDATE_URL);
    // Add cache-busting query parameter so GitHub CDN doesn't serve a stale cached response
    QUrlQuery query;
    query.addQueryItem("t", QString::number(QDateTime::currentMSecsSinceEpoch()));
    url.setQuery(query);

    QNetworkRequest request(url);
    request.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
    request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, QNetworkRequest::NoLessSafeRedirectPolicy);
    request.setHeader(QNetworkRequest::UserAgentHeader, QString("%1/%2").arg(DefinitionHolder::NAME, DefinitionHolder::VERSION));

    m_accessManager->get(request);
}


//-----------------------------------------------------------------------------
// Private slots
//-----------------------------------------------------------------------------

void UpdateManager::updateResponseSlot(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << "Update check failed with error:" << reply->errorString();
        emit updateErrorSignal();
        reply->deleteLater();
        return;
    }

    QString tmp = QString::fromUtf8(reply->readAll()).trimmed();

    if (tmp.isEmpty()) {
        emit updateErrorSignal();
        reply->deleteLater();
        return;
    }

    QStringList s = tmp.split(";", Qt::SkipEmptyParts);

    if (s.isEmpty()) { //software_build;
        emit updateErrorSignal();
        reply->deleteLater();
        return;
    }

    bool a = false;
    int softwareBuild = s.at(0).trimmed().toInt(&a);

    if (!a) {
        emit updateErrorSignal();
        reply->deleteLater();
        return;
    }

    bool softwareUpdate = softwareBuild > DefinitionHolder::SOFTWARE_BUILD;

    if (softwareUpdate) {
        int r = QMessageBox::question(nullptr, tr("New Software Version"),
                                      tr("A new version of %1 is available!<br>"
                                         "Do you want to download the new version?")
                                      .arg(DefinitionHolder::NAME),
                                      QMessageBox::Yes | QMessageBox::No,
                                      QMessageBox::Yes);

        if (r == QMessageBox::Yes) {
            QUrl downloadUrl(DefinitionHolder::DOWNLOAD_URL);
            QDesktopServices::openUrl(downloadUrl);
            emit updatesAccepted();
        }

    } else {
        //no updates available
        emit noUpdateSignal();
    }

    //delete reply
    reply->deleteLater();
}


//-----------------------------------------------------------------------------
// Private
//-----------------------------------------------------------------------------
