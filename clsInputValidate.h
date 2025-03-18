#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"
#include "clsUtility.h"
template<class T>
class clsInputValidate
{

public:

    static bool IsNumberBetween(T Number, T From, T To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;

    }


    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        //Date>=From && Date<=To
        if ((clsDate::isDateAfterDate2(Date, From) || clsDate::isDate1EqualDate2(Date, From))
            &&
            (clsDate::isDate1BeforeDate2(Date, To) || clsDate::isDate1EqualDate2(Date, To))
            )
        {
            return true;
        }

        //Date>=To && Date<=From
        if ((clsDate::isDateAfterDate2(Date, To) || clsDate::isDate1EqualDate2(Date, To))
            &&
            (clsDate::isDate1EqualDate2(Date, From) || clsDate::isDate1EqualDate2(Date, From))
            )
        {
            return true;
        }

        return false;
    }

    static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        T Number;
        while (!(cin >> Number)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, Enter again: ")
    {
        T Number = ReadNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadNumber();
        }
        return Number;
    }


    static bool IsValideDate(clsDate Date)
    {
        return	clsDate::isValidDate(Date);
    }

    static string ReadString(string message)
    {
        string  S1 = "";
        cout << message;
        // Usage of std::ws will extract all the whitespace character
        getline(cin >> ws, S1);
        return S1;
    }


};