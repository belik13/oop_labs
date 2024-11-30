//
// Created by bmaks on 29.11.2024.
//
#ifndef LAB_6_ELF_HPP
#define LAB_6_ELF_HPP

#pragma once

#include "npc.hpp"
#include "visitor.hpp"


class Elf : public NPC {
public:
    Elf(const std::string&, int, int);
    Elf(std::istream&);

    virtual bool accept(const std::shared_ptr<NPC>&) const override;

    void save(std::ostream&) override;

    friend std::ostream& operator<<(std::ostream&, Elf&);
};


#endif //LAB_6_ELF_HPP
