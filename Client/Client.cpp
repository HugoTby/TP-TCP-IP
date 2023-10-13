#include "Client.h"
InitiationQt::InitiationQt(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	socket = new QTcpSocket(this);
	QObject::connect(socket, SIGNAL(connected()), this, SLOT(onSocketConnected()));
	QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));
	QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));

	server = new QTcpServer(this);
	QObject::connect(server, SIGNAL(newConnection()), this, SLOT(onServerNewConnection()));
	server->listen(QHostAddress::AnyIPv4, 4321);

	// préremplissage Ip et Port 
	ui.IPLineEdit->setText("192.168.64.129"); 
	ui.portLineEdit->setText("12345");    
}
void InitiationQt::onDisplayMessageButtonClicked(){
	
}
//Code pour le bouton connection 
void InitiationQt::onConnectButtonClicked(){
	QString ip = ui.IPLineEdit->text();
	QString port = ui.portLineEdit->text();



	bool ok;
	int portAsInt = port.toInt(&ok);
	if (ok)
	{
		socket->connectToHost(ip, portAsInt);
	}
}
//Statu du server 
void InitiationQt::onSocketConnected(){
	ui.connectionStatusLabel->setText("Status connexion : connecte !");
}
//Statu du server
void InitiationQt::onSocketDisconnected(){
	ui.connectionStatusLabel->setText("Status connexion : Déconnecté !");
}



// Envoi du mess 
void InitiationQt::onSendMessageButtonClicked() {
	if (socket->state() == QTcpSocket::ConnectedState) {
		QString message = ui.plainTextEdit->toPlainText(); // Récupère le texte du QTextEdit

		if (!message.isEmpty()) {
			QByteArray data = message.toUtf8();
			socket->write(data);
		}
	}
}
//Affichage du resultat 
void InitiationQt::onSocketReadyRead(){
	QByteArray data = socket->read(socket->bytesAvailable());
	QString str(data);

	int indexVirgule = str.indexOf(',');  // trouver l'index de la virgule

	QString avantLaVirgule;
	QString aprèsLaVirgule;

	if (indexVirgule != -1 && indexVirgule < str.length() - 1) {
		avantLaVirgule = str.left(indexVirgule).trimmed();
		aprèsLaVirgule = str.mid(indexVirgule + 1).trimmed();
	}

	ui.connectionStatusLabel1->setText("la valeur demandee pour le capteur " + avantLaVirgule + " est : " + aprèsLaVirgule);
}
//
void InitiationQt::onServerNewConnection(){
	ui.connectionStatusLabel->setText("Un client s'est connecte");
	QTcpSocket * client = server->nextPendingConnection();
	QObject::connect(client, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
	QObject::connect(client, SIGNAL(disconnected()), this, SLOT(onClientDisconnected()));
}
void InitiationQt::onClientDisconnected(){
	QTcpSocket *obj = qobject_cast<QTcpSocket*>(sender());
	QObject::disconnect(obj, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
	QObject::disconnect(obj, SIGNAL(disconnected()), this, SLOT(onClientDisconnected()));
	obj->deleteLater();
}
void InitiationQt::onClientReadyRead(){
	QTcpSocket *obj = qobject_cast<QTcpSocket*>(sender());
	QByteArray coucou = obj->read(obj->bytesAvailable());
	QString str(coucou);
	ui.connectionStatusLabel1->setText("Message recu = " + str);
	obj->write(coucou);
}

//Code bouton Celcius 
void InitiationQt::EnvoiCel() {
	QString cel = "Td";
	QString num = ui.plainTextEdit->toPlainText();
	QByteArray data = cel.toUtf8();
	QByteArray data2 = num.toUtf8();
	socket->write(data + data2);

}
// code bouton Far
void InitiationQt::EnvoiFar() {
	
	QString far = "Tf";
	QString num = ui.plainTextEdit->toPlainText();
	QByteArray data = far.toUtf8();
	QByteArray data2 = num.toUtf8();
	socket->write(data + data2);
	


}
// Code bouton hygrométrie
void InitiationQt::EnvoiHyg() {

	QString hyg = "Hr";
	QString num = ui.plainTextEdit->toPlainText();
	QByteArray data = hyg.toUtf8();
	QByteArray data2 = num.toUtf8();
	socket->write(data + data2);


	
}


