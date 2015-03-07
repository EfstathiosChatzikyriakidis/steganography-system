#ifndef _I18N_H
#define _I18N_H

#include <QTranslator>

class I18N
{
    public:
        I18N ();

        ~I18N ();

        I18N (const QString & path, const QString & encoding);

        void setPath (const QString & path);
        void setEncoding (const QString & encoding);

        QString getPath ();
        QString getEncoding ();

        void Translate ();

    private:
        QString _path, _encoding;

        QTranslator _apTranslator, _qtTranslator;
};

#endif // _I18N_H
