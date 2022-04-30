#include "RunGame.h"
#include <windows.h>

using namespace std;

int main() {
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h,5);
        cout << "==========WELCOME TO THE DUELIST REALM==========" << endl;
        SetConsoleTextAttribute(h,3);
        cout << endl;

        cout << "          *******            *******            " << endl <<
                "          *********          *********          " << endl <<
                "          ***   *****        ***   ***          " << endl <<
                "          ***    *****       ********           " << endl <<
                "          ***   *****        ***  ***           " << endl <<
                "          *********          ***   ***          " << endl <<
                "          *******            ***    ***         " << endl;

        cout << endl;
    SetConsoleTextAttribute(h,5);
        cout << "THE THREE MIGHTY NATIONS OF DWARF, HUMAN AND ELF, HAVE NEVER LIVED IN PEACE " << endl
             << "THEIR WORLDS SCORCHED BY WAR AND KILLING HAS BEEN GOING ON FOR FAR TOO LONG " << endl
             << "THE DUELIST REALM WAS CREATED UNDER AN AGREEMENT FROM ALL THREE NATIONS TO RESOLVE THIS" << endl
             << "EACH NATION SHALL SEND THEIR TOUGHEST AND STRONGEST FIGHTERS TO TAKE PART IN A BATTLE TO THE DEATH"
             << endl
             << "THE REIGNING VICTOR SHALL EARN THEIR NATION THE POWER TO RULE ALL THE LANDS" << endl
             << "AND THIS VICTOR SHALL BE ANNOUNCED CHAMPION OF THE DUELIST REALM!" << endl;
    SetConsoleTextAttribute(h,1);
    //system("Color 03");

    cout << endl;
    RunGame game;
}
