#include <QCoreApplication>
#include <QDebug>
#include "server.h"

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv); // On initialise QT
	Server server;

	if (!server.listen(QHostAddress::Any, 12345)) {
		qCritical() << "Erreur de lancement du serveur."; // Si le serveur ne démarre pas
		return 1;
	}
	else {
		qDebug() << "Le serveur est config sur le port 12345."; // Indication de connexion au port
	}

	// Exemple d'affichage de l'état de connexion
	if (server.isClientConnected()) {
		qDebug() << "Un client est connecte au serveur."; // Si un user est connecté
	}
	else {
		qDebug() << "Aucun client n est connecte au serveur."; // Si aucun user n'est connecté
	}

	return app.exec();
}

