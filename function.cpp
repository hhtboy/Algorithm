#include "header.h"
#include <iostream>

void me::Init(int num)
{
    myPhoneNum = num;
}

void me::ShowInfo()
{
    std::cout << myPhoneNum;
}

// void me::SendText(you &ohsgirl, int sendNum)
// {
//     ohsgirl.GetText(sendNum);
// }

// void you::GetText(int getNum)
// {
//     getPhoneNum = getNum;
//     std::cout << getPhoneNum;
// }
