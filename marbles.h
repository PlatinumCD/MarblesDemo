#ifndef MARBLES_H
#define MARBLES_H

#include <string>
#include <sst/core/subcomponent.h>

namespace SST {
namespace MarblesDemo {

class Marble : public SubComponent {
public:
    SST_ELI_REGISTER_SUBCOMPONENT_API(
        SST::MarblesDemo::Marble
    )

    Marble(ComponentId_t id, Params& params) : SubComponent(id), comp_id(id) {}
    virtual void print(SST::Output *output) {}

    ComponentId_t comp_id;
};


template<typename T>
class LargeMarble : public Marble {
public:
    SST_ELI_REGISTER_SUBCOMPONENT_DERIVED_API(
        SST::MarblesDemo::LargeMarble<T>,
        SST::MarblesDemo::Marble
    )

    LargeMarble(ComponentId_t id, Params& params) : Marble(id, params) {}

    virtual void print(SST::Output *output) override {
        std::string template_type;

        if (std::is_same<T, float>::value) template_type = "float";
        if (std::is_same<T, int>::value) template_type = "int";

        output->output("\tLargeMarble(%ld) is templated with type %s\n", comp_id, template_type.c_str());
    }
};

template<typename T>
class SmallMarble : public Marble {
public:
    SST_ELI_REGISTER_SUBCOMPONENT_DERIVED_API(
        SST::MarblesDemo::SmallMarble<T>,
        SST::MarblesDemo::Marble
    )

    SmallMarble(ComponentId_t id, Params& params) : Marble(id, params) {}
    virtual void print(SST::Output *output) override {
        std::string template_type;

        if (std::is_same<T, float>::value) template_type = "float";
        if (std::is_same<T, int>::value) template_type = "int";

        output->output("\tSmallMarble(%ld) is templated with type %s\n", comp_id, template_type.c_str());
    }
};

class SmallIntMarble : public SmallMarble<int> {
public:
    SST_ELI_REGISTER_SUBCOMPONENT(
        SmallIntMarble,
        "MarblesDemo",
        "SmallIntMarble",
        SST_ELI_ELEMENT_VERSION(1, 0, 0),
        "Implements the SmallMarble derivation of a Marble",
        SST::MarblesDemo::SmallMarble<int>
    )

    SmallIntMarble(ComponentId_t id, Params& params) : SmallMarble<int>(id, params) {}
};

class SmallFloatMarble : public SmallMarble<float> {
public:
    SST_ELI_REGISTER_SUBCOMPONENT(
        SmallFloatMarble,
        "MarblesDemo",
        "SmallFloatMarble",
        SST_ELI_ELEMENT_VERSION(1, 0, 0),
        "Implements the SmallMarble derivation of a Marble",
        SST::MarblesDemo::SmallMarble<float>
    )

    SmallFloatMarble(ComponentId_t id, Params& params) : SmallMarble<float>(id, params) {}
};

class LargeIntMarble : public LargeMarble<int> {
public:
    SST_ELI_REGISTER_SUBCOMPONENT(
        LargeIntMarble,
        "MarblesDemo",
        "LargeIntMarble",
        SST_ELI_ELEMENT_VERSION(1, 0, 0),
        "Implements the LargeMarble derivation of a Marble",
        SST::MarblesDemo::LargeMarble<int>
    )

    LargeIntMarble(ComponentId_t id, Params& params) : LargeMarble<int>(id, params) {}
};

class LargeFloatMarble : public LargeMarble<float> {
public:
    SST_ELI_REGISTER_SUBCOMPONENT(
        LargeFloatMarble,
        "MarblesDemo",
        "LargeFloatMarble",
        SST_ELI_ELEMENT_VERSION(1, 0, 0),
        "Implements the LargeMarble derivation of a Marble",
        SST::MarblesDemo::LargeMarble<float>
    )

    LargeFloatMarble(ComponentId_t id, Params& params) : LargeMarble<float>(id, params) {}
};


} // namespace MarblesDemo
} // namespace SST

#endif // MARBLE_H
