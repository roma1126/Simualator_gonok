#include <iostream>
#include <string>
#include "Transport.h"
#include "Botinki.h"
#include "Camel.h"
#include "fast_Camel.h"
#include "Kentavr.h"
#include "Kover_samolet.h"
#include "Metla.h"
#include "Orel.h"


class Menu
{
public:
    Menu(){}

    void menu1() const
    {
        std::cout << "1. Гонка для наземного транспорта. " << std::endl
            << "2. Гонка для воздушного транспорта. " << std::endl
            << "3. Гонка для назменого и воздушного транспорта. " << std::endl
            << " Выберите тип гонки: ";
    };
    bool inf_menu1(std::string& str, int& game_type)
    {
        int game = 0;
        while (true)
        {
            menu1();
            std::cin >> game;
            if (std::cin.fail())
            {
                std::cout << "Неизвестный тип данных!" << std::endl;
                std::cin.clear();
                std::cin.ignore();
                continue;
            }
            if ((game != 1) && (game != 2) && (game != 3))
            {
                return false;
            }
            else
            {
                str = (game == 1) ? +"Гонка для назменого транспорта. " :
                    (game == 2) ? +"Гонка для воздушного транспорта. " : +"Гонка для назменого и воздушного транспорта. ";
                game_type = (game == 1) ? 1 :
                    (game == 2) ? 2 : 3;
            }
            break;
        }
        return true;
    }

    void menu2(std::string& str) const
    {
        std::cout << str << std::endl << "Укажите длину дистанции (должна быть положительная)" << std::endl;
    }
    bool inf_menu2(std::string& str, int& distance)
    {
        int game = 0;
        while (true)
        {
            menu2(str);
            std::cin >> game;
            if (std::cin.fail())
            {
                std::cout << "Неизвестный тип данных!" << std::endl;
                std::cin.clear();
                std::cin.ignore();
                continue;
            }
            if (game <= 0) 
            {
                return false;
            }
            else
            {
                distance = game;
                str = str + "Расстояние: " + std::to_string(distance) + " ";
                break;
            }
            
        }
        return true;
    }

    void menu3() const
    {
        std::cout << "Должно быть зарегистрировано минимум 2 транспортных стредства" << std::endl
            << "1. Зарегестрировать транспортное средство" << std::endl
            << "Выберите действие: ";
    }

