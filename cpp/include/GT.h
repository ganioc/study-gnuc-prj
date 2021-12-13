#pragma once

using namespace std;
class GT_cls
{
  public:
    GT_cls(size_t val = 0) : bound(val) {}
    bool operator()(const string &s)
    {
        return s.size() >= bound;
    };

  private:
    std::string::size_type bound;
};

