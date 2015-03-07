#ifndef _STYLE_SHEET_H
#define _STYLE_SHEET_H

#include <QString>

class StyleSheet
{
    public:
        StyleSheet ();

        ~StyleSheet ();

        StyleSheet (const QString & path);

        void setPath (const QString & path);

        QString getPath ();

        QString retrieve (const QString & file);

    private:
        QString _path;
};

#endif // _STYLE_SHEET_H
