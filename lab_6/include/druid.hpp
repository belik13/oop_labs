//
// Created by bmaks on 29.11.2024.
//

#ifndef LAB_6_DRUID_HPP
#define LAB_6_DRUID_HPP

#pragma once

#include "npc.hpp"
#include "visitor.hpp"


class Druid : public NPC {
public:
    Druid(const std::string&, int, int);
    Druid(std::istream&);

    virtual bool accept(const std::shared_ptr<NPC>&) const override;

    void save(std::ostream&) override;

    friend std::ostream& operator<<(std::ostream&, Druid&);
};


#endif //LAB_6_DRUID_HPP
