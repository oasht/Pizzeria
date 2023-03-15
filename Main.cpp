#include "Header.h"
#pragma once

int main()
{

    Product* p_d = new Adapter_dollar(new Dollar);
    vector<Pizza*> v;
    double total = 0;

    system("color F0");
    const int num_menu = 3;
    int ch = 0, active_menu = 0;
    bool q;
    cout << "Please choose pizzas for you order!" << endl;
    Sleep(2000);
    do
    {
        bool exit = false;
        while (!exit)
        {
           
            show_menu();
            gotoxy(0, active_menu);
            ch = _getch();
            if (ch == 224) ch = _getch();
            switch (ch)
            {

            case 27: exit = true; break;
            case 72: active_menu--; break;
            case 80: active_menu++; break;
            case 13:

                if (active_menu == 0)
                {

                    system("cls");
                    v.push_back(create_Margherita());
                }
                else if (active_menu == 1)
                {
                    system("cls");
                    v.push_back(create_Ham_and_Mushrooms());

                }
                else if (active_menu == 2)
                {
                    system("cls");
                    v.push_back(create_Seafood());
                }
                break;
            }
            if (active_menu < 0) active_menu = num_menu - 1;
            if (active_menu > num_menu - 1) active_menu = 0;

        }
        system("cls");
        cout << "If you want to add one more pizza press 1, no - 0" << endl;
        cin >> q;
        system("cls");
    } while (q == 1);
    system("cls");
    Final(v, p_d);

    return 0;
}
