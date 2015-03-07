#include <QCoreApplication>
#include <QLibraryInfo>
#include <QTextCodec>
#include <QLocale>

#include "I18N.h"

I18N::~I18N ()
{
}

I18N::I18N ()
{
}

I18N::I18N (const QString & path, const QString & encoding)
{
    _path = path;
    _encoding = encoding;
}

void I18N::setEncoding (const QString & encoding)
{
    _encoding = encoding;
}

void I18N::setPath (const QString & path)
{
    _path = path;
}

QString I18N::getEncoding ()
{
    return _encoding;
}

QString I18N::getPath ()
{
    return _path;
}

void I18N::Translate ()
{
    QTextCodec::setCodecForCStrings (QTextCodec::codecForName (_encoding.toAscii ()));
    QTextCodec::setCodecForTr (QTextCodec::codecForName (_encoding.toAscii ()));

    _apTranslator.load (
        QCoreApplication::applicationName () + "_" + QLocale::system ().name (),
        QCoreApplication::applicationDirPath () + "/" + _path
    );

    _qtTranslator.load (
        "qt_" + QLocale::system ().name (),
        QLibraryInfo::location (QLibraryInfo::TranslationsPath)
    );

    QCoreApplication::installTranslator (&_apTranslator);
    QCoreApplication::installTranslator (&_qtTranslator);
}
