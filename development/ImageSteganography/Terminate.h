#ifndef _TERMINATE_H
#define _TERMINATE_H

#include <QString>

namespace Tools
{
    class Terminate
    {
        private:
            Terminate ();

            ~Terminate ();

        public:
            static void UI (const QString & message);
    };
}

#endif // _TERMINATE_H
