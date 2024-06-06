#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QApplication>

#include <QMessageBox>
#include <QCloseEvent>
#include <iostream>
#include <QTextStream>
#include <memory> // Для std::unique_ptr
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Реализация make_unique для C++11
namespace std {
    template<typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args&&... args) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }
}
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
//###########################################################################
        // запишем синапсы

        // Инициализация умного указателя на std::vector<long long>
            std::unique_ptr<std::vector<long long>> list_of_synapses = std::make_unique<std::vector<long long>>();
            // Имя файла для записи
                QString filename = "/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt";
                // /home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt
                QFile file3(filename);

                // Открываем файл для записи
                if (!file3.open(QIODevice::WriteOnly | QIODevice::Text |QIODevice::Truncate)) {
                    std::cerr << "Unable to open file for writing!" << std::endl;

                }

                QTextStream out(&file3);

                // Записываем данные из вектора в файл
                for (const auto& value : *list_of_synapses) {
                    out << value << "\n";
                }

                // Закрываем файл
                file3.close();

                std::cout << "Successfully wrote the vector to " << filename.toStdString() << std::endl;


//###########################################################################
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
