// cycle_of_distinguishing_a_one_with_vectors_GUI_2
#include "dialog.h"
#include "ui_dialog.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
#include <QTextStream>
#include <QFile>
#include <fstream>

#include <iostream>
using namespace std;
#include <QFileDialog>
#include <vector>
#include <memory> // Для std::unique_ptr
#include <QDebug>
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QString    Nazvaniye_fayla_s_neyronami_i_signalom="";
long long variable_error;
int var ;
int variable_synapse_index_counter=0;

 int neuron_index = 0, synapse_index = 0;
 bool all_sinapsi_proydeni=false;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Реализация make_unique для C++11
namespace std {
    template<typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args&&... args) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }
}
//###########################################################################
// Инициализация умного указателя на std::vector<long long>
    std::unique_ptr<std::vector<long long>> list_of_synapses = std::make_unique<std::vector<long long>>();
     std::unique_ptr<std::vector<long long>> list_of_neurons = std::make_unique<std::vector<long long>>();
//########################################################################################################
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
//###########################################################################
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
              // выведем название программы
               std::cout << "  cycle_of_distinguishing_a_one_with_vectors_GUI_2_uu" << std::endl;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// откроем txt нейроны
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     QString filePath = QFileDialog::getOpenFileName(this, tr("Выберите файл txt"),
     //QDir::homePath()
       "/home/viktor/Загрузки/Data/Images/chars74k_png_Fnt_Sample1_black-white/300/txt/"
        , tr("Все файлы txt (*.txt)"));
         if (!filePath.isEmpty()) {
          // filePath содержит полный путь выбранного файла
       Nazvaniye_fayla_s_neyronami_i_signalom=filePath;
               }
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         //########################################################################################################
         ////////////////////////////////////////////// загрузка нейронов и сигнала из файла в вектор
         // читаем нейроны в вектор
          // Открытие файла для чтения
          int chislo_oshibok_neyronov=0;
              std::cout << "читаем нейроны в вектор"<< std::endl;
             QFile file(Nazvaniye_fayla_s_neyronami_i_signalom);
             if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                 qDebug() << "Не удалось открыть файл!";
                    }

             // Создание текстового потока для чтения из файла
             QTextStream in(&file);
             while (!in.atEnd()) {
                 QString line = in.readLine();
                 bool ok;
                 long long value = line.toLongLong(&ok);
                 if (ok) {
                     list_of_neurons->push_back(value);
                 } else {
         //            qDebug() << "Не удалось преобразовать строку в число:" << line;
                 }
                  if (ok) {
         //        qDebug() << "Преобразование в long long прошло успешно:";
         //        qDebug() << "Значение:" << value;
             } else {
         //        qDebug() << "Ошибка преобразования в long long:";
         //        qDebug() << "Строка не является числовой, или значение выходит за пределы long long";
                   chislo_oshibok_neyronov++;
             }
             }
             // Закрытие файла
             file.close();
               std::cout << "конец чтения нейронов в вектор"<< std::endl;
                 std::cout << "//########################################################################################################"<< std::endl;
                 std::cout << "число ошибок форматов нейронов = "<< chislo_oshibok_neyronov<< std::endl;
                         std::cout << "//########################################################################################################"<< std::endl;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////// загрузка синапсов из файла в вектор
  // Открытие файла для чтения
           int chislo_oshibok_sinapsov=0;
     std::cout << "читаем синапсы в вектор"<< std::endl;
    QFile file2("/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt");
       if (!file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
      qDebug() << "Не удалось открыть файл!";
                      }

          // Создание текстового потока для чтения из файла
           QTextStream in2(&file2);
        while (!in2.atEnd()) {
         QString line = in2.readLine();
               bool ok;
            long long value = line.toLongLong(&ok);
                 if (ok) {
                                     list_of_synapses->push_back(value);
              } else
                                 {
                         //            qDebug() << "Не удалось преобразовать строку в число:" << line;
                                 }
    if (ok) {
       //        qDebug() << "Преобразование в long long прошло успешно:";
          //        qDebug() << "Значение:" << value;
              } else {
                         //        qDebug() << "Ошибка преобразования в long long:";
qDebug() << "Строка не является числовой, или значение выходит за пределы long long: "<< line ;
                                   chislo_oshibok_sinapsov++;
                             }

                             }
                             // Закрытие файла
                             file2.close();
 std::cout << "конец чтения синапсов в вектор"<< std::endl;
      std::cout << "//########################################################################################################"<< std::endl;
         std::cout << "число ошибок форматов синапсов = "<< chislo_oshibok_sinapsov<< std::endl;
      std::cout << "//########################################################################################################"<< std::endl;
