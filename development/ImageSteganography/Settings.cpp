#include "Terminate.h"
#include "Settings.h"

Settings::Settings ()
{
}

Settings::~Settings ()
{
}

QMap<QString, QMap<QString, QVariant>> Settings::_dictionary;

void Settings::splashScreen (QSettings & settings)
{
    QString group; QString key; QVariant value;

    group = "SplashScreen";

    settings.beginGroup (group);

    key = "Delay";

    value = QVariant::fromValue (3);

    if (!settings.value (key).isNull ())
    {
        int temp = settings.value (key).toInt ();

        if (temp <= 10 && temp >= 0)
        {
            value = QVariant::fromValue (temp);
        }
    }

    _dictionary[group][key] = value;

    settings.setValue (key, value);

    settings.endGroup ();
}

void Settings::establish ()
{
    static QSettings settings;

    _dictionary.clear ();

    splashScreen (settings);

    settings.sync ();

    if (settings.status () != QSettings::NoError)
    {
        Tools::Terminate::UI (tr ("Settings cannot be established!"));
    }
}

QVariant Settings::getSetting (const QString & group, const QString & property)
{
    if (!_dictionary.contains (group) || !_dictionary[group].contains (property))
    {
        Tools::Terminate::UI (tr ("Property '%1' from Group '%2' cannot be retrieved!").arg (property, group));
    }

    return _dictionary[group][property];
}
