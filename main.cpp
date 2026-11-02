/*
 *  Copyright (c) 2012 Giorgio Wicklein <giowckln@gmail.com>
 */

//-----------------------------------------------------------------------------
// Hearders
//-----------------------------------------------------------------------------

#include "widgets/mainwindow.h"
#include "utils/definitionholder.h"
#include "utils/qtsingleapplication/qtsingleapplication.h"
#include "components/settingsmanager.h"

#include <QtCore/QTranslator>
#include <QtCore/QLocale>
#include <QtWidgets/QStyleFactory>
#include <QFile>
#include <QSettings>


//-----------------------------------------------------------------------------
// Main
//-----------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    //enable high DPI scaling on Windows and Linux
    //NOTE: don't move, must be called before QApplication initialization
    //or it won't work at all
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QtSingleApplication symphytumApp(argc, argv);
    symphytumApp.setApplicationName(DefinitionHolder::NAME);
    symphytumApp.setApplicationVersion(DefinitionHolder::VERSION);
    symphytumApp.setOrganizationName(DefinitionHolder::COMPANY);
    symphytumApp.setOrganizationDomain(DefinitionHolder::DOMAIN_NAME);
    symphytumApp.setWindowIcon(QIcon(":/images/icons/symphytum.png"));

    //only one instance allowed
    if (symphytumApp.sendMessage("Wake up!"))
        return 0;

    //setup translations
    SettingsManager settingsManager;
    QString lang = settingsManager.restoreProperty("language", "preferences").toString();
    if (lang.isEmpty() || lang == "system") {
        lang = QLocale::system().name();
    }

    QTranslator qtTranslator;
    QTranslator myappTranslator;

    if (!lang.startsWith("en", Qt::CaseInsensitive)) {
        QString langCode = lang;
        if (langCode.startsWith("el", Qt::CaseInsensitive)) {
            langCode = "el";
        }
        qtTranslator.load("qt_" + langCode, ":/languages");
        symphytumApp.installTranslator(&qtTranslator);
        myappTranslator.load("symphytum_" + langCode, ":/languages");
        symphytumApp.installTranslator(&myappTranslator);
    }

    // Determine theme (light/dark) from settings
    bool dark = settingsManager.restoreProperty("theme", "preferences").toString() == "dark";
    // Set Fusion style for consistent appearance
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    // Apply theme
    MainWindow::applyTheme(dark);

    //init gui
    MainWindow w;
    w.show();

    //wake up window
    symphytumApp.setActivationWindow(&w);

    return symphytumApp.exec();
}
