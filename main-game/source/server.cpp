
#include "server.h"
#include <QDebug>
#include <QTimer>
#include <QJsonObject>
#include <QJsonDocument>

server::server(QGraphicsScene *scene_param,QGraphicsView * view_param, quint16 port_param, gamestate *state_param, target *t_param):
    port(port_param)
{
    t = t_param;
    state = state_param;
    view = view_param;
    gameStarted = false;
    server_local = new QWebSocketServer(QStringLiteral("Archery Server"),QWebSocketServer::NonSecureMode,this);
}

void server::startServer()
{

    if(server_local->listen(QHostAddress("192.168.137.112"),port))
    {
            qDebug() << "Server Started";
            qDebug() << server_local->serverUrl().toString();
            qDebug() << "Server listening on port" << port;
            QObject::connect(server_local,&QWebSocketServer::newConnection,this, &server::connectionSetup);
    }
    else
    {
            qDebug() << "Error In Connecting To Port : " << port;
            qDebug() << "Error Message : " << server_local->errorString();
            std::exit(EXIT_FAILURE);
    }
            qDebug() << "Server's connecting URL : " << server_local->serverUrl();
}
void server::startGame()
{
    client_local->sendTextMessage("Are You Ready ?");
}

void server::connectionSetup()
{
    qDebug() << "Got A New Connection To Play Game";

    if(gameStarted)
    {
            QWebSocket *client_Socket = server_local->nextPendingConnection();
            client_Socket->sendTextMessage("The Game Has Already Started . <br>Please Join Us For The Next Game.");
    }

    else
    {
            QWebSocket *client_Socket = server_local->nextPendingConnection();
            client_local = client_Socket;
            view->show();
            startGame();
            QObject::connect(client_Socket, &QWebSocket::binaryMessageReceived, this, &server::processBinary,Qt::DirectConnection);
            QObject::connect(client_Socket, &QWebSocket::textMessageReceived, this, &server::processText,Qt::DirectConnection);

            client_Socket->sendTextMessage("Successfully Connected.");
            qDebug() << "Added To server_local And Sent Response Message";
    }
}

void server::gameLoop()
{
    gameStarted = true;
    loop_Running = true;
    sendGameState();
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(sendGameState()));
    timer->start(50);

}

void server::processText(QString text)
{
    if(text.contains("Yes"))
    {
        gameLoop();
    }
}

void server::processBinary(QByteArray binary)
{
    QJsonDocument message_doc = QJsonDocument::fromBinaryData(binary);
    QJsonObject message = message_doc.object();
    state->Player2Position.setX(710);
    state->Player2Position.setY(message["player1_posY"].toInt());

   //double targetX = 800 - message["target_posX"].toDouble();
   //double targetY = message["target_posY"].toDouble();
   state->isArrow2 = message["isArrow1"].toBool();
   state->hit = message["hit"].toInt();

   if(state->isArrow2)
   {
        state->Arrow2Position.setX(800 - message["arrow1_posX"].toDouble());
        state->Arrow2Position.setY(message["arrow1_posY"].toDouble() + 25);

        qDebug() << "Arrow X = " << state->Arrow2Position.x() << " Arrow Y = " << state->Arrow2Position.y();
        double angle  = message["arrow1_angle"].toDouble();
        if(angle < 0)
           state->Arrow2Angle = -(180 + angle);
        else
            state->Arrow2Angle = 180 - angle;
    }

    double angle = message["bow1_angle"].toDouble();
    if(angle < 0)
        state->Bow2Angle = (180 - angle);
    else
        state->Bow2Angle = 180 - angle;

    //state->Bow2Angle = (message["bow2_angle"].toDouble());
    state->points2 = message["points1"].toInt();
    qDebug() << state->points2;
}

void server::sendGameState()
{
    QJsonObject message;
    message = state->getJsonObject();
    QJsonDocument message_doc(message);
    QByteArray message_byte = message_doc.toBinaryData();
    client_local->sendBinaryMessage(message_byte);
}



