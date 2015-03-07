#ifndef _IALGORITHM_ACTION_H
#define _IALGORITHM_ACTION_H

#include <QSharedPointer>

#include <QImage>

#include "AlgorithmConfiguration.h"

class IAlgorithmAction
{
    public:
        virtual ~IAlgorithmAction ();

        virtual bool encrypt (QImage & image, QString & message, QSharedPointer<AlgorithmConfiguration> configuration = QSharedPointer<AlgorithmConfiguration> (0)) = 0;
        virtual bool decrypt (QImage & image, QString & message, QSharedPointer<AlgorithmConfiguration> configuration = QSharedPointer<AlgorithmConfiguration> (0)) = 0;

    protected:
        IAlgorithmAction ();
};

#endif // _IALGORITHM_ACTION_H
