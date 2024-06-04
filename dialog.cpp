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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QString    Nazvaniye_fayla_s_neyronami_i_signalom="";
long long variable_error;
int var ;
int variable_synapse_index_counter=0;
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
           /// Читает нейроны и сигнал из файла в вектор.
             std::ifstream is(
                   Nazvaniye_fayla_s_neyronami_i_signalom.toUtf8().constData()
                 );
             std::istream_iterator<unsigned long long> start(is), end;
             std::vector<unsigned long long> list_of_neurons(start, end);
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
















}

Dialog::~Dialog()
{
    delete ui;
}

