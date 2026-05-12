#pragma once
#include<iostream>
using namespace std;

class cTime
{
private:
    int gio;
    int phut;
    int giay;

public:
    void ChuanHoa();
    cTime(int = 0, int = 0, int = 0);
    cTime operator+(int) const;
    cTime operator-(int) const;
    cTime& operator++();    
    cTime operator++(int);  
    cTime& operator--();
    cTime operator--(int);
    friend istream& operator>>(istream&, cTime&);
    friend ostream& operator<<(ostream&, const cTime&);
};
