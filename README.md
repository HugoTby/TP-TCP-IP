# Compte Rendu - TP Client/Serveur TCP/IP avec Qt

## Sommaire
1. Introduction
2. Principe de la notion de client/serveur en informatique
3. Qu'est-ce qu'un protocole ?
4. Notion de port et de socket sous TCP/IP
5. Applications demandées
   - Réalisation de l'application cliente TCP/IP en C++
   - Réalisation de l'application serveur TCP/IP en C++
6. Conclusion
7. Annexe : Code source

## Introduction
Ce rapport décrit la création d'une application client/serveur utilisant le protocole TCP/IP et le framework Qt. L'objectif principal est de créer des applications client et des applications serveur capables de communiquer selon des protocoles définis.

**Questions Préliminaires :**

1. Principe de la notion de client/serveur en informatique : Le modèle client-serveur est un paradigme de communication dans lequel un serveur fournit des services ou des ressources à un ou plusieurs clients. Le client envoie une requête au serveur, et le serveur traite la requête et renvoie une réponse. Cela permet l'allocation des tâches et la gestion des ressources.

2. Qu'est-ce qu'un protocole ? À quoi sert-il ? Un protocole est un ensemble de règles et de conventions qui définissent la manière dont les données sont échangées entre les parties communicantes. Dans ce cas, le protocole décrit le format des messages entre client et serveur et les actions à réaliser en réponse à ces messages.

3. Expliquer la notion de port et de socket sous TCP/IP :
   - Un port est un numéro associé à un processus sur un ordinateur. Il permet de diriger le trafic réseau vers le bon processus.
   - Un socket est un point de communication bidirectionnel entre deux ordinateurs sur un réseau. Il est défini par une adresse IP et un port.

4. En utilisant l'aide de Qt, quelles sont les classes de Qt permettant la création d'une application cliente et d'une application serveur ? Qt propose des classes pour créer des applications client/serveur TCP/IP. Pour le client, on peut utiliser `QTcpSocket`, et pour le serveur, on peut utiliser `QTcpServer`.

## Applications demandées

### Réalisation de l'application cliente TCP/IP en C++
L'application client est développée en C++ avec Qt. Elle comprend une interface utilisateur qui permet de sélectionner les informations à récupérer (température en °C, température en °F ou mesure d'humidité). L'application se connecte au serveur en spécifiant l'adresse IP et le port, ces derniers sont pré-remplis permettant de gagner du temps dans le traitement de la demande. Elle envoie des trames de requête au serveur, reçoit des réponses, traite les trames et affiche les informations de manière stylée.

### Réalisation de l'application serveur TCP/IP en C++
L'application serveur a également été développée en C++ avec Qt. Elle utilise la classe QTcpServer pour créer un serveur TCP. L'application traite les requêtes provenant du client en suivant un protocole de communication spécifique. Elle génère aléatoirement des valeurs de température et d'hygrométrie dans les plages spécifiées et renvoie des réponses au client selon le protocole qui a été établi dans la consigne du TP.

## Conclusion
Ce TP a permis de comprendre les concepts de base liés aux applications client/serveur, aux protocoles, aux ports et aux sockets. Les applications créées utilisent Qt pour la communication TCP/IP et respectent un protocole défini. Les applications cliente et serveur fonctionnent correctement et sont capables d'interagir de manière efficace.

## Annexe : Code Source
Voici le lien du repository GitHub : [https://github.com/HugoTby/TP-TCP-IP](https://github.com/HugoTby/TP-TCP-IP)
