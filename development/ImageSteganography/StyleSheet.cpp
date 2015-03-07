#include <QCoreApplication>
#include <QTextStream>
#include <QFile>

#include "StyleSheet.h"

StyleSheet::StyleSheet ()
{
}

StyleSheet::~StyleSheet ()
{
}

StyleSheet::StyleSheet (const QString & path)
{
    _path = path;
}

void StyleSheet::setPath (const QString & path)
{
    _path = path;
}

QString StyleSheet::getPath ()
{
    return _path;
}

QString StyleSheet::retrieve(const QString & file)
{
    QFile styleSheet (QCoreApplication::applicationDirPath () + "/" + _path + "/" + file);

    QString contents;

    if (styleSheet.open (QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream t (&styleSheet);

        while (!t.atEnd ())
        {
            contents += t.readLine();
        }

        styleSheet.close ();
    }

    return contents;
}
