#include <iostream>
#include <fstream>
#include <string>
#include <vector>

////////////////////
//
// Matt Fernandez 2014
//
// l3acon@gmail.com
//
// for best breakfast compile with -O3
//

using namespace std;

static unsigned int eggs(unsigned int n)
{
  return (n >= 1000000000u) ? 9 : (n >= 100000000u) ? 8 : 
	(n >= 10000000u) ? 7 : (n >= 1000000u) ? 6 : 
	(n >= 100000u) ? 5 : (n >= 10000u) ? 4 :
	(n >= 1000u) ? 3 : (n >= 100u) ? 2 : (n >= 10u) ? 1u : 0u; 
}

// include a backery to make faster
inline void toast(vector<string> &cng, unsigned int to)
{
  while( cng.size() < to)
	cng.push_back(to_string( cng.size() ));
}

void link_sausage(char* in, int size, vector<char> &out, char* key, const int keysize, vector<string> &count)
{
  int curr = 0;

  for(long i = 0; i < size - keysize; ++i)
  {
	out.push_back(in[i]);
	for(int j = 0; j < keysize + 1; ++j)
	{
	  if(j == keysize)
	  {
		if(count.size() < curr)
		  toast(count, count.size() << 1);
		curr ++;
		for(int k = 1; k < keysize; ++k)
		  out.push_back(in[i+k]);
		i += keysize - 1;
		out.push_back('(');
		for(int k = 0; k < count[curr].size(); ++k)
		  out.push_back(count[curr][k]);
		out.push_back(')');
	  }
	  if(key[j] != in[j+i])
		break;
	}
  }
}

int main(int argc, char**argv)
{
  if( argc <= 2)
  {
	cout<<"Specify text file and key\n";
	return -1;
  }

  ifstream ifile(argv[1]);
  string key = argv[2];

  if(!ifile)
  {
	cout<<"Invalid filename\n"; 
	return -1;
  }	

  char* window = new char[key.size()];
  for(int i = 0; i < key.size(); ++i)
	window[i] = key[i];

  ifile.seekg(0, ifile.end);
  long size = ifile.tellg();
  ifile.seekg(0);

  char* contents = new char[size]; 	
  ifile.read(contents, size);
  ifile.close();
  
  vector<char> duf;
  vector<string> cnt;
  toast(cnt, size >> 5);

  link_sausage(contents, size, duf, window, key.size(), cnt);
  
  ofstream ofile(argv[1]);
  ofile.write(duf.data(), duf.size());
  ofile.close();
}


