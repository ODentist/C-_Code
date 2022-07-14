#include<iostream>
#include<string>
using namespace std;
class Building
{   
    friend void goodgay(Building *building);
    public:
    Building()
    {
        m_BedRoom="bedroom";
        m_SittingRoom="sitting room";
    }
    public:
    string m_SittingRoom="sitting room";
    private:
    string m_BedRoom="bedroom";
};
//全局函数
void goodgay(Building *building)
{
   cout<<"goodguy is visiting the "<<building -> m_SittingRoom<<endl;
   cout<<"goodguy is visiting the "<<building -> m_BedRoom<<endl;
}
void test()
{
    Building building;
    goodgay(&building);
}
int main()
{
    test();
    system("pause");
    return 0;
}