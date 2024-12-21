# SST MarblesDemo Element

This demo illustrates the flexibility and extensibility of SST SubComponents by showcasing a hierarchical and templated component structure. It demonstrates how to create, extend, and register subcomponents within the SST framework.

The use of templating and inheritance in SST development allows developers to create flexible and reusable components that can be easily extended and customized for different data types, enhancing code efficiency and reducing maintenance efforts.


Here we create a SubComponent API called `Marble`:
```
class Marble : public SubComponent {
public:
    SST_ELI_REGISTER_SUBCOMPONENT_API(
        SST::MarblesDemo::Marble
    )

    Marble(ComponentId_t id, Params& params) : SubComponent(id) {}
};
```

Building on `Marble`, we create a hierarchical structure by developing a templated derivation. This allows for the creation of subcomponents that can be specialized for different data types, enhancing code reusability and flexibility:
```
template<typename T>
class SmallMarble : public Marble {
public:
    SST_ELI_REGISTER_SUBCOMPONENT_DERIVED_API(
        SST::MarblesDemo::SmallMarble<T>,
        SST::MarblesDemo::Marble
    )

    SmallMarble(ComponentId_t id, Params& params) : Marble(id, params) {}
};
```

We implement and register the `SmallMarble<T>` as `SmallIntMarble`, demonstrating the process of component registration in SST. This step is crucial for integrating new components into the SST framework and ensuring they are recognized and usable within simulations:
```
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
```

## Components

- **MarblesBag**: A component that acts as a container for marbles. It has a parameter to specify the maximum number of marbles it can hold.

- **Marble Types**: The script defines several types of marbles:
  - `SmallIntMarble`
  - `SmallFloatMarble`
  - `LargeIntMarble`
  - `LargeFloatMarble`

  These types are derived from a base class `Marble`, allowing them to be used interchangeably within the bag.

## How It Works

1. **Setup**: The script imports necessary libraries and sets the number of marbles to 10.

2. **Component Creation**: It creates an instance of the `MarblesBag` component and sets its parameters.

3. **Random Selection**: The script randomly selects a marble type for each slot in the bag and adds it as a subcomponent.

4. **Inheritance and Polymorphism**: The use of inheritance allows all marble types to be treated as `Marble` objects, ensuring compatibility with the `MarblesBag`.