    bool inf_menu3()
    {
        int game = 0;
        std::cin >> game;
        if (std::cin.fail())
        {
            std::cout << "Неизвестный тип данных!" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            return false;
        }
        if (game == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void menu4(std::string& str) const
    {
        std::cout << str << std::endl;
        std::cout <<
            "1. Ботинки-вездеходы" << std::endl
            << "2. Метла" << std::endl
            << "3. Верблюд" << std::endl
            << "4. Кентавр" << std::endl
            << "5. Орел" << std::endl
            << "6. Верблюд-быстроход" << std::endl
            << "7. Ковёр-самолёт" << std::endl
            << "0. Закончить регистрацию" << std::endl
            << "Выберите транспорт или 0 для окончания процесса регистрации:"<<std::endl;
    }

    bool inf_menu4(std::string& str, const int& distance, int& count, const int& game_type, std::string** transport)
    {
        while (true)
        {
            menu4(str);
            int game = 0;
            std::cin >> game;

            if (std::cin.fail())
            {
                std::cout << "Неизвестный тип данных!" << std::endl;
                std::cin.clear();
                std::cin.ignore();
                continue;
            }
            if (game == 0)
            {
                if (count > 1)
                {
                    return true;
                }
                else
                {
                    std::cout << "Недостаточно транспортных средств для начала гонки!" << std::endl;
                    continue;
                }
            }
            if (game == 1)
            {
                if (game_type == 2)
                {
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                    continue;
                }
                if (transport[0][2] != "1")
                {
                    Botinki bot_skorohod;
                    transport[0][1] = std::to_string(bot_skorohod.finish(distance));
                    str = str + " " + transport[0][0];
                    transport[0][2] = "1";
                    std::cout << transport[0][0] << " успешно зарегестрирован!" << std::endl;
                    count += 1;
                    continue;
                }
                else
                {
                    std::cout << transport[0][0] << " уже зарегестрирован" << std::endl;
                    continue;
                }
            }

            if (game == 2)
            {
                if (game_type == 1)
                {
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                    continue;
                }
                if (transport[1][2] != "1")
                {
                    Metla metla;
                    transport[1][1] = std::to_string(metla.finish(distance));
                    str = str + " " + transport[1][0];
                    transport[1][2] = "1";
                    std::cout << transport[1][0] << " успешно зарегестрирован!" << std::endl;
                    count += 1;
                    continue;
                }
                else
                {
                    std::cout << transport[1][0] << " уже зарегестрирован" << std::endl;
                    continue;
                }
            }

            if (game == 3)
            {
                if (game_type == 2)
                {
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                    continue;
                }
                if (transport[2][2] != "1")
                {
                    Camel camel;
                    transport[2][1] = std::to_string(camel.finish(distance));
                    str = str + " " + transport[2][0];
                    transport[2][2] = "1";
                    std::cout << transport[2][0] << " успешно зарегестрирован!" << std::endl;
                    count += 1;
                    continue;
                }
                else
                {
                    std::cout << transport[2][0] << " уже зарегестрирован" << std::endl;
                    continue;
                }
            }

            if (game == 4)
            {
                if (game_type == 2)
                {
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                    continue;
                }
                if (transport[3][2] != "1")
                {
                    Kentavr kentavr;
                    transport[3][1] = std::to_string(kentavr.finish(distance));
                    str = str + " " + transport[3][0];
                    transport[3][2] = "1";
                    std::cout << transport[3][0] << " успешно зарегестрирован!" << std::endl;
                    count += 1;
                    continue;
                }
                else
                {
                    std::cout << transport[3][0] << " уже зарегестрирован" << std::endl;
                    continue;
                }
            }

            if (game == 5)
            {
                if (game_type == 1)
                {
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                    continue;
                }
                if (transport[4][2] != "1")
                {
                    Orel orel;
                    transport[4][1] = std::to_string(orel.finish(distance));
                    str = str + " " + transport[4][0];
                    transport[4][2] = "1";
                    std::cout << transport[4][0] << " успешно зарегестрирован!" << std::endl;
                    count += 1;
                    continue;
                }
                else
                {
                    std::cout << transport[4][0] << " уже зарегестрирован" << std::endl;
                    continue;
                }
            }

            if (game == 6)
            {
                if (game_type == 2)
                {
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                    continue;
                }
                if (transport[5][2] != "1")
                {
                    fast_Camel fast_camel;
                    transport[5][1] = std::to_string(fast_camel.finish(distance));
                    str = str + " " + transport[5][0];
                    transport[5][2] = "1";
                    std::cout << transport[5][0] << " успешно зарегестрирован!" << std::endl;
                    count += 1;
                    continue;
                }
                else
                {
                    std::cout << transport[5][0] << " уже зарегестрирован" << std::endl;
                    continue;
                }
            }

            if (game == 7)
            {
                if (game_type == 1)
                {
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                    continue;
                }
                if (transport[6][2] != "1")
                {
                   Kover_samolet kover_samolet;
                    transport[6][1] = std::to_string(kover_samolet.finish(distance));
                    str = str + " " + transport[6][0];
                    transport[6][2] = "1";
                    std::cout << transport[1][0] << " успешно зарегестрирован!" << std::endl;
                    count += 1;
                    continue;
                }
                else
                {
                    std::cout << transport[6][0] << " уже зарегестрирован" << std::endl;
                    continue;
                }
            }

            if (game < 0 || game>8)
            {
                std::cout << "Неверный пункт меню" << std::endl;
                continue;
            }
            
        }
    }

    void menu5() const
    {
        std::cout << "1. Зарегестрировать транспорт" << std::endl
            << "2. Начать гонку" << std::endl
            <<"Выберите действие: ";
    }

    bool inf_menu5()
    {
        int game = 66;
        while (true)
        {
            std::cin >> game;
            if (std::cin.fail())
            {
                std::cout << "Неизвестный тип данных!" << std::endl;
                std::cin.clear();
                std::cin.ignore();
                continue;
            }
            if (game == 1)
            {
                return 1;
            }
            if (game == 2)
            {
                return 2;
            }
            else
            {
                std::cout << "Неверный пункт меню!" << std::endl;
                continue;
            }
        }
    }

    bool results(std::string** transport, int rows) const
    {
        std::cout << "Результаты гонки: " << std::endl;

        for (int i = 0; i < rows - 1;i++)
        {
            if (transport[i][2] == "1")
            {
                std::cout << transport[i][0] << " " << transport[i][1] << std::endl;
            }

        }
        std::cout << std::endl;
        return true;
    }

    int inf_menu6()
    {
        int game = 0;
        while (true)
        {
            std::cout << "1. Провести еще одну гонку" << std::endl
                << "2. Выйти" << std::endl;
            std::cin >> game;
            if (std::cin.fail())
            {
                std::cout << "Неизвестный тип данных!" << std::endl;
                std::cin.clear();
                std::cin.ignore();
                continue;
            }
            return game;
        }      
    }
};









int main()
{
    setlocale(LC_ALL, "Rus");

    int rows = 7;
    int cols = 3;

    std::string** p_transport = new std::string * [rows];
    std::string transport2[7] = { "Ботинки-вездеходы","Метла", "Верблюд", "Кентавр", "Орел", "Верблюд-быстроход", "Ковёр-самолёт" };

    for (int i = 0; i < rows - 1; i++)
    {
        p_transport[i] = new std::string[cols];
    }

    for (int i = 0; i < rows - 1; i++)
    {

        p_transport[i][0] = transport2[i];
    }

    std::string str;


    int distance = 0;
    int count = 0; 
    int game_type = 0;

    std::cout << "Добро пожаловать в гоночный симулятор! " << std::endl;

    while (true)
    {
        int game = 0;

        Menu menu;

        while (true)
        {
            if (menu.inf_menu1(str, game_type))
            {
                std::cout << std::endl;
                break;
            }
            else
            {
                std::cout << "Неизвестный тип гонки!" << std::endl;
            }
        }

        while (true)
        {
            if (menu.inf_menu2(str, distance))
            {
                std::cout << std::endl;
                break;
            }
            else
            {
                std::cout << "Дистанция не соответсвует условиям!"<<std::endl;
            };

        }

        while (true)
        {
            menu.menu3();
            if (menu.inf_menu3())
            {
                std::cout << std::endl;
                break;
            };
        }

        while (true)
        {

            if (menu.inf_menu4(str, distance, count, game_type, p_transport))
            {
                std::cout << std::endl;
                break;
            }
            else
            {
                std::cout << "Неверный пункт меню! " << std::endl;
            };
        }

        while (true)
        {

            menu.menu5();

            unsigned game_int = 66;
            game_int = menu.inf_menu5();

            if (game_int == 1)
            {
                std::cout << std::endl;
                break;
                
            }
            else if (game_int == 2)
            {
                menu.inf_menu4(str, distance, count, game_type, p_transport);
            }

        }

        while (true)
        {
            if (menu.results(p_transport, rows))
            {
                break;
            };
        }

        while (true)
        {
            int game_int = (menu.inf_menu6());

            if (game_int == 1)
            {
                for (int i = 0; i < rows - 1; i++)
                {
                    p_transport[i][1] = "0";
                    p_transport[i][2] = "0";
                }
                count = 0;
                distance = 0;
                game = 0;
                str = "";
                game_type = 0;
                break;
            }
            else if (game_int == 2)

            {
                for (int i = 0; i < rows - 1; i++)
                {
                    delete[]p_transport[i];
                }
                return 0;
            }
            else
            {
                std::cerr << "Неверный пунки меню! " << std::endl;
                continue;
            }
            break;
        }
    }
    return 0;
}
