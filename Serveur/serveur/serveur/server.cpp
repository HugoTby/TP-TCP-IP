// server.cpp
#include "server.h"
#include <QTcpSocket>
#include <QRandomGenerator>
#include <QDebug>

Server::Server(QObject *parent) : QTcpServer(parent) {
	// Initialisation de votre serveur
}

void Server::incomingConnection(qintptr socketDescriptor) {
	// Nouvelle connexion entrante
	QTcpSocket *clientSocket = new QTcpSocket(this);
	clientSocket->setSocketDescriptor(socketDescriptor);

	// Mettre à jour l'état de connexion
	qDebug() << "Nouvelle connexion entrante.";
	clientConnected = true;
	qDebug() << "Etat de connexion mis a jour : le client est connecte.";


	connect(clientSocket, &QTcpSocket::readyRead, this, [clientSocket, this]() {
		// Lorsque des données sont prêtes à être lues
		QByteArray data = clientSocket->readAll();
		processRequest(data, clientSocket);
		});
}
bool Server::isClientConnected() const {
	return clientConnected;
}



void Server::processRequest(const QByteArray &request, QTcpSocket *clientSocket) {
	QString response;

	// Analyser la demande
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

