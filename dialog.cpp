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
#include <chrono>
#include <thread>
//#include <log4cpp/Category.hh>
//#include <log4cpp/Appender.hh>
//#include <log4cpp/Layout.hh>
//#include <log4cpp/Priority.hh>
//#include <QLogger>
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QString    Nazvaniye_fayla_s_neyronami_i_signalom="";
long long variable_error;
int var ;
int variable_synapse_index_counter=10100;

 int neuron_index = 0, synapse_index = 0;
 bool all_sinapsi_proydeni=false;
 std::vector<unsigned long long> readData;
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
//    std::unique_ptr<std::vector<//unsigned
//    long long>> list_of_synapses = std::make_unique<std::vector<
//          //  unsigned
//            long long>>();
     std::unique_ptr<std::vector<long long>> list_of_neurons = std::make_unique<std::vector<long long>>();
//########################################################################################################
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
//###########################################################################
  //  closeApp() ;
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
//           int chislo_oshibok_sinapsov=0;
//     std::cout << "читаем синапсы в вектор"<< std::endl;
//    QFile file2("/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt");
//       if (!file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
//      qDebug() << "Не удалось открыть файл!";
//                      }

//          // Создание текстового потока для чтения из файла
//           QTextStream in2(&file2);
//        while (!in2.atEnd()) {
//         QString line = in2.readLine();
//               bool ok;
//            long long value = line.toLongLong(&ok);
//                 if (ok) {
//                                     list_of_synapses->push_back(value);
//              } else
//                                 {
//                         //            qDebug() << "Не удалось преобразовать строку в число:" << line;
//                                 }
//    if (ok) {
//       //        qDebug() << "Преобразование в long long прошло успешно:";
//          //        qDebug() << "Значение:" << value;
//              } else {
//                         //        qDebug() << "Ошибка преобразования в long long:";
//qDebug() << "Строка не является числовой, или значение выходит за пределы long long: "<< line ;
//                                   chislo_oshibok_sinapsov++;
//                             }

//                             }
//                             // Закрытие файла
//                             file2.close();
//###########################################################################
                         std::ifstream is("/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt");
                          std::istream_iterator<unsigned long long> start(is), end;
                          std::vector<unsigned long long> list_of_synapses(start, end);
                          std::cout << "Read " << list_of_synapses.size() << " numbers" << std::endl;
//###########################################################################
 std::cout << "конец чтения синапсов в вектор"<< std::endl;
      std::cout << "//########################################################################################################"<< std::endl;
  //       std::cout << "число ошибок форматов синапсов = "<< chislo_oshibok_sinapsov<< std::endl;
      std::cout << "//########################################################################################################"<< std::endl;
//########################################################################################################
//########################################################################################################
//  if (chislo_oshibok_sinapsov!=0 || chislo_oshibok_neyronov!=0)
//      // если есть ошибки в форматах синапсов или нейронов останавливаем
// // программу
//        // Остановить выполнение программы
//                           {
//           exit(EXIT_SUCCESS);

//              }

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
/// решение
      b:

std::cout << "list_of_neurons->at(200)= "  <<list_of_neurons->at(200)  <<std::endl;

     if       (list_of_neurons->at(200)<0) goto d;
      if (variable_synapse_index_counter==0)variable_synapse_index_counter=10100;
          for ( var = 100;              // первый for
         var < 200

           ; ++var) // This is the range of neurons

          {
          //    if (list_of_neurons->at(200)<0) break;
              for ( neuron_index = 0, synapse_index = 0;

                /*,*/ synapse_index < 10100;
                  ++neuron_index, synapse_index = synapse_index + 100)

              { // // ошибка сегментации


              if (neuron_index < 200)

                  list_of_neurons->at(var)
//###########################################################################
                          =
                          list_of_neurons->at(var) //-5310911
                  +
                          (
                          (list_of_neurons->at(neuron_index)
                    //  /   // деление
                           -
                   list_of_synapses.at(synapse_index))
                              )
                              ; // + на -

              } //
              if       (list_of_neurons->at(200)<0) goto d;
          }
      //////////////////////
          for (int   neuron_index = 100, synapse_index = 10000;       // второй for

       synapse_index < 10100
       ;
            ++neuron_index, ++synapse_index)
          {
                    if (list_of_neurons->at(200)<0) break;

   //      if (list_of_synapses->at(synapse_index)!=0)
              list_of_neurons->at(200)
//###########################################################################
                      =
                      list_of_neurons->at(200) //-5310911
              +
                      (
                      (list_of_neurons->at(neuron_index)
                     //  / // деление
                       -
                       list_of_synapses.at(synapse_index))
                          )
              ; // + на -
     //    if       (list_of_neurons->at(200)<0) goto d;
      //   std::cout << "list_of_neurons->at(200)= "  <<list_of_neurons->at(200)  <<std::endl;
          }
   //         if       (list_of_neurons->at(200)<0) goto d;
//########################################################################################################
   variable_synapse_index_counter--;
//################################# конец решения ###################################################################
/////////////   показываем что определила программа
std::cout << "list_of_neurons->at(200)= "  <<list_of_neurons->at(200)  <<std::endl;
std::cout << "variable_synapse_index_counter= "  <<variable_synapse_index_counter  <<std::endl;
// list_of_synapses->at(variable_synapse_index_counter)
std::cout << "list_of_synapses->at("<<variable_synapse_index_counter<<")= "  <<list_of_synapses.at(variable_synapse_index_counter)  <<std::endl;
     if       (list_of_neurons->at(200)<0) goto d;
