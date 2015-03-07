#include <QColor>

#include "AlgorithmLSBAction.h"

AlgorithmLSBAction::AlgorithmLSBAction ()
{
}

AlgorithmLSBAction::~AlgorithmLSBAction ()
{
}

bool AlgorithmLSBAction::encrypt (QImage & image, QString & message, QSharedPointer<AlgorithmConfiguration> configuration)
{
    QImage temporaryImage = image;

    std::wstring temporaryMessage = message.toStdWString ();

    int length = temporaryMessage.length ();

    int x = 0, y = 0;

    for (unsigned int mask = 1; mask; mask <<= 1)
    {
        QPoint point (x, y);

        if (temporaryImage.valid (point))
        {
            QColor color (temporaryImage.pixel (point));

            int red = (length & mask) ? color.red () | 1 : color.red () & ~1;

            color.setRed (red);

            temporaryImage.setPixel (point, color.rgb ());

            if (++x >= temporaryImage.width ())
            {
                ++y; x = 0;
            }
        }
        else
        {
            return false;
        }
    }

    for (int c = 0; c < length; c++)
    {
        wchar_t character = temporaryMessage[c];

        for (wchar_t mask = 1; mask; mask <<= 1)
        {
            QPoint point (x, y);

            if (temporaryImage.valid (point))
            {
                QColor color (temporaryImage.pixel (point));

                int blue = (character & mask) ? color.blue () | 1 : color.blue () & ~1;

                color.setBlue (blue);

                temporaryImage.setPixel (point, color.rgb ());

                if (++x >= temporaryImage.width ())
                {
                    ++y; x = 0;
                }
            }
            else
            {
                return false;
            }
        }
    }

    image = temporaryImage;

    return true;
}

bool AlgorithmLSBAction::decrypt (QImage & image, QString & message, QSharedPointer<AlgorithmConfiguration> configuration)
{
    QString temporary;

    int length = 0;

    int x = 0, y = 0;

    for (unsigned int mask = 1; mask; mask <<= 1)
    {
        QPoint point (x, y);

        if (image.valid (point))
        {
            QColor color (image.pixel (point));

            if (color.red () & 1)
            {
                length |= mask;
            }

            if (++x >= image.width ())
            {
                ++y; x = 0;
            }
        }
        else
        {
            return false;
        }
    }

    for (int c = 0; c < length; c++)
    {
        wchar_t character = 0;

        for (wchar_t mask = 1; mask; mask <<= 1)
        {
            QPoint point (x, y);

            if (image.valid (point))
            {
                QColor color (image.pixel (point));

                if (color.blue () & 1)
                {
                    character |= mask;
                }

                if (++x >= image.width ())
                {
                    ++y; x = 0;
                }
            }
            else
            {
                return false;
            }
        }

        temporary.append (character);
    }

    message = temporary;

    return true;
}
