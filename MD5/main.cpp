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
    QByteArray result;

    if(theFile.open(QIODevice::ReadOnly))
    {
      result = QCryptographicHash::hash(theFile.readAll(),QCryptographicHash::Md5);
      qDebug()<< "\n" << "MD5 Value:  " << QString(result.toHex().constData()).toUpper();
      result = QCryptographicHash::hash(theFile.readAll(),QCryptographicHash::Sha1);
      qDebug()<< "\n" << "Sha1 Value: " << QString(result.toHex().constData()).toUpper();

      theFile.close();
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
