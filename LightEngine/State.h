#pragma once

class Plant;

class State {
public:
    virtual ~State() = default;
    virtual void Start(Plant* plant) = 0;
    virtual void Update(Plant* plant) = 0;
};
