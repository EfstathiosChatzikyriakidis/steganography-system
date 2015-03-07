#ifndef _ALGORITHM_LSB_ACTION_H
#define _ALGORITHM_LSB_ACTION_H

#include "IAlgorithmAction.h"

class AlgorithmLSBAction : public IAlgorithmAction
{
    public:
        AlgorithmLSBAction ();

        ~AlgorithmLSBAction ();

        bool encrypt (QImage & image, QString & message, QSharedPointer<AlgorithmConfiguration> configuration = QSharedPointer<AlgorithmConfiguration> (0));
        bool decrypt (QImage & image, QString & message, QSharedPointer<AlgorithmConfiguration> configuration = QSharedPointer<AlgorithmConfiguration> (0));
};

#endif // _ALGORITHM_LSB_ACTION_H
