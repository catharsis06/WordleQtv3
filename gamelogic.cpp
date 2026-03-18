#include "gamelogic.h"
#include <QTime>
#include <QFile>
#include <QTextStream>
#include <QDir>

GameLogic::GameLogic(QObject *parent) : QObject(parent), m_attempts(0), m_score (0)
{
    qsrand(QTime::currentTime().msecsSinceStartOfDay());

    startNewGame();
}

void GameLogic::startNewGame()
{
    const QString words[10] = {
            "барс", "рука", "лось", "перо", "нога",
            "стол", "окно", "сова", "тигр", "рыба"
        };

    m_secretWord = words[qrand()%10];

    m_attempts = 0;
    m_score = 0;

    emit logMessage("[game]: Загаданное слово: ****");
}
