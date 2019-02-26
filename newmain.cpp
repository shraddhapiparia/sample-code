#include <iostream>
using namespace std;

int main(){

	cout<<"Inside main\n";
	enum Status{A,U};
	typedef Status* SAP;
	SAP *brd = new SAP[6];
	for(int i=0;i<6;i++){
		brd[i]= new Status[4];
	}
	int b[6][4], count = 0;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<4;j++)
		{
			b[i][j]=count++;
			brd[i][j] = A;
		}
	}
	for(int i=0;i<6;i++)
        {
                for(int j=0;j<4;j++)
                {
                       cout<< b[i][j] << " ";
			cout<< brd[i][j] << " ";
                }
		cout <<"\n";
        }
	return 0;
}
