#include <QSplashScreen>
#include <QApplication>
#include <QPixmap>

#include "GlobalDeclarations.h"

#include "MainWindow.h"
#include "StyleSheet.h"
#include "Settings.h"
#include "Sleep.h"
#include "I18N.h"

int main (int argc, char * argv[])
{
    QApplication application (argc, argv);

    application.setApplicationName (APPLICATION_NAME);
    application.setApplicationVersion (APPLICATION_VERSION);
    application.setOrganizationName (ORGANIZATION_NAME);

    I18N i18n (TRANSLATIONS_PATH, APPLICATION_ENCODING);

    i18n.Translate ();

    Settings::establish ();

    QPixmap pixmap (SPLASH_SCREEN_GRAPHIC);

    QSplashScreen splash (pixmap);

    splash.show ();

    MainWindow window;

    StyleSheet styleSheet (STYLE_SHEETS_PATH);

    window.setStyleSheet (styleSheet.retrieve ("MainWindow.qss"));

    Tools::Sleep::seconds (Settings::getSetting ("SplashScreen", "Delay").toInt ());

    window.show ();

    splash.finish (&window);

    return application.exec ();
}
