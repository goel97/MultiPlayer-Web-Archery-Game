#ifndef CLIENT_H
#define CLIENT_H

#include <QWebSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
#include "gamestate.h"

/*!
 * \brief Classs to Create Client
 */
class client : public QObject
{
    Q_OBJECT
public :
    /*!
     * \brief Reference to the state of the game
     */
    gamestate * state;
    /*!
     * \brief Client Constructor
     * \param state_param State of the Game
     */
    client(gamestate * state_param);
    /*!
     * \brief TO Establish Connection between Server and CLient.
     * \param url_param Server's URL
     */
    void estServerConnection(QUrl url_param);

private :
    /*!
     * \brief Socket of the Client.
     */
    QWebSocket Client_local;
    /*!
     * \brief Local copy of the Server's URL
     */
    QUrl Server_url;

private Q_SLOTS:
    /*!
     * \brief To Start the Game when connected.
     */
    void connectionSetup();
    /*!
     * \brief Process the Text message sent by the Server.
     */
    void processText(QString text);
    /*!
     * \brief Process the Binary message sent by the Server.
     */
    void processBinary(QByteArray message_bytes);
    /*!
     * \brief Send State of the Game in Client to Server.
     */
    void sendGameState();
};

#endif // CLIENT_H
