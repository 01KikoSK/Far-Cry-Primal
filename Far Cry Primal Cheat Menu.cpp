#include <iostream>

enum Cheats {
    GOD_MODE,
    INFINITE_AMMO,
    MAX_HEALTH,
    NUM_CHEATS
};

void printCheatMenu() {
    std::cout << "Cheat Menu:\n";
    std::cout << "1. God Mode\n";
    std::cout << "2. Infinite Ammo\n";
    std::cout << "3. Max Health\n";
    std::cout << "4. Exit\n";
}

bool isValidOption(int option) {
    return option >= 1 && option <= NUM_CHEATS;
}

void applyCheat(Cheats cheat, bool enable) {
    switch (cheat) {
        case GOD_MODE:
            std::cout << "God mode " << (enable ? "enabled" : "disabled") << ".\n";
            break;
        case INFINITE_AMMO:
            std::cout << "Infinite ammo " << (enable ? "enabled" : "disabled") << ".\n";
            break;
        case MAX_HEALTH:
            std::cout << "Max health " << (enable ? "enabled" : "disabled") << ".\n";
            break;
        default:
            std::cout << "Invalid cheat.\n";
    }
}

int main() {
    int option;
    bool enable;
    Cheats cheat;

    while (true) {
        printCheatMenu();
        std::cin >> option;

        if (!isValidOption(option)) {
            std::cout << "Invalid option. Try again.\n";
            continue;
        }

        switch (option) {
            case 1:
                cheat = GOD_MODE;
                break;
            case 2:
                cheat = INFINITE_AMMO;
                break;
            case 3:
                cheat = MAX_HEALTH;
                break;
            case 4:
                return 0;
            default:
                std::cout << "Something went wrong. Exiting...\n";
                return 1;
        }

        std::cout << "Enable cheat? (1 for yes, 0 for no): ";
        std::cin >> enable;

        applyCheat(cheat, enable);
    }

    return 0;
}