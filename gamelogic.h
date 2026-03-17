#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QObject>

class GameLogic : public QObject
{
    Q_OBJECT
public:
    explicit GameLogic(QObject *parent = nullptr);
    void startNewGame();
    QString processGuess(const QString &guess);
    int getScore() const;
    bool isGameOver() const;
    void saveScore();

signals:
    void logMessage(const QString &text);

private:
    QString m_secretWord;
    int m_attempts;
    int m_score;

    QString getFeedback(const QString &guess) const;
};

#endif // GAMELOGIC_H
