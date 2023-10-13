#include "server.h"
#include <QTcpSocket>
#include <QRandomGenerator>
#include <QDebug>

Server::Server(QObject *parent) : QTcpServer(parent) {
	// Initialisation du serveur
}

void Server::incomingConnection(qintptr socketDescriptor) {
	// Nouvelle connexion entrante
	QTcpSocket *clientSocket = new QTcpSocket(this);
	clientSocket->setSocketDescriptor(socketDescriptor);

	// Récupérer l'adresse IP du client
	QHostAddress clientAddress = clientSocket->peerAddress();
	QString clientIPv4 = clientAddress.toString();

	// Supprimer "::ffff:" si présent
	if (clientIPv4.startsWith("::ffff:")) {
		clientIPv4 = clientIPv4.mid(7); // Pour supprimer les 7 premiers caractères "::ffff:"
	}


	// On met à jour l'état de connexion
	qDebug() << "Nouvelle connexion entrante depuis : " << clientIPv4;
	clientConnected = true;
	qDebug() << "Etat de connexion mis a jour : le client est connecte au serveur.";


	connect(clientSocket, &QTcpSocket::readyRead, this, [clientSocket, this]() {
		// Lorsque des données sont prêtes à être lues
		QByteArray data = clientSocket->readAll();
		processRequest(data, clientSocket);
		});
}
bool Server::isClientConnected() const {
	return clientConnected; // Une personne est connectée
}



void Server::processRequest(const QByteArray &request, QTcpSocket *clientSocket) {
	QString response;

	// Analyse de la demande
	if (request.startsWith("Td")) {
		QString sensorType = request.mid(0, 2);
		QString sensorID = request.mid(2, 2);

		// Générer des valeurs aléatoires pour la réponse
		float value = QRandomGenerator::global()->generateDouble() * 55.0 - 20.0;

		// Formater la réponse pour "Td"
		response = QString("%1%2,%3").arg(sensorType).arg(sensorID).arg(value, 0, 'f', 2);
	}
	else if (request.startsWith("Tf")) {
		QString sensorType = request.mid(0, 2);
		QString sensorID = request.mid(2, 2);

		// Générer des valeurs aléatoires pour la réponse
		float value = (QRandomGenerator::global()->generateDouble() * 55.0 - 20.0) * 9.0 / 5.0 + 32.0;

		// Formater la réponse pour "Tf"
		response = QString("%1%2,%3").arg(sensorType).arg(sensorID).arg(value, 0, 'f', 2);
	}
	else if (request.startsWith("Hr")) {
		QString sensorType = request.mid(0, 2);
		QString sensorID = request.mid(2, 2);

		// Générer des valeurs aléatoires pour la réponse
		float value = QRandomGenerator::global()->generateDouble() * 100.0;

		// Formater la réponse pour "Hr"
		response = QString("%1%2,%3").arg(sensorType).arg(sensorID).arg(value, 0, 'f', 2);
	}
	else {
		response = "Requete non valide.";
	}


	// Répondre au client
	clientSocket->write(response.toUtf8());
}

