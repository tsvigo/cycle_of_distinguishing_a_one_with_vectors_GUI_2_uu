#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QApplication>

#include <QMessageBox>
#include <QCloseEvent>
#include <iostream>
#include <QTextStream>
#include <memory> // Для std::unique_ptr
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Реализация make_unique для C++11
//namespace std {
//    template<typename T, typename... Args>
//    std::unique_ptr<T> make_unique(Args&&... args) {
//        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
//    }
//}
//###########################################################################
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
//###########################################################################
protected slots:
    void closeApp() {
        // Выполнить нужный код здесь.
        qDebug() << "Application closed.";
    }
//###########################################################################


private slots:
    void on_Dialog_finished(int result);
    void on_Dialog_destroyed();
    void on_Dialog_rejected();
    void on_Dialog_destroyed(QObject *arg1);
};
#endif // DIALOG_H
