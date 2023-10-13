#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>

class Server : public QTcpServer // On d�clare la classe
{
	Q_OBJECT
public:
	Server(QObject *parent = nullptr); // d�claration du constructeur
	bool isClientConnected() const; // D�claration de la fonction d'ino de connexion

protected:
	void incomingConnection(qintptr socketDescriptor) override; // Pour une connection entrante

private:
	void processRequest(const QByteArray &request, QTcpSocket *clientSocket); // requete
	bool clientConnected = false; // Client connect� ? d�faut = false
};

#endif // SERVER_H
