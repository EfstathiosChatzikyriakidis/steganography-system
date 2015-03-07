#include "Sleep.h"

namespace Tools
{
    Sleep::Sleep ()
    {
    }

    Sleep::~Sleep()
    {
    }

    void Sleep::seconds (const unsigned long seconds)
    {
        QThread::sleep (seconds);
    }
}
