#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
   ifstream fin;
   fin.open("uvatourdefrance.txt");
   if(!fin){
    cerr<<"error"<<endl;
    return 1;
   }

   int f,r,k;
   int fv[50],rv[50];
   double ratio[100];

   while(fin>>f>>r){
    for(int i=0;i<f;i++)
        fin>>fv[i];

    for(int i=0;i<r;i++)
        fin>>rv[i];

    k=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<f;j++){
            ratio[k]=(double)rv[i]/(double)fv[j];
            k++;
        }
    }
    sort(ratio,ratio+k);

    double maxs=-1;
    for(int i=0;i<k-1;i++){
        maxs=max(maxs,ratio[i+1]/ratio[i]);
    }
        cout<<maxs<<endl;
   }
for(int i=0;i<k;i++)
    cout<<ratio[i]<<endl;
    return 0;
}
