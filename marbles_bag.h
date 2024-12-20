#ifndef MARBLES_BAG_H
#define MARBLES_BAG_H

#include <vector>
#include <sst/core/component.h>
#include <sst/core/subcomponent.h>
#include <sst/elements/MarblesDemo/marbles.h>

namespace SST {
namespace MarblesDemo {

class MarblesBag : public Component {
public:
    SST_ELI_REGISTER_COMPONENT(
        MarblesBag,
        "MarblesDemo",
        "MarblesBag",
        SST_ELI_ELEMENT_VERSION(1,0,0),
        "A component that holds marbles",
        COMPONENT_CATEGORY_UNCATEGORIZED
    )

    SST_ELI_DOCUMENT_PARAMS(
        {"max_marbles", "The maximum number of marbles that can be held in the bag", "10"}
    )

    SST_ELI_DOCUMENT_SUBCOMPONENT_SLOTS(
        {"marbleSlot", "Slot to load a marble subcomponent", "SST::MarblesDemo::Marble"}
    )

    MarblesBag(ComponentId_t id, Params& params) : Component(id) {
        output = new SST::Output("MarblesBag", 1, 0, SST::Output::STDOUT);
        int maxMarbles = params.find<int>("max_marbles", 10);
        SubComponentSlotInfo* info = getSubComponentSlotInfo("marbleSlot");
        if (info) { // at least one SubComponent was loaded
            int maxSlot = info->getMaxPopulatedSlotNumber();
            int marbleLimit = std::min(maxSlot + 1, maxMarbles);
            marbles.resize(marbleLimit);
            for (int i = 0; i < marbleLimit; i++) {
                if (info->isPopulated(i)) { // check for holes in the vector
                    marbles[i] = info->create<Marble>(i, ComponentInfo::SHARE_NONE);
                }
            }
        }
        
        output->output("\nMarble Bag Inventory:\n\n");
        for (int i = 0; i < marbles.size(); i++) {
            marbles[i]->print(output);
        }
        output->output("\n");
    }

private:
    std::vector<Marble*> marbles;
    SST::Output *output;
};

} // namespace MarblesDemo
} // namespace SST

#endif // MARBLES_BAG_H
