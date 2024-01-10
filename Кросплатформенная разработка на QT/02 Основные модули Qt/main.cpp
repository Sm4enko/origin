#include <QCoreApplication>
#include <QDebug>
#include <QtSql>
#include <QSqlQuery>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

void database ()
{
  QSqlDatabase db = QSqlDatabase::addDatabase ("QPSQL");
  db.setHostName ("your_postgresql_host");
  db.setDatabaseName ("your_database_name");
  db.setUserName ("your_username");
  db.setPassword ("your_password");

  if (db.open ())
    {
      qDebug () << "Connected to PostgreSQL database";

      QSqlQuery query;
      query.exec ("SELECT version()");
      if (query.next ())
    {
      qDebug () << "PostgreSQL Version:" << query.value (0).toString ();
    }
      else
    {
      qDebug () << "Error1";
    }
    }
  else
    {
      qDebug () << "Error 2";
    }
}

void network ()
{
  QNetworkAccessManager networkManager;
  QNetworkRequest request (QUrl ("test.com"));

  QNetworkReply *reply = networkManager.get (request);

  QObject::connect (reply, &QNetworkReply::finished,[&]()
            {
            if (reply->error () == QNetworkReply::NoError)
            {
            qDebug () << "Network request successful. Response:" <<
            reply->readAll ();}
            else
            {
            qDebug () << "Network request failed. Error:" <<
            reply->errorString ();}

            reply->deleteLater (); QCoreApplication::quit ();}
  );
}

int main (int argc, char *argv[])
{
  QCoreApplication app (argc, argv);

  database ();

  network ();

  qDebug () << "Hello World";

  return app.exec ();
}
