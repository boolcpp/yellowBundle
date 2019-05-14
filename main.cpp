#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

enum class Lang {
  DE, FR , IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};

bool operator==(const Region& Lreg, const Region& Rreg){
  return tie(Lreg.std_name, Lreg.parent_std_name, Lreg.names, Lreg.population) ==
         tie(Rreg.std_name, Rreg.parent_std_name, Rreg.names, Rreg.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions)
{
 // map<Region&, int> mp;
  int max = 0;
  for(const auto& x : regions){
      int count = 0;
      for( const auto& y : regions){
          if(x == y){++count;}
        }
      if(count > max){max = count;}
    }

  return  max;
}

int main()
{
  return 0;
}
