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
    QByteArray ba;

    if(theFile.open(QIODevice::ReadOnly))
    {
      ba = QCryptographicHash::hash(theFile.readAll(),QCryptographicHash::Md5);
      theFile.close();
      qDebug()<< "\n" << QString(ba.toHex().constData()).toUpper();
    }
    else
    {
      theFile.close();
      qDebug()<< "\n" << "ERROR: File is NOT exist!";
    }
  }
  else
  {
    qDebug()<< "\n" << "WARNING: Missing file path input.";
  }

  return 0;
}
