#pragma once

#include <string>

class IStoper
{
    public:
    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual double getElapsedTime() = 0;
    virtual void dumpToFile(std::string const&) = 0;
};

