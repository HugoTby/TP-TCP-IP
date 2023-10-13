#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>

class Server : public QTcpServer // On déclare la classe
{
	Q_OBJECT
public:
	Server(QObject *parent = nullptr); // déclaration du constructeur
	bool isClientConnected() const; // Déclaration de la fonction d'ino de connexion

protected:
	void incomingConnection(qintptr socketDescriptor) override; // Pour une connection entrante

private:
	void processRequest(const QByteArray &request, QTcpSocket *clientSocket); // requete
	bool clientConnected = false; // Client connecté ? défaut = false
};

#endif // SERVER_H
