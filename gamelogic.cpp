#include "gamelogic.h"
#include <QTime>

GameLogic::GameLogic(QObject *parent) : QObject(parent), m_attempts(0), m_score (0)
{
    qsrand(QTime::currentTime().msecsSinceStartOfDay());

    startNewGame();
}
