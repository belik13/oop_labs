//
// Created by bmaks on 29.11.2024.
//

#ifndef LAB_7_ELF_HPP
#define LAB_7_ELF_HPP


#pragma once

#include "npc.hpp"
#include "visitor.hpp"


class Elf : public NPC {
public:
    Elf(const std::string&, int, int);
    Elf(std::istream&);

    virtual bool accept(const std::shared_ptr<NPC>&) const override;

    virtual int get_move_distance() {
        return 3;
    }

    void save(std::ostream&) override;

    friend std::ostream& operator<<(std::ostream&, Elf&);
};


#endif //LAB_7_ELF_HPP
