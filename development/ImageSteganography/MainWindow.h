#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H

#include <QMainWindow>
#include <QActionGroup>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private slots:
        void loadImageFromDisk ();
        void saveImageToDisk ();

        void encryptToImage ();
        void decryptFromImage ();

        void on_actionAbout_triggered ();
        void on_actionHelp_triggered ();

    public:
        explicit MainWindow (QWidget * parent = 0);

        ~MainWindow ();

    private:
        void groupingActions ();
        void assignActionsIDs ();
        void registerConnections ();
        void registerAlgorithms ();

        static const QString ACTION_ID;

        Ui::MainWindow * ui;

        QSharedPointer<QActionGroup> actionsGroup;

        QImage image;
};

#endif // _MAIN_WINDOW_H
