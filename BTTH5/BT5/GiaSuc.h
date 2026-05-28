#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class GiaSuc
{
public:
    virtual ~GiaSuc() {}
    virtual void Keu() = 0;
    virtual int SinhCon() = 0;
    virtual int ChoSua() = 0;
    virtual string Loai() = 0;
};
