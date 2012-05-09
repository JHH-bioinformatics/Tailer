#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include"sequences.hpp"
int main ()
{
  Sequences<int>                    h1;
  Sequences<int, std::deque>        h2;
  Sequences<std::string, std::list> h3;
}
