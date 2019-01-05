#include "converter.hpp"

class Csv2Ts : public Converter
{
public:
    Csv2Ts() = delete;
    explicit Csv2Ts(std::string &&filename);

    void convert() override;
};
