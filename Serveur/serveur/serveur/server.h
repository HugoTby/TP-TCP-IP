// server.h
#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>

class Server : public QTcpServer
{
	Q_OBJECT
public:
	Server(QObject *parent = nullptr);
	bool isClientConnected() const; // Déclaration de la fonction

protected:
	void incomingConnection(qintptr socketDescriptor) override;

private:
	void processRequest(const QByteArray &request, QTcpSocket *clientSocket);
	bool clientConnected = false;
};

#endif // SERVER_H
