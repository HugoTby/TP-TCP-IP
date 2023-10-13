#include "InitiationQt.h"
InitiationQt::InitiationQt(QWidget *parent)
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

}
void InitiationQt::onDisplayMessageButtonClicked(){
	ui.label->setText("Hello word !");
}
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
void InitiationQt::onSocketConnected(){
	ui.connectionStatusLabel->setText("Status connexion : connecte !");
}
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
void InitiationQt::onSocketReadyRead(){

	QByteArray data = socket->read(socket->bytesAvailable());
	QString str(data);
	ui.connectionStatusLabel->setText("Status connexion : Message recu = " + str);
}
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
	ui.connectionStatusLabel->setText("Status connexion : Message recu = " + str);
	obj->write(coucou);
}

