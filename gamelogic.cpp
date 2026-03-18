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

QString GameLogic::processGuess(const QString &guess)
{
    QString g = guess.trimmed().toLower();

    if (g.length() != 4) {
        return "[game]: Слово должно быть из 4 букв!";
    }

    m_attempts++;

    emit logMessage("[player]: " + g);

    if (g == m_secretWord){
        int points = 6 - m_attempts;
        if (points < 1) points = 1;

        m_score += points;

        return QString("[game]: Вы отгадали слово и заработали %1 баллов! Желаете продолжить?").arg(points);
    }
};

QString GameLogic::getFeedback(const QString &guess) const
{
    QString letters = "";

    QString view = "_ _ _ _";

    for(int i = 0; i < 4; ++i){

        if(guess[i] == m_secretWord[i]) {
            view[i*2] = guess[i];
        }

        if(m_secretWord.contains(guess[i]) && !letters.contains(guess[i])) {
            if(!letters.isEmpty()) letters += ", ";
            letters += guess[i];
        }
    }

    if (letters.isEmpty()) letters = "-";

    return "[game]: Отгаданные буквы: " + letters + "\nСлово: " + view;
}

int GameLogic::getScore() const
{
    return m_score;
}

bool GameLogic::isGameOver() const
{
    return m_attempts >= 5;
}

void GameLogic::saveScore()
{
    if (m_score == 0) return;

    QString path = QDir::currentPath() + "/records.txt";

    QFile file(path);

    if(file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);

        out << m_score << "\n";

        file.close();
    }
}
