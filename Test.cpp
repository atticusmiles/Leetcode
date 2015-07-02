// string constructor
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

int main ()
{
  string s0 ("Initial string");

  // constructors used in the same order as described above:
  string s1;
  string s2 (s0);
  string s3 (s0, 8, 3);
  string s4 ("A character sequence", 6);
  string s5 ("Another character sequence");
  string s6 (10, 'x');
  string s7a (10, 42);
  string s7b (s0.begin(), s0.begin()+7);

  unordered_map <char,int> ump= {{'I',1},{'V',5}};

  ump.insert(pair<char,int>('X',10));
  // ump['X']=10;
  // ump.erase('X');
  cout<<ump['X']<<endl;
  // cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
  // cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6: " << s6;
  // cout << "\ns7a: " << s7a << "\ns7b: " << s7b << endl;
  while(1);
  return 0;
}