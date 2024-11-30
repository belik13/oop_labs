//
// Created by bmaks on 29.11.2024.
//

#ifndef LAB_6_OBSERVER_HPP
#define LAB_6_OBSERVER_HPP

#include "npc.hpp"


class TextObserver : public Observer {
private:
    TextObserver() {};

public:
    static std::shared_ptr<Observer> get() {
        static TextObserver instance;
        return std::shared_ptr<Observer>(&instance, [](Observer*) {});
    }

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override {
        if (win) {
            std::cout << '\n' << "Murder --------" << '\n' << "killer: " << *attacker << '\n' << "victim: " << *defender;
        }
    }
};


class FileObserver : public Observer {
private:
    FileObserver() {};

public:
    static std::shared_ptr<Observer> get() {
        static FileObserver instance;
        return std::shared_ptr<Observer>(&instance, [](Observer*) {});
    }

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override {
        if (win) {
            std::ofstream fs("log.txt", std::ios::app);
            fs << '\n' << "Murder --------" << '\n' << "killer: " << *attacker << '\n' << "victim: " << *defender;
            fs.close();
        }
    }
};

#endif //LAB_6_OBSERVER_HPP
