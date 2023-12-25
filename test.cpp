#include<bits/stdc++.h>
using namespace std;
class Test{
    private:
        int num=0;
        struct _data{
            int data1;
            char data2;
            string data3;
        };
        _data *data=new _data[0];
    public:
        void add_ele(int d1,char d2,string d3){
            _data *tmp=new _data[num+1];
            for(int a=0;a<num;a++){
                tmp[a]=data[a];
            }
            tmp[num].data1=d1;
            tmp[num].data2=d2;
            tmp[num].data3=d3;
            delete[] data;
            num++;
            data=new _data[num];
            for(int a=0;a<num;a++){
                data[a]=tmp[a];
            }
            delete[] tmp;
        }
        void dump_ele(){
            for(int a=0;a<num;a++){
                cout<<endl;
                cout<<data[a].data1<<endl;
                cout<<data[a].data2<<endl;
                cout<<data[a].data3<<endl;
            }
        }
        void init_ele(){
            delete[] data;
            num=0;
            data=new _data[0];
        }
        ~Test(){
            delete[] data;
        }
};
int main(){
    Test test1;
    test1.add_ele(1,'A',"Hello");
    test1.add_ele(2,'B',"ddd");
    test1.dump_ele();
    test1.init_ele();
    test1.dump_ele();
}