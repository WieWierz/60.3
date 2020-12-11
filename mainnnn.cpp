#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int nwd(int x, int y)
{
    if (x < y)
        return nwd(y, x);
    if (y == 0)
        return x;
    return nwd(y, x%y);
}

struct liczby
{
int liczba;
};

struct liczby2
{
int liczba2;
};

class collection
{
    vector <struct liczby> zbior;
    vector <struct liczby2> zbior2;
    
  public:
      void file_read();
      void show();
      void licz();
      void znajdz_max();
};

void collection::show()
{
    for (vector<struct liczby>::iterator it = zbior.begin(); it != zbior.end(); ++it)
		{
			cout << it->liczba <<endl;
		}
}

void collection::file_read()
{
    ifstream fileIn;
    fileIn.open("liczby.txt");
	int licz;
    if(fileIn.good()){
    	while( getline(fileIn, licz) )
               zbior.push_back(licz);
    		
		}
	}
}

void collection::licz()
{
	for(int m=0;m<200;m++){
	int k=0;
	for(int i=0;i<200;i++){
		if(nwd(zbior[k],zbior[i])==1){
			zbior2.push_back(zbior[k]);
		}
	}
	k++;
}
}

void collection::znajdz_max()
{
	max = zbior2[0]; 
	
	for(int i=1;i<200;i++)
		if(max<zbior2[i])
			max = zbior2[i];
	cout<<max;
}

int main(int argc, char** argv) {

    collection numbers;
    numbers.file_read();
    numbers.show();
    numbers.licz();
    numbers.znajdz_max();
    
       return 0;
}
