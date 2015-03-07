#ifndef _SETTINGS_H
#define _SETTINGS_H

#include <QSettings>

class Settings : public QObject
{
    Q_OBJECT

    private:
        Settings ();

        ~Settings ();

        static QMap<QString, QMap<QString, QVariant>> _dictionary;

        static void splashScreen (QSettings & settings);

    public:
        static void establish ();

        static QVariant getSetting (const QString & group, const QString & property);
};

#endif // _SETTINGS_H
