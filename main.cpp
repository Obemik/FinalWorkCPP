#include "lib.h"
#include "Library.h"
#include "UI.h"

int main() {
    Library library;
    UI ui;

    library.loadFromFile();

    while (true) {
        ui.showMenu();
        int option;
        cin >> option;
        ui.executeOption(option, library);

        library.saveToFile();
    }

    return 0;
}