// list_of_synapses->at(synapse_index)
std::cout << "list_of_synapses->at(0)= "  <<list_of_synapses.at(0) <<std::endl;
/// подстройка //////////////////////////////////////////////////////////////////////////////////////////////
///
          if       (list_of_neurons->at(200)>=0) // если Программа считает что это не 1.
// начиная с variable_synapse_index_counter=10100 надо менять каждый синапс на 1
//              for (variable_synapse_index_counter=10100;variable_synapse_index_counter>-1;
//                   variable_synapse_index_counter--)
              {
  list_of_synapses.at(variable_synapse_index_counter)
          =
          list_of_synapses.at(variable_synapse_index_counter)
        - 1
      //  10
        // 9223372036854775807
      // 1459315198938531889
     // 859689765
          ;

//   if( list_of_synapses->at(0)<=-9223372036854775808)
// // exit(0);
//       goto d;
//   if( list_of_synapses->at(variable_synapse_index_counter)<-9223372036854775808)
//  exit(0);
   if( list_of_synapses.at(variable_synapse_index_counter)<0//-9223372036854775808
           )
       list_of_synapses.at(variable_synapse_index_counter)=0
             //  -9223372036854775808
               ;
  if (variable_synapse_index_counter==0 &&
     list_of_synapses.at(variable_synapse_index_counter)<=0
                      //  -9223372036854775808
          )
  {

      goto e;
  }
               if(variable_synapse_index_counter==0)variable_synapse_index_counter=10100;
               if(list_of_neurons->at(200)>=0)
                  goto b;
               if(list_of_neurons->at(200)<0)
                goto d;
              }
          else goto d;
e:
std::cout << "все синапсы пройдены, поставлены на минимумы и ошибка не пропала." << std::endl;

////  конец подстройки ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      d:
/////////////   показываем что определила программа
    if
      //  ( variable_error <=0)
        (list_of_neurons->at(200)<0)

    {
        ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это 1.");
        std::cout << "Программа считает что это 1."  <<std::endl;
       // Odin_Programmi=true;
        //   goto d;
    }
                           else {
        ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это не 1.");
         std::cout << "Программа считает что это не 1."  <<std::endl;
        //  Odin_Programmi=false;

    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
          // запишем синапсы
              // Имя файла для записи
//###########################################################################
           QString filename = "/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt";


 //   bool writeVectorToFile(const QVector<int>& vector, const QString& filename)
           QFile file3(filename);

           // Открываем файл для записи
           if (!file3.open(QIODevice::WriteOnly | QIODevice::Text)) {
               std::cerr << "Cannot open file for writing: " << qPrintable(file3.errorString()) << std::endl;

           }

           // Создаем текстовый поток для записи в файл
           QTextStream out(&file3);

           // Записываем каждый элемент вектора в файл
           for (const auto& number : list_of_synapses) {
               out << number << '\n';
           }

           // Сбрасываем буфер потока
           out.flush();

           // Закрываем файл после записи
           file3.close();
//#############bool readVectorFromFile(QVector<int>& vector, const QString& fileName)

           {//QVector<unsigned long long> readData;
           QFile file(filename);
           if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {

           }
           QTextStream in(&file);
           readData.clear();
           while (!in.atEnd()) {
               QString line = in.readLine();
               bool ok;
               int value = line.toULongLong(&ok);
               if (ok) {

                   readData.push_back(value);
               } else {

               }
           }
           file.close();

       }
//##############################################################
           if (list_of_synapses == readData) {
               QMessageBox::information(this, tr("Success"), tr("Vector successfully verified in file."));
           } else {
               QMessageBox::critical(this, tr("Error"), tr("Data in file does not match vector."));
           }

//###########################################################################
           QStringList mismatchIndices;
           for (size_t i = 0; i < list_of_synapses.size(); ++i) {
               if (list_of_synapses.at(i) != readData.at(i)) {
                   mismatchIndices << QString::number(i);
               }
           }
           if (mismatchIndices.isEmpty()) {
               QMessageBox::information(this, tr("Success"), tr("Vector successfully verified in file."));
           } else {
//               QMessageBox::critical(this, tr("Error"),
//                                     tr("Data in file does not match vector at indices: %1").arg(mismatchIndices.join(", ")));
 //       qDebug() << "Data mismatch at indices:" << mismatchIndices.join(", ");

//std::cout << "list_of_synapses[0] = "<<list_of_synapses[0]  <<std::endl;
//std::cout << "list_of_synapses[1] = "<<list_of_synapses[1]  <<std::endl;
           }

//###########################################################################
            //      std::cout << "Successfully wrote the vector to " << filename.toStdString() << std::endl;

                  // Sleep for 5 seconds
             //     std::this_thread::sleep_for(std::chrono::seconds(5));

                  qDebug() << "Program execution completed.";









}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_Dialog_finished(int result)
{
       closeApp() ;
}


void Dialog::on_Dialog_destroyed()
{
     closeApp() ;
}


void Dialog::on_Dialog_rejected()
{
     closeApp() ;
}


void Dialog::on_Dialog_destroyed(QObject *arg1)
{
     closeApp() ;
}

