import sst
import random

num_marbles = 10

marbles_bag_params = {
    "maxMarbles": num_marbles
}

# Create an instance of the MarblesBag component
marbles_bag = sst.Component("marbles_bag", "MarblesDemo.MarblesBag")
marbles_bag.addParams(marbles_bag_params)

marble_types = [
    "MarblesDemo.SmallIntMarble",
    "MarblesDemo.SmallFloatMarble",
    "MarblesDemo.LargeIntMarble",
    "MarblesDemo.LargeFloatMarble"
]

# Add marbles to the component's subcomponent slots
for i in range(num_marbles):
    marble_type = random.choice(marble_types)
    marble = marbles_bag.setSubComponent("marbleSlot", marble_type, i)
