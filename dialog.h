#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QApplication>

#include <QMessageBox>
#include <QCloseEvent>
#include <iostream>
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;

protected:
    void closeEvent(QCloseEvent *event) override {
        // Ваш код здесь
        std::cout << "Executing custom code before closing the dialog." << std::endl;

        // Можно также показать диалоговое окно для подтверждения
        auto reply = QMessageBox::question(this, "Exit", "Are you sure you want to quit?",
                                           QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            event->accept();  // Закрыть диалог
        } else {
            event->ignore();  // Отменить закрытие
        }
    }



};
#endif // DIALOG_H
