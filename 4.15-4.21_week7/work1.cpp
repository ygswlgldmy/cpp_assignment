#include <iostream>

double total(const class CBank& cbank, const class BBank& bbank, const class GBank& gbank);

class CBank {
private:
    double balance;

public:
    CBank(double balance) : balance(balance) {}

    friend double total(const CBank& cbank, const BBank& bbank, const GBank& gbank);
};

class BBank {
private:
    double balance;

public:
    BBank(double balance) : balance(balance) {}

    friend double total(const CBank& cbank, const BBank& bbank, const GBank& gbank);
};

class GBank {
private:
    double balance;

public:
    GBank(double balance) : balance(balance) {}

    friend double total(const CBank& cbank, const BBank& bbank, const GBank& gbank);
};

double total(const CBank& cbank, const BBank& bbank, const GBank& gbank) {
    return cbank.balance + bbank.balance + gbank.balance;
}

int main() {
    CBank cbank(2800);
    BBank bbank(3300);
    GBank gbank(2000);

    double totalBalance = total(cbank, bbank, gbank);
    std::cout << "三个银行的总存款数是:" << std::endl << totalBalance << "万" << std::endl;
    return 0;
}