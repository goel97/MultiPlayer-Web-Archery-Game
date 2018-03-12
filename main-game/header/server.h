#ifndef SERVER_H
#define SERVER_H
#include <QWebSocketServer>
#include <QWebSocket>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "gamestate.h"
#include "target.h"

/*!
 * \brief Class to create Server
 */
class server: public QObject{
    Q_OBJECT

   private:
    /*!
     * \brief port to communicate with the client
     */
    const quint16 port;
    /*!
     * \brief QWebSocketServer object to listen on the given address
     */
    QWebSocketServer * server_local;
    /*!
     * \brief Reference to socket of the connected client
     */
    QWebSocket * client_local;
    /*!
     * \brief Flag to check if Game has already started
     */
    bool gameStarted;
    /*!
     * \brief Flag to check if the Game is running
     */
    bool loop_Running;
    /*!
     * \brief Reference to the Scene of the Game
     */
    QGraphicsScene * scene;
    /*!
     * \brief Reference to the View of the Game
     */
    QGraphicsView * view;
    /*!
     * \brief Reference to the State of the Game
     */
    gamestate * state;
    /*!
     * \brief Starts the Game by connecting the signals to specifi slots.
     */
    void startGame();
    /*!
     * \brief Reference to the Target of the Game.
     */
    target *t;

   private Q_SLOTS:

    /*!
     * \brief To setup the connection with the client
     */
    void connectionSetup();
    /*!
     * \brief Process the text message sent by the Client
     */
    void processText(QString text);
    /*!
     * \brief Process the binary message sent by th Client
     */
    void processBinary(QByteArray binary);
    /*!
     * \brief Sends the GameState to the Client as JSon object
     */
    void sendGameState();

   public:

    /*!
     * \brief Server Constructor
     * \param scene_param Scene of the Game
     * \param view_param View of the Game
     * \param port_param Port for communication
     * \param state_param State of the Game
     * \param t_param Target
     */
    server(QGraphicsScene * scene_param,QGraphicsView * view_param,quint16 port_param,gamestate * state_param, target *t_param);
    /*!
     * \brief Starts the server
     */
    void startServer();
    /*!
     * \brief Runs the Game loop
     */
    void gameLoop();

};

#endif // SERVER_H
