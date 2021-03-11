#include <iostream>
#include <stdexcept>
#include <string>
#include <string>

using namespace std;

const int MODOLO = 10;
const int FORFACE=100000;
const int FORTROSO=1000;
const int LENGHT = 8;
const int MAX = 4;
const int WIDTH = 7;
const int HEIGHT = 5;


string hat(int c) {


    switch (c) {
        case 1:
            return "       \n _===_ \n";

        case 2:
            return "  ___  \n ..... \n";

        case 3:
            return "   _   \n  /_\\  \n";

        case 4:
            return "  ___  \n (_*_) \n";

    }
    return "";

}

string Le(int n) {
    switch (n) {
        case 1:
            return ".";

        case 2:
            return "o";

        case 3:
            return "O";

        case 4:
            return "-";

    }
    return "";
}

string Nose(int n) {
    switch (n) {
        case 1:
            return ",";

        case 2:
            return ".";

        case 3:
            return "_";

        case 4:
            return " ";

    }
    return "";
}

string Re(int n) {
    switch (n) {
        case 1:
            return ".";

        case 2:
            return "o";

        case 3:
            return "O";

        case 4:
            return "-";

    }
    return "";
}

string face(int n) {

    string le;
    string nose;
    string re;
    string la = " ";
    string ra = " ";
    nose = Nose(n % MODOLO);
    n = n / MODOLO;
    le = Le(n % MODOLO);
    n = n / MODOLO;
    re = Re(n % MODOLO);
    n = n / MODOLO;
    if (n % MODOLO == 2) {

        la = "\\";
    }
    n = n / MODOLO;
    if (n % MODOLO == 2) {
        ra = "/";
    }

    return la + "(" + le + nose + re + ")" + ra + "\n";
}

string Troso(int n) {

    string la = " ";
    string ra = " ";
    string troso = " ";


    switch (n % MODOLO) {
        case 1:
            la = "<";
            break;
        case 3:
            la = "/";
            break;
    }
    n = n / MODOLO;
    switch (n % MODOLO) {
        case 1:
            ra = ">";
            break;
        case 3:
            ra = "\\";
            break;
    }
    n = n / MODOLO;
    switch (n % MODOLO) {
        case 1:
            troso = "( : )";
            break;
        case 2:
            troso = "(] [)";
            break;
        case 3:
            troso = "(> <)";
            break;
        case 4:
            troso = "(   )";
            break;
    }
    return la + troso + ra + "\n";

}

string Base(int n) {
    switch (n) {
        case 1:
            return " ( : ) ";

        case 2:
            return " (\" \") ";

        case 3:
            return " (___) ";

        case 4:
            return " (   ) ";


    }
    return "";
}

namespace ariel {
    string snowman(int snown) {

        if (snown < 0) {
            throw std::invalid_argument("negative input");
        }
        int n = snown;
        int count = 0;
        do {
            int t = n % MODOLO;
//            cout<<t<<endl;
            if (t > MAX || (n != 0 && t == 0)) {
                throw std::invalid_argument("illegal input");
            }

            count++;
            n = n / MODOLO;


        } while (n != 0);
        if (count > LENGHT) {
            throw std::invalid_argument("to long input more then 8");
        }
        if (count < LENGHT) {
            throw std::invalid_argument("to short input less then 8");
        }

        n = snown;
        snown = 0;
        while (n != 0) {
            snown = snown * MODOLO;

            snown += (n % MODOLO);
            n = n / MODOLO;
        }

        string ans = " ";

        ans = hat(snown % MODOLO);
        snown = snown / MODOLO;

        ans += face(snown % FORFACE);
        snown = snown / FORTROSO;

        ans += Troso(snown % FORTROSO);
        snown = snown / FORTROSO;

        ans += Base(snown);

        return (ans);
    }
}

