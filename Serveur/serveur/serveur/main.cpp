#include <QCoreApplication>
#include <QDebug>
#include "server.h"

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	Server server;

	if (!server.listen(QHostAddress::Any, 12345)) {
		qCritical() << "Le serveur n a pas pu demarrer.";
		return 1;
	}
	else {
		qDebug() << "Le serveur ecoute sur le port 12345.";
	}

	// Exemple d'affichage de l'état de connexion
	if (server.isClientConnected()) {
		qDebug() << "Un client est connecte.";
	}
	else {
		qDebug() << "Aucun client n est connecte.";
	}

	return app.exec();
}

