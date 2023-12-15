#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
using namespace std;

enum StudyLvl{
  Low,
  Medium,
  High
};

enum Jobs {
  Homeless,
  CoalWorker,
  Policeman,
  Programmer
};

enum Permissions {
  default_user,
  admin
};

enum BankStatus { 
  Disabled,
  Enabled
};

class Bank { // Сам банк
  public:
    int Bank_Balance = 0;
    int Status() { 
      return Bank_Status;
    }
    void SetStatus(BankStatus status) {
      this->Bank_Status = status;
    }
  private:
    BankStatus Bank_Status = Enabled;
};
//dsadas
class User { // Пользователь - самый распространенный класс
public: 
    uint32_t balance = 0;
    uint32_t deposit = 0;
    int studylvl = study;
    int worksi = work;
    int id;
    string username;
    void BalanceUp(int money) {
      this->balance += money;
    }
    int BalanceShow() {
      return balance;
    }
    int DepositUp(int money) {
      this->deposit += money;
      return deposit;
    }

    void ChooseWork(int _worknum) {
      switch(_worknum) {
        case 0:
          worksi = 0;
          cout << endl << "Вы: " <<worksi << endl;
        case 1:
          worksi = 1;
          cout << endl << "Вы: " <<worksi << endl;
        case 2:
          worksi = Jobs::Policeman;
        case 3:
          worksi = Jobs::Programmer;
      }
    }
    
    void ShowWork() {
      switch(worksi) {
        case 0:
          cout << "Вы бездомный" << endl;
        case 1:
          cout << "Вы шахтер" << endl;
        case 2:
          cout << "Вы полицейский" << endl;
        case 3:
          cout << "Вы программист" << endl;
      }
    }


    void StudyUp(int days, int choose_study) {
      if (days <= 10) {
      string result = "Процесс идет";
      if (choose_study == 2){
        if (balance < 30) {
          cout << endl <<"У вас не хватает: " << 30 - balance << "$" << endl;
          return;
        }
        studylvl = StudyLvl::Medium;
      }
      if (choose_study == 1){
        if (balance < 50) {
          cout << endl <<"У вас не хватает: " << 50 - balance << "$" << endl;
          return;
        }
        studylvl = StudyLvl::High;
      }
      do {
        result.push_back('.');
        days -= 1;
        cout << endl << result;
        std::chrono::seconds timespan(1);
        std::this_thread::sleep_for(timespan);
      }
      while (days > 0);
    } if (days > 10) {
      cout << "Максимум для обучения 10 дней!";
    } else {
      cout << endl << "Вы подняли свое образование до " << (study == 1 ? "Среднего" : "Высшего") << endl;
    }
  }
  private:
    Permissions perm = default_user;
    string prefix = "[User]";
    StudyLvl study = Low;
    Jobs work = Homeless;
};

class Admin : public User { // Админ - самый недоработанный класс :)
public:
    void BalanceBan(int user_id) {
      cout << "User " << user_id << " banned" << endl;
    }
private:
    Permissions perm = admin;
    string prefix = "[Admin]";
};

void Menu() {cout << endl << "Добро пожаловать в меню нашего приложения 'Bank'! Версия 1.1" << endl;
      cout << "Что вы хотите сделать?" << endl << "1 - Пополнить баланс  2 - Показать баланс  3 - Забанить пользователя(-В разработке-)  4 - Выйти из программы" 
      << endl << "5 - Получить статус банка  6 - Установить статус банку  7 - Увеличить уровень обучения  8 - Выбрать работу" << endl;}


struct UDType {
  int a = 5;
};

int main() {
  User user;
  Admin admin;
  Bank bank;
  char menu_selector;
  char exit;
    do {
      Menu();
      cin >> menu_selector;
      switch (menu_selector)
      {
      case '1':
        long money;
        cout << endl <<"Сколько вы хотите положить на счет?" << endl;
        cin >> money;
        user.BalanceUp(money);
        break;
      case '2':
        cout << endl << "Ваш баланс: " << user.BalanceShow() << endl;
        break;
      case '3':
        cout << endl << "Раздел в разработке" << endl;
        break;
      case '4':
        exit = 1;
        break;
      case '5':
        cout << endl << "Статус банка: " << ((bank.Status() == 1) ? ("Enabled") : ("Disabled")) << endl; // Проверяем статус банка и при 1 выдаем строковое значение "Enabled" в других случаях "Disabled"
        break;
      case '6':
        char num;
        cout << endl << "Какой статус установить?" << endl << "1 - Включить  2 - Выключить" << endl;
        cin >> num;
        switch (num) {
          case '1':
            bank.SetStatus(BankStatus::Enabled);
            break;
          case '2':
            bank.SetStatus(BankStatus::Disabled);
            break;
          default:
            cout << "Команда введена неверно" << endl;
            break;
        }
        break;
      case '7': // Учеба
        int _days;
        int _choose_study;
        cout << endl << "Введите кол-во дней(Максимум: 10  Минимум: 1): ";
        cin >> _days;
        cout << endl << "Какой уровень образования вы хотите: " << endl << "1 - Высшее (ТРЕБУЕТСЯ 50$)" << endl << "2 - Среднее (ТРЕБУЕТСЯ 30$)";
        cin >> _choose_study;
        user.StudyUp(_days, _choose_study);
        break;
      case '8': // Работа
        int worknum;
        cout << endl << "Какую работу вы хотите? " << endl << "0 - Безработный  1 - Шахтер  2 - Полицейский  3 - Программист" << endl;
        cin >> worknum;
        user.ChooseWork(worknum);
        user.ShowWork();
    }
  }
  while (exit != 1);
}












  //system("start cmd.exe");
  //system("start program.exe"); He-he-he