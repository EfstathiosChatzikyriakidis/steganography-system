#ifndef _IALGORITHM_REQUEST_H
#define _IALGORITHM_REQUEST_H

#include <QString>

class IAlgorithmRequest
{
    public:
        virtual ~IAlgorithmRequest ();

        void setName (const QString & name);

        QString getName ();

    protected:
        IAlgorithmRequest ();

        QString _name;
};

#endif // _IALGORITHM_REQUEST_H