//########################################################################################################
//########################################################################################################
  if (chislo_oshibok_sinapsov!=0 || chislo_oshibok_neyronov!=0)
      // если есть ошибки в форматах синапсов или нейронов останавливаем
 // программу
        // Остановить выполнение программы
                           {
           exit(EXIT_SUCCESS);

              }

//########################################################################################################
  //########################################################################################################
  /////////////   показываем что определила программа
      if
        //  ( variable_error <=0)
          (list_of_neurons->at(200)<0)

      {
          ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это 1.");
         // Odin_Programmi=true;
             goto d;
      }
                             else {
          ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это не 1.");
          //  Odin_Programmi=false;

      }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// Solution function ////////////////////////////////////////////////////////////
      b:
          for ( var = 100;
         var < 200

           ; ++var) // This is the range of neurons

          {
              for ( neuron_index = 0, synapse_index = 0;

                /*,*/ synapse_index < 10100;
                  ++neuron_index, synapse_index = synapse_index + 100)

              { // // ошибка сегментации


              if (neuron_index < 200)
                  list_of_neurons->at(var)=list_of_neurons->at(var) //-5310911
                  +  (list_of_neurons->at(neuron_index)/
                   list_of_synapses->at(synapse_index)); // + на -

              } //
          }
      //////////////////////
          for (int   neuron_index = 100, synapse_index = 10000;

       synapse_index < 10100
       ;
            ++neuron_index, ++synapse_index)
          {
         if (list_of_synapses->at(synapse_index)!=0)
              list_of_neurons->at(200) = list_of_neurons->at(200) //-5310911
              + (list_of_neurons->at(neuron_index) / list_of_synapses->at(synapse_index))
              ; // + на -
          }
//########################################################################################################
//########################################################################################################
      /////////////   показываем что определила программа
          if
            //  ( variable_error <=0)
              (list_of_neurons->at(200)>=0)

          {
              ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это не 1.");
                     if (variable_synapse_index_counter>0) // вот была ошибка
             {
             // если все синапсы пройдены, поставлены на минимумы и ошибка не пропала.
                   if (list_of_synapses->at(variable_synapse_index_counter) < 9223372036854775807 // почему 2147483646?
                   && list_of_synapses->at(variable_synapse_index_counter) >0
                   ) // < 2147483646 или > 1
           {
    list_of_synapses->at(variable_synapse_index_counter)  =
            list_of_synapses->at(variable_synapse_index_counter)-1;  // +1 или -1
    variable_synapse_index_counter--;
              std::cout << "list_of_neurons->at(200) = " << list_of_neurons->at(200)<< std::endl;
      goto b;
           }
           }
        else
      {
       std::cout << "все синапсы пройдены, поставлены на минимумы и ошибка не пропала." << std::endl;
      all_sinapsi_proydeni=true;
       std::cout << "list_of_neurons->at(200) = " <<list_of_neurons->at(200)<< std::endl;
      }
        // Odin_Programmi=true;
     }
            else {
              ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это 1.");
              //  Odin_Programmi=false;
              goto d;
          }
      ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      d: ;;













}

Dialog::~Dialog()
{
    delete ui;
}

