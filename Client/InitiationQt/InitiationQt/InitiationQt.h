#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_InitiationQt.h"
#include <qtcpsocket.h>
#include <qtcpserver.h>

class InitiationQt : public QMainWindow
{
	Q_OBJECT

public:
	InitiationQt(QWidget *parent = Q_NULLPTR);
	//~InitiationQt();

private:
	Ui::InitiationQtClass ui;
	QTcpSocket * socket;
	QTcpServer * server;
public slots:
	void onDisplayMessageButtonClicked();
	void onConnectButtonClicked();
	void onSocketConnected();
	void onSocketDisconnected();
	void onSendMessageButtonClicked();
	void onSocketReadyRead();
	void onServerNewConnection();
	void onClientDisconnected();
	void onClientReadyRead();
	void EnvoiCel();
	void EnvoiFar();
	void EnvoiHyg();
	
};