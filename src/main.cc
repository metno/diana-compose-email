
#include "compose_email.h"

#include <QApplication>
#include <QLocale>
#include <QProcess>
#include <QTranslator>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    const QString locale = QLocale::system().name();
    QTranslator translator;
    translator.load(QString(":/translations/submit_report_") + locale);
    app.installTranslator(&translator);

    QString tmpdir, from;

    int a = 1;
    for (; a < argc; ++a) {
        QString arg(argv[a]);
        if (arg == "--")
            break;
        if (arg == "-tmpdir") {
            if (a+1 < argc) {
                tmpdir = argv[a+1];
                a += 1;
            }
        }
        if (arg == "-from") {
            if (a+1 < argc) {
                from = argv[a+1];
                a += 1;
            }
        }
    }
    a += 1; // skip "--"

    MailDialog dialog;
    if (!from.isEmpty())
        dialog.setFrom(from);
    for (; a<argc; ++a)
        dialog.attach(argv[a]);
    dialog.exec();

    if (!tmpdir.isEmpty()) {
        QProcess::execute("rm", QStringList() << "-rvf" << tmpdir);
    }

    return 0;
}
