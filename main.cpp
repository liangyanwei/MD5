#include <QByteArray>
#include <QFile>
#include <QCryptographicHash>
#include <QDebug>

int main(int argc, char **argv)
{
  if(argc == 2)
  {
    QString filePath = argv[1];
    QFile theFile(filePath);

    theFile.open(QIODevice::ReadOnly);
    QByteArray ba = QCryptographicHash::hash(theFile.readAll(),QCryptographicHash::Md5);
    theFile.close();

    qDebug()<< "\n" << QString(ba.toHex().constData()).toUpper();
  }

  return 0;
}
