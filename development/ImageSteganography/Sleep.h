#ifndef _SLEEP_H
#define _SLEEP_H

#include <QThread>

namespace Tools
{
    class Sleep : public QThread
    {
        private:
            Sleep ();

            ~Sleep ();

        public:
            static void seconds (const unsigned long seconds);
    };
}

#endif // _SLEEP_H
