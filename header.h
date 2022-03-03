#ifndef __HEADER_H__
#define __HEADER_H__
namespace CONST_VAR
{
    enum
    {
        nameLength = 20,
        replyLength = 100,
    };
}

class me //메세지를 보낼 사람
{
private:
    //char myName[CONST_VAR::nameLength];
    int myPhoneNum; //보낼 숫자

public:
    void Init(int num);
    void ShowInfo();
    //void SendText(you &ohsgirl, int sendNum);
};

class you //메세지를 받고 수령했음을 알려줄 사람
{
private:
    char youName[CONST_VAR::nameLength];
    int getPhoneNum; //받을 숫자

public:
    void GetText(int getNum);
};

void test();
#endif