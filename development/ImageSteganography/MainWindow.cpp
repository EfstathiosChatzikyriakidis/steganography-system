#include <QCoreApplication>
#include <QDesktopServices>
#include <QMessageBox>
#include <QFileDialog>
#include <QUrl>

#include "AlgorithmRequestFactory.h"
#include "AlgorithmActionFactory.h"

#include "AlgorithmLSBRequest.h"
#include "AlgorithmLSBAction.h"

#include "MainWindow.h"

#include "ui_MainWindow.h"

const QString MainWindow::ACTION_ID = "ActionID";

MainWindow::MainWindow (QWidget * parent) : QMainWindow (parent), ui (new Ui::MainWindow)
{
    ui->setupUi (this);

    actionsGroup = QSharedPointer<QActionGroup> (new QActionGroup (this));

    groupingActions ();
    assignActionsIDs ();
    registerAlgorithms ();
    registerConnections ();
}

MainWindow::~MainWindow ()
{
    delete ui;
}

void MainWindow::loadImageFromDisk ()
{
    const QString fileName = QFileDialog::getOpenFileName (this, tr ("Open Image"), QDir::currentPath (), tr ("Images (*.bmp *.png *.ppm *.xpm)"));

    if (!fileName.isEmpty ())
    {
        image = QImage (fileName);

        if (image.isNull ())
        {
            QMessageBox::critical (this, tr ("Load Image Error"), tr ("Cannot load image: '%1'").arg (fileName));

            return;
        }

        ui->graphicView->setPixmap (QPixmap::fromImage (image));
    }
}

void MainWindow::saveImageToDisk ()
{
    if (!image.isNull ())
    {
        const QString fileName = QFileDialog::getSaveFileName (this, tr ("Save Image"), QDir::currentPath (), tr ("Images (*.bmp *.png *.ppm *.xpm)"));

        if (!fileName.isEmpty ())
        {
            if (!image.save (fileName))
            {
                QMessageBox::critical (this, tr ("Save Image Error"), tr ("Cannot save image: '%1'").arg (fileName));
            }
        }
    }
}

void MainWindow::encryptToImage ()
{
    if (!image.isNull ())
    {
        QString message = ui->messageEdit->toPlainText ();
        if (!message.isEmpty ())
        {
            const QAction * action = actionsGroup->checkedAction ();
            if (action != 0)
            {
                QSharedPointer<IAlgorithmRequest> request = AlgorithmRequestFactory::getInstance (action->property (ACTION_ID.toAscii ()).toString ());
                if (!request.isNull ())
                {
                    QSharedPointer<IAlgorithmAction> action = AlgorithmActionFactory::getInstance (request);
                    if (!action.isNull ())
                    {
                        if (action->encrypt (image, message))
                        {
                            ui->graphicView->setPixmap (QPixmap::fromImage (image));
                        }
                        else
                        {
                            QMessageBox::warning (this, tr ("Encryption Algorithm"), tr ("The message cannot be encrypted in the image!"));
                        }
                    }
                }
            }
        }
    }
}

void MainWindow::decryptFromImage ()
{
    if (!image.isNull ())
    {
        const QAction * action = actionsGroup->checkedAction ();
        if (action != 0)
        {
            QSharedPointer<IAlgorithmRequest> request = AlgorithmRequestFactory::getInstance (action->property (ACTION_ID.toAscii ()).toString ());
            if (!request.isNull ())
            {
                QSharedPointer<IAlgorithmAction> action = AlgorithmActionFactory::getInstance (request);
                if (!action.isNull ())
                {
                    QString message;

                    if (action->decrypt (image, message))
                    {
                        ui->messageEdit->setPlainText (message);
                    }
                }
            }
        }
    }
}

void MainWindow::on_actionAbout_triggered ()
{
    QMessageBox::about (this, QCoreApplication::applicationName (), "<h2>" + QCoreApplication::applicationName () + " - " + QCoreApplication::applicationVersion () + "</h2>" + "<p>" + QCoreApplication::organizationName () + "</p>");
}

void MainWindow::on_actionHelp_triggered ()
{
    QUrl url ("http://efxa.org/steganography-system/");

    QDesktopServices::openUrl (url);
}

void MainWindow::groupingActions ()
{
    actionsGroup->addAction (ui->actionLSB);
}

void MainWindow::assignActionsIDs ()
{
    QList<QAction *> actions = actionsGroup->actions ();

    for (int i = 0; i < actions.size (); i++)
    {
        actions[i]->setProperty (ACTION_ID.toAscii (), QString ("Action %1").arg (i));
    }
}

void MainWindow::registerConnections ()
{
    connect (ui->loadButton, SIGNAL (clicked ()), this, SLOT (loadImageFromDisk ()));
    connect (ui->saveButton, SIGNAL (clicked ()), this, SLOT (saveImageToDisk ()));

    connect (ui->encryptButton, SIGNAL (clicked ()), this, SLOT (encryptToImage ()));
    connect (ui->decryptButton, SIGNAL (clicked ()), this, SLOT (decryptFromImage ()));
}

void MainWindow::registerAlgorithms ()
{
    AlgorithmRequestFactory::registerRequest (
        ui->actionLSB->property(ACTION_ID.toAscii ()).toString (), QSharedPointer<IAlgorithmRequest> (new AlgorithmLSBRequest ())
    );

    AlgorithmActionFactory::registerAction (
        QSharedPointer<IAlgorithmRequest> (new AlgorithmLSBRequest ()), QSharedPointer<IAlgorithmAction> (new AlgorithmLSBAction ())
    );
}
