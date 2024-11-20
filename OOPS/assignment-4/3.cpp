#include <iostream>
using namespace std;

class Alpha
{
private:
    int alphaData;

public:
    Alpha(int data) : alphaData(data)
    {
        cout << "Alpha constructor called. Data: " << alphaData << endl;
    }
    void displayAlpha()
    {
        cout << "Alpha Data: " << alphaData << endl;
    }
    ~Alpha()
    {
        cout << "Alpha destructor called." << endl;
    }
};

class Beta
{
private:
    int betaData;

public:
    Beta(int data) : betaData(data)
    {
        cout << "Beta constructor called. Data: " << betaData << endl;
    }
    void displayBeta()
    {
        cout << "Beta Data: " << betaData << endl;
    }
    ~Beta()
    {
        cout << "Beta destructor called." << endl;
    }
};

class Gamma : public Alpha, public Beta
{
private:
    int gammaData;

public:
    Gamma(int alphaVal, int betaVal, int gammaVal)
        : Alpha(alphaVal), Beta(betaVal), gammaData(gammaVal)
    {
        cout << "Gamma constructor called. Data: " << gammaData << endl;
    }
    void displayGamma()
    {
        displayAlpha();
        displayBeta();
        cout << "Gamma Data: " << gammaData << endl;
    }
    ~Gamma()
    {
        cout << "Gamma destructor called." << endl;
    }
};

int main()
{
    int alphaVal, betaVal, gammaVal;

    cout << "Enter data for Alpha: ";
    cin >> alphaVal;
    cout << "Enter data for Beta: ";
    cin >> betaVal;
    cout << "Enter data for Gamma: ";
    cin >> gammaVal;

    Gamma gammaObj(alphaVal, betaVal, gammaVal);

    cout << "\nDisplaying data:\n";
    gammaObj.displayGamma();

    return 0;
}
