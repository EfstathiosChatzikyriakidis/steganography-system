#include <QCoreApplication>

#include <QMessageBox>

#include "Terminate.h"

namespace Tools
{
    Terminate::Terminate ()
    {
    }

    Terminate::~Terminate ()
    {
    }

    void Terminate::UI (const QString & message)
    {
        QMessageBox::critical (0, QCoreApplication::applicationName (), message);

        exit (-1); // do not use QCoreApplication::exit(-1) here.
    }
}